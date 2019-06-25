class Twitter {
public:
    typedef unordered_map<int, unordered_set<int>> IDMAP;
    
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        posts.push_back(make_pair(userId, tweetId));
        if(userFollow.find(userId) == userFollow.end()) userFollow.insert( make_pair(userId, unordered_set<int>{}) );
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> latest;
        int npost = 0;
        for(vector<pair<int,int>>::reverse_iterator rit = posts.rbegin(); rit != posts.rend(); rit++){
            if(npost >=10) return latest;
            if(rit->first == userId || userFollow[userId].find(rit->first) != userFollow[userId].end()){
                latest.push_back( rit -> second );
                npost++;
            }
        }
        return latest;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(userFollow.find(followerId) == userFollow.end()) 
            userFollow.insert( make_pair(followerId, unordered_set<int>{followeeId}) );
        else userFollow[followerId].insert( followeeId );        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(userFollow.find(followerId) == userFollow.end()) 
            userFollow.insert( make_pair(followerId, unordered_set<int>{}) );
        else userFollow[followerId].erase( followeeId );
    }
    IDMAP userFollow;
    vector<pair<int,int>> posts; // user id : value posted
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
