// https://leetcode.com/problems/product-of-the-last-k-numbers/

#include <vector>

class ProductOfNumbers {
private:
    vector<int> plist;
    
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0)           // if num = 0, remove all the previous products
            plist.clear();
        else if(plist.empty()) // if plist is empty or the last element is 0 
            plist.push_back(num);   //create a new section for positive products
        else                   //if the last elment is positive
            plist.push_back(plist.back() * num);  // extend the section of positve products
    }
    
    int getProduct(int k) {
        if(k > plist.size()) // must span at least a zero
            return 0;

        if(k == plist.size())
            return plist.back();
        
        return plist.back() / plist[plist.size() - k - 1];
        
    }
};
