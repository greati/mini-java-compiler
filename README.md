# mjc

A compiler for the Mini-Java programming language.

## Mini-Java language

Take a look at `documentation/mjmanual.pdf` to read 
the manual and more details about the Mini-Java programming language. 

## Mini-Java Compiler (mjc)

`mjc` is the compiler implemented for the Mini-Java programming
language following the specifications present in the manual.

### Play with the mjlexer

`mjlexer` is the lexical analyzer used by `mjc` to recognize the
Mini-Java tokens. It was generated by the `lex` tool. 
You can test `mjlexer` by following the steps below:

1. install `flex`, to gather the `lex` tool
2. run `$ make lexer`
3. run either `echo "your code goes here" | ./bin/mjlexer` or
    `./bin/mjlexer < your-program.mj`

### Play with the LL(1) parsers

LL(1) parsers apply left derivations from left to right 
looking at most one token ahead in order to select the
proper production. `mjc` can be used with two LL(1) parsers,
a recursive and a non-recursive ones. You can run
each of those parsers by following these steps:

1. run `$ make ll1parser`
2. run `$ ./bin/mjcll1 [R | N] < your-program.mj`, where
`R` indicates to use the recursive parser, and `N`, the non-recursive.

### Play with the LALR parser

Yacc was used to generate a bottom-up parser for the Mini-Java Language.
You can run it by following these steps:

1. run `$ make lalrparserast
2. run `$ ./bin/mjclalr < your-program.mj`

This will print an Abstract Syntax Tree of the program.

