'''
MJ Tokens
'''

TERMS = "program,id,;,ε,class,{,},declarations,enddeclarations,=,comma,int,\
string,[],method,(,),void,val,@,[,],:=,return,if,else,for,to,step,while\
,switch,case,default,print,read,<,<=,==,!=,>=,>,+,-,not,||,*,/,&&,%,num,str,.,$"
TERMS = TERMS.split(',')

NON_TERMS = "PROGRAM,CLASS-DECL-LIST,CLASS-DECL,CLASS-BODY,DECLS-OPT,DECLS,METHOD-DECL-LIST,FIELD-DECL-LIST-DECLS,FIELD-DECL,FIELD-DECL-AUX1,FIELD-DECL-AUX2,TYPE,TYPE-AUX,BRACKETS-OPT,METHOD-DECL,METHOD-RETURN-TYPE,FORMAL-PARAMS-LIST,VAL-OPT,FORMAL-PARAMS-LIST-AUX,ID-LIST-COMMA,FORMAL-PARAMS-LIST-OPT,VAR-DECL-ID,VAR-INIT,ARRAY-INIT,VAR-INIT-LIST-COMMA,ARRAY-CREATION-EXPR,ARRAY-DIM-DECL,ARRAY-DIM-DECL-LIST,BLOCK,STMT-LIST,STMT-LIST-SEMICOLON,STMT,VARIABLE-START-STMT,ASSIGN-STMT,METHOD-CALL-STMT,ACTUAL-PARAMS-LIST,EXPRESSION-LIST-COMMA,RETURN-STMT,EXPRESSION-OPT,IF-STMT,ELSE-PART,IF-STMT-AUX,FOR-STMT,FOR-INIT-EXPR,STEP-OPT,WHILE-STMT,SWITCH-STMT,CASE,CASE-LIST,PRINT-STMT,READ-STMT,EXPRESSION,REL-EXPR,REL-EXPR-AUX,ADD-EXPR,ADD-EXPR-AUX,MULT-EXPR,MULT-EXPR-AUX,UNARY-EXPR,METHOD-CALL-OPT,REL-OP,UNARY-OP,ADD-OP,MULT-OP,UNSIG-LIT,VARIABLE,VARIABLE-AUX"

NON_TERMS_CPP = NON_TERMS.replace('-', '_').split(',')

NON_TERMS_DICT = dict(zip(NON_TERMS.split(','), NON_TERMS_CPP))

TOKS = "TOK_PROGRAM,\
    TOK_IDENTIFIER,\
    TOK_SEMICOLON,\
    '',\
    TOK_CLASS,\
    TOK_LCURLY,\
    TOK_RCURLY,\
    TOK_DECLARATIONS,\
    TOK_ENDDECLARATIONS,\
    TOK_EQUALS,\
    TOK_COMMA,\
    TOK_INT,\
    TOK_STRING,\
    TOK_LRSQUARE,\
    TOK_METHOD,\
    TOK_LPAREN,\
    TOK_RPAREN,\
    TOK_VOID,\
    TOK_VAL,\
    TOK_ARROBA,\
    TOK_LSQUARE,\
    TOK_RSQUARE,\
    TOK_ASSIGN,\
    TOK_RETURN,\
    TOK_IF,\
    TOK_ELSE,\
    TOK_FOR,\
    TOK_TO,\
    TOK_STEP,\
    TOK_WHILE,\
    TOK_SWITCH,\
    TOK_CASE,\
    TOK_DEFAULT,\
    TOK_PRINT,\
    TOK_READ,\
    TOK_LESS,\
    TOK_LESSEQ,\
    TOK_EQEQ,\
    TOK_DIFF,\
    TOK_GREATEREQ,\
    TOK_GREATER,\
    TOK_PLUS,\
    TOK_MINUS,\
    TOK_NOT,\
    TOK_2PIPE,\
    TOK_ASTERISK,\
    TOK_SLASH,\
    TOK_AND,\
    TOK_MOD,\
    TOK_INTEGERCONSTANT,\
    TOK_STRINGCONSTANT,\
    TOK_DOT,\
    END_OF_FILE"
TOKS = TOKS.replace(" ", "").split(',')

