struct DATA{
  public:
    DATA(int m_key, int m_value, pair<int, int> m_freqLastcall) : 
      key(m_key), value(m_value), freqLastcall(m_freqLastcall) {}

    ~DATA(){}

    int key;
    int value;
    // first: call frequency
    // second: last call id;
    pair<int, int> freqLastcall;
};

class LFUCache {
  public:
    LFUCache(int capacity) {
      NCapacity = capacity;
      idxUsed = 0;
    }

    int get(int key) {
      if(NCapacity <=0) return -1;

      idxUsed++;
      if(keyDataMap.find( key ) != keyDataMap.end()){
        DATA *dpoint = keyDataMap[key];
        map<pair<int, int>, DATA *>::iterator it = freqCallDataMap.find( dpoint->freqLastcall );
        freqCallDataMap.erase( it );
        (dpoint->freqLastcall).first++;
        (dpoint->freqLastcall).second = idxUsed;
        freqCallDataMap.insert( make_pair(dpoint->freqLastcall, dpoint) );
        return dpoint -> value;
      }else return -1;
    }

    void put(int key, int value) {
      if(NCapacity <=0) return;

      idxUsed++; // put is call too!!!

      // found the key, then update the value
      if(keyDataMap.find( key ) != keyDataMap.end()){
        DATA *dpoint = keyDataMap[key];
        map<pair<int, int>, DATA *>::iterator it = freqCallDataMap.find( dpoint->freqLastcall );
        freqCallDataMap.erase( it );
        dpoint -> value = value;
        (dpoint->freqLastcall).first++;
        (dpoint->freqLastcall).second = idxUsed;
        freqCallDataMap.insert( make_pair(dpoint->freqLastcall, dpoint) );
      }
      // key is not found:
      else{ 
        //if data size reached its capacity, remove the one in the lowest order!
        if(keyDataMap.size() == NCapacity){
          map<pair<int, int>, DATA *, pairComp>::iterator it = freqCallDataMap.begin();
          DATA * dpoint = it->second;
          freqCallDataMap.erase( it );
          map<int, DATA *>::iterator jt = keyDataMap.find(dpoint -> key);
          delete dpoint;
          keyDataMap.erase(jt);
        }
        pair<int, int> freqCall(0, idxUsed);
        DATA * dpoint = new DATA(key, value, freqCall);
        keyDataMap.insert( make_pair(key, dpoint) );
        freqCallDataMap.insert( make_pair(freqCall, dpoint) );
      }
    }

  private:
    int NCapacity;
    int idxUsed;

    // key: DATA.key
    // value: DATA address
    map<int, DATA *> keyDataMap;

    //1st order: frequency
    //2nd order: if same frequency, then compare the last call index
    struct pairComp
    {
      bool operator()(const pair<int, int> & p1, const pair<int, int> & p2) const
      {
        if     (p1.first < p2.first) return true;
        else if(p1.first > p2.first) return false;
        return (p1.second < p2.second);
      }
    };    
    // key: DATA.freqLastcall
    // value: DATA address
    map<pair<int, int>, DATA *, pairComp> freqCallDataMap;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
