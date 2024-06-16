#!/bin/bash


for f in *.txt
do
  echo "Processing $f file..."

  filename=$(basename "$f")

  extension="${filename##*.}"
  filename="${filename%.*}"  
  sudo touch "$filename".srt
  sudo chmod 777 "$filename".srt

  if [ ! $(pgrep srt) ]; then 

    cat "$f" | ./srt > "$filename".srt

  fi


done

