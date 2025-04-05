// PHYS30762 Programming in C++
// Assignment 5
// Programme to model radioactive decay.
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>
#include"Nucleus.h"
#include"StableNucleus.h"
#include"RadioactiveNucleus.h"
#include"Particle.h"
#include"Electron.h"
#include"Photon.h"

int main()
{
  std::vector<Nucleus*> nuclei;
  nuclei.reserve(4);
  nuclei.emplace_back(new RadioactiveNucleus("Na-22"));
  nuclei.emplace_back(new RadioactiveNucleus("Co-60"));
  nuclei.emplace_back(new RadioactiveNucleus("Cs-137"));
  nuclei.emplace_back(new StableNucleus("Fe-56"));

  std::cout<<std::string(80, '-')<<std::endl;
  std::cout<<"Isotope | Z   | A   | Halflife (yr) | Decayed?"<<std::endl;
  std::cout<<std::string(80, '-')<<std::endl;
  for(const auto& nucleus : nuclei)
  {
    nucleus->printData();
  }
  std::cout<<std::string(80, '-')<<std::endl;
  return 0;
}
