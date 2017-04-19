yacc -d sli8.y
lex sli8.l
gcc -w lex.yy.c y.tab.c 
./a.out test_pgm5.txt

