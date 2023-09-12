# 42 Berlin - C Piscine - Schell01 - Exercise 01

**Subject**
> * _Write a command line that will display the list of groups for which the login, contained in the environment variable FT_USER , is a member. Separated by commas without spaces._    
> * _Examples :_    
>    * _for FT_USER=nours, the result is "god,root,admin,master,nours,bocal" (without quotation marks)_    
>_$>./print_groups.sh_    
>_god,root,admin,master,nours,bocal$>_    
>    * _for FT_USER=daemon, the result is "daemon,bin" (without quotation marks)_    
>_$>./print_groups.sh_
>_daemon,bin$>_

<br>

**Commands used**   
>
>_touch, echo, cat, export, id, td_   

<br>

**Solution**    
>
>**Create file**
>```diff 
>touch print_groups.sh
>```
>
>**Place the command line**        
>```diff
>echo "id -G -n \$FT_USER | tr ' ' ',' | tr -d '\n'" > print_groups.sh
>```
>
>**Print file**
>
>```diff
>cat print_groups.sh   
>```
>_$>_    
>_id -G -n $FT_USER | tr ' ' ',' | tr -d '\n'_   
>_$>_

<br>

**Result**   
>_**Set variable**_   
>```diff
>export FT_USER=nours
>```
>_or_    
>```diff
>export FT_USER=daemon
>```
>
>_**Command line test**_ 
>```diff
>./print_groups.sh
>```

<br>

**Id options**  
>```diff
>man Id
>```
>**-G, --groups**
>_print all group IDs_
>
>**-n, --name**
_print a name instead of a number, for -ugG_

**tr options**  
>```diff
>man tr
>```
>**-d, --delete**    
>_delete characters in SET1, do not translate_
>
>**\n**    
>_new line_

