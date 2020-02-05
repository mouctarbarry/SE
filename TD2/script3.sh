let "som=0"
for i in `seq 1 $1`
do 
let "som=som+$i"
done 
echo $som
