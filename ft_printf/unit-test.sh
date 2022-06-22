#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette ./*.c ./*.h
echo -e "\033[32;1m"printfTester"\033[m"
read $a
git clone https://github.com/Tripouille/printfTester.git
cd printfTester/
make m
cd ..
rm -rf printfTester/
echo -e "\033[32;1m"DONE"\033[m"
echo -e "\033[32;1m"ft_printf_tester"\033[m"
read $a
git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester/
sh test m
cd ..
rm -rf ft_printf_tester/
echo -e "\033[32;1m"DONE"\033[m"

