class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> que[2];
        que[0].push(beginWord);
        int cur = 0;
        
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        int step = 1;
        
        while(!que[cur].empty()) {
            int next = 1 - cur;
            step++;
            
            while (!que[cur].empty()) {
                string word = que[cur].front();
                que[cur].pop();
                
                for (int i = 0; i < word.size(); ++i) {
                    char tmp = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch != tmp) {
                            word[i] = ch;
                            if (words.find(word) == words.end()) continue;
                            
                            unordered_set<string>::iterator it = visited.find(word);
                            if (it == visited.end()) {
                                que[next].push(word);
                                
                                if (word == endWord) {
                                    return step;
                                } else {
                                    visited.insert(word);
                                }
                            }
                        }
                    }
                    word[i] = tmp;
                }
            }

            cur = 1 - cur;
        }
        
        return 0;
    }
};
