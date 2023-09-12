# 42 Berlin - C Piscine - Schell01 - Exercise 02

**Subject**
> * _ Write a command line that searches for all file names that end with ".sh" (without quotation marks) in the current directory and all its sub-directories. It should display only the file names without the .sh._    
> * _Examples of output :_     
>_$>./find_sh.sh | cat -e_        
>_find_sh$_    
>_file1$_    
>_file2$_    
>_file3$_    
>_$>_    

<br>

**Commands used**   
>
>_touch, echo, cat, chmod, find, basename, cut_   

<br>

**Solution**    
>
>**Create file**
>```diff 
>touch find_sh.sh
>```
>
>**Place the command line**        
>```diff
>echo "find . -type f -name '*sh' -exec basename {} \\; | cut -f 1 -d '.'" > find_sh.sh
>```
>
>**Print file**
>
>```diff
>cat find_sh.sh   
>```
>_$>_    
>_find . -type f -name '*sh' -exec basename {} \\\; | cut -f 1 -d '.'_   
>_$>_    
>
>**Make the script executable**   
>```diff
>chmod +x find_sh.sh
>```

<br>

**Result**   
>_**Create test files**_   
>```diff
>touch file{1,2,3}.sh
>```
>
>_**Command line test**_ 
>```diff
>./find_sh.sh
>```
>_$_    
>_find_sh$_    
>_file2$_    
>_file1$_    
>_file3$_    
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
>**-name**   
>_This option is supported, but POSIX  conformance  depends  on  the POSIX conformance of the system's  fnmatch(3) library  function. As  of findutils-4.2.2, shell metacharacters (`*', `?' or `[]' for example) match a leading `.',  because  IEEE PASC interpretation 126 requires this. This is a change  from previous versions of findutils._
>
>**-exec command {}**    
>_This variant of the -exec  action  runs  the specified command on the selected files_
>
**Basename**  
>```diff
>man basename
>```
>_DESCRIPTION_    
>_Print NAME with any  leading  directory  components removed.  If specified, also remove a trailing SUF‐FIX._
>
**Cut options**  
>```diff
>man cut
>```
>**-f, --fields=LIST**    
>_select only these fields;   also  print  any line  that  contains no delimiter character, unless the -s option is specified_
>
>**-d, --delimiter=DELIM**    
>_use DELIM instead of TAB for field delimiter_