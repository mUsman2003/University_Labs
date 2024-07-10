# ! / bin / bash

#	Muhammad Usman
# 	22i-0900
# 	CS-D


#-----------------------------------------------------------#
#---------------------------Task 1--------------------------#
#-----------------------------------------------------------#

echo -n "Enter Your marks : "
read v1

case "$v1" in

[8-9][0-9]|100)		echo "Grade A+";;
[7][5-9]) 			echo "Grade A";;
[7][0-4]) 			echo "Grade A-";;
[6][5-9]) 			echo "Grade B+";;
[6][0-4]) 			echo "Grade B";;
[5][5-9]) 			echo "Grade B-";;
[5][0-4]) 			echo "Grade C+";;
[4][5-9])			echo "Grade C";;
[4][0-4]) 			echo "Grade D";;
[0-9]|[1-3][0-9]) 	echo "Grade F";;

*) echo "outoff Bound" ;;
esac		

#-----------------------------------------------------------#
#---------------------------Task 2--------------------------#
#-----------------------------------------------------------#

echo -n "Enter number of rows (odd) : "
read row

ht=$(($row/2))
rem=$(($row%2))

if [ $rem -eq 0 ]
then	echo "Not a Valid Number :("

else
	i=0
	while [ $i -le $ht ]
	do
		n=0
		while [ $n -le $i ]
		do
			echo -n "* "
			n=$(($n+1))
		done
		echo ""
		i=$(($i+1))
	done

	i=$(($ht-1))
	while [ $i -ge 0 ]
	do
		n=0
		while [ $n -le $i ]
		do
			echo -n "* "
			n=$(($n+1))
		done
		echo ""
		i=$(($i-1))
	done 
fi

#-----------------------------------------------------------#
#---------------------------Task 3--------------------------#
#-----------------------------------------------------------#

v1=$1
v2=0
if [ -z $v1 ]
then
	echo "Not Possible"

else
	echo -n "Input Number : "
	echo $v1
	echo -n "Reverse order of Number : "

	while [ $v1 -gt 0 ]
	do
		v2=$((v1%10))
		v1=$((v1/10))
		echo -n $v2
	done
fi
 































