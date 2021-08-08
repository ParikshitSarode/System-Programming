#!/bin/bash

echo "Enter a number"
read num
res=1
#variable to store result 
while [[ num -gt 1 ]]
do
	res=$((num*$res))   #factorial computing
	num=$((num-=1))		#decrementing num
done
echo $res	#printing factorial