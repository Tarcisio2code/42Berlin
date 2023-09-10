# 42 Berlin - C Piscine - Schell00 - Exercise 04


**Subject**
>  
> * _In a midLS file, place the command line that will list all files and directories in your
current directory (except for hidden files or any file that starts by a dot - yes, that
includes double-dots), separated by a comma, by order of creation date. Make sure
directories names are followed by a slash character._
>
>_The file's name was not chosen randomly._   
>_Make sure you understand the difference between the public key and Ithe private key._

<br>

**Commands used**   
>
>_touch, mkdir, ls_   

<br>

**Solution**    
>
>**Create files**
>```diff   
>touch midLS   
>```
>_only for tests_    
>_$ touch test2_    
>_$ mkdir test3_    
>_$ touch test4_    
>
>**List Files**   
>```diff
>ls -l
>```   
>_$_    
>_total 8_   
>_-rw-r--r-- 1 tsilva tsilva    8 Sep  7 15:36 midLS_  
>_-rw-r--r-- 1 tsilva tsilva    0 Sep  7 15:55 test2_  
>_drwxr-xr-x 2 tsilva tsilva 4096 Sep  7 15:56 test3_  
>_-rw-r--r-- 1 tsilva tsilva    0 Sep  7 15:57 test4_  
>_$_ 
>
>**Place the command line**    
>```diff
>echo ls -mtp > midLS   
>```

<br>

**Result**   
>_$_    
>_ls -mtp_   
>_test4, test3/, test2, midLS_    
>_$_   

<br>

**ls options**
>```diff
>man ls
>```
>_**-m** &ensp;fill width with a comma separated list of entries_   
>_**-t** &ensp; sort by time, newest first; see --time_   
>_**-p** &ensp;--indicator-style=slash append / indicator to directories_
