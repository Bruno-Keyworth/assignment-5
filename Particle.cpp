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

void Particle::printData()
{

}
