#include <iostream>
#include <string>
#include <utility>
#include "ForwardList.hpp"
#include "Vector.hpp"
#include "functions.hpp"

int main()
{
  try
  {
    std::string str;
    bool isOver = false;
    zasulsky::ForwardList < std::pair< std::string, zasulsky::Vector< std::string > > > list;
    while (!std::cin.eof())
    {
      std::getline(std::cin, str);
      getSequence(list, str, isOver);
    }
    outputNames(list, std::cout);
    outputSequence(list, std::cout, isOver);
  }
  catch (...)
  {
    std::cerr << "incorrect use of programm\n";
    return 1;
  }
}
