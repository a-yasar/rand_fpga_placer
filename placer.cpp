#include "./includes/placer.h"

#define MAX_LUT 4
#define MAX_FF 4
#define N 4
#define MAX_ITER 100

namespace placer{

  void placer::create_clb(std::pair<int,int> loc){
    int lut=0, ff=0, i=0;

    while((lut<MAX_LUT || ff<MAX_FF) && i<gates.size()){
      parser::gate g = gates[i];

      if(gate_map.find(i) != gate_map.end()){
        ++i;
        continue;
      }

      if(g.gate_name == "SB_DFF" && ff<MAX_FF){
        gate_map[i] = loc;
        ++ff;
        ++i;
      }
      else if(lut<MAX_LUT){
        gate_map[i] = loc;
        ++lut;
        ++i;
      }
      else{
        ++i;
      }
    }
  }
  
  void placer::init_relations(){
    for(int i=0; i<gates.size(); i++){
      std::string s = gates[i].outputs[0];
      if(std::find(outputs.begin(), outputs.end(), s) == outputs.end()){
        std::vector<int> v;

        for(int j=0; j<gates.size(); j++){
          std::vector<std::string> ins = gates[j].inputs;
          if(std::find(ins.begin(), ins.end(), s) != ins.end()){
            v.push_back(j);
          }
        }

        related[i] = v;
      }
    }
  }

  std::pair<int,int> swap(std::pair<int,int> loc, std::pair<int,int> loc1,std::pair<int,int> loc2){
    if(loc == loc1)
      return loc2;
    else if(loc == loc2)
      return loc1;
    else
      return loc;
  }

  int placer::dist_manhattan(int s){
    std::vector<int> v = related[s];
    std::pair<int, int> loc_s = swap(gate_map[s], loc1, loc2);

    int d = 0;
    for(int i=0; i<v.size(); i++){
      std::pair<int, int> loc = swap(gate_map[v[i]], loc1, loc2);
      d+= std::abs(loc_s.first - loc.first) + std::abs(loc_s.second-loc.second);
    }

    return d;
  }

  int placer::total_cost(){
    int total = 0;

    for(auto it=related.begin(); it!=related.end(); ++it){
      total += dist_manhattan(it->first);
    }
    return total;
  }

  void placer::update_gate_map(){

    for(auto it=gate_map.begin(); it!=gate_map.end(); ++it){
      gate_map[it->first] = swap(it->second, loc1, loc2);
    }
  }

  void placer::place(parser::model model){
    inputs = model.get_inputs();
    outputs = model.get_outputs();
    gates = model.get_gates();

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        create_clb(std::make_pair(i, j));
      }
    }

    init_relations();
    int old_cost = total_cost();

    for(int i=0; i<MAX_ITER; i++){
      for(int j=0; j<MAX_ITER; j++){
        loc1 = std::make_pair(rand()%N, rand()%N);
        loc2 = std::make_pair(rand()%N, rand()%N);
        int new_cost = total_cost();

        if(new_cost < old_cost){
          old_cost = new_cost;
          update_gate_map();
        }
      }
    }        
  }

  std::unordered_map<int, std::pair<int,int> > placer::get_gate_map(){
    return gate_map;
  }
    
  std::vector<std::string> placer::get_inputs(){
    return inputs;
  }
  
  std::vector<std::string> placer::get_outputs(){
    return outputs;
  }

}