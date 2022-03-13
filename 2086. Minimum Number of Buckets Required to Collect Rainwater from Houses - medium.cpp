// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
class Solution {
public:
    int minimumBuckets(string street) {
        size_t i = 0, pos = street.find("H.H");
        int bucket = 0;
        
        while(pos != string::npos){
            int res = num_houses(street, i, pos);
            if(res < 0)  return -1;
            bucket += res;
          
            // arrive to "H.H"
            bucket ++;
            i = pos + 3;
            pos = street.find("H.H", i);
        }
        
        int res = num_houses(street, i, street.size());
        if(res < 0)  return -1;
        return bucket + res;
    }
    
    int num_houses(string &street, size_t start, size_t end){
        int i = start, bucket = 0, house = 0;
        while(i < end){
            if(street[i] == 'H')
                house ++;
            else if(house){ // street[i] == '.'
                if(house > 2)
                    return -1;
                if(house == 2 && (start + house == i))
                    return -1;
                
                bucket += house;
                house = 0;
            }
            ++ i;
        }

        if(!house)  return bucket;
        
        if(house >= 2 || (start + house == i))
            return -1;

        return bucket + house;

    }
};
