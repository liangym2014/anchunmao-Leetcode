// https://leetcode.com/problems/subdomain-visit-count/
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for(auto &domain: cpdomains){
            size_t pos = domain.find(' ');
            int num = stoi(domain.substr(0, pos)), n = domain.size();
            
            size_t start = pos + 1;
            pos = domain.find('.', start);
            
            while(pos != string::npos){
                m[domain.substr(start, n - start)] += num;
                start = pos + 1;
                pos = domain.find('.', start);
            }
            m[domain.substr(start, n - start)] += num;
        }
        
        vector<string> ans;
        ans.reserve(m.size());
        for(const auto &[domain, count]:m){
            ans.push_back(to_string(count) + " " + domain);
        }
        return ans;
    }
};
