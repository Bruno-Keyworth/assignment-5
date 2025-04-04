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

class RadioactiveNucleus : public Nucleus
{
private:
  double half_life;
  bool has_decayed = false;
public:
  void setHalfLife(double halflife);
  void printData() override;
  
  RadioactiveNucleus(int Z, int A) : Nucleus(Z, A)
  {
    
  }
  RadioactiveNucleus(int Z, int A, double halflife) : Nucleus(Z, A)
  {
    
  }
  
};

#endif
