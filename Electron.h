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
#include<functional>
#include"Particle.h"

class Electron : public Particle
{
private:
  const double rest_mass = 0.511;
protected:

public:
  void printData() override;
  
  Electron(double E) : Particle(0.511, E) {}
  
  friend class Photon;
};

#endif
