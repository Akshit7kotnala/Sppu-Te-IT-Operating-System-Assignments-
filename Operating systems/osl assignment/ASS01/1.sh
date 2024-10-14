cont=0
while [ $cont -eq 0 ] 
do
echo "Student Database"
echo "1.CREATE 2.INSERT 3.DISPLAY 4. SEARCH 5.DELETE 6.UPDATE 7. EXIT"
echo "Enter the Choice"
read choice

case $choice in 
    1) 
       if [ -f student.txt ]
       then 
            echo "File Already Present"     
       else
            touch student.txt
            echo "File Created Successfully"
       fi;;           
    2) 
       read -p "Enter the Regno:" regno
       read -p "Enter the Name:" name
       read -p "Enter the Mobile:" mobile
       echo $regno $name $mobile >> student.txt
       echo "Record Inserted Successfully";;    
    3) 
       echo "1. All records 2.Top Records 3. Bottom Records"
       read ch
       if [ $ch -eq 1 ]
       then 
            cat student.txt
       elif [ $ch -eq 2 ] 
       then 
            head -5 student.txt
       elif [ $ch -eq 3 ]
       then
            tail -5 student.txt
       fi;;
    4) 
        read -p "Enter the Regno:" regno 
        grep -w $regno student.txt > temp
        if [ -s temp ] 
        then
            echo "Record Present"
            grep -w $regno student.txt
        else
            echo "Record Not Present"
        fi;;    
    5) 
        read -p "Enter the Regno:" regno 
        grep -w $regno student.txt > temp
        if [ -s temp ] 
        then
            grep -v $regno student.txt > temp
            echo "Record Deleted"
            mv temp student.txt
        else
            echo "Record Not Present"
        fi;;
    6)  read -p "Enter the Regno:" regno 
        grep -w $regno student.txt > temp
        if [ -s temp ] 
        then
            grep -v $regno student.txt > temp
            mv temp student.txt
            read -p "Enter the Name:" name
            read -p "Enter the Mobile:" mobile
            echo $regno $name $mobile >> student.txt
            echo "Record Updated Successfully"
         else
            echo "Record Not Present"
        fi;;   
    7) exit ;;
    *) echo "Invalid Choice"
esac    
    echo "Do you Want to Continue (Press 0)"
    read cont
done
