class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(data.find(key) == data.end()){
            data.insert( make_pair(key, 1) );
            order.insert( make_pair(1, key) );
        }
        else{
            multimap<int, string>::iterator it = order.find( data[key] );
            while(it != order.end()){
                if(it->second == key){
                    order.erase(it);
                    break;
                }
                it++;
            }
            data[key]++;
            order.insert( make_pair(data[key], key) );
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(data.find(key) == data.end()) return;
        multimap<int, string>::iterator it = order.find( data[key] );
        while(it != order.end()){
            if(it->second == key){
                order.erase(it);
                break;
            }
            it++;
        }
        
        if(data[key] == 1){
            data.erase(key);
        }else{
            data[key]--;
            order.insert( make_pair(data[key], key) );
        }

    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(order.empty()) return "";
        multimap<int, string>::reverse_iterator rit = order.rbegin();
        return rit -> second;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(order.empty()) return "";
        return ( order.begin() ) -> second;
    }
    unordered_map<string, int> data;
    multimap<int, string> order;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