TERM_TOK = dict(zip(TERMS, TOKS))

FIRST = """PROGRAM : program
CLASS-DECL-LIST : ε,class
CLASS-DECL : class
CLASS-BODY : {
DECLS-OPT : ε,declarations
DECLS : declarations
METHOD-DECL-LIST : ε,method
FIELD-DECL-LIST-DECLS : ε,id,int,string
FIELD-DECL : id,int,string
FIELD-DECL-AUX1 : =,,,ε
FIELD-DECL-AUX2 : ,,ε
TYPE : id,int,string
TYPE-AUX : id,int,string
BRACKETS-OPT : [],ε
METHOD-DECL : method
METHOD-RETURN-TYPE : void,id,int,string
FORMAL-PARAMS-LIST : val,id,int,string
VAL-OPT : val,ε
FORMAL-PARAMS-LIST-AUX : ;,ε
ID-LIST-COMMA : ,,ε
FORMAL-PARAMS-LIST-OPT : ε,val,id,int,string
VAR-DECL-ID : id
VAR-INIT : {,@,(,+,-,not,num,str,id
ARRAY-INIT : {
VAR-INIT-LIST-COMMA : ,,ε
ARRAY-CREATION-EXPR : @
ARRAY-DIM-DECL : [
ARRAY-DIM-DECL-LIST : ε,[
BLOCK : declarations,{
STMT-LIST : {
STMT-LIST-SEMICOLON : ;,ε
STMT : id,return,if,while,for,switch,print,read
VARIABLE-START-STMT : :=,(
ASSIGN-STMT : :=
METHOD-CALL-STMT : (
ACTUAL-PARAMS-LIST : ε,(,+,-,not,num,str,id
EXPRESSION-LIST-COMMA : ,,ε
RETURN-STMT : return
EXPRESSION-OPT : ε,(,+,-,not,num,str,id
IF-STMT : if
ELSE-PART : else,ε
IF-STMT-AUX : if,{
FOR-STMT : for
FOR-INIT-EXPR : id
STEP-OPT : step,ε
WHILE-STMT : while
SWITCH-STMT : switch
CASE : case
CASE-LIST : default,ε,case
PRINT-STMT : print
READ-STMT : read
EXPRESSION : (,+,-,not,num,str,id
REL-EXPR : (,+,-,not,num,str,id
REL-EXPR-AUX : ε,<,<=,==,!=,>=,>
ADD-EXPR : (,+,-,not,num,str,id
ADD-EXPR-AUX : ε,+,-,||
MULT-EXPR : (,+,-,not,num,str,id
MULT-EXPR-AUX : ε,*,/,&&,%
UNARY-EXPR : (,+,-,not,num,str,id
METHOD-CALL-OPT : ε,(
REL-OP : <,<=,==,!=,>=,>
UNARY-OP : +,-,not
ADD-OP : +,-,||
MULT-OP : *,/,&&,%
UNSIG-LIT : num,str
VARIABLE : id
VARIABLE-AUX : .,ε,[""".splitlines()

FIRST_DECL = ""

FIRST_STRING = ""
for l in FIRST:
    l = l.replace(" ", "")
    l = l.split(":", 1)
    variable = NON_TERMS_DICT[l[0]]
    terms = []
    for t in l[1].replace(',,,', ',comma,').replace(',,', 'comma,').split(','):
        if t != '':
            terms.append(TERM_TOK[t])
    terms = ','.join(terms)
    FIRST_STRING += "{ " + variable + ", {" + terms +"} },\n"

print(FIRST_STRING)

