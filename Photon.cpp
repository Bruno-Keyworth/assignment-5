// PHYS30762 Programming in C++
// Assignment 5
// Implementation of Photon class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Photon.h"
#include"Electron.h"
#include"functions.h"

void Photon::printData()
{
  std::string row;
  row += "Photon  ";
  row += " | " + add_spaces(source, 6);
  row += " | " + to_string_trimmed(energy);
  std::cout<<row<<std::endl;
}

void Photon::setE(double E)
{
  if(E<rest_mass) { throw std::invalid_argument("Error: Energy cannot be less than rest mass energy"); }
  energy = E;
  if(E>2*rest_mass)
  {
    electrons.push_back(std::make_shared<Electron>(E/2));
    electrons.push_back(std::make_shared<Electron>(E/2));
  }
}
