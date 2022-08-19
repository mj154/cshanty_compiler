// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "grammar.hh"


// Unqualified %code blocks.
#line 34 "cshanty.yy"

   // C std code for utility functions
   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   // Our code for interoperation between scanner/parser
   #include "scanner.hpp"
   #include "ast.hpp"
   #include "tokens.hpp"

  //Request tokens from our scanner member, not 
  // from a global function
  #undef yylex
  #define yylex scanner.yylex

#line 62 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "cshanty.yy"
namespace cshanty {
#line 135 "parser.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (cshanty::Scanner &scanner_yyarg, cshanty::ProgramNode** root_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      root (root_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 158 "cshanty.yy"
                  {
		  (yylhs.value.transProgram) = new ProgramNode((yystack_[0].value.transDeclList));
		  *root = (yylhs.value.transProgram);
		  }
#line 618 "parser.cc"
    break;

  case 3:
#line 164 "cshanty.yy"
                  { 
	  	  (yylhs.value.transDeclList) = (yystack_[1].value.transDeclList); 
	  	  DeclNode * declNode = (yystack_[0].value.transDecl);
		  (yylhs.value.transDeclList)->push_back(declNode);
	  	  }
#line 628 "parser.cc"
    break;

  case 4:
#line 170 "cshanty.yy"
                  {
		  (yylhs.value.transDeclList) = new std::list<DeclNode * >();
		  }
#line 636 "parser.cc"
    break;

  case 5:
#line 175 "cshanty.yy"
                  { (yylhs.value.transDecl) = (yystack_[0].value.transVarDecl); }
#line 642 "parser.cc"
    break;

  case 6:
#line 177 "cshanty.yy"
                  { (yylhs.value.transDecl) = (yystack_[0].value.transFn); }
#line 648 "parser.cc"
    break;

  case 7:
#line 179 "cshanty.yy"
                  { (yylhs.value.transDecl) = (yystack_[0].value.transRecordDecl); }
#line 654 "parser.cc"
    break;

  case 8:
#line 182 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[4].value.transToken)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transRecordDecl) = new RecordTypeDeclNode(p, (yystack_[3].value.transID), (yystack_[1].value.transVarDeclList));
		  }
#line 663 "parser.cc"
    break;

  case 9:
#line 188 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transType)->pos(), (yystack_[1].value.transID)->pos());
		  (yylhs.value.transVarDecl) = new VarDeclNode(p, (yystack_[2].value.transType), (yystack_[1].value.transID));
		  }
#line 672 "parser.cc"
    break;

  case 10:
#line 194 "cshanty.yy"
                  {
		  (yylhs.value.transVarDeclList) = new std::list<VarDeclNode *>();
		  (yylhs.value.transVarDeclList)->push_back((yystack_[0].value.transVarDecl));
		  }
#line 681 "parser.cc"
    break;

  case 11:
#line 199 "cshanty.yy"
                  {
		  (yylhs.value.transVarDeclList) = (yystack_[1].value.transVarDeclList);
		  (yylhs.value.transVarDeclList)->push_back((yystack_[0].value.transVarDecl));
		  }
#line 690 "parser.cc"
    break;

  case 12:
#line 205 "cshanty.yy"
                  { 
		  (yylhs.value.transType) = new IntTypeNode((yystack_[0].value.transToken)->pos());
		  }
#line 698 "parser.cc"
    break;

  case 13:
#line 209 "cshanty.yy"
                  {
		  (yylhs.value.transType) = new BoolTypeNode((yystack_[0].value.transToken)->pos());
		  }
#line 706 "parser.cc"
    break;

  case 14:
#line 213 "cshanty.yy"
                  {
		  (yylhs.value.transType) = new RecordTypeNode((yystack_[0].value.transID)->pos(), (yystack_[0].value.transID));
		  }
#line 714 "parser.cc"
    break;

  case 15:
