#include <fstream>
#include <iostream>
#include "./includes/parser.h"
#include "./includes/placer.h"
#include "./includes/composer.h"


using namespace std;

int print_usage()
{
  cerr << "Usage: ./blif_placer [FILE].blif" << endl;
  return -1;
}

int main(int argc, char* argv[])
{
  if(argc != 2){
    return print_usage();
  }

  ifstream ifs (argv[1]);
  if(!ifs){
    return print_usage();
  }

  parser::model model = parser::parse(ifs);
  placer::placer p;
  p.place(model);  

  ifstream ifs2 (argv[1]);
  composer::compose(ifs2, p);
  std::cout << p.get_gate_map().size() << std::endl;

  return 0;
}