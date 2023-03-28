###############
RED=$'\e[1;31m'
GREEN=$'\e[1;32m'
YELLOW=$'\e[1;33m'
BLUE=$'\e[1;34m'
CLEAR=$'\033[0m'
###############

echo -e "${GREEN}\n✅ Success Cases ✅${CLEAR}\n"

echo -e ${BLUE}'./PmergeMe 3 5 9 7 4'${CLEAR}
./PmergeMe 3 5 9 7 4

echo -e ${BLUE}'./PmergeMe 10 9 8 7 6 5 4 3 2 1 0'${CLEAR}
./PmergeMe 10 9 8 7 6 5 4 3 2 1 0

echo -e ${BLUE}"./PmergeMe `jot -r 100 1 1000 | tr '\n' ' '`"${CLEAR}
./PmergeMe `jot -r 100 1 1000 | tr '\n' ' '`

# echo -e ${BLUE}"./PmergeMe `jot -r 500 1 5000 | tr '\n' ' '`"${CLEAR}
# ./PmergeMe `jot -r 500 1 5000 | tr '\n' ' '`

# echo -e ${BLUE}"./PmergeMe `jot -r 1000 1 5000 | tr '\n' ' '`"${CLEAR}
# ./PmergeMe `jot -r 1000 1 5000 | tr '\n' ' '`

# echo -e ${BLUE}"./PmergeMe `jot -r 3000 1 10000 | tr '\n' ' '`"${CLEAR}
# ./PmergeMe `jot -r 3000 1 10000 | tr '\n' ' '`

# echo -e ${BLUE}"./PmergeMe `jot -r 10000 1 40000 | tr '\n' ' '`"${CLEAR}
# ./PmergeMe `jot -r 10000 1 40000 | tr '\n' ' '`

echo -e "${YELLOW}\n💥 Error Cases 💥${CLEAR}"

echo -e ${BLUE}'./PmergeMe'${CLEAR}
./PmergeMe

echo -e ${BLUE}'./PmergeMe -1 4'${CLEAR}
./PmergeMe -1 4

echo -e ""
