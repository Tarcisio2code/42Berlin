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

**Solution**    
>**Create file**   
>>_$**touch** testShell00_   
>
>**List file**    
>>_$**ls -l**_   
>>_total 14_   
>>_-rw-r--r-- 1 tsilva tsilva 1 Jun  5 00:00 testShell00_   
>>_$_
>
>**Change file size**    
>>_$**truncate** -s 40 testShell00_    
>
>**Change file date and time**    
>>_$**touch** -t 202306012342 testShell00_    
>
>**Change file access mode**    
>>_$**chmod** 455 testShell00_    
>>>_Octal mode: 4 (read), 2 (write), 1(execute)_    
>>>_4 = Owner Read | 5 = Group Read + Execute | 5 = Public Read + Execute_   

**Result**    
>_$ls -l_   
>_total 14_    
>_-r--r-xr-x 1 tsilva tsilva 40 Jun  1 23:42 testShell00_    
>_$_