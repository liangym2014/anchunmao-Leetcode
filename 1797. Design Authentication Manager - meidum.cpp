// https://leetcode.com/problems/design-authentication-manager/

class AuthenticationManager {
private:
    int ttl;
    unordered_map<string, int> tokens;
public:
    AuthenticationManager(int timeToLive): ttl(timeToLive) {
        
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
        
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokens.count(tokenId) == 0)
            return;
        
        if(tokens[tokenId] <= currentTime){
            tokens.erase(tokenId);
            return;
        }
        
        tokens[tokenId] = currentTime + ttl;
    }
    
    int countUnexpiredTokens(int currentTime) {
        vector<string> expire_keys;
        for(auto &e: tokens){
            if(e.second <= currentTime)
                expire_keys.push_back(e.first);
        }
        
        for(auto &key: expire_keys)
            tokens.erase(key);
        return tokens.size();
    }
};
