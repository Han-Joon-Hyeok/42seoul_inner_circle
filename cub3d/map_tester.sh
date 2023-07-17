# echo "File extension test"
# echo "TEST1"
# ./cub3D nocub
# echo "TEST2"
# ./cub3D yes.cub
# echo "TEST3"
# ./cub3D no.cub3D
# echo "TEST4"
# ./cub3D no.42seoul

RED=$'\e[1;31m'
GREEN=$'\e[1;32m'
BLUE=$'\e[1;34m'
CLEAR=$'\033[0m'

echo "MAP test Start"
echo "TEST1 : valid"
./cub3D ./custom_maps/test_W1.cub
echo "TEST2 : valid"
./cub3D ./custom_maps/test_W2.cub
echo "TEST3 : valid"
./cub3D ./custom_maps/test_W3.cub
echo "TEST4 : valid"
./cub3D ./custom_maps/test_W4.cub
echo "TEST5 : valid"
./cub3D ./custom_maps/test_W5.cub
echo "TEST6 : valid"
./cub3D ./custom_maps/test_W6.cub
echo "TEST7 : valid"
./cub3D ./custom_maps/test_W7.cub
echo "TEST8 : valid"
./cub3D ./custom_maps/test_W8.cub
echo "TEST9 : valid"
./cub3D ./custom_maps/test_W9.cub
echo "TEST10 : valid"
./cub3D ./custom_maps/test_W10.cub
# echo "TEST8 : 2 players"
# ./cub3D ./custom_maps/test_W8.cub
# echo "TEST8 : 2 players"
# ./cub3D ./custom_maps/test_W8.cub
# echo "TEST8 : 2 players"
# ./cub3D ./custom_maps/test_W8.cub
# echo "TEST8 : 2 players"
# ./cub3D ./custom_maps/test_W8.cub
# echo "TEST8 : 2 players"
# ./cub3D ./custom_maps/test_W8.cub
# echo "TEST8 : 2 players"
# ./cub3D ./custom_maps/test_W8.cub
# echo "TEST8 : 2 players"
# ./cub3D ./custom_maps/test_W8.cub

# echo "TEST7"
# ./cub3D cub3D_map_tester/maps/test_W7.cub
