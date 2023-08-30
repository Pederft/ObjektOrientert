#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>



void vecFor(std::vector<std::string> h);
void vecBak(std::vector<std::string> h);

void Hei(std::vector<std::string>& h, std::string old, std::string replacement);

void setFor(std::set<std::string> h);
void setBak(std::set<std::string> h);

void Hallaisen(std::set<std::string>& h, std::string old, std::string replacement);