#line 217 "cshanty.yy"
                  {
		  (yylhs.value.transType) = new StringTypeNode((yystack_[0].value.transToken)->pos());
		  }
#line 722 "parser.cc"
    break;

  case 16:
#line 221 "cshanty.yy"
                  {
		  (yylhs.value.transType) = new VoidTypeNode((yystack_[0].value.transToken)->pos());
		  }
#line 730 "parser.cc"
    break;

  case 17:
#line 226 "cshanty.yy"
                  {
		  Position * pos = new Position((yystack_[6].value.transType)->pos(), (yystack_[0].value.transToken)->pos());
		  std::list<FormalDeclNode *> * f = new std::list<FormalDeclNode *>();
		  (yylhs.value.transFn) = new FnDeclNode(pos, (yystack_[6].value.transType), (yystack_[5].value.transID), f, (yystack_[1].value.transStmts));
		  }
#line 740 "parser.cc"
    break;

  case 18:
#line 232 "cshanty.yy"
                  {
		  Position * pos = new Position((yystack_[7].value.transType)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transFn) = new FnDeclNode(pos, (yystack_[7].value.transType), (yystack_[6].value.transID), (yystack_[4].value.transFormalList), (yystack_[1].value.transStmts));
		  }
#line 749 "parser.cc"
    break;

  case 19:
#line 238 "cshanty.yy"
                  {
		  (yylhs.value.transFormalList) = new std::list<FormalDeclNode *>();
		  (yylhs.value.transFormalList)->push_back((yystack_[0].value.transFormal));
		  }
#line 758 "parser.cc"
    break;

  case 20:
#line 243 "cshanty.yy"
                  {
		  (yylhs.value.transFormalList) = (yystack_[2].value.transFormalList);
		  (yylhs.value.transFormalList)->push_back((yystack_[0].value.transFormal));
		  }
#line 767 "parser.cc"
    break;

  case 21:
#line 262 "cshanty.yy"
                  {
		  Position * pos = new Position((yystack_[1].value.transType)->pos(), (yystack_[0].value.transID)->pos());
		  (yylhs.value.transFormal) = new FormalDeclNode(pos, (yystack_[1].value.transType), (yystack_[0].value.transID));
		  }
#line 776 "parser.cc"
    break;

  case 22:
#line 268 "cshanty.yy"
                  {
		  (yylhs.value.transStmts) = new std::list<StmtNode *>();
		  //$$->push_back($1);
	   	  }
#line 785 "parser.cc"
    break;

  case 23:
#line 273 "cshanty.yy"
                  {
		  (yylhs.value.transStmts) = (yystack_[1].value.transStmts);
		  (yylhs.value.transStmts)->push_back((yystack_[0].value.transStmt));
	  	  }
#line 794 "parser.cc"
    break;

  case 24:
#line 279 "cshanty.yy"
                  {
		  Position * p = (yystack_[0].value.transVarDecl)->pos();
		  (yylhs.value.transStmt) = new VarDeclNode(p, (yystack_[0].value.transVarDecl)->getTypeNode(), (yystack_[0].value.transVarDecl)->ID());
		  }
#line 803 "parser.cc"
    break;

  case 25:
#line 284 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[1].value.transAssignExp)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new AssignStmtNode(p, (yystack_[1].value.transAssignExp)); 
		  }
#line 812 "parser.cc"
    break;

  case 26:
#line 289 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transLVal)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new PostDecStmtNode(p, (yystack_[2].value.transLVal));
		  }
#line 821 "parser.cc"
    break;

  case 27:
#line 294 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transLVal)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new PostIncStmtNode(p, (yystack_[2].value.transLVal));
		  }
#line 830 "parser.cc"
    break;

  case 28:
#line 299 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transToken)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new ReceiveStmtNode(p, (yystack_[1].value.transLVal));
		  }
#line 839 "parser.cc"
    break;

  case 29:
#line 304 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transToken)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new ReportStmtNode(p, (yystack_[1].value.transExp));
		  }
