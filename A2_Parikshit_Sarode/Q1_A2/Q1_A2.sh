#!/bin/bash
time=$(date +"%H")
#echo $time

if [[ $time -ge 17 ]]; then
	echo "Good Evening"
elif [[ $time -ge 12 ]]; then
	echo "Good Afternoon"
elif [[ $time -ge 0 ]]; then
	echo "Good Morning"
fi