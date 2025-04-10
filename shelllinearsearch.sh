echo "Enter the Size of the Array: "
read size
for((i=0;i<size;i++))
do
    echo "Enter the Number: "
    read a[i]
done

echo "Enter the Search String: "
read search
count=0
for((i=0;i<size;i++))
do
    if [ ${a[$i]} == $search ]
    then
        count=1
        break
    fi
done

if [ $count == 1 ]
then 
    echo "Element Found at $i"
else
    echo "Element Not Found"
fi