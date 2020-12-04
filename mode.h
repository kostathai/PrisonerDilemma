#include "factory.h"
#include "table.h"
#include <conio.h>
#include <iomanip>
#include <string>
#include <set>
#include <memory>

void OneGame(std::unique_ptr<Unit>& , std::unique_ptr<Unit>& , std::unique_ptr<Unit>& ,
             std::vector<std::vector<char>>&, bool , char* , char* , char* );

void fast(char* , char*, char*, int );

void detailed(char* , char* , char* );

void tour(const std::string& ,const std::string& ,const std::string& , std::map<std::string, int>& );

void tournament(std::set<std::string>& );

