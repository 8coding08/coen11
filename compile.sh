#!/bin/bash

echo "Type output file"
read out
echo "Type input file"
read in

gcc -o $out $in

./$out

exit
