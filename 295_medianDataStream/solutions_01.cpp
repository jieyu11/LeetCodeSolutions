class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        ntotal = 0;
    }
    
    void addNum(int num) {
        ntotal++;
        if(ntotal==1){
            numbers.push_back( static_cast<double>(num) );
        }else{
            vector<double>::iterator it = upper_bound(numbers.begin(), numbers.end(),num);
            numbers.insert(it, num);
        }
    }
    
    double findMedian() {
        if(ntotal%2==1) return numbers[ ntotal/2 ];
        else{
            return (numbers[ ntotal/2 ] + numbers[ ntotal/2-1 ]) / 2.;
        }
    }
    private:
    vector<double> numbers;
    unsigned int ntotal;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

