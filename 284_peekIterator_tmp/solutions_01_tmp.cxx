// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
  Data* data;
public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
      ptrIter = new Iterator( nums );
        if(!ptrIter->hasNext()) nextone.push( ptrIter -> next() );
  }

    // Returns the next element in the iteration without advancing the iterator.
  int peek() {
        if(!nextone.empty()) return nextone.front();
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
        int inext = nextone.front();
      nextone.pop();
        if(!ptrIter->hasNext()) nextone.push( ptrIter -> next() );
        return inext;
  }

  bool hasNext() const {
      if(nextone.empty()) return false;
        return true;
  }
private:
    Iterator * ptrIter;
    queue<int> nextone;
};
