#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "./gate.h"

namespace parser{

  class model{
  private:
    std::string model_name;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
    std::vector<parser::gate> gates;
    parser::gate logic_gate(std::string line);
    parser::gate lut_ff(std::string line);    

  public:
    void insert(std::string, std::string);
    std::vector<std::string> get_inputs();
    std::vector<std::string> get_outputs();
    std::string get_model_name();
	std::vector<gate> get_gates();
    void print();
  };
}

#endif