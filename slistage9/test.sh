yacc -d sli9n.y
lex sli9.l
gcc -w lex.yy.c y.tab.c 
./a.out test_pgm6.txt
