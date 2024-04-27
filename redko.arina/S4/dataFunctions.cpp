#include "dataFunctions.hpp"
#include <iostream>

int redko::cutKey(std::string & str)
{
  int key = std::stoi(str.substr(0, str.find_first_of(" ", 0)));
  if (str.find_first_of(" ") == std::string::npos)
  {
    str = "";
  }
  else
  {
    str = str.substr(str.find_first_of(" ") + 1);
  }
  return key;
}

void redko::print(BSTree< std::string, BSTree < int, std::string > > & dataSets)
{
  std::string setName = "";
  std::cin >> setName;
  redko::BSTree< std::string, BSTree < int, std::string > >::iterator currSet = dataSets.find(setName);
  if (currSet != dataSets.end())
  {
    if (!dataSets[setName].empty())
    {
      std::cout << setName;
      redko::BSTree< int, std::string >::iterator currElem = dataSets[setName].begin();
      while (currElem != dataSets[setName].end())
      {
        std::cout << ' ' << currElem->first << ' ' << currElem->second;
        ++currElem;
      }
      std::cout << '\n';
    }
    else
    {
      std::cout << "<EMPTY>\n";
    }
  }
}

void redko::complement(BSTree< std::string, BSTree < int, std::string > > & dataSets)
{
  std::string newSetName = "";
  std::string firstSetName = "";
  std::string secondSetName = "";
  std::cin >> newSetName >> firstSetName >> secondSetName;
  redko::BSTree< int, std::string > dataSet{};
  redko::BSTree< int, std::string >::iterator currElem = dataSets[firstSetName].begin();
  while (currElem != dataSets[firstSetName].end())
  {
    if (dataSets[secondSetName].find(currElem->first) == dataSets[secondSetName].end())
    {
      dataSet.insert(*currElem);
    }
    ++currElem;
  }
  currElem = dataSets[secondSetName].begin();
  while (currElem != dataSets[secondSetName].end())
  {
    if (dataSets[firstSetName].find(currElem->first) == dataSets[firstSetName].end())
    {
      dataSet.insert(*currElem);
    }
    ++currElem;
  }
  dataSets.insert({ newSetName, dataSet });
}

void redko::intersect(BSTree< std::string, BSTree < int, std::string > > & dataSets)
{
  std::string newSetName = "";
  std::string firstSetName = "";
  std::string secondSetName = "";
  std::cin >> newSetName >> firstSetName >> secondSetName;
  redko::BSTree< int, std::string > dataSet{};
  redko::BSTree< int, std::string >::iterator currElem = dataSets[firstSetName].begin();
  while (currElem != dataSets[firstSetName].end())
  {
    if (dataSets[secondSetName].find(currElem->first) != dataSets[secondSetName].end())
    {
      dataSet.insert(*currElem);
    }
    ++currElem;
  }
  dataSets.insert({ newSetName, dataSet });
}

void redko::unite(BSTree< std::string, BSTree < int, std::string > > & dataSets)
{
  std::string newSetName = "";
  std::string firstSetName = "";
  std::string secondSetName = "";
  std::cin >> newSetName >> firstSetName >> secondSetName;
  redko::BSTree< int, std::string > dataSet = dataSets[firstSetName];
  redko::BSTree< int, std::string >::iterator currElem = dataSets[secondSetName].begin();
  while (currElem != dataSets[secondSetName].end())
  {
    dataSet.insert(*currElem);
    ++currElem;
  }
  dataSets.insert({ newSetName, dataSet });
}
