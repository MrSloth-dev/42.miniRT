#!/usr/bin/env bash

# names of directories -mindepth 1 for not including . and ..
for dir in $(find . -mindepth 1 -type d); do
	echo -n "${dir^^}DIR" | sed 's/.\///';
	echo " = ${dir}" | sed 's/\./src/'
	echo -n "${dir^^} = " | sed 's/.\///';
	#fils in each directory
	for file in $(find "${dir}" -type f -name '*.c' -exec basename {} \;); do
		echo -e "\t\$(${dir^^}DIR)/$file \ " | sed 's/(\.\//(/'
	done
	echo ""
done

echo -ne "SRCS = "
for dir in $(find . -mindepth 1 -type d); do
	echo -ne "\$(${dir^^}) " | sed 's/(\.\//(/'
done
