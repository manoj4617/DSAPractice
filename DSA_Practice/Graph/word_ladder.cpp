#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * Returns the length of the shortest word ladder from beginWord to endWord, or
 * 0 if no such ladder exists.
 *
 * A word ladder is a sequence of words, where each word is one edit away from
 * the previous word. An edit is either a change of one character, or a swap of
 * two characters. The words in the ladder must all be present in the given
 * wordList.
 *
 * @param beginWord The starting word of the ladder.
 * @param endWord The ending word of the ladder.
 * @param wordList A vector of words that must contain all the words in the
 *                 ladder.
 * @return The length of the shortest word ladder, or 0 if no such ladder exists.
 */
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Create a set of all the words in the word list, for fast lookups.
    unordered_set<string> dict(wordList.begin(), wordList.end());
    
    // If the end word is not in the word list, or if the begin and end words
    // are the same, then there is no ladder.
    if(dict.find(endWord) == dict.end() || beginWord == endWord){
        return 0;
    }
    
    // Keep track of all the words we've visited so far. This prevents us from
    // getting stuck in an infinite loop if there are cycles in the graph of
    // words.
    unordered_set<string> visited;
    
    // The number of steps in the ladder. We start at 0, and increment it
    // each time we move to a new level of the queue.
    int steps = 0;
    
    // The queue of words to visit. We start with the begin word, and then
    // add all its neighbors, and then all their neighbors, and so on.
    queue<string> q;
    q.push(beginWord);
    visited.insert(beginWord);

    // Keep going until we've visited all the words in the graph.
    while(!q.empty()){
        // Increment the number of steps each time we move to a new level
        // of the queue.
        steps++;
        
        // The length of the current level of the queue. We'll visit all the
        // words in this level before moving on to the next one.
        int len = q.size();
        
        // Visit all the words in the current level.
        for(int i=0;i<len;++i){
            // Get the current word, and remove it from the queue.
            string word = q.front();
            q.pop();

            // If the current word is the end word, then we've found a ladder,
            // and we can return the number of steps.
            if(word == endWord){
                return steps;
            }
            
            // Visit all the neighbors of the current word. We do this by
            // iterating over all the characters in the word, and swapping each
            // one with all 26 possible characters.
            for(int j=0;j<word.length();++j){
                char original = word[j];
                for(char c='a';c<='z';++c){
                    if(c == original) continue;
                    word[j] = c;
                    
                    // If the resulting word is in the word list, and we
                    // haven't visited it before, then add it to the queue and
                    // mark it as visited.
                    if(dict.find(word) != dict.end() && visited.find(word) == visited.end()){
                        q.push(word);
                        visited.insert(word);
                    }
                }
                word[j] = original;
            }
        }
    }

    // If we've reached this point, then there is no ladder from beginWord to
    // endWord, so we return 0.
    return 0;
}

int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {
        "hot","dot","dog","lot","log","cog"
    };

    cout << ladderLength(beginWord, endWord, wordList);
    return 0;
}