# 42 Berlin - C Piscine - Schell00 - Exercise 01


**Subject**
> * _Create a file called testShell00 in your submission directory._
>
> * _Figure out a way for the output to look like this (except for the “total 1” line):_
>
>    _$> ls -l_   
>_Total 1_  
>_-r--r-xr-x 1 XX XX 40 Jun 1 23:42 testShell00_    
>_$>_   
>
> * _Once you’ve achieved the previous steps, execute the following command to create
the file to be submitted: tar -cf testShell00.tar testShell00._
>

<br>

**Commands used**   
>_touch, ls, truncate, chmod_   

<br>

**Solution**    
>**Create file**
>```diff 
>touch testShell00   
>```
>
>**List file**    
>```diff 
>ls -l   
>```
>_total 14_   
>_-rw-r--r-- 1 tsilva tsilva 1 Jun  5 00:00 testShell00_   
>_$_
>
>**Change file size**    
>```diff 
>truncate -s 40 testShell00    
>``` 
>
>**Change file date and time**    
>```diff 
>touch -t 202306012342 testShell00    
>```
>
>**Change file access mode**    
>```diff 
>chmod 455 testShell00    
>```

<br>

**Result** 
>```diff 
>ls -l
>```   
>_$_    
>_total 14_    
>_-r--r-xr-x 1 tsilva tsilva 40 Jun  1 23:42 testShell00_    
>_$_

<br>

**Command options**
>```diff
>Man ls
>```    
>**-l**    
>_use a long listing format_
>
>```diff
>Man touch
>```    
>**-t**    
>_use [[CC]YY]MMDDhhmm[.ss] instead of current time_
>```diff
>Man truncate
>```    
>**-s**    
>_set or adjust the file size by SIZE bytes_
>
>```diff
>Man chmod
>```
>_Octal mode: 4 (read), 2 (write), 1(execute)_    
>_4 = Owner Read | 5 = Group Read + Execute | 5 = Public Read + Execute_ 
