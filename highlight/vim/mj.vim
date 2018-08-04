" Vim syntax file
" Language: Mini-Java
" Maintainer: Vitor Greati
" Latest Revision: 2018-08-04

if exists("b:current_syntax")
  finish
endif

" Keywords
syn keyword mjKeywords program class if else while for return when not print read break method declarations enddeclarations val switch case not
syn keyword mjTypes int string void
syn keyword mjTodo contained TODO FIXME NOTE

" Matches

" Integer with - + or nothing in front
syn match mjIdentifier '[a-zA-Z][a-zA-Z0-9\_]*'
syn match mjNumber '\d\+'
syn match mjComment "#.*$" contains=mjTodo
syn match mjError '[0-9][a-zA-Z\_]+' " improve regex!

" Regions

syntax region mjString start=/\v"/ skip=/\v\\./ end=/\v"/

let b:current_syntax = "mj"
hi def link mjTodo           Todo
hi def link mjComment        Comment
hi def link mjKeywords       Statement
hi def link mjTypes          Type
hi def link mjString         String
hi def link mjNumber         Constant
hi def link mjIdentifier     Identifier
hi def link mjError          Error





