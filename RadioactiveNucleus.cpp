// PHYS30762 Programming in C++
// Assignment 5
// Implementation of RadioactiveNucleus class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"RadioactiveNucleus.h"

void RadioactiveNucleus::setHalfLife(double halflife)
{
  if(halflife <= 0) { throw std::invalid_argument("Error: Half life must be positive."); }
  half_life = halflife;
}

void RadioactiveNucleus::printData()
{
  std::cout<<getType()<<getZ()<<getA()<<std::endl;
}

