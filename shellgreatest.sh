echo "Enter the Number A: "
read a
echo "Enter the Number  B: "
read b
echo "Enter the Number C: "
read c
if [ $a -gt $b ]
then
    if [ $a -gt $c ]
    then
        echo "A is the Greatest"
    fi
fi

if [ $b -gt $a ]
then
    if [ $b -gt $c ]
    then
        echo "B is the Greatest"
    else
        echo "C is the Greatest"
    fi
fi