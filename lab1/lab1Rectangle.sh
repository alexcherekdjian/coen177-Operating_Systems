# Name: Alex Cherekdjian

# Date: January 8, 2019

# Title: Lab1 – task 2

# Description: This program computes the area of a circle given a radius

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

        echo "Enter height of rectangle: "

        read height

        echo "Enter width of rectangle: "

        read width

        area=`expr $height \* $width`

        echo "The area of the rectangle is $area"

 

        echo "Would you like to repeat for another rectangle [Yes/No]?"

        read response

 

done