#line 848 "parser.cc"
    break;

  case 30:
#line 309 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[6].value.transToken)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new IfStmtNode(p, (yystack_[4].value.transExp), (yystack_[1].value.transStmts));
		  }
#line 857 "parser.cc"
    break;

  case 31:
#line 314 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[10].value.transToken)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new IfElseStmtNode(p, (yystack_[8].value.transExp), (yystack_[5].value.transStmts), (yystack_[1].value.transStmts));
		  }
#line 866 "parser.cc"
    break;

  case 32:
#line 319 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[6].value.transToken)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new WhileStmtNode(p, (yystack_[4].value.transExp), (yystack_[1].value.transStmts));
		  }
#line 875 "parser.cc"
    break;

  case 33:
#line 324 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transToken)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new ReturnStmtNode(p, (yystack_[1].value.transExp));
		  }
#line 884 "parser.cc"
    break;

  case 34:
#line 329 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[1].value.transToken)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new ReturnStmtNode(p, nullptr);
		  }
#line 893 "parser.cc"
    break;

  case 35:
#line 334 "cshanty.yy"
                  { 
		  Position * p = new Position((yystack_[1].value.transCallExp)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transStmt) = new CallStmtNode(p, (yystack_[1].value.transCallExp)); 
		  }
#line 902 "parser.cc"
    break;

  case 36:
#line 340 "cshanty.yy"
                  { (yylhs.value.transExp) = (yystack_[0].value.transAssignExp); }
#line 908 "parser.cc"
    break;

  case 37:
#line 342 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new MinusNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 917 "parser.cc"
    break;

  case 38:
#line 347 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new PlusNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 926 "parser.cc"
    break;

  case 39:
#line 352 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new TimesNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 935 "parser.cc"
    break;

  case 40:
#line 357 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new DivideNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 944 "parser.cc"
    break;

  case 41:
#line 362 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new AndNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 953 "parser.cc"
    break;

  case 42:
#line 367 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new OrNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 962 "parser.cc"
    break;

  case 43:
#line 372 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new EqualsNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 971 "parser.cc"
    break;

  case 44:
#line 377 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new NotEqualsNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 980 "parser.cc"
    break;

  case 45:
#line 382 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new GreaterNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 989 "parser.cc"
    break;

  case 46:
#line 387 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new GreaterEqNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 998 "parser.cc"
    break;

  case 47:
#line 392 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new LessNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 1007 "parser.cc"
    break;

  case 48:
#line 397 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transExp)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new LessEqNode(p, (yystack_[2].value.transExp), (yystack_[0].value.transExp));
		  }
#line 1016 "parser.cc"
    break;

  case 49:
#line 402 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[1].value.transToken)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new NotNode(p, (yystack_[0].value.transExp));
		  }
#line 1025 "parser.cc"
    break;

  case 50:
#line 407 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[1].value.transToken)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transExp) = new NegNode(p, (yystack_[0].value.transExp));
		  }
#line 1034 "parser.cc"
    break;

  case 51:
#line 412 "cshanty.yy"
                  { (yylhs.value.transExp) = (yystack_[0].value.transExp); }
#line 1040 "parser.cc"
    break;

  case 52:
#line 415 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transLVal)->pos(), (yystack_[0].value.transExp)->pos());
		  (yylhs.value.transAssignExp) = new AssignExpNode(p, (yystack_[2].value.transLVal), (yystack_[0].value.transExp));
		  }
#line 1049 "parser.cc"
    break;

  case 53:
#line 421 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[2].value.transID)->pos(), (yystack_[0].value.transToken)->pos());
		  std::list<ExpNode *> * noargs =
		    new std::list<ExpNode *>();
		  (yylhs.value.transCallExp) = new CallExpNode(p, (yystack_[2].value.transID), noargs);
		  }
#line 1060 "parser.cc"
    break;

  case 54:
