#include "./includes/composer.h"

namespace composer{

  void compose(std::istream& ist, placer::placer p){
    std::string line;
    std::unordered_map<int, std::pair<int,int> > gate_map = p.get_gate_map();
    std::ofstream outf;
    outf.open("out.blif");

    int g = 0;
    int io=0;

    while(std::getline(ist, line)){
      boost::trim(line);
      outf << line << "\n";
      size_t pos = line.find(' ');
      const std::string command = line.substr(0, pos);

      line = line.substr(pos+1);

      if(command == ".inputs"){
        outf << ".attr loc ";
        for(int i=0; i<p.get_inputs().size(); i++){
          outf << "I/0(" << io << ") ";
          ++io;
        }
        outf << "\n";
      }
      else if(command == ".outputs"){
        outf << ".attr loc ";
        for(int i=0; i<p.get_outputs().size(); i++){
          outf << "I/0(" << io << ") ";
          ++io;
        }
        outf << "\n";
      }
      else if(command == ".gate"){
        outf << ".attr loc " << gate_map[g].first << " " << gate_map[g].second << "\n";        
        ++g;
      }
      else if(command == ".names"){
        outf << ".attr loc " << gate_map[g].first << " " << gate_map[g].second << "\n";
        ++g;
      }
      else{
        //unhandled TO-DO
      }
  	}

    outf.close();
  }
}