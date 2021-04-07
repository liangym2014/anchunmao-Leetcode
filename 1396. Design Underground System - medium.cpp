/*
https://leetcode.com/problems/design-underground-system/
*/

#include <unordered_map>
#include <utility>
using namespace std;

class UndergroundSystem {
private:
    //key: startstation + '-' + endstation, value: {total time, number of records}
    unordered_map<string, pair<int, int>> averageTime;
    //key: customer id, value: {start station, checkin time}
    unordered_map<int, pair<string, int>> customers;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customers[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> record = customers[id];
        stationName = record.first + '-' + stationName;

        averageTime[stationName].first += t - record.second;
        averageTime[stationName].second ++;

        customers.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + '-' + endStation;
        pair<int, int> record = averageTime[key];
        return 1.0 * record.first / record.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
