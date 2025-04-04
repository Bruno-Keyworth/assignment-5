// PHYS30762 Programming in C++
// Assignment 5
// Declaration of StableNucleus class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.
#ifndef STABLE_NUCLEUS
#define STABLE_NUCLEUS

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Nucleus.h"

class StableNucleus : public Nucleus
{
protected: 
  //...
public:
  void printData() override;

};

#endif
