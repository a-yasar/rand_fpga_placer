#ifndef PLACER_H
#define PLACER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "./model.h"

namespace placer{

  class placer{

  public:
    void place(parser::model model);
    std::unordered_map<int, std::pair<int,int> > get_gate_map();
    std::vector<std::string> get_inputs();
    std::vector<std::string> get_outputs();
    std::vector<parser::gate> gates;    

  private:
    std::pair<int, int> loc1;
    std::pair<int, int> loc2;
    void create_clb(std::pair<int, int> loc);
    void init_relations();
    int dist_manhattan(int s);
    int total_cost();
    void update_gate_map();
    std::unordered_map<int, std::pair<int,int> > gate_map;
    std::unordered_map<int, std::vector<int> > related;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
  };
}

#endif