#ifndef __SETFUNC_H__ 
#define __SETFUNC_H__

#include <set>
#include <string>
using namespace std;

set<int> parseSet(const std::string& str); 
void printSet(const std::set<int>&);
set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1); 
set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1); std::set<int> 
getDifference(const std::set<int>& set0, const std::set<int>& set1);



#endif //__SETFUNC _H__



