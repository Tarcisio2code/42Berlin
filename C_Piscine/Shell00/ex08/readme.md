# 42 Berlin - C Piscine - Schell00 - Exercise 08

**Subject**
>  
> * _In a file called clean place the command line that will search for all files - in the current directory as well as in its sub-directories - with a name ending by ~, or a name that start and end by #._   
> * _The command line will show and erase all files found._   
> * _Only one command is allowed: no ’;’ or ’&&’ or other shenanigans._   
>

<br>

**Commands used**   
>
>_touch, echo, cat, mkdir, find_   

<br>

**Solution**    
>
>**Create file**
>```diff 
>touch clean
>```
>
>**Place the command line**        
>```diff
>echo 'find . -type f \( -name '\'#*#\'' -o -name '\'*~\'' \) -print -delete' > clean   
>```
>
>**Print file**
>
>```diff
>cat clean   
>```
>_find . -type f \( -name '#*#' -o -name '*~' \) -print -delete_   
>

<br>

**Result**   
>_**Create test files**_   
>```diff
>touch '#test1#'_   
>mkdir -p tests && touch tests/'test~'   
>```
>
>_**List test files**_   
>```diff
>find   
>```
>_._   
>_./tests   
>_./tests/test~   
>_./#test1#   
>
>_**Command line test**_ 
>```diff
>find . -type f \( -name '#*#' -o -name '*~' \) -print -delete   
>```
>_./tests/test~_   
>_./#test1#_   
>
>_**Check if files are deleted**_    
>_find_   
>_._   
>_./tests   

<br>

**Find options**   
>```diff
>man find    
>```
>**-type** c    
>_File is of type c:_    
>
>**f**    
>_regular file_    
>
>**-name**   
>_This option is supported, but POSIX  conformance  depends  on  the POSIX conformance of the system's  fnmatch(3) library  function. As  of findutils-4.2.2, shell metacharacters (`*', `?' or `[]' for example) match a leading `.',  because  IEEE PASC interpretation 126 requires this. This is a change  from previous versions of findutils._
>   
>-**print**   
>_True;  print the full file name on the standard output, followed by a newline._   
>
>**-delete**   
>_Delete files; true if removal succeeded._

