//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
struct node{
    int llim, rlim;
    node *l = NULL, *r = NULL;
    
    node(int lt, int rt){
        llim = lt;
        rlim = rt;
    }
};

class Solution {
private:
    int m, k, num_bouquets;
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long flowers = m * k;
        
        if(flowers > n)
            return -1;
        
        if(flowers == n)
            return *max_element(bloomDay.begin(), bloomDay.end());
        
        // construct a vector of index
        vector<int> idx(n);
        for(int i = 0; i < n; i ++)
            idx[i] = i;
        
        // sort index in descending order based on the corresponding value in bloomDay
        stable_sort(idx.begin(), idx.end(),
            [&bloomDay](const int &i1, const int &i2) {return bloomDay[i1] > bloomDay[i2];});
        
        int i;
        num_bouquets = n / k;
        this->m = m;
        this->k = k;
        // construct a tree with index as left limit and right limit
        node *root = new node(0, n - 1);
        
        for(auto &i: idx){
            // binary search the tree with idx as the key.
            // each time split the node into two new node (left limit, idx - 1) and (idx + 1, right limit),
            // until num_bouquest is reduced to smaller than m, the day of that element is the largest value
            // that has to remain in bloomDay.
            if(!bs(root, i))
                return bloomDay[i];
        }

        return -1;
    }
    
    bool bs(node *root, int& idx){
        if(root->l && root->l->rlim >= idx)
            return bs(root->l, idx);
        else if(root->r)
            return bs(root->r, idx);
        else{
            int variance = (root->rlim - root->llim + 1) / k;
            
            if(root->llim < idx){
                root->l = new node(root->llim, idx - 1);
                variance -= (idx - root->llim) / k;
            }
            
            if(root->rlim > idx){
                root->r = new node(idx + 1, root->rlim);
                variance -= (root->rlim - idx) / k;
            }

            num_bouquets -= variance;
            return num_bouquets >= m;
        }
    }
};
