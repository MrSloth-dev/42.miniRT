#!/usr/bin/env bash

# names of directories
for dir in $(find . -mindepth 1 -type d); do
	echo -n "${dir^^}DIR" | sed 's/.\///';
	echo " = ${dir}" | sed 's/\./src/'
	echo -n "${dir^^} = " | sed 's/.\///';
	for file in $(find "${dir}" -type f -name '*.c' -exec basename {} \;); do
		echo -e "\t\$(${dir^^}DIR)/$file \ " | sed 's/(\.\//(/'
	done
	echo ""
done

echo -ne "SRCS = "
for dir in $(find . -mindepth 1 -type d); do
	echo -ne "\$(${dir^^}) " | sed 's/(\.\//(/'
done
