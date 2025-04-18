// PHYS30762 Programming in C++
// Assignment 5
// Declaration of Nucleus class
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.
#ifndef NUCLEUS
#define NUCLEUS

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<functional>
#include"Photon.h"

class Nucleus
{
private:
  std::vector<std::string> elements = {
          "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",
          "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca",
          "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
          "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr",
          "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
          "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
          "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
          "Lu", "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg",
          "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
          "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
          "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
          "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
      };
protected:
  int atomic_number = 55;
  int atomic_mass = 137;
  std::string type = "Cs-137";
  void trySet(const std::function<void()>& setter);
  void setZ();
  void setA();
  virtual void setType();
public:
  void setZ(int Z);
  void setA(int A);
  virtual void setType(std::string ntype) { type = ntype; setZ(); setA(); }
  int getZ() const { return atomic_number; }
  int getA() const { return atomic_mass; }
  std::string getType() const { return type; }
  virtual void printData() const;
  
  Nucleus() = default;
  Nucleus(int Z, int A)
  {
    trySet([&] { setZ(Z); });
    trySet([&] { setA(A); });
  }
  Nucleus(std::string isotope)
  {
    trySet([&] { setType(isotope); });
  }
  
  virtual ~Nucleus() = default;
  // Copy constructor
  Nucleus(const Nucleus& other) = default;
  // Copy assignment operator
  Nucleus& operator=(const Nucleus& other) = default;
  // Move constructor
  Nucleus(Nucleus&& other) noexcept = default;
  // Move assignment operator
  Nucleus& operator=(Nucleus&& other) noexcept = default;
};

#endif
