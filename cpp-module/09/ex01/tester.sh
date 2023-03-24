###############
RED=$'\e[1;31m'
GREEN=$'\e[1;32m'
YELLOW=$'\e[1;33m'
BLUE=$'\e[1;34m'
CLEAR=$'\033[0m'
###############

echo -e "${GREEN}\n✅ Success Cases ✅${CLEAR}\n"

echo -e './RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"'
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo -e '\n./RPN "7 7 * 7 -"'
./RPN "7 7 * 7 -"

echo -e '\n./RPN "1 2 * 2 / 2 * 2 4 - +"'
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo -e "${YELLOW}\n💥 Error Cases 💥${CLEAR}"

echo -e '\n./RPN "(1 + 1)"'
./RPN "(1 + 1)"