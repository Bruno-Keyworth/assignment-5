// PHYS30762 Programming in C++
// Assignment 5
// Implementation of Electron class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Electron.h"
#include"Photon.h"
#include"functions.h"

void Electron::printData()
{
  std::string row;
  row += "Electron ";
  row += " | " + to_string_trimmed(energy);
  std::cout<<row<<std::endl;
}
