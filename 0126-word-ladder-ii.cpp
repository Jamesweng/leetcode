class Solution {
private:
    struct Node {
        string word;
        Node* prev;
        
        Node(const string& w, Node* p = NULL):word(w), prev(p) {
        }
    };
    
    void get_ans(Node* node, vector<string>& new_ans) {
        if (!node) return;
        get_ans(node->prev, new_ans);
        new_ans.push_back(node->word);
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        queue<Node*> que[2];
        que[0].push(new Node(beginWord));
        int cur = 0;
        
        unordered_map<string, int> visited;
        visited[beginWord] = 1;
        int step = 1;
        
        while(!que[cur].empty()) {
            int next = 1 - cur;
            step++;
            
            while (!que[cur].empty()) {
                Node* node = que[cur].front();
                string word = node->word;
                que[cur].pop();
                bool found = false;
                
                for (int i = 0; i < word.size() && !found; ++i) {
                    char tmp = word[i];
                    for (char ch = 'a'; ch <= 'z' && !found; ch++) {
                        if (ch != tmp) {
                            word[i] = ch;
                            if (words.find(word) == words.end()) continue;
                            
                            unordered_map<string, int>::iterator it = visited.find(word);
                            if (it == visited.end() || it->second == step) {
                                Node* new_node = new Node(word, node);
                                que[next].push(new_node);
                                
                                if (word == endWord) {
                                    ans.push_back(vector<string>());
                                    get_ans(new_node, ans.back());
                                    found = true;
                                } else {
                                    visited[word] = step;
                                }
                            }
                        }
                    }
                    word[i] = tmp;
                }
            }

            if (!ans.empty()) break;
            cur = 1 - cur;
        }
        
        // new nodes will be released when program exit.
        return ans;
    }
};
