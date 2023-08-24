# The AwA(AwA WaW Awa) Language

## What is awa-lang
AwA-lang is a "LaTeX-like" programming language.

## Grammar
### Code blocks
1.`{awa code}`

2.`(awa code)` Ignore output

### call functions
`\fn_name{arg1}{arg2}{arg3} ......`

### varibles
`$var_name$`

### define function
`{\def{name} awa-code}`

### define var
`\set{var_name}{value}`

### if
`{\if{\eq{a}{b}} awa-code if true}`

//if(argc==0) 有没有一种可能之心argc=1（
## Example:
`({\def{print} $1$})(\set{hello}{llo})he{\if{\eq{$hello$}{llo}} llo}\print{world \input }`

## Usage:
`./awa example.txt`

## Build: 
Change some arguments first.

`make`

`make clean` after use