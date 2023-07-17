###############
RED=$'\e[1;31m'
GREEN=$'\e[1;32m'
YELLOW=$'\e[1;33m'
BLUE=$'\e[1;34m'
CLEAR=$'\033[0m'
###############

echo -e "${BLUE}\n📖 File extension test 📖${CLEAR}\n"

echo -e "${YELLOW}🔮 INVALID TEST1: invalid extension (nocub)${CLEAR}\n"
OUTPUT=$(./cub3D nocub)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}$OUTPUT${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST2: invalid extension (no.cub3D)${CLEAR}\n"
OUTPUT=$(./cub3D no.cub3D)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}$OUTPUT${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST3: invalid extension (no.42Seoul)${CLEAR}\n"
OUTPUT=$(./cub3D no.42Seoul)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}$OUTPUT${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST4: not existing file (not_existed.cub)${CLEAR}\n"
OUTPUT=$(./cub3D not_existed.cub)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}$OUTPUT${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST5: image wall file extension(*.xpm)${CLEAR}\n"
OUTPUT=$(./cub3D map/map_info_invalid6.cub)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}$OUTPUT${CLEAR}\n"
fi


echo -e "${BLUE}\n📖 Map info test 📖${CLEAR}\n"
echo -e "${YELLOW}🔮 VALID TEST1: valid map info${CLEAR}\n"
OUTPUT=$(./cub3D map/map_info_valid.cub)
if [ $? -eq 0 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}$OUTPUT${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 VALID TEST2: valid rgb value(00,    153,15)${CLEAR}\n"
OUTPUT=$(./cub3D map/map_info_valid2.cub)
if [ $? -eq 0 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}KO${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST1: invalid wall info(NOO)${CLEAR}\n"
OUTPUT=$(./cub3D map/map_info_invalid1.cub)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}KO${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST2: invalid rgb value(00,,,,153,15)${CLEAR}\n"
OUTPUT=$(./cub3D map/map_info_invalid2.cub)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}KO${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST3: not existed wall file(NOT_EXISTED.xpm)${CLEAR}\n"
OUTPUT=$(./cub3D map/map_info_invalid3.cub)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}KO${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST4: map content has to be last${CLEAR}\n"
OUTPUT=$(./cub3D map/map_info_invalid4.cub)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}KO${CLEAR}\n"
fi

echo -e "${YELLOW}🔮 INVALID TEST5: invalid rgb value(00,    1 53,15)${CLEAR}\n"
OUTPUT=$(./cub3D map/map_info_invalid5.cub)
if [ $? -eq 1 ]
then
	echo -e "\n${GREEN}OK${CLEAR}\n"
else
	echo -e "\n${RED}$OUTPUT${CLEAR}\n"
fi