FOLLOW = """PROGRAM : $
CLASS-DECL-LIST : $
CLASS-DECL : class,$
CLASS-BODY : class,$
DECLS-OPT : method,},{
DECLS : method,},{
METHOD-DECL-LIST : }
FIELD-DECL-LIST-DECLS : enddeclarations
FIELD-DECL : ;
FIELD-DECL-AUX1 : ;
FIELD-DECL-AUX2 : ;
TYPE : id,[
TYPE-AUX : [],id,[
BRACKETS-OPT : id,=,,,;,[
METHOD-DECL : method,}
METHOD-RETURN-TYPE : id
FORMAL-PARAMS-LIST : )
FORMAL-PARAMS-LIST-AUX : )
ID-LIST-COMMA : ;,)
FORMAL-PARAMS-LIST-OPT : )
VAR-DECL-ID : =,,,;
VAR-INIT : ,,;,}
ARRAY-INIT : ,,;,}
VAR-INIT-LIST-COMMA : }
ARRAY-CREATION-EXPR : ,,;,}
ARRAY-DIM-DECL : [,,,;,}
ARRAY-DIM-DECL-LIST : ,,;,}
BLOCK : method,}
STMT-LIST : method,},else,;,default,case
STMT-LIST-SEMICOLON : }
STMT : ;,}
VARIABLE-START-STMT : ;,}
ASSIGN-STMT : ;,},to
METHOD-CALL-STMT : ;,},*,/,&&,%,+,-,||,<,<=,==,!=,>=,>,,,],),{,step,to
ACTUAL-PARAMS-LIST : )
EXPRESSION-LIST-COMMA : ),]
RETURN-STMT : ;,}
EXPRESSION-OPT : ;,}
IF-STMT : ;,}
ELSE-PART : ;,}
IF-STMT-AUX : ;,}
FOR-STMT : ;,}
FOR-INIT-EXPR : to
STEP-OPT : {
WHILE-STMT : ;,}
SWITCH-STMT : ;,}
CASE : default,case,}
CASE-LIST : }
PRINT-STMT : ;,}
READ-STMT : ;,}
EXPRESSION : ,,;,],},),{,step,to
REL-EXPR : ,,;,],},),{,step,to
REL-EXPR-AUX : ,,;,],},),{,step,to
ADD-EXPR : <,<=,==,!=,>=,>,,,;,],},),{,step,to
ADD-EXPR-AUX : <,<=,==,!=,>=,>,,,;,],},),{,step,to
MULT-EXPR : +,-,||,<,<=,==,!=,>=,>,,,;,],},),{,step,to
MULT-EXPR-AUX : +,-,||,<,<=,==,!=,>=,>,,,;,],},),{,step,to
UNARY-EXPR : *,/,&&,%,+,-,||,<,<=,==,!=,>=,>,,,;,],},),{,step,to
METHOD-CALL-OPT : *,/,&&,%,+,-,||,<,<=,==,!=,>=,>,,,;,],},),{,step,to
REL-OP : (,+,-,not,num,str,id
UNARY-OP : (,+,-,not,num,str,id
ADD-OP : (,+,-,not,num,str,id
MULT-OP : (,+,-,not,num,str,id
UNSIG-LIT : *,/,&&,%,+,-,||,<,<=,==,!=,>=,>,,,;,],},),{,step,to
VARIABLE : :=,(,*,/,&&,%,+,-,||,<,<=,==,!=,>=,>,,,;,],},),{,step,to
VARIABLE-AUX : :=,(,*,/,&&,%,+,-,||,<,<=,==,!=,>=,>,,,;,],},),{,step,to""".splitlines()

FOLLOW_DECL = ""

FOLLOW_STRING = ""
for l in FOLLOW:
    l = l.replace(" ", "")
    l = l.split(":", 1)
    variable = NON_TERMS_DICT[l[0]]
    terms = []
    for t in l[1].replace(',,,', ',comma,').replace(',,', 'comma,').split(','):
        if t != '':
            terms.append(TERM_TOK[t])
    terms = ','.join(terms)
    FOLLOW_STRING += "{ " + variable + ", {" + terms +"} },\n"
print(FOLLOW_STRING)

