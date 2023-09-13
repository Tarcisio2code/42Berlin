# 42 Berlin - C Piscine - Schell01 - Exercise 05

**Subject**
> * _Create a file containing only "42", and NOTHING else._   
>
> * _Its name will be :_   
>"\\?$\*'MaRViN'\*$?\\"
>
> * _Example :_   
>$>ls -lRa \*MaRV\* | cat -e    
>-rw---xr-- 1 75355 32015 2 Oct 2 12:21 "\\?$\*'MaRViN'\*$?\\"$    
>$>

<br>

**Commands used**   
>
>_touch, echo, cat, ls_   

<br>

**Solution**    
>
>**Create file**
>```diff 
>touch \"\\\?\$\*\'MaRViN\'\*\$\?\\\"
>```
>
>**populate file**        
>```diff
>echo "42" > '"\?$*'\''MaRViN'\''*$?\"'
>```
>
>**Print file**
>```diff
>cat '"\?$*'\''MaRViN'\''*$?\"'
>```
>_$>_    
>_42_   
>_$>_    
>
>**Change file permissions**
>```diff
>chmod 614 '"\?$*'\''MaRViN'\''*$?\"'
>```
>
>**Change file size**
>```diff
>truncate -s 2 '"\?$*'\''MaRViN'\''*$?\"'
>```
>
>**Change file date and time**
>```diff
>touch -t 202310021221 '"\?$*'\''MaRViN'\''*$?\"'
>```

<br>

**Result**   
>_**Command line test**_ 
>```diff
>ls -lRa *MaRV* | cat -e
>```
>_$_    
>_-rw---xr-- 1 tsilva tsilva 2 Oct  2  2023 "\\?$\*'MaRViN'\*$?\\"$_    
>_$_    

<br>

**ls options**  
>```diff
>man ls
>```
>**-l**    
>_use a long listing format._    
>
>**-R, --recursive**    
>_list subdirectories recursively._    
>
>**-a, --all**    
>_do not ignore entries starting with_
