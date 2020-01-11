# Name: Alex Cherekdjian

# Date: January 8, 2019

# Title: Lab1 – task 1

# Description: This program computes the area of a rectangle given a height and width.

echo Executing $0

echo $(/bin/ls | wc -l) files

wc -l $(/bin/ls)

echo Executing $0

echo "HOME="$HOME

echo "USER="$USER

echo "PATH="$PATH

echo "PWD="$PWD

echo "\$\$"=$$

user='acherekd'

numusers=`who | wc -l`

echo "Hi $user! There are $numusers users logged on."

if [ $user = "acherekd" ]

then

        echo "Now you can proceed!"

else

        echo "Check who logged in!"

        exit 1

fi


response="Yes"


while [ $response != "No" ] 

do

        echo "Enter radius: "

        read radius

		pi=3.14159265
        area=`echo $pi \* $radius \* $radius | bc -l`

        echo "The area of the circle is $area"

 

        echo "Would you like to repeat for another circle [Yes/No]?"

        read response

 

done
