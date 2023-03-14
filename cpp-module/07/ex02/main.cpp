#include <iostream>

#include "Array.hpp"

#define ARRAY_SIZE 5

int main(void) {
  // Error case: when n is negative value
  std::cout << std::string(50, '=') << std::endl;

  try {
    Array<int> int_arr(-1);   // invalid argument
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Error case: when index is out of range
  try {
    Array<std::string> str_arr(ARRAY_SIZE);
    std::cout << str_arr[ARRAY_SIZE] << std::endl;   // index is out of range
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Success case: subscript operator
  try {
    Array<std::string> str_arr(ARRAY_SIZE);
    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      str_arr[idx] = "HELLO idx: " + std::to_string(idx);
    }
    std::cout << str_arr[0] << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Success case: copy constructor
  try {
    Array<std::string> str_arr(ARRAY_SIZE);

    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      str_arr[idx] = "HELLO idx: " + std::to_string(idx);
    }

    Array<std::string> copy_arr(str_arr);

    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      std::cout << copy_arr[idx] << std::endl;
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Success case: copy assignment operator
  try {
    Array<std::string> str_arr(ARRAY_SIZE);
    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      str_arr[idx] = "HELLO idx: " + std::to_string(idx);
    }

    Array<std::string> copy_arr;

    copy_arr = str_arr;
    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      std::cout << copy_arr[idx] << std::endl;
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  {
    const Array<int> arr(5);
    // arr[0] = 1; // Can't modify const object
  }
  {
    Array<int> arr(5);
    std::cout << arr[0] << std::endl;
    arr[0] = 1; // Can modify non-const object
    std::cout << arr[0] << std::endl;
  }
}

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
