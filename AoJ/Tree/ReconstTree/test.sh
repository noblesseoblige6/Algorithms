#!/bin/sh
echo 41 > test.txt
for i in {1..41}
do
  echo $i >> test.txt;
done
for i in {1..41}
do
  echo $i >> test.txt;
done
