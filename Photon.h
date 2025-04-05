// PHYS30762 Programming in C++
// Assignment 5
// Declaration of Photon class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.
#ifndef PHOTON
#define PHOTON

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<functional>
#include"Particle.h"
#include"Electron.h"

class Photon : public Particle
{
private:
  std::string source;
protected:
  double energy;

public:
  void printData() override;
  void setSource(std::string emitted_by) { source = emitted_by; }
  
  Photon(double E) : Particle(0, E) {}
  Photon(double E, std::string emitted_by) : Particle(0, E)
  {
    trySet([&] { setSource(emitted_by); });
  }

  friend class Electron;
};

#endif
