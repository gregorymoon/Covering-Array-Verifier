#!/bin/bash/

DIR=../1/inputs

for entry in "$DIR"/*
do
	sh ./serial_verify "$entry"
done

wait
