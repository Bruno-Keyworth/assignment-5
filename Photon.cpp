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
  if(E<0) { throw std::invalid_argument("Error: photon energy cannot be negative."); }
  energy = E;
  if(E>1.022)
  {
    electrons.push_back(std::make_shared<Electron>(E/2));
    electrons.push_back(std::make_shared<Electron>(E/2, true));
  }
}
