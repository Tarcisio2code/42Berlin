# 42 Berlin - C Piscine - Schell00 - Exercise 05


**Subject**
>  
> * _Create a shell script that displays the ids of the last 5 commits of your git repository._
>>_&> bash **git_commit.sh** | cat -e_   
>>_baa23b54f0adb7bf42623d6d0a6ed4587e11412a$_   
>>_2f52d74b1387fa80eea844969e8dc5483b531ac1$_   
>>_905f53d98656771334f53f59bb984fc29774701f$_   
>>_5ddc8474f4f15b3fcb72d08fcb333e19c3a27078$_   
>>_e94d0b448c03ec633f16d84d63beaef9ae7e7be8$_   
>>_&>_

>

<br>

**Commands used**   
>
>_touch, echo, cat, git,_   

**Solution**    
>
>**Create file**   
>>_$ **touch** git_commit.sh_      
>
>**Place the command lines**    
>>_$ **echo '#!/bin/sh'** > git_commit.sh_  
>>_$ **echo 'git log --format="%H" -n5'** >> git_commit.sh_   
>
>**Print file**
>>_$ cat git_commit.sh_   
>>_#!/bin/sh_   
>>_git log --format="%H" -n5_   

**Result**   
>_$ bash git_commit.sh | cat -e_   
>_1a1978037379b787960e9aa058d78d8614b1337b$_   
>_44cf3b21442b5ad341ef136ad84bf42082402e3d$_   
>_1df56ce479b4d2114765a70a2665f9f150fca12c$_   
>_8237afb3f5673b19885123cb0a38128b19927add$_   
>_d29332211fa707f7bfcb612ab687f5ce280bc901$_    
 

**Git log options**   
>_**--format**_    
>_Pretty-print the contents of the commit logs in a given format, where <format> can be one of oneline,_
>_short, medium, full, fuller, reference, email, raw, **format:string** and tformat:<string>._
>
>_%H : commit hash_
>
>_https://git-scm.com/docs/git-log_
