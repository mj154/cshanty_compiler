.data
gbl_a: .quad 0
.text
.globl main
fun_foo: pushq %rbp
movq %rsp, %rbp
addq $16, %rbp
subq $0, %rsp
#Fn body foo
#            [a] := 9
movq $9, %rax
movq a, gbl_a
#            REPORT [a]
movq gbl_a, di
callq printInt
#Fn epilogue foo
lbl_0: addq $0, %rsp
popq %rbp
retq

main: pushq %rbp
movq %rsp, %rbp
addq $16, %rbp
subq $0, %rsp
#Fn body main
#            call foo
callq lbl_fun_foo
#            setret 0
movq $0, %rax
#            goto lbl_1
jmp lbl_1
#Fn epilogue main
lbl_1: addq $0, %rsp
popq %rbp
retq

