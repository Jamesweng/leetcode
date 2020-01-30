# Read from the file file.txt and print its transposed content to stdout.
cat file.txt | awk 'BEGIN{} {for(i=1;i<=NF;++i) col[i]=col[i]?col[i] " " $i:$i} END{for(i=1;i<=NF;++i) print col[i]}'
