#include "./includes/model.h"

namespace parser{

  void model::insert(std::string line, std::string name){
    size_t pos = line.find(' ');
    const std::string command = line.substr(0, pos);

    line = line.substr(pos+1);

    if(command == ".model"){
      model_name = line;
    }
    else if(command == ".inputs"){
      boost::algorithm::split(inputs, line, boost::is_space(), boost::algorithm::token_compress_on);
    }
    else if(command == ".outputs"){
      boost::algorithm::split(outputs, line, boost::is_space(), boost::algorithm::token_compress_on);
    }
    else if(command == ".gate"){
      gates.push_back(lut_ff(line));
    }
    else if(command == ".names"){
      gates.push_back(logic_gate(line));
    }
    else{
      //unhandled TO-DO
    }
  }

  //private functions
  parser::gate model::logic_gate(std::string line){
    parser::gate result;
    std::vector<std::string> ports;

    result.gate_name = "logic_gate";

    boost::algorithm::split(ports, line, boost::is_space(), boost::algorithm::token_compress_on);

    for(int i=0; i<ports.size(); i++){
      if(i != ports.size()-1){
        result.inputs.push_back(ports[i]);
      }
      else{
        result.outputs.push_back(ports[i]);
      }
    }

    return result;
  }

  parser::gate model::lut_ff(std::string line){
    parser::gate result;
    size_t pos = line.find(' ');
    std::vector<std::string> ports;

    result.gate_name = line.substr(0, pos);

    line = line.substr(pos+1);
    boost::algorithm::split(ports, line, boost::is_space(), boost::algorithm::token_compress_on);

    for(int i=0; i<ports.size(); i++){
      pos = ports[i].find('=');

      if(i != ports.size()-1){
        result.inputs.push_back(ports[i].substr(pos+1));
      }
      else{
        result.outputs.push_back(ports[i].substr(pos+1));
      }
    }

    return result;
  }
  
  //public functions
  void model::print(){
    std::cout << "MODEL NAME" << std::endl;
    std::cout << model_name << std::endl;

    std::cout << "INPUTS"<< std::endl;
    for(int i=0; i<inputs.size(); i++){
      std::cout << inputs[i] << " ";
    }
    std::cout << std::endl;
  
    std::cout << "OUTPUTS"<< std::endl;
    for(int i=0; i<outputs.size(); i++){
      std::cout << outputs[i] << " ";
    }
    std::cout << std::endl;    
  }

  std::vector<std::string> model::get_inputs(){
    return inputs;
  }

  std::vector<std::string> model::get_outputs(){
    return outputs;
  }

  std::string model::get_model_name(){
    return model_name;
  }

  std::vector<gate> model::get_gates(){
    return gates;
  }

}