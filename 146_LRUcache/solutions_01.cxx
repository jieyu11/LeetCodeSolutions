class LRUCache {
public:
    LRUCache(int capacity) {
        m_max = capacity;
        m_time = 0;
        m_size = 0;
    }
    
    int get(int key) {
        if(valueMap.find(key) != valueMap.end()){
            timekeyMap.erase( keytimeMap[key] );
            timekeyMap[ m_time ] = key;
            keytimeMap[key] = m_time;
            m_time++;
            return valueMap[ key ];
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if key already exists
        if(valueMap.find(key) != valueMap.end()){
            valueMap[ key ] = value;
            timekeyMap.erase( keytimeMap[key] );
            timekeyMap[ m_time ] = key;
            keytimeMap[key] = m_time;
        }else{
            if(m_size >= m_max){
                map<long int, int>::iterator it_oldkey = timekeyMap.begin();
                valueMap.erase( it_oldkey -> second );
                keytimeMap.erase( it_oldkey -> second );
                timekeyMap.erase( it_oldkey -> first );
                m_size--;
            }
            valueMap[ key ] = value;
            timekeyMap[ m_time ] = key;
            keytimeMap[key] = m_time;
            m_size++;
        }
        m_time++;
    }
private:
    int m_max;
    int m_size;
    long int m_time;
    map<long int, int> timekeyMap;
    map<int, long int> keytimeMap;
    map<int, int> valueMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
