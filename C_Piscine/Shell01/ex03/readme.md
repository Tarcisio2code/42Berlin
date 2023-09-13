# 42 Berlin - C Piscine - Schell01 - Exercise 03

**Subject**
> * _Write a command line that counts and displays the number of regular files and directories in the current directory and all its sub-directories. It should include ".", the starting directory._   
> * _Example of output :_   
>_$>./count_files.sh | cat -e_   
>_42$_   
>_$>_    

<br>

**Commands used**   
>
>_touch, echo, cat, find, wc_   

<br>

**Solution**    
>
>**Create file**
>```diff 
>touch count_files.sh
>```
>
>**Place the command line**        
>```diff
>echo "find . -type f,d | wc -l" > count_files.sh
>```
>
>**Print file**
>
>```diff
>cat count_files.sh   
>```
>_$>_    
>_find . -type f,d | wc -l_   
>_$>_    
>
>**Make the script executable**   
>```diff
>chmod +x count_files.sh
>```

<br>

**Result**   
>_**Command line test**_ 
>```diff
>./count_files.sh
>```
>_$_    
>_2$_    
>_$_    

<br>

**Find options**  
>```diff
>man Find
>```
>**-type** c    
>_File is of type c:_    
>
>**f**    
>_regular file_    
>
>**d**    
>_directory_    
>
**Wc options**  
>```diff
>man wc
>```
>_DESCRIPTION_    
>_Print newline, word, and byte counts for each FILE, and  a  total  line if more than one FILE is speci‐fied._
>
>**-l, --lines**    
>_print the newline counts_
