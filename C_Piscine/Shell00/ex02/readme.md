# 42 Berlin - C Piscine - Schell00 - Exercise 02


**Subject**
> * _ Create the following files and directories. Do what’s necessary so that when you use the ls -l command in your directory, the output will looks like this :_
>
>    _$> ls -l_   
>_Total XX_  
>_drwx--xr-x 2 XX XX XX Jun 1 20:47 test0_    
>_-rwx--xr-- 1 XX XX  4 Jun 1 21:46 test1_    
>_dr-x---r-- 2 XX XX XX Jun 1 22:45 test2_    
>_-r-----r-- 2 XX XX  1 Jun 1 23:44 test3_    
>_-rw-r----x 1 XX XX  2 Jun 1 23:43 test4_    
>_-r-----r-- 2 XX XX  1 Jun 1 23:44 test5_    
>_lrwxr-xr-x 1 XX XX  5 Jun 1 22:20 test6 -> test0_    
>_$>_   
>
> * _Once you’ve done that, run tar -cf exo2.tar * to create the file to be submitted_
>_Don’t worry about what you’ve got instead of "XX"._   
>_A year will be accepted instead of the time, on the timestamp of the
files._

<br>

**Commands used**   
>_mkdir, touch, ls, ln, truncate and chmod._   

**Solution**    
>**Create directories**   
>```diff
>mkdir test{0,2}    
>```
>
>**Create files**
>```diff   
>touch test{1,3,4}   
>```
>
>**List files**    
>```diff
>ls -l   
>```
>_$_   
>_total 8_   
>_drwxr-xr-x 2 tsilva tsilva 4096 Jun  5 09:35 test0_   
>_-rw-r--r-- 1 tsilva tsilva    0 Jun  5 09:37 test1_   
>_drwxr-xr-x 2 tsilva tsilva 4096 Jun  5 09:35 test2_   
>_-rw-r--r-- 1 tsilva tsilva    0 Jun  5 09:37 test3_   
>_-rw-r--r-- 1 tsilva tsilva    0 Jun  5 09:37 test4_   
>_$_   
>
>**Create hard link**   
>```diff
>ln test3 test5   
>```
>
>**Create symbolic link**      
>```diff
>ln -s test0 test6   
>```
>
>**Change file size**    
>```diff
>truncate -s 4 test1       
>truncate -s 1 test3    
>truncate -s 2 test4    
>```
>
>**Change file date and time**    
>```diff
>touch -t 06012047 test0   
>touch -t 06012146 test1   
>touch -t 06012245 test2   
>touch -t 06012344 test3   
>touch -t 06012343 test4   
>touch -h -t 06012220 test6    
>```
>
>**Change file access mode**    
>```diff
>chmod 715 test0   
>chmod 714 test1   
>chmod 504 test2   
>chmod 404 test3   
>chmod 641 test4   
>```

<br>

**Result**
>```diff
>ls -l   
>```
>_$_
>_total 8_   
>_drwx--xr-x 2 tsilva tsilva 4096 Jun  1 22:20 test0_   
>_-rwx--xr-- 1 tsilva tsilva    4 Jun  1 21:46 test1_   
>_dr-x---r-- 2 tsilva tsilva 4096 Jun  1 22:45 test2_   
>_-r-----r-- 2 tsilva tsilva    1 Jun  1 23:44 test3_   
>_-rw-r----x 1 tsilva tsilva    2 Jun  1 23:43 test4_   
>_-r-----r-- 2 tsilva tsilva    1 Jun  1 23:44 test5_   
>_lrwxrwxrwx 1 tsilva tsilva    5 Jun  1 22:20 test6 -> test0_       
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
>Man ln
>```    
>**-s**    
>_make symbolic links instead of hard links_
>
>```diff
>Man touch
>```    
>**-t**    
>_use [[CC]YY]MMDDhhmm[.ss] instead of current time_
>
>**-h** 
>_--no-dereference_    
>_affect  each  symbolic  link  instead of any referenced file (useful only on systems that can change the timestamps of a symlink)_    
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
>
>_**About test6 symbolic link permissions**_    
>_13.3 chmod: Change access permissions_    
>_chmod changes the access permissions of the named files. Synopsis:_    
>
>  _chmod [option]… {mode | --reference=ref_file} file…_    
>
>_***chmod never changes the permissions of symbolic links***, since the chmod system call cannot change their permissions. This is not a problem since the permissions of >symbolic links are never used. However, for each symbolic link listed on the command line, chmod changes the permissions of the pointed-to file. In contrast, chmod >ignores symbolic links encountered during recursive directory traversals._
>
>>_https://www.gnu.org/software/coreutils/manual/html_node/chmod-invocation.html_
>