#line 428 "cshanty.yy"
                  {
		  Position * p = new Position((yystack_[3].value.transID)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transCallExp) = new CallExpNode(p, (yystack_[3].value.transID), (yystack_[1].value.transActuals));
		  }
#line 1069 "parser.cc"
    break;

  case 55:
#line 434 "cshanty.yy"
                  {
		  std::list<ExpNode *> * list =
		    new std::list<ExpNode *>();
		  list->push_back((yystack_[0].value.transExp));
		  (yylhs.value.transActuals) = list;
		  }
#line 1080 "parser.cc"
    break;

  case 56:
#line 441 "cshanty.yy"
                  {
		  (yylhs.value.transActuals) = (yystack_[2].value.transActuals);
		  (yylhs.value.transActuals)->push_back((yystack_[0].value.transExp));
		  }
#line 1089 "parser.cc"
    break;

  case 57:
#line 447 "cshanty.yy"
                  { (yylhs.value.transExp) = (yystack_[0].value.transLVal); }
#line 1095 "parser.cc"
    break;

  case 58:
#line 449 "cshanty.yy"
                  { (yylhs.value.transExp) = new IntLitNode((yystack_[0].value.transIntToken)->pos(), (yystack_[0].value.transIntToken)->num()); }
#line 1101 "parser.cc"
    break;

  case 59:
#line 451 "cshanty.yy"
                  { (yylhs.value.transExp) = new StrLitNode((yystack_[0].value.transStrToken)->pos(), (yystack_[0].value.transStrToken)->str()); }
#line 1107 "parser.cc"
    break;

  case 60:
#line 453 "cshanty.yy"
                  { (yylhs.value.transExp) = new TrueNode((yystack_[0].value.transToken)->pos()); }
#line 1113 "parser.cc"
    break;

  case 61:
#line 455 "cshanty.yy"
                  { (yylhs.value.transExp) = new FalseNode((yystack_[0].value.transToken)->pos()); }
#line 1119 "parser.cc"
    break;

  case 62:
#line 457 "cshanty.yy"
                  { (yylhs.value.transExp) = (yystack_[1].value.transExp); }
#line 1125 "parser.cc"
    break;

  case 63:
#line 459 "cshanty.yy"
                  {
		  (yylhs.value.transExp) = (yystack_[0].value.transCallExp);
		  }
#line 1133 "parser.cc"
    break;

  case 64:
#line 464 "cshanty.yy"
                  {
		  (yylhs.value.transLVal) = (yystack_[0].value.transID);
		  }
#line 1141 "parser.cc"
    break;

  case 65:
#line 468 "cshanty.yy"
                  {
		  Position * pos = new Position((yystack_[3].value.transID)->pos(), (yystack_[0].value.transToken)->pos());
		  (yylhs.value.transLVal) = new IndexNode(pos, (yystack_[3].value.transID), (yystack_[1].value.transID));
		  }
#line 1150 "parser.cc"
    break;

  case 66:
#line 474 "cshanty.yy"
                  {
		  Position * pos = (yystack_[0].value.transIDToken)->pos();
		  (yylhs.value.transID) = new IDNode(pos, (yystack_[0].value.transIDToken)->value()); 
		  }
#line 1159 "parser.cc"
    break;


