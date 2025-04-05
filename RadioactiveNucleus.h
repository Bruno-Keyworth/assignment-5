// PHYS30762 Programming in C++
// Assignment 5
// Declaration of RadioactiveNucleus class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.
#ifndef RADIOACTIVE_NUCLEUS
#define RADIOACTIVE_NUCLEUS

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Nucleus.h"
#include"Photon.h"

class RadioactiveNucleus : public Nucleus
{
private:
  double half_life;
  bool has_decayed = false;
  std::vector<std::string> isotopes = {"Na-22", "Co-60", "Cs-137"};
  std::vector<double> half_lives = {2.603, 5.272, 30.17};
  std::vector<std::string> history;
  std::vector<std::vector<double>> photon_energies = {{1274.5}, {1.1732, 1.3325}, {0.661}};

public:
  void setHalfLife();
  void setHalfLife(double halflife);
  void printData() override;
  std::vector<Photon> decay();
  
  RadioactiveNucleus(int Z, int A) : Nucleus(Z, A)
  {
    trySet([&] { setHalfLife(); });
  }
  RadioactiveNucleus(std::string isotope) : Nucleus(isotope)
  {
    trySet([&] { setHalfLife(); });
  }
  RadioactiveNucleus(std::string isotope, double halflife) : Nucleus(isotope)
  {
    trySet([&] { setHalfLife(halflife); });
  }
  RadioactiveNucleus(int Z, int A, double halflife) : Nucleus(Z, A)
  {
    trySet([&] { setHalfLife(halflife); });
  }
  
};

#endif
