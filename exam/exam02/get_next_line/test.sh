gcc -Wall -Werror -Wextra get_next_line.c main.c
./a.out < get_next_line.c > yours_.res
cat -e yours_.res > yours.res
cat -e < main.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res get_next_line
