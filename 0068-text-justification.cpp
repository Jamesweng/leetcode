class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> text;
        int wordsLength = 0;
        int begin = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (wordsLength + words[i].size() > maxWidth) {
                wordsLength--;
                
                int wordCount = i - begin;
                
                int spaceCount = wordCount == 1 ? 0 : 1 + (maxWidth - wordsLength) / (wordCount - 1);
                int extraSpaceCount = wordCount == 1 ? 0 : (maxWidth - wordsLength) % (wordCount - 1);
                string line = "";
                for (int j = begin; j < i; ++j) {
                    line += words[j];
                    if (j < i - 1) {
                        int padding = spaceCount + ((j - begin < extraSpaceCount) ? 1 : 0);
                        for (int k = 0; k < padding; ++k) line += ' ';
                    }
                }
                while (line.size() < maxWidth) line += ' ';
                text.push_back(line);
                
                begin = i;
                wordsLength = words[i].size() + 1;
            } else {
                wordsLength += words[i].size() + 1;
            }
        }
        if (wordsLength > 0) {
            string line = "";
            int wordsLength = 0;
            for (int i = begin; i < words.size(); ++i) {
                line += words[i];
                wordsLength += words[i].size();
                if (i < words.size() - 1) {
                    line += ' ';
                    wordsLength++;
                }
            }
            for (int i = wordsLength; i < maxWidth; ++i) {
                line += ' ';
            }
            text.push_back(line);
        }
        return text;
    }
};