PRODUCTIONS = """0  PROGRAM ➝ program id ; CLASS-DECL CLASS-DECL-LIST
1  CLASS-DECL-LIST ➝ CLASS-DECL CLASS-DECL-LIST
2  CLASS-DECL-LIST ➝ ε
3  CLASS-DECL ➝ class id CLASS-BODY
4  CLASS-BODY ➝ { DECLS-OPT METHOD-DECL-LIST }
5  DECLS-OPT ➝ DECLS
6  DECLS-OPT ➝ ε
7  DECLS ➝ declarations FIELD-DECL-LIST-DECLS enddeclarations
8  METHOD-DECL-LIST ➝ METHOD-DECL METHOD-DECL-LIST
9  METHOD-DECL-LIST ➝ ε
10  FIELD-DECL-LIST-DECLS ➝ FIELD-DECL ; FIELD-DECL-LIST-DECLS
11  FIELD-DECL-LIST-DECLS ➝ ε
12  FIELD-DECL ➝ TYPE VAR-DECL-ID FIELD-DECL-AUX1
13  FIELD-DECL-AUX1 ➝ FIELD-DECL-AUX2
14  FIELD-DECL-AUX1 ➝ = VAR-INIT FIELD-DECL-AUX2
15  FIELD-DECL-AUX2 ➝ , VAR-DECL-ID FIELD-DECL-AUX1
16  FIELD-DECL-AUX2 ➝ ε
17  TYPE ➝ TYPE-AUX BRACKETS-OPT
18  TYPE-AUX ➝ id
19  TYPE-AUX ➝ int
20  TYPE-AUX ➝ string
21  BRACKETS-OPT ➝ [] BRACKETS-OPT
22  BRACKETS-OPT ➝ ε
23  METHOD-DECL ➝ method METHOD-RETURN-TYPE id ( FORMAL-PARAMS-LIST-OPT ) BLOCK
24  METHOD-RETURN-TYPE ➝ void
25  METHOD-RETURN-TYPE ➝ TYPE
26  FORMAL-PARAMS-LIST ➝ val TYPE id ID-LIST-COMMA FORMAL-PARAMS-LIST-AUX
27  FORMAL-PARAMS-LIST ➝ TYPE id ID-LIST-COMMA FORMAL-PARAMS-LIST-AUX
28  FORMAL-PARAMS-LIST-AUX ➝ ; FORMAL-PARAMS-LIST
29  FORMAL-PARAMS-LIST-AUX ➝ ε
30  ID-LIST-COMMA ➝ , id ID-LIST-COMMA
31  ID-LIST-COMMA ➝ ε
32  FORMAL-PARAMS-LIST-OPT ➝ FORMAL-PARAMS-LIST
33  FORMAL-PARAMS-LIST-OPT ➝ ε
34  VAR-DECL-ID ➝ id BRACKETS-OPT
35  VAR-INIT ➝ EXPRESSION
36  VAR-INIT ➝ ARRAY-INIT
37  VAR-INIT ➝ ARRAY-CREATION-EXPR
38  ARRAY-INIT ➝ { VAR-INIT VAR-INIT-LIST-COMMA }
39  VAR-INIT-LIST-COMMA ➝ , VAR-INIT VAR-INIT-LIST-COMMA
40  VAR-INIT-LIST-COMMA ➝ ε
41  ARRAY-CREATION-EXPR ➝ @ TYPE ARRAY-DIM-DECL ARRAY-DIM-DECL-LIST
42  ARRAY-DIM-DECL ➝ [ EXPRESSION ]
43  ARRAY-DIM-DECL-LIST ➝ ARRAY-DIM-DECL ARRAY-DIM-DECL-LIST
44  ARRAY-DIM-DECL-LIST ➝ ε
45  BLOCK ➝ DECLS-OPT STMT-LIST
46  STMT-LIST ➝ { STMT STMT-LIST-SEMICOLON }
47  STMT-LIST-SEMICOLON ➝ ; STMT STMT-LIST-SEMICOLON
48  STMT-LIST-SEMICOLON ➝ ε
49  STMT ➝ VARIABLE VARIABLE-START-STMT
50  STMT ➝ RETURN-STMT
51  STMT ➝ IF-STMT
52  STMT ➝ WHILE-STMT
53  STMT ➝ FOR-STMT
54  STMT ➝ SWITCH-STMT
55  STMT ➝ PRINT-STMT
56  STMT ➝ READ-STMT
57  VARIABLE-START-STMT ➝ ASSIGN-STMT
58  VARIABLE-START-STMT ➝ METHOD-CALL-STMT
59  ASSIGN-STMT ➝ := EXPRESSION
60  METHOD-CALL-STMT ➝ ( ACTUAL-PARAMS-LIST )
61  ACTUAL-PARAMS-LIST ➝ EXPRESSION EXPRESSION-LIST-COMMA
62  ACTUAL-PARAMS-LIST ➝ ε
63  EXPRESSION-LIST-COMMA ➝ , EXPRESSION EXPRESSION-LIST-COMMA
64  EXPRESSION-LIST-COMMA ➝ ε
65  RETURN-STMT ➝ return EXPRESSION-OPT
66  EXPRESSION-OPT ➝ EXPRESSION
67  EXPRESSION-OPT ➝ ε
68  IF-STMT ➝ if EXPRESSION STMT-LIST ELSE-PART
69  ELSE-PART ➝ else IF-STMT-AUX
70  ELSE-PART ➝ ε
71  IF-STMT-AUX ➝ IF-STMT
72  IF-STMT-AUX ➝ STMT-LIST
73  FOR-STMT ➝ for FOR-INIT-EXPR to EXPRESSION STEP-OPT STMT-LIST
74  FOR-INIT-EXPR ➝ id ASSIGN-STMT
75  STEP-OPT ➝ step EXPRESSION
76  STEP-OPT ➝ ε
77  WHILE-STMT ➝ while EXPRESSION STMT-LIST
78  SWITCH-STMT ➝ switch EXPRESSION { CASE CASE-LIST }
79  CASE ➝ case EXPRESSION STMT-LIST
80  CASE-LIST ➝ CASE CASE-LIST
81  CASE-LIST ➝ default STMT-LIST
82  CASE-LIST ➝ ε
83  PRINT-STMT ➝ print EXPRESSION
84  READ-STMT ➝ read id
85  EXPRESSION ➝ REL-EXPR
86  REL-EXPR ➝ ADD-EXPR REL-EXPR-AUX
87  REL-EXPR-AUX ➝ REL-OP ADD-EXPR
88  REL-EXPR-AUX ➝ ε
89  ADD-EXPR ➝ MULT-EXPR ADD-EXPR-AUX
90  ADD-EXPR-AUX ➝ ADD-OP MULT-EXPR ADD-EXPR-AUX
91  ADD-EXPR-AUX ➝ ε
92  MULT-EXPR ➝ UNARY-EXPR MULT-EXPR-AUX
93  MULT-EXPR-AUX ➝ MULT-OP UNARY-EXPR MULT-EXPR-AUX
94  MULT-EXPR-AUX ➝ ε
95  UNARY-EXPR ➝ UNARY-OP UNARY-EXPR
96  UNARY-EXPR ➝ UNSIG-LIT
97  UNARY-EXPR ➝ VARIABLE METHOD-CALL-OPT
98  UNARY-EXPR ➝ ( EXPRESSION )
99  METHOD-CALL-OPT ➝ METHOD-CALL-STMT
100  METHOD-CALL-OPT ➝ ε
101  REL-OP ➝ <
102  REL-OP ➝ <=
103  REL-OP ➝ ==
104  REL-OP ➝ !=
105  REL-OP ➝ >=
106  REL-OP ➝ >
107  UNARY-OP ➝ +
108  UNARY-OP ➝ -
109  UNARY-OP ➝ not
110  ADD-OP ➝ +
111  ADD-OP ➝ -
112  ADD-OP ➝ ||
113  MULT-OP ➝ *
114  MULT-OP ➝ /
115  MULT-OP ➝ &&
116  MULT-OP ➝ %
117  UNSIG-LIT ➝ num
118  UNSIG-LIT ➝ str
119  VARIABLE ➝ id VARIABLE-AUX
120  VARIABLE-AUX ➝ . id VARIABLE-AUX
121  VARIABLE-AUX ➝ ε
122  VARIABLE-AUX ➝ [ EXPRESSION EXPRESSION-LIST-COMMA ] VARIABLE-AUX
""".splitlines()

