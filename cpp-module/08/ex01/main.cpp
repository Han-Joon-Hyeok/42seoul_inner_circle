#include <ctime>
#include <deque>
#include <iostream>

#include "Span.hpp"

#define MAX_VALUE 50000

int main(void) {
  srand(time(NULL));

  // Subject sample test case
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.shortestSpan();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  // // Error: MaxSizeException
  // try {
  //   Span sp = Span(5);
  //   sp.addNumber(6);
  //   sp.addNumber(3);
  //   sp.addNumber(17);
  //   sp.addNumber(9);
  //   sp.addNumber(11);
  //   sp.addNumber(11);   // Exception: can't add more elements.
  // } catch (std::exception& e) {
  //   std::cout << e.what() << std::endl;
  // }

  // // Span class with 50,000 numbers
  // try {
  //   Span sp(MAX_VALUE);
  //   for (int idx = 0; idx < MAX_VALUE; idx += 1) {
  //     sp.addNumber(rand());
  //   }
  //   std::cout << sp.shortestSpan() << std::endl;
  //   std::cout << sp.longestSpan() << std::endl;
  // } catch (const std::exception& e) {
  //   std::cerr << e.what() << '\n';
  // }

  // addNumbers using range of iterators
  // try {
  //   std::deque<int> v;

  //   for (int idx = 0; idx < MAX_VALUE; idx += 1) {
  //     v.push_back(idx);
  //   }

  //   Span sp(MAX_VALUE);
  //   sp.addNumbers(v.begin(), v.end());

  //   std::cout << sp.shortestSpan() << std::endl;
  //   std::cout << sp.longestSpan() << std::endl;
  // } catch (std::exception& e) {
  //   std::cerr << e.what() << '\n';
  // }
}
