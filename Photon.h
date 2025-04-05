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
  std::string type;
protected:
  double energy;

  void trySet(const std::function<void()>& setter);
public:
  void printData() override;
  
  Photon(double E) : Particle(0, E) {}
  
  friend class Electron;
};

#endif
