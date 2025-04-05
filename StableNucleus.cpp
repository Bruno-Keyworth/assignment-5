// PHYS30762 Programming in C++
// Assignment 5
// Implementation of StableNucleus class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"StableNucleus.h"
#include"functions.h"

void StableNucleus::printData()
{
  std::string row;
  row += add_spaces(type, 7);
  row += " | " + add_spaces(std::to_string(atomic_number), 3);
  row += " | " + add_spaces(std::to_string(atomic_mass), 3);
  row += " | N/A           | No";
  std::cout<<row<<std::endl;
}
