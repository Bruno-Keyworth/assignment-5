// PHYS30762 Programming in C++
// Assignment 5
// Programme to model radioactive decay.
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Nucleus.h"
#include"StableNucleus.h"
#include"RadioactiveNucleus.h"
#include"Particle.h"
#include"Electron.h"
#include"Photon.h"

int main()
{
  RadioactiveNucleus n(11, 23);
  n.printData();
  return 0;
}
