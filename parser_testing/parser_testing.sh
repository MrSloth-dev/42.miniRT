#!/usr/bin/env bash

CLR_RMV="\e[0m"
RED="\e[1;31m"
GREEN="\e[1;32m"
YELLOW="\e[1;33m"
BLUE="\e[1;34m"
CYAN="\e[1;36m"

set -uo pipefail
trap 'rm -f ./gmon.out' EXIT

script_dir=$(dirname "$(realpath $0)")
invalid_dir="${script_dir}"/invalid

bin="/home/mrsloth/CommonCore/4.miniRT/miniRT"
if [[ ! -e "${bin}" ]]; then
	echo "${bin}"
	echo "No binary found"
	exit 1
fi

## These tests should fail
total=0
passed=0
failed=0
for file in $(find "$invalid_dir" -type f); do
		((total++))
		echo -e "Test ${total} :'${file}'"
		std_err=$(${bin} "${file}" 2>&1)
		exit_code=$?
		if [[ $exit_code -eq 0 ]]; then
			echo -e "${RED} ${std_err} ${CLR_RMV}"
			((failed++))
		else
			((passed++))
			echo -e "${GREEN} ${std_err} ${CLR_RMV}"
		fi
done
echo "Total tests -> ${total}"
echo "Passed tests -> ${passed}"
echo "Failed tests -> ${failed}"
if [[ ${passed} -eq ${total} ]]; then
	echo "All tests Passed!"
fi

