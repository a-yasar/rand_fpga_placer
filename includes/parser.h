#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include "./model.h"

namespace parser{

  parser::model parse(std::istream& ist);
}

#endif