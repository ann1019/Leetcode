#!/bin/bash
file="./file.txt"

format1="^\([0-9]{3}\)[[:space:]][0-9]{3}-[0-9]{4}$"
format2="^[0-9]{3}-[0-9]{3}-[0-9]{4}$"

while IFS='' read -r line || [[ -n "$line" ]];
do
	if [[ "$line" =~  $format1 || "$line" =~ $format2 ]]; then
		echo "$line"
	fi
	
done <"$file"


# Faster Solution
# https://www.cnblogs.com/grandyang/p/5389375.html
# sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
