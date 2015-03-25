#include <iostream>
#include <string>
#include <vector>

namespace placer{

  struct node
  {  
    std::string node_name;
    std::string type;
    std::vector<std::string> input_neighbors;
    std::vector<std::string> output_neighbors;    
  };
  
}