#include "./includes/parser.h"

namespace parser{

  parser::model parse(std::istream& ist){
    std::string line;
    parser::model m;
    int c=0;

    while(std::getline(ist, line)){
      boost::trim(line);
      if (boost::algorithm::starts_with(line, ".")) m.insert(line, std::to_string(c));

      ++c;
  	}
    return m;
  }
}