#line 1163 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -36;

  const signed char Parser::yytable_ninf_ = -15;

  const short
  Parser::yypact_[] =
  {
     -36,     1,    42,   -36,   -36,   -36,   -36,    -6,   -36,   -36,
     -36,   -36,   -36,    -6,   -36,   -36,    -3,    44,    41,   117,
     -36,   -36,   150,    -6,    34,    -6,     8,   -36,   -36,   -36,
      -1,   -36,   -36,    41,    38,    21,   -36,   -36,   -36,    26,
      -6,   446,   410,    47,   -36,   -36,    39,    45,     2,    94,
      35,   446,    48,    51,   -36,   -36,   446,   198,   446,   -36,
     -36,   213,   -36,   -36,   -36,    81,    22,   -36,   237,   446,
     -36,   -36,   446,    50,    55,    -6,   428,   -36,   261,   -36,
     288,   -36,   -36,   -36,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   -36,   446,   -36,   315,   342,
     -36,   -36,    58,   -36,   342,    57,    60,   -36,   378,   -36,
     397,   397,   397,   397,   397,    -5,   397,   364,    -5,   -36,
      66,   -36,   446,   -36,   -36,   -36,   342,   144,   164,    88,
     -36,    75,   -36,   178,   -36
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,    13,    66,    12,     0,    15,    16,
       3,     7,     5,     0,     6,    14,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,    19,     8,    11,
       0,    22,    21,     0,     0,     0,    20,    22,    17,     0,
       0,     0,     0,     0,    24,    23,     0,     0,     0,    64,
       0,     0,     0,    64,    61,    58,     0,     0,     0,    59,
      60,     0,    36,    63,    51,    57,    64,    34,     0,     0,
      25,    35,     0,     0,     0,     0,     0,    18,     0,    28,
       0,    50,    57,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,    33,     0,    52,
      26,    27,     0,    53,    55,     0,     0,    62,    41,    40,
      43,    45,    46,    47,    48,    37,    44,    42,    38,    39,
       0,    65,     0,    54,    22,    22,    56,     0,     0,    30,
      32,     0,    22,     0,    31
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -36,   -36,   -36,   -36,   -36,    10,   -36,    11,   -36,   -36,
      71,   -35,   -36,    52,   -28,   -21,   -36,    54,   -32,    -2
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,    10,    11,    44,    22,    23,    14,    26,
      27,    35,    45,    61,    62,    63,   105,    64,    65,    66
  };

  const short
  Parser::yytable_[] =
  {
      15,     3,    50,    48,    85,    16,    72,    46,    52,     5,
      73,    17,    12,    13,    47,    33,    15,    15,    48,    74,
      15,    30,    46,    32,    18,    82,     4,    38,    21,    47,
      25,    15,    29,    49,    96,    20,     5,    39,    53,     6,
       4,    77,    75,    34,    25,    76,     4,     4,    49,    51,
       5,    39,    40,     6,    41,    42,     5,     5,     8,     6,
       6,    31,     9,    43,   122,    37,    40,    19,    41,    42,
      69,    75,     8,   102,     7,    70,     9,    43,     8,     8,
      20,    71,     9,     9,    79,    72,   100,   124,   121,   127,
     128,   101,   123,   125,    68,    48,    48,   133,   131,    46,
      46,    48,   132,    78,    36,    46,    47,    47,    80,   -14,
      83,    81,    47,     0,    75,     0,     0,    76,     0,     0,
       0,    98,     4,     0,    99,    49,    49,     0,   104,     0,
       0,    49,     5,     0,     0,     6,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     4,
     129,     0,    24,     0,     8,     4,    28,     0,     9,     5,
      39,     0,     6,     0,     0,     5,     0,     0,     6,     4,
     130,     0,     0,     0,   126,    40,     0,    41,    42,     5,
      39,     8,     6,     4,   134,     9,    43,     8,     0,     0,
       0,     9,     0,     5,    39,    40,     6,    41,    42,     0,
       0,     8,     0,     0,     0,     9,    43,     0,     0,    40,
      54,    41,    42,     5,     0,     8,    84,    55,     0,     9,
      43,    56,    85,     0,    86,     0,    87,    88,     0,     0,
       0,     0,     0,     0,    89,    90,    59,    91,    60,    92,
      84,    93,    94,     0,     0,     0,    85,     0,    86,    95,
      87,    88,    96,     0,     0,     0,     0,     0,    89,    90,
       0,    91,     0,    92,    84,    93,    94,     0,     0,     0,
      85,     0,    86,    97,    87,    88,    96,     0,     0,     0,
       0,     0,    89,    90,     0,    91,     0,    92,     0,    93,
      94,    84,     0,     0,     0,     0,   106,    85,     0,    86,
      96,    87,    88,     0,     0,     0,     0,     0,     0,    89,
      90,     0,    91,     0,    92,     0,    93,    94,    84,     0,
       0,     0,     0,   107,    85,     0,    86,    96,    87,    88,
       0,     0,     0,     0,     0,     0,    89,    90,     0,    91,
       0,    92,     0,    93,    94,    84,     0,     0,     0,     0,
     120,    85,     0,    86,    96,    87,    88,     0,     0,     0,
       0,     0,     0,    89,    90,     0,    91,    84,    92,     0,
      93,    94,     0,    85,     0,    86,     0,    87,    88,     0,
       0,    96,     0,     0,     0,    89,    90,    85,    91,    86,
      92,    87,    88,    94,     0,     0,     0,     0,     0,    89,
      90,     0,    91,    96,    92,     0,    85,    94,   -15,     0,
     -15,   -15,     0,     0,     0,     0,     0,    96,   -15,   -15,
       0,    91,    54,   -15,     0,     5,    94,     0,     0,    55,
       0,     0,     0,    56,    57,    58,    96,     0,     0,     0,
      54,     0,     0,     5,     0,     0,    67,    55,    59,     0,
      60,    56,    57,    58,     0,     0,     0,     0,    54,     0,
       0,     5,     0,   103,     0,    55,    59,     0,    60,    56,
      57,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,    60
  };

  const short
  Parser::yycheck_[] =
  {
       2,     0,    37,    35,     9,     7,     4,    35,    40,    15,
       8,    13,     2,     2,    35,     7,    18,    19,    50,    17,
      22,    23,    50,    25,    27,    57,     5,     6,    18,    50,
      19,    33,    22,    35,    39,    36,    15,    16,    40,    18,
       5,     6,    20,    35,    33,    23,     5,     5,    50,    23,
      15,    16,    31,    18,    33,    34,    15,    15,    37,    18,
      18,    27,    41,    42,     7,    27,    31,    23,    33,    34,
      23,    20,    37,    75,    32,    36,    41,    42,    37,    37,
      36,    36,    41,    41,    36,     4,    36,    27,    30,   124,
     125,    36,    35,    27,    42,   127,   128,   132,    10,   127,
     128,   133,    27,    51,    33,   133,   127,   128,    56,    15,
      58,    57,   133,    -1,    20,    -1,    -1,    23,    -1,    -1,
      -1,    69,     5,    -1,    72,   127,   128,    -1,    76,    -1,
      -1,   133,    15,    -1,    -1,    18,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,     5,
       6,    -1,    35,    -1,    37,     5,     6,    -1,    41,    15,
      16,    -1,    18,    -1,    -1,    15,    -1,    -1,    18,     5,
       6,    -1,    -1,    -1,   122,    31,    -1,    33,    34,    15,
      16,    37,    18,     5,     6,    41,    42,    37,    -1,    -1,
      -1,    41,    -1,    15,    16,    31,    18,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    -1,    -1,    31,
      12,    33,    34,    15,    -1,    37,     3,    19,    -1,    41,
      42,    23,     9,    -1,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    38,    24,    40,    26,
       3,    28,    29,    -1,    -1,    -1,     9,    -1,    11,    36,
      13,    14,    39,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    24,    -1,    26,     3,    28,    29,    -1,    -1,    -1,
       9,    -1,    11,    36,    13,    14,    39,    -1,    -1,    -1,
      -1,    -1,    21,    22,    -1,    24,    -1,    26,    -1,    28,
      29,     3,    -1,    -1,    -1,    -1,    35,     9,    -1,    11,
      39,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,    24,    -1,    26,    -1,    28,    29,     3,    -1,
      -1,    -1,    -1,    35,     9,    -1,    11,    39,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    24,
      -1,    26,    -1,    28,    29,     3,    -1,    -1,    -1,    -1,
      35,     9,    -1,    11,    39,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    24,     3,    26,    -1,
      28,    29,    -1,     9,    -1,    11,    -1,    13,    14,    -1,
      -1,    39,    -1,    -1,    -1,    21,    22,     9,    24,    11,
      26,    13,    14,    29,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,    24,    39,    26,    -1,     9,    29,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    39,    21,    22,
      -1,    24,    12,    26,    -1,    15,    29,    -1,    -1,    19,
      -1,    -1,    -1,    23,    24,    25,    39,    -1,    -1,    -1,
      12,    -1,    -1,    15,    -1,    -1,    36,    19,    38,    -1,
      40,    23,    24,    25,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    15,    -1,    35,    -1,    19,    38,    -1,    40,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    44,    45,     0,     5,    15,    18,    32,    37,    41,
      46,    47,    48,    50,    51,    62,    62,    62,    27,    23,
      36,    48,    49,    50,    35,    50,    52,    53,     6,    48,
      62,    27,    62,     7,    35,    54,    53,    27,     6,    16,
      31,    33,    34,    42,    48,    55,    57,    58,    61,    62,
      54,    23,    61,    62,    12,    19,    23,    24,    25,    38,
      40,    56,    57,    58,    60,    61,    62,    36,    56,    23,
      36,    36,     4,     8,    17,    20,    23,     6,    56,    36,
      56,    60,    61,    56,     3,     9,    11,    13,    14,    21,
      22,    24,    26,    28,    29,    36,    39,    36,    56,    56,
      36,    36,    62,    35,    56,    59,    35,    35,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      35,    30,     7,    35,    27,    27,    56,    54,    54,     6,
       6,    10,    27,    54,     6
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    46,    46,    46,    47,    48,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    62
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     5,     3,
       1,     2,     1,     1,     1,     1,     1,     7,     8,     1,
       3,     2,     0,     2,     1,     2,     3,     3,     3,     3,
       7,    11,     7,     3,     2,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     3,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     4,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end file\"", "error", "$undefined", "AND", "ASSIGN", "BOOL", "CLOSE",
  "COMMA", "DEC", "DIVIDE", "ELSE", "EQUALS", "FALSE", "GREATER",
  "GREATEREQ", "ID", "IF", "INC", "INT", "INTLITERAL", "LBRACE", "LESS",
  "LESSEQ", "LPAREN", "MINUS", "NOT", "NOTEQUALS", "OPEN", "OR", "PLUS",
  "RBRACE", "RECEIVE", "RECORD", "REPORT", "RETURN", "RPAREN", "SEMICOL",
  "STRING", "STRLITERAL", "TIMES", "TRUE", "VOID", "WHILE", "$accept",
  "program", "globals", "decl", "recordDecl", "varDecl", "varDeclList",
  "type", "fnDecl", "formals", "formalDecl", "stmtList", "stmt", "exp",
  "assignExp", "callExp", "actualsList", "term", "lval", "id", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   157,   157,   163,   170,   174,   176,   178,   181,   187,
     193,   198,   204,   208,   212,   216,   220,   225,   231,   237,
     242,   261,   268,   272,   278,   283,   288,   293,   298,   303,
     308,   313,   318,   323,   328,   333,   339,   341,   346,   351,
     356,   361,   366,   371,   376,   381,   386,   391,   396,   401,
     406,   411,   414,   420,   427,   433,   440,   446,   448,   450,
     452,   454,   456,   458,   463,   467,   473
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
    };
    const int user_token_number_max_ = 297;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 5 "cshanty.yy"
} // cshanty
#line 1749 "parser.cc"

#line 479 "cshanty.yy"


void cshanty::Parser::error(const std::string& msg){
	std::cout << msg << std::endl;
	std::cerr << "syntax error" << std::endl;
}
