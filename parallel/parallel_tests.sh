#!/bin/bash/

DIR=../1/inputs

for entry in "$DIR"/*
do
	sh ./parallel_verify "$entry"
done

wait
