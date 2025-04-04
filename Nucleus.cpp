// PHYS30762 Programming in C++
// Assignment 5
// Implementation of Nucleus class.
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Nucleus.h"

void Nucleus::setZ(int Z)
{
  if(Z < 1) { throw std::invalid_argument("Error: Atomic Number must be positive."); }
  atomic_number = Z;
  if(Z > elements.size()) { type = "?"; }
  else { type = elements[Z-1]; }
}

void Nucleus::setA(int A)
{
  if(A < atomic_number) { throw std::invalid_argument("Error: Atomic mass cannot be less than atomic number."); }
  atomic_mass = A;
}

void Nucleus::setType(std::string ntype)
{
  if(std::find(elements.begin(), elements.end(), ntype) != elements.end())
  {
    type = ntype;
    atomic_number = std::distance(elements.begin(), std::find(elements.begin(), elements.end(), ntype)) + 1;
  }
  else { throw std::invalid_argument("Error: Element not recognised: " + ntype); }
}

void Nucleus::trySet(const std::function<void()>& setter)
{
  try { setter(); }
  catch (const std::invalid_argument& error) { std::cout << error.what() << std::endl; }
}

void Nucleus::printData()
{
  std::cout<<getType()<<getZ()<<getA()<<std::endl;
}
