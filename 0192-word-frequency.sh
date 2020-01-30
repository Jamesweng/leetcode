# Read from the file words.txt and output the word frequency list to stdout.
awk '{for(i=1;i<=NF;++i) print $i}' words.txt | sort | uniq -c | sort -nr | awk '{print $2" "$1}'
