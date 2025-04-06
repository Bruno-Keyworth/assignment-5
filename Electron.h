// PHYS30762 Programming in C++
// Assignment 5
// Declaration of Electron class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.
#ifndef ELECTRON
#define ELECTRON

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>
#include<functional>
#include"Particle.h"

class Electron : public Particle
{
private:
  std::vector<std::shared_ptr<class Photon>> photons;
  friend class Photon;
  friend Photon radiate(Electron& electron);
  friend Photon radiate(Electron& electron, double photon_energy);
  double photon_energy = 0.1;
  bool anti = false;
public:
  void printData() override;
  void setE(double E) override;
  void setAnti(bool is_anti) { anti = is_anti; }
  void setAnti();
  
  Electron(double E) : Particle(0.511, E) {}
  Electron(double E, bool is_anti) : Particle(0.511, E) { setAnti(is_anti); }
};

#endif
