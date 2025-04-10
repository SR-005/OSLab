echo "Read the Limit: "
read limit
a=0
b=1
echo "$a"
echo "$b"
for((i=0;i<limit-2;i++))
do  
    c=$((a+b))
    echo "$c"
    a=$b
    b=$c
done