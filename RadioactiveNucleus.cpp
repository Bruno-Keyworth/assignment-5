// PHYS30762 Programming in C++
// Assignment 5
// Implementation of RadioactiveNucleus class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <memory>
#include"RadioactiveNucleus.h"
#include"functions.h"
#include"Photon.h"

void RadioactiveNucleus::setHalfLife(double halflife)
{
  if(halflife <= 0) { throw std::invalid_argument("Error: Half life must be positive."); }
  half_life = halflife;
}

void RadioactiveNucleus::setHalfLife()
{
  int index = get_index(type, isotopes);
  if(index < isotopes.size())
  {
    half_life = half_lives[index];
  } else { throw std::invalid_argument("Error: Isotope halflife unknown: " + type); }
}

void RadioactiveNucleus::setPhotons()
{
  int index = get_index(type, isotopes);
  if(index < isotopes.size())
  {
    for(double photon_energy : photon_energies[index]) { photons.emplace_back(std::make_unique<Photon>(photon_energy)); }
  } else { throw std::invalid_argument("Error: Decay scheme unknown: " + type); }
}

void RadioactiveNucleus::setPhotons(std::vector<double> energies)
{
  photons.clear();
  for(double energy : energies){ photons.emplace_back(std::make_unique<Photon>(energy)); }
}

std::vector<Photon> RadioactiveNucleus::decay()
{
  has_decayed = true;

  std::vector<Photon> radiated_photons;
  radiated_photons.reserve(photons.size());
  for(auto& ptr : photons) { if(ptr) { radiated_photons.push_back(std::move(*ptr)); } }
  photons.clear();
  for(int i=0; i<radiated_photons.size(); i++)
  {
    radiated_photons[i].printData();
  }
  return radiated_photons;
}

void RadioactiveNucleus::printData() const
{
  std::string row;
  row += add_spaces(type, 7);
  row += " | " + add_spaces(std::to_string(atomic_number), 3);
  row += " | " + add_spaces(std::to_string(atomic_mass), 3);
  row += " | " + add_spaces(to_string_trimmed(half_life), 13);
  if(has_decayed) { row += " | Yes"; }
  else { row += " | No"; }
  std::cout<<row<<std::endl;
}

