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
#include<memory>
#include<functional>
#include"Particle.h"
#include"Electron.h"

class Photon : public Particle
{
private:
  friend class Electron;
  friend double photoelectric_effect(Photon& photon);
  friend std::vector<Electron> pair_production(Photon& photon);
  friend void compton_effect(Photon& photon, double theta);
  std::string source;
  std::vector<std::shared_ptr<class Electron>> electrons;

public:
  void printData() override;
  void setSource(std::string emitted_by) { source = emitted_by; }
  void setE(double E) override;
  
  Photon(double E) : Particle(0, E) {}
  Photon(double E, std::string emitted_by) : Particle(0, E)
  {
    trySet([&] { setSource(emitted_by); });
  }
};

#endif
