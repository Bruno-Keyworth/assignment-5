// PHYS30762 Programming in C++
// Assignment 5
// Implementation of Nucleus class.
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Nucleus.h"
#include"functions.h"

void Nucleus::setZ(int Z)
{
  if(Z < 1) { throw std::invalid_argument("Error: Atomic Number must be positive."); }
  atomic_number = Z;
}

void Nucleus::setZ()
{
  std::string element = type.substr(0, type.find('-'));
  int index = get_index(element, elements);
  if(index < elements.size())
  {
    atomic_number = index + 1;
  } else { throw std::invalid_argument("Error: Element not recognised " + element); }
}

void Nucleus::setA(int A)
{
  if(A < atomic_number) { throw std::invalid_argument("Error: Atomic mass cannot be less than atomic number."); }
  atomic_mass = A;
}

void Nucleus::setA()
{
  int A = std::stoi(type.substr(type.find('-') + 1));
  if(A < atomic_number) { throw std::invalid_argument("Error: Atomic mass cannot be less than atomic number."); }
  atomic_mass = A;
}

void Nucleus::setType()
{
  type = elements[atomic_number-1] + "-" + std::to_string(atomic_mass);
}

void Nucleus::trySet(const std::function<void()>& setter)
{
  try { setter(); }
  catch (const std::invalid_argument& error) { std::cout << error.what() << std::endl; }
}

void Nucleus::printData()
{
  std::string row;
  row += add_spaces(type, 7);
  row += " | " + add_spaces(std::to_string(atomic_number), 3);
  row += " | " + add_spaces(std::to_string(atomic_mass), 3);
  std::cout<<row<<std::endl;
}
