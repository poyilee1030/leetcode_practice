#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Twitter {
public:
    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        posts.push_back({ userId, tweetId });
    }

    vector<int> getNewsFeed(int userId) {
        // 10 tweets
        int count = 10;
        vector<int> result;

        // since postTweet pushes to the back, looping from back gets most recent
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 0) {
                break;
            }

            int followingId = posts[i].first;
            int tweetId = posts[i].second;
            unordered_set<int> following = followMap[userId];
            // add to result if they're following them or it's a tweet from themself
            if (following.find(followingId) != following.end() || followingId == userId) {
                result.push_back(tweetId);
                count--;
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
private:
    // pairs: [user, tweet]
    vector<pair<int, int>> posts;
    // hash map: {user -> people they follow}
    unordered_map<int, unordered_set<int>> followMap;
};


class _0355_design_twitter
{
public:
	void do_test(_0355_design_twitter* sol)
	{
        Twitter twitter;
        // User 1 posts a new tweet (id = 5).
        twitter.postTweet(1, 5);

        // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
        vector<int> res1 = twitter.getNewsFeed(1);
        print_res(res1);
        
        // User 1 follows user 2.
        twitter.follow(1, 2);

        // User 2 posts a new tweet (id = 6).
        twitter.postTweet(2, 6);
        
        // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. 
        // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
        vector<int> res2 = twitter.getNewsFeed(1);
        print_res(res2);
        
        // User 1 unfollows user 2.
        twitter.unfollow(1, 2);
        
        // User 1's news feed should return a list with 1 tweet id -> [5], 
        // since user 1 is no longer following user 2.
        vector<int> res3 = twitter.getNewsFeed(1);
        print_res(res3);
	}

    void print_res(vector<int> res)
    {
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << res[i];
            if (i < res.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
};
