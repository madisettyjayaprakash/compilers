yacc -d sli2new.y
lex sli2new.l
gcc -w lex.yy.c y.tab.c
./a.out test.txt
