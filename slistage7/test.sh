yacc -d sli2new.y
lex sli2new.l
gcc -w lex.yy.c y.tab.c
./a.out test.txt
lex label.l
gcc lex.yy.c
./a.out l1.txt
cd /home/jayaprakash21/xsm_expl
./xsm -l library.lib -e tar.xsm

