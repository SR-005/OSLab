echo "Enter a Number: "
read num
fact=1
i=1
while (( i <= num ))
do
    fact=$((fact *i))
    i=$((i +1))
done
echo "$fact"