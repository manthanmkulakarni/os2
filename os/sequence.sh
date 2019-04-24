#! bin/sh

read i j
while [ $i != $j ]
do
mkdir manthan+$i
i=$(($i+1))
done
