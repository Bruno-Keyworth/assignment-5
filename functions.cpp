// PHYS30762 Programming in C++
// Assignment 5
// Implementation of functions
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <sstream>
#include <iomanip>
#include"functions.h"
#include"Photon.h"
#include"Electron.h"

int get_index(std::string element, std::vector<std::string> vector)
{
  if(std::find(vector.begin(), vector.end(), element) != vector.end())
  {
    return std::distance(vector.begin(), std::find(vector.begin(), vector.end(), element)) ;
  }
  else { return vector.size(); }
}
int get_index(int element, std::vector<int> vector)
{
  if(std::find(vector.begin(), vector.end(), element) != vector.end())
  {
    return std::distance(vector.begin(), std::find(vector.begin(), vector.end(), element)) ;
  }
  else { return vector.size(); }
}

int get_index(std::vector<int> element, std::vector<std::vector<int>> vector)
{
  if(std::find(vector.begin(), vector.end(), element) != vector.end())
  {
    return std::distance(vector.begin(), std::find(vector.begin(), vector.end(), element)) ;
  }
  else { return vector.size(); }
}
int get_index(double element, std::vector<double> vector)
{
  if(std::find(vector.begin(), vector.end(), element) != vector.end())
  {
    return std::distance(vector.begin(), std::find(vector.begin(), vector.end(), element)) ;
  }
  else { return vector.size(); }
}

std::string add_spaces(std::string str, int length)
{ // Fills out string to given length by adding spaces to the end
  str.append(length - str.size(), ' ');
  return str;
}

std::string to_string_trimmed(double value)
{
  std::ostringstream out;
  out << std::fixed << std::setprecision(10) << value;  // Adjust precision as needed
  std::string str = out.str();

  // Remove trailing zeros and unnecessary decimal points
  str.erase(str.find_last_not_of('0') + 1, std::string::npos);
  if (str.back() == '.') {
      str.pop_back();  // Remove trailing decimal point if necessary
  }
  return str;
}

double photoelectric_effect(Photon& photon)
{
  std::cout<<"Photoelectric effect: Photon energy = "<<photon.getE()<<" MeV"<<std::endl;
  return photon.energy;
}

void compton_effect(Photon& photon, double theta)
{
  double E_prime = photon.getE() / (1 + (photon.getE() / 0.511) * (1 - cos(theta)));
  photon.setE(E_prime);
  std::cout<<"Compton effect: Photon energy = "<<photon.getE()<<" MeV"<<std::endl;
}

std::vector<Electron> pair_production(Photon& photon)
{
  if (photon.getE() < 1.022)
  {
    std::cerr << "Error: Photon energy is too low for pair production. Energy must be greater than 1.022 MeV."<<std::endl;
    return {};
  }
  std::vector<Electron> electrons;
  for (const auto& electron : photon.electrons)
  {
    electrons.push_back(*electron);
  }
  return electrons;
}

// The electron can only radiate photons whose energies add up to less than the difference between total electron energy and rest mass energy. A default photon energy of 0.1 MeV is set, or a different energy can be added as an argument to the radiate function.
Photon radiate(Electron& electron)
{
  if(electron.energy-electron.rest_mass < electron.photon_energy) { throw std::invalid_argument("Electron has insufficient energy to radiate this photon."); }
  else if(electron.photons.size()==0) { electron.setE(electron.energy); }
  Photon photon = *(electron.photons[0]);
  electron.photons.erase(electron.photons.begin());
  electron.energy -= photon.getE();
  std::cout<<"Electron radiated photon of energy "<<photon.getE()<<" MeV"<<std::endl;
  std::cout<<"Remaining electron energy = "<<electron.energy<<" MeV"<<std::endl;
  return photon;
}

Photon radiate(Electron& electron, double photon_energy)
{
  (electron.photons).clear();
  double delta_E = electron.energy - electron.rest_mass;
  int num_photons = static_cast<int>(floor(delta_E/photon_energy));
  for(int i=0; i<num_photons; i++) { electron.photons.push_back(std::make_shared<Photon>(photon_energy)); }
  Photon photon = *(electron.photons[0]);
  electron.photons.erase(electron.photons.begin());
  electron.energy -= photon.getE();
  std::cout<<"Electron radiated photon of energy "<<photon.getE()<<" MeV"<<std::endl;
  std::cout<<"Remaining electron energy = "<<electron.energy<<" MeV"<<std::endl;
  return photon;
}
