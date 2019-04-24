#! bin/bash

echo "Enter the value of n"
read n
fib1=0
fib2=1
for((x=0;x<$n;x++))
do
echo $fib1
	temp=$fib2
	fib2=$[$temp+$fib1]
	fib1=$temp
done

echo "q to quit"
read option

if [ $option == q ]
then
clear

fi



#!/bin/bash

x=1
while [[ $x != 10 ]]
do
    echo $x
    x=$(( $x + 1 ))
done




#! bin/sh

factorial ()
{

i=1
fact=1

while [ $i -le $1 ]
do 
fact=$(( $fact * $i ))
i=$(( $i + 1 ))
	
done
return $fact
}

echo "Enter the number"
read n
factorial $n  # Here $n is passed as parameter to factorial function
f=$?	      #To get back the retuen value of function called

echo $f




#! /bin/sh

echo "Enter the numbers"

read a b c

if [ $a -gt $b ] && [ $a -gt $c ]
then 
	echo $a

else 
	if [ $b -gt $c ]
	then 
		echo $b
	else
		echo $c

	fi

fi





