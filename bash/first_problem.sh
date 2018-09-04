#!/bin/bash

set 12 13 14
echo "args are: $1, $2 and $3"
shift
echo "args are: $1, $2 and $3"

for j
do
  echo $j
done
echo "----------"
count=1
for i in 5 1 4 2
do
  echo $i
  for j
  do
    echo "j is $j and $i is $i"
  done
done
echo "Done"

