// PHYS30762 Programming in C++
// Assignment 5
// Implementation of Particle class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Particle.h"
void Particle::trySet(const std::function<void()>& setter)
{
  try { setter(); }
  catch (const std::invalid_argument& error) { std::cout << error.what() << std::endl; }
}

void Particle::setE(double E)
{
  if(E<rest_mass) { throw std::invalid_argument("Error: Energy cannot be less than rest mass energy"); }
  energy = E;
}

void Particle::setMass(double mass)
{
  if(mass<0) { throw std::invalid_argument("Error: Rest mass cannot be negative"); }
  rest_mass = mass;
}

void Particle::printData()
{

}
