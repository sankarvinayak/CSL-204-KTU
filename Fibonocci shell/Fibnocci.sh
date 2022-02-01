echo "Enter how many number of elements the series need to be printed"
read n
a=-1
b=1
i=1;
while [ "$i" -le "$n" ]
do
t=`expr $a + $b`
echo $t
a=$b
b=$t
i=`expr $i + 1`
done
