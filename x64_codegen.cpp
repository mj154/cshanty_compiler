#include <ostream>
#include "3ac.hpp"

namespace cshanty{

void IRProgram::allocGlobals(){
	//Choose a label for each global
	int i = 1;
	for(std::map<SemSymbol*, SymOpd*>::iterator iter = globals.begin(); iter != globals.end(); iter++){
		std::string temp = iter->second->getName();
		iter->second->setMemoryLoc("gbl_" + temp);
		i+=1;
	}
}

void IRProgram::datagenX64(std::ostream& out){
	
	out << ".data\n";
	for(std::map<SemSymbol*, SymOpd*>::iterator iter = globals.begin(); iter != globals.end(); iter++)
	{
		std::string memloc = iter->second->getMemoryLoc() + ": " + ".quad 0\n";
		out << memloc;
	}
	

	out << ".text\n" << ".globl main\n";
	// out << ".align 8\n";
	
}

void IRProgram::toX64(std::ostream& out){
	allocGlobals();
	datagenX64(out);
	// Iterate over each procedure and codegen it
	for(auto procedure : *procs){
		procedure->toX64(out); out << "\n";
	}
}

void Procedure::allocLocals(){
	//Allocate space for locals
	// Iterate over each procedure and codegen it
	int offset = -24; //space for locals
	for(std::map<SemSymbol*, SymOpd*>::iterator iter = locals.begin(); iter != locals.end(); iter++)
	{
		iter->second->setMemoryLoc(std::to_string(offset) + "(%rbp)");
		offset-=8;
	}

	int temp = 8;
	for (auto temporary : temps){
		if (!temps.empty()) //nonempty temps
		{
			temporary->setMemoryLoc("%r" + std::to_string(temp));
			temp++;
			offset-=8; //8 byte aligned
		}
	}


}

void Procedure::toX64(std::ostream& out){
	//Allocate all locals
	allocLocals();

	enter->codegenLabels(out);
	enter->codegenX64(out);
	out << "#Fn body " << myName << "\n";
	for (auto quad : *bodyQuads){
		quad->codegenLabels(out);
		out << "#" << quad->toString() << "\n";
		quad->codegenX64(out);
	}
	out << "#Fn epilogue " << myName << "\n";
	leave->codegenLabels(out);
	leave->codegenX64(out);
}

void Quad::codegenLabels(std::ostream& out){
	if (labels.empty()){ return; }

	size_t numLabels = labels.size();
	size_t labelIdx = 0;
	for ( Label * label : labels){
		out << label->getName() << ": ";
		if (labelIdx != numLabels - 1){ out << "\n"; }
		labelIdx++;
	}
}

void BinOpQuad::codegenX64(std::ostream& out){
	src1->genLoadVal(out, A);

	switch(opr){
		case ADD64:
			src2->genLoadVal(out, B);
			out << "addq %rax, %rbx\n";
			dst->genStoreVal(out, B);
			break;

		case SUB64:
			src2->genLoadVal(out, B);
			out << "subq %rbx, %rax\n";
			dst->genStoreVal(out, A);
			break;
		
		case MULT64:
			src2->genLoadVal(out, B);
			out << "imulq %rbx\n";
			dst->genStoreVal(out, A);
			break;

		case DIV64:
			src2->genLoadVal(out, B);
			out << "movq $0, %rdx\n";
			out << "idivq %rbx\n";
			dst->genStoreVal(out, A);
			break;

		case AND64:
			src2->genLoadVal(out, B);
			out << "andq %rbx, %rax\n";
			dst->genStoreVal(out, A);
			break;
		
		case OR64:
			src2->genLoadVal(out, B);
			out << "orq %rbx, %rax\n";
			dst->genStoreVal(out, A);
			break;

		case EQ64:
			src2->genLoadVal(out, B);
			out << "cmpq %rax, %rbx\n";
			out << "sete %al\n";
			dst->genStoreVal(out, A);
			break;

		case NEQ64:
			src2->genLoadVal(out, B);
			out << "cmpq %rax, %rbx\n";
			out << "setne %al\n";
			dst->genStoreVal(out, A);
			break;

		case LT64:
			src2->genLoadVal(out, B);
			out << "cmpq %rbx, %rax\n";
			out << "setl %al\n";
			dst->genStoreVal(out, A);
			break;
		
		case GT64:
			src2->genLoadVal(out, B);
			out << "cmpq %rbx, %rax\n";
			out << "setg %al\n";
			dst->genStoreVal(out, A);
			break;

		case LTE64:
			src2->genLoadVal(out, B);
			out << "cmpq %rbx, %rax\n";
			out << "setle %al\n";
			dst->genStoreVal(out, A);
			break;
		
		case GTE64:
			src2->genLoadVal(out, B);
			out << "cmpq %rbx, %rax\n";
			out << "setge %al\n";
			dst->genStoreVal(out, A);
			break;

		
	}
}

void UnaryOpQuad::codegenX64(std::ostream& out){
	src->genLoadVal(out, A);
	switch(op){

		case NOT64:
			out <<"negq %rax\n";
			dst->genStoreVal(out, A);
			break;
		case NEG64:
			out <<"xorq $1, $rax\n";
			dst->genStoreVal(out, A);

	}


		
}

void AssignQuad::codegenX64(std::ostream& out){
	src->genLoadVal(out, A);
	dst->genStoreVal(out, A);
}

void GotoQuad::codegenX64(std::ostream& out){
	out << "jmp " << tgt->getName() << "\n";
}

void IfzQuad::codegenX64(std::ostream& out){
	cnd->genLoadVal(out, A);

	out <<"compq $0, %rax\nje";
	out << tgt->getName() << "\n";
}

void NopQuad::codegenX64(std::ostream& out){
	out << "nop" << "\n";
}

void IntrinsicOutputQuad::codegenX64(std::ostream& out){
	if (myType->isBool()){
		myArg->genLoadVal(out, DI);
		out << "callq printBool\n";
	} else {
		if (myType->isInt()){
			myArg->genLoadVal(out, DI);
			out << "callq printInt\n";
		} else
		
		if(myType->isString()){
			myArg->genLoadVal(out, DI);
			out << "callq printString\n";
		} else

		if (myType->isVoid()){
			myArg->genLoadVal(out, DI);
			out << "callq printVoid\n";
		}

		else

		if (myType->isRecord()){
			myArg->genLoadVal(out, DI);
			out << "callq printRecord\n";
		}

		

	}
}

void IntrinsicInputQuad::codegenX64(std::ostream& out){
	TODO(Implement me) //hm
}

void CallQuad::codegenX64(std::ostream& out){
	out << "callq lbl_fun_";
	out << callee->getName() << "\n";
}

void EnterQuad::codegenX64(std::ostream& out){
	out << "pushq " << "%rbp\n";
	out << "movq " << "%rsp, %rbp\n";



	out << "addq " << "$16, %rbp\n";
	out << "subq " << "$" << myProc->arSize() << ", %rsp\n";
}

void LeaveQuad::codegenX64(std::ostream& out){
	out << "addq $";
	out << myProc->arSize() << ", %rsp\n";
	
	out << "popq %rbp\nretq\n";
}

void SetArgQuad::codegenX64(std::ostream& out){
	if(index<6){
		if (index == 1){
			opd->genLoadVal(out, A);
		} else

		if (index == 2){
			opd->genLoadVal(out, B);
		} else

		if (index == 3){
			opd->genLoadVal(out, C);
		} else
		if (index == 4){
			opd->genLoadVal(out, D);
		} else
		if (index == 5){
			opd->genLoadVal(out, DI);
		}
		
	}
	else //i>=6
	{out << "pushq $" << opd->valString() << "\n";}
}

void GetArgQuad::codegenX64(std::ostream& out){
	//We don't actually need to do anything here
}

void SetRetQuad::codegenX64(std::ostream& out){
	opd->genLoadVal(out, A);
}

void GetRetQuad::codegenX64(std::ostream& out){
	opd->genStoreVal(out, A);
}

void IndexQuad::codegenX64(std::ostream& out){
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
}

void SymOpd::genLoadVal(std::ostream& out, Register reg){
	out << "movq " << getMemoryLoc() << ", " << RegUtils::rootStr(reg) << "\n"; 
}

void SymOpd::genStoreVal(std::ostream& out, Register reg){
	out << "movq " << RegUtils::rootStr(reg) << ", " << getMemoryLoc() << "\n";
}

void SymOpd::genLoadAddr(std::ostream& out, Register reg) {
	TODO(Implement me if necessary)
}

void AuxOpd::genLoadVal(std::ostream& out, Register reg){
	out << "movq " << getMemoryLoc() << ", " << RegUtils::rootStr(reg) << "\n"; 
}

void AuxOpd::genStoreVal(std::ostream& out, Register reg){
	out << "movq " << RegUtils::rootStr(reg) << ", " << getMemoryLoc() << "\n";
}
void AuxOpd::genLoadAddr(std::ostream& out, Register reg){
	out << "movq " << getMemoryLoc() << ", " << RegUtils::rootStr(reg) << "\n"; 
}


void AddrOpd::genStoreVal(std::ostream& out, Register reg){
	out << "movq " << RegUtils::rootStr(reg) << ", " << getMemoryLoc() << "\n";
}

void AddrOpd::genLoadVal(std::ostream& out, Register reg){
	out << "movq " << getMemoryLoc() << ", " << RegUtils::rootStr(reg) << "\n"; 
}

void AddrOpd::genStoreAddr(std::ostream& out, Register reg){
	out << "movq " << RegUtils::rootStr(reg) << ", " << getMemoryLoc() << "\n";
}

void AddrOpd::genLoadAddr(std::ostream & out, Register reg){
	out << "movq " << getMemoryLoc() << ", " << RegUtils::rootStr(reg) << "\n"; 
}

void LitOpd::genLoadVal(std::ostream & out, Register reg){
	out << getMovOp() << " $" << val << ", " << getReg(reg) << "\n";
}

}
