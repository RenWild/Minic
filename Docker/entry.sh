#!/bin/bash

echo "HELLO ! this is Minic OpenBench client docker"
echo "\$1 shall be your username"
echo "\$2 shall be your password"
echo "\$3 shall be your available number of threads"
echo 42 > machine.txt
echo "*************************************"
ls
echo "*************************************"
python3 OpenBench.py -U $1 -P $2 -S http://serv.x-ray.fr:8000 -T $3
