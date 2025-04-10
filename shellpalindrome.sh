echo "Enter a String: "
read str
rev="$( rev<<< "$str" )"
if [ $rev == $str ]
then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi