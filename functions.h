// PHYS30762 Programming in C++
// Assignment 5
// Declaration of various functions
// Created by Bruno Keyworth (ID: 11021856) on 03/04/2025.
#ifndef FUNCTIONS
#define FUNCTIONS

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<functional>


int get_index(std::string element, std::vector<std::string> vector);
int get_index(int element, std::vector<int> vector);
int get_index(double element, std::vector<double> vector);
std::string add_spaces(std::string str, int length);
std::string to_string_trimmed(double value);
#endif
