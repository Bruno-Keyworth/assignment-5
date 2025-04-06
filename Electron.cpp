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
  if(anti) { row += "Positron"; }
  else { row += "Electron"; }
  row += " | " + add_spaces(to_string_trimmed(std::round(energy * 10000.0) / 10000.0), 6);
  row += " | " + to_string_trimmed(rest_mass);
  std::cout<<row<<std::endl;
}

void Electron::setE(double E)
{
  if(E<rest_mass) { throw std::invalid_argument("Error: Energy cannot be less than rest mass energy"); }
  energy = E;
  double delta_E = energy - rest_mass;
  int num_photons = static_cast<int>(floor(delta_E/photon_energy));
  for(int i=0; i<num_photons; i++) { photons.push_back(std::make_shared<Photon>(photon_energy)); }
}

void Electron::setAnti()
{
  if(anti) { anti = false; }
  else { anti = true; }
}
