echo "Enter the first number"
read a
echo "Enter the second number"
read b
echo "Enter the third number"
read c
if test $a -ge $b -a $a -ge $c
then 
echo "First number $a is the largest"
elif test $b -ge $a -a $b -ge $c
then 
echo "Second number $b is the largest"
else
echo "Third number $c is the largest"
fi