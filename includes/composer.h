#ifndef COMPOSER_H
#define COMPOSER_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include "placer.h"

namespace composer{

  void compose(std::istream& ist, placer::placer p);
}

#endif