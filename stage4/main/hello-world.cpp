#include "lib/hello-time.h"
#include "main/hello-greet.h"
#include <ctime>
#include <string>
#include <iostream>

int main(int argc, char **argv) {
  std::string who = "wolrd";
  if (argc > 1) {
    who = argv[1];
  }
  std::cout << get_greet(who) << std::endl;
  print_localtime();
  return 0;
}