prods = ""
for p in PRODUCTIONS:
    p = p.split("  ", 1)
    k = p[0]
    r = p[1].split(" ➝ ")
    r[0] = r[0].replace(" ", '')
    var = NON_TERMS_DICT[r[0]]
    right = r[1].split(' ')
    prod = []
    for s in right:
        if s == ',':
            s = 'comma'
        if s in TERM_TOK:
            if TERM_TOK[s] != '':
                prod.append(TERM_TOK[s])
        else:
            prod.append(NON_TERMS_DICT[s])
    prod = ",".join(prod)
    if prod == "''":
        prod = ""
    prods += "{ " + str(k) + ", { " + var + ", {" + prod + "}" + " }" + " },\n"
print(prods)

TABLE = """PROGRAM | 0 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
CLASS-DECL-LIST | . . . . 1 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 2 
CLASS-DECL | . . . . 3 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
CLASS-BODY | . . . . . 4 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
DECLS-OPT | . . . . . 6 6 5 . . . . . . 6 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
DECLS | . . . . . . . 7 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
METHOD-DECL-LIST | . . . . . . 9 . . . . . . . 8 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
FIELD-DECL-LIST-DECLS | . 10 . . . . . . 11 . . 10 10 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
FIELD-DECL | . 12 . . . . . . . . . 12 12 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
FIELD-DECL-AUX1 | . . 13 . . . . . . 14 13 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
FIELD-DECL-AUX2 | . . 16 . . . . . . . 15 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
TYPE | . 17 . . . . . . . . . 17 17 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
TYPE-AUX | . 18 . . . . . . . . . 19 20 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
BRACKETS-OPT | . 22 22 . . . . . . 22 22 . . 21 . . . . . . 22 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
METHOD-DECL | . . . . . . . . . . . . . . 23 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
METHOD-RETURN-TYPE | . 25 . . . . . . . . . 25 25 . . . . 24 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
FORMAL-PARAMS-LIST | . 27 . . . . . . . . . 27 27 . . . . . 26 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
FORMAL-PARAMS-LIST-AUX | . . 28 . . . . . . . . . . . . . 29 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
ID-LIST-COMMA | . . 31 . . . . . . . 30 . . . . . 31 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
FORMAL-PARAMS-LIST-OPT | . 32 . . . . . . . . . 32 32 . . . 33 . 32 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
VAR-DECL-ID | . 34 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
VAR-INIT | . 35 . . . 36 . . . . . . . . . 35 . . . 37 . . . . . . . . . . . . . . . . . . . . . 35 35 35 . . . . . 35 35 . . 
ARRAY-INIT | . . . . . 38 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
VAR-INIT-LIST-COMMA | . . . . . . 40 . . . 39 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
ARRAY-CREATION-EXPR | . . . . . . . . . . . . . . . . . . . 41 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
ARRAY-DIM-DECL | . . . . . . . . . . . . . . . . . . . . 42 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
ARRAY-DIM-DECL-LIST | . . 44 . . . 44 . . . 44 . . . . . . . . . 43 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
BLOCK | . . . . . 45 . 45 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
STMT-LIST | . . . . . 46 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
STMT-LIST-SEMICOLON | . . 47 . . . 48 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
STMT | . 49 . . . . . . . . . . . . . . . . . . . . . 50 51 . 53 . . 52 54 . . 55 56 . . . . . . . . . . . . . . . . . . 
VARIABLE-START-STMT | . . . . . . . . . . . . . . . 58 . . . . . . 57 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
ASSIGN-STMT | . . . . . . . . . . . . . . . . . . . . . . 59 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
METHOD-CALL-STMT | . . . . . . . . . . . . . . . 60 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
ACTUAL-PARAMS-LIST | . 61 . . . . . . . . . . . . . 61 62 . . . . . . . . . . . . . . . . . . . . . . . . 61 61 61 . . . . . 61 61 . . 
EXPRESSION-LIST-COMMA | . . . . . . . . . . 63 . . . . . 64 . . . . 64 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
RETURN-STMT | . . . . . . . . . . . . . . . . . . . . . . . 65 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
EXPRESSION-OPT | . 66 67 . . . 67 . . . . . . . . 66 . . . . . . . . . . . . . . . . . . . . . . . . . 66 66 66 . . . . . 66 66 . . 
IF-STMT | . . . . . . . . . . . . . . . . . . . . . . . . 68 . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
ELSE-PART | . . 70 . . . 70 . . . . . . . . . . . . . . . . . . 69 . . . . . . . . . . . . . . . . . . . . . . . . . . . 
IF-STMT-AUX | . . . . . 72 . . . . . . . . . . . . . . . . . . 71 . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
FOR-STMT | . . . . . . . . . . . . . . . . . . . . . . . . . . 73 . . . . . . . . . . . . . . . . . . . . . . . . . . 
FOR-INIT-EXPR | . 74 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
STEP-OPT | . . . . . 76 . . . . . . . . . . . . . . . . . . . . . . 75 . . . . . . . . . . . . . . . . . . . . . . . . 
WHILE-STMT | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 77 . . . . . . . . . . . . . . . . . . . . . . . 
SWITCH-STMT | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 78 . . . . . . . . . . . . . . . . . . . . . . 
CASE | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 79 . . . . . . . . . . . . . . . . . . . . . 
CASE-LIST | . . . . . . 82 . . . . . . . . . . . . . . . . . . . . . . . . 80 81 . . . . . . . . . . . . . . . . . . . . 
PRINT-STMT | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 83 . . . . . . . . . . . . . . . . . . . 
READ-STMT | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 84 . . . . . . . . . . . . . . . . . . 
EXPRESSION | . 85 . . . . . . . . . . . . . 85 . . . . . . . . . . . . . . . . . . . . . . . . . 85 85 85 . . . . . 85 85 . . 
REL-EXPR | . 86 . . . . . . . . . . . . . 86 . . . . . . . . . . . . . . . . . . . . . . . . . 86 86 86 . . . . . 86 86 . . 
REL-EXPR-AUX | . . 88 . . 88 88 . . . 88 . . . . . 88 . . . . 88 . . . . . 88 88 . . . . . . 87 87 87 87 87 87 . . . . . . . . . . . . 
ADD-EXPR | . 89 . . . . . . . . . . . . . 89 . . . . . . . . . . . . . . . . . . . . . . . . . 89 89 89 . . . . . 89 89 . . 
ADD-EXPR-AUX | . . 91 . . 91 91 . . . 91 . . . . . 91 . . . . 91 . . . . . 91 91 . . . . . . 91 91 91 91 91 91 90 90 . 90 . . . . . . . . 
MULT-EXPR | . 92 . . . . . . . . . . . . . 92 . . . . . . . . . . . . . . . . . . . . . . . . . 92 92 92 . . . . . 92 92 . . 
MULT-EXPR-AUX | . . 94 . . 94 94 . . . 94 . . . . . 94 . . . . 94 . . . . . 94 94 . . . . . . 94 94 94 94 94 94 94 94 . 94 93 93 93 93 . . . . 
UNARY-EXPR | . 97 . . . . . . . . . . . . . 98 . . . . . . . . . . . . . . . . . . . . . . . . . 95 95 95 . . . . . 96 96 . . 
METHOD-CALL-OPT | . . 100 . . 100 100 . . . 100 . . . . 99 100 . . . . 100 . . . . . 100 100 . . . . . . 100 100 100 100 100 100 100 100 . 100 100 100 100 100 . . . . 
REL-OP | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 101 102 103 104 105 106 . . . . . . . . . . . . 
UNARY-OP | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 107 108 109 . . . . . . . . . 
ADD-OP | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 110 111 . 112 . . . . . . . . 
MULT-OP | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 113 114 115 116 . . . . 
UNSIG-LIT | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 117 118 . . 
VARIABLE | . 119 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
VARIABLE-AUX | . . 121 . . 121 121 . . . 121 . . . . 121 121 . . . 122 121 121 . . . . 121 121 . . . . . . 121 121 121 121 121 121 121 121 . 121 121 121 121 121 . . 120 . """.splitlines()

table = ""
for t in TABLE:
    t = t.split(" | ", 1)
    k = t[0].replace(" ", '')
    var = NON_TERMS_DICT[k]
    table += "{ " + var + ", { " 
    right = t[1].split(' ')
    tab = []
    for i in range(0, len(TOKS)):
        s = right[i].replace(" ", '')
        if s != '.' and TOKS[i] != '':
            tab.append("{ " + TOKS[i] + ", " + s + " }")
    tab = ",".join(tab)
    if tab == "''":
        tab = ""
    table += tab + " }" + " },\n"
print(table)