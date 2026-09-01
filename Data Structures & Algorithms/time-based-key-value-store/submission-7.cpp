class TimeMap {
public:
    TimeMap() {
        
    }
    vector<int> time;
    map<int,pair<string,string>> m;
    
    void set(string key, string value, int timestamp) {
        if(m.find(timestamp)==m.end()) {
            time.push_back(timestamp);
            m[timestamp]={key,value};
        }
    }
    
    string get(string key, int tar) {
       int l=0,r=time.size()-1;
       int ans=-1;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(time[mid]<=tar){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
       }
      
       if(ans==-1) return "";
       cout<<m[time[ans]].first<<" ";
       return m[time[ans]].second;
    }
};
