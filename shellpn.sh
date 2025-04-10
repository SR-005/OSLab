echo "Enter the Number: "
read num
if [ $num -lt 0 ]
then
    echo "The Number is Negative"
elif [ $num -gt 0 ]
then
    echo "The Number is Positive"
else
echo "The Number is Neither Positive Nor Negative"
fi
