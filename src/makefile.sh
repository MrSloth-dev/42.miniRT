#!/usr/bin/env bash

# names of directories
for dir in $(find . -mindepth 1 -type d); do
	echo -n ${dir^^} | sed 's/.\///';
	echo " = ${dir}" | sed 's/\./src/'
	for file in $(find "${dir}" -type f -name '*.c' -exec basename {} \;); do
		echo -e "\t\$(${dir^^})/$file \ " | sed 's/(\.\//(/'
	done
	echo ""
done
