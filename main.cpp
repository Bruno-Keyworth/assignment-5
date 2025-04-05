// PHYS30762 Programming in C++
// Assignment 5
// Programme to model radioactive decay.
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>
#include<variant>
#include"Nucleus.h"
#include"StableNucleus.h"
#include"RadioactiveNucleus.h"
#include"Particle.h"
#include"Electron.h"
#include"Photon.h"

int main()
{
  std::vector<std::variant<RadioactiveNucleus, StableNucleus>> nuclei;
  nuclei.reserve(4);
  nuclei.emplace_back(RadioactiveNucleus("Na-22"));
  nuclei.emplace_back(RadioactiveNucleus("Co-60"));
  nuclei.emplace_back(RadioactiveNucleus("Cs-137"));
  nuclei.emplace_back(StableNucleus("Fe-56"));

  std::cout<<"Initial nuclei data:"<<std::endl;
  std::cout<<std::string(80, '-')<<std::endl;
  std::cout<<"Isotope | Z   | A   | Halflife (yr) | Decayed?"<<std::endl;
  std::cout<<std::string(80, '-')<<std::endl;
  for(const auto& nucleus : nuclei) std::visit([](auto& n) { n.printData(); }, nucleus);
  std::cout<<std::string(80, '-')<<std::endl;
  
  std::cout<<"Decay product data:"<<std::endl;
  std::cout<<std::string(80, '-')<<std::endl;
  std::cout<<"Particle | Source | Energy"<<std::endl;
  std::cout<<std::string(80, '-')<<std::endl;
  for(auto& nucleus : nuclei) { std::visit([](auto& n) { if constexpr (std::is_same_v<decltype(n), RadioactiveNucleus&>) {n.decay();} }, nucleus); }
  std::cout<<std::string(80, '-')<<std::endl;
  
  std::cout<<"Final nuclei data:"<<std::endl;
  std::cout<<std::string(80, '-')<<std::endl;
  std::cout<<"Isotope | Z   | A   | Halflife (yr) | Decayed?"<<std::endl;
  std::cout<<std::string(80, '-')<<std::endl;
  for(const auto& nucleus : nuclei) std::visit([](auto& n) { n.printData(); }, nucleus);
  std::cout<<std::string(80, '-')<<std::endl;
  return 0;
}
