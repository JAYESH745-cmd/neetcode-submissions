class TimeMap {
public:
    TimeMap() {
        
    }
    vector<int> time;
    map<string,map<int,string>> m;
    
    void set(string key, string value, int timestamp) {
        time.push_back(timestamp);
        m[key][timestamp]=value;
    }
    
    string get(string key, int tar) {
       auto k = m.find(key);

    if (k == m.end())
        return "";

    auto it = k->second.lower_bound(tar);

    if (it != k->second.end() && it->first == tar)
        return it->second;

    if (it == k->second.begin())
        return "";

    --it;
    return it->second;
    
    }
};
