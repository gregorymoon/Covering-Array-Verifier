#!/bin/bash/
#SBATCH -N 1
#SBATCH -n 1
#SBATCH --time=00:05:00

DIR=~/1/inputs

for entry in "$DIR"/*
do
	sbatch -N1 -n1 --time=00:05:00 --qos=test  ./run.batch "$entry" &
done

wait
