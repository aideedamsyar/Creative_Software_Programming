#ifndef __SORTED_H__ 
#define __SORTED_H__
#include <vector> 

class SortedArray{
    public:
        void AddNumber(int num);
        std::vector<int> GetSortedAscending(); 
        std::vector<int> GetSortedDescending(); int GetMax();
        int GetMin();
    private:
        std::vector<int> numbers_;
};

#endif //__SORTED _H__