#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <boost/algorithm/string.hpp>

namespace parser{

  struct gate
  {  
    std::string gate_name;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;    
  };

}

#endif