// exmaple6.cpp
#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
  using namespace boost::program_options;
  options_description desc("Command line options");  
  // 定义描述选项: (选项全称，缩写)， (参数类型->默认值)，(描述)
  desc.add_options()
    ("help,h", "print help message")
    ("person,p", value<string>()->default_value("world"), "person name")
    ("file,f", value< vector<string> >(), "input file name");

  variables_map vm;  // 存储传入的参数
  store(parse_command_line(argc, argv, desc), vm);  // 根据描述选项解析参数
  // notify(vm);

  if(vm.count("help")){
    cout << desc << endl;
    return 0;
  }
  cout << "Hello " << vm["person"].as<string>() << endl;
  cout << "argc: " << argc << endl;

  for (int i = 0; i < argc; i++) {
    cout << "*argv:" << argv[i] << endl;
  }

  if(vm.count("file")){
    vector<string> files(vm["file"].as< vector<string> >());
    cout << "Got " << files.size() << " files." << endl;
  }

  return 0;
}

/*  Ubuntu 16.04 LTS
g++ example6.cpp -lboost_program_options

./a.out
Hello world

./a.out -h
Commad line options:
  -h [ --help ]                print help message
  -p [ --person ] arg (=world) person name
  -f [ --file ] arg            input file name

./a.out -p Splay
Hello Splay
*/
