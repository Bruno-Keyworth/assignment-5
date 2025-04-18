// PHYS30762 Programming in C++
// Assignment 5
// Declaration of Particle class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.
#ifndef PARTICLE
#define PARTICLE

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<functional>

class Photon;
class Electron;
class Particle
{
private:
  std::string type = "unknown";
protected:
  double rest_mass;
  double energy;
  friend Photon radiate(Electron& electron);
  friend Photon radiate(Electron& electron, double photon_energy);
  friend double photoelectric_effect(Photon& photon);
  friend std::vector<Electron> pair_production(Photon& photon);
  friend void compton_effect(Photon& photon, double theta);
  void trySet(const std::function<void()>& setter);
public:
  void setMass(double mass);
  virtual void setE(double E);
  void setType(std::string ptype) { type = ptype; }
  double getMass() const { return rest_mass; }
  double getE() const { return energy; }
  std::string getType() const { return type; }
  virtual void printData();
  
  Particle(double mass, double E)
  {
    trySet([&] { setMass(mass); });
    trySet([&] { setE(E); });
  }
  Particle(std::string ptype, double mass, double E)
  {
    trySet([&] { setType(ptype); });
    trySet([&] { setMass(mass); });
    trySet([&] { setE(E); });
  }
};

#endif
