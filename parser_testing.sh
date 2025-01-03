#!/usr/bin/env bash

test_files=("test" \
	"test.rt" \
	".rt" \
	"./teste/invalid_ambient.rt" \
	"./teste/multiple_ambient.rt" \
	"./teste/invalid_camera.rt" \
	"./teste/multiple_camera.rt" \
	"./teste/invalid_light.rt" \
	"./teste/multiple_light.rt" \
	"./input/ex.rt" \
)
total=0
passed=0
failed=0
for file in ${test_files[@]}; do
	((total++))
	echo "${file}"
	if [[ ! $(./minirt "${file}") ]]; then
		((passed++))
	else
		((failed++))
	fi
done
echo "Total tests -> ${total}"
echo "Passed tests -> ${passed}"
echo "Failed tests -> ${failed}"
