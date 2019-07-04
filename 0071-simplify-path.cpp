class Solution {
public:
    string simplifyPath(string path) {
        string last = "";
        vector<string> dirs;
        
        for (int i = 0; i < path.size(); ) {
            char ch = path[i];
            
            if (ch == '/' && ((i + 1 < path.size() && path[i + 1] == '/') || (i == path.size() - 1))) {
                i = i + 1;
            } else if (ch == '/' && ((i + 2 < path.size() && path[i + 1] == '.' && path[i + 2] == '/') || (i + 1 == path.size() - 1 && path[i + 1] == '.'))) {
                i = i + 2;
            } else {
                if (ch == '/') {
                    if (last != "") {
                        if (last == "..") {
                            if (!dirs.empty()) dirs.pop_back();
                        } else {
                            dirs.push_back(last);
                        }
                    }
                    last = "";
                } else {
                    last += ch;
                }
                i = i + 1;
            }
        }
        if (last != "") {
            if (last == "..") {
                if (!dirs.empty()) dirs.pop_back();
            } else {
                dirs.push_back(last);
            }
        }
        
        string ans = "";
        for (int i = 0; i < dirs.size(); ++i) {
            ans += '/' + dirs[i];
        }
        if (ans == "") ans = "/";
        return ans;
    }
};
