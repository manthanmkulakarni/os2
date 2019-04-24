read a b
echo "enter the operator"
read c
case $c in
"+") echo $(($a+$b));;
"-") echo $(($a-$b));;
"*") echo $(($a*$b));;
esac
