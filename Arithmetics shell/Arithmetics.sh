echo "1 Addition"
echo "2 Subtraction"
echo "3 Multiplication"
echo "4 Division"
echo "Enter your choice"
read a
echo "Enter the first value"
read b
echo "Enter the third value"
read c
case $a in
1)d=`expr $b + $c`
echo "The sum of digits $b and $c is $d"
;;
2)d=`expr $b - $c`
echo "The diffrence between $b and $c is $d"
;;
3)d=`expr $b \* $c`
echo "The product of $b and $c is $d"
;;
4)d=`expr $b / $c`
echo "$b divided by $c is $d"
esac