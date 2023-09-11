# 42 Berlin - C Piscine - Schell00 - Exercise 06


**Subject**
>  
> * _In this exercice, you will write a short shell script that lists all the existing files ignored by your GiT repository. Example:_    
>_&> bash git_ignore.sh | cat -e_   
>_.DS_Store$_   
>_mywork.c~$_   
>_&>_   
>

<br>

**Commands used**   
>
>_touch, echo, cat, git, bash_   

<br>

**Solution**    
>
>**Create file**   
>```diff
>touch git_ignore.sh      
>```
>
>**Place the command lines**    
>```diff
>echo '#!/bin/sh' > git_ignore.sh   
>echo 'git ls-files --others --ignored --exclude-standard' >> git_ignore.sh   
>```
>
>**Print file**
>```diff
>cat git_ignore.sh   
>```
>_#!/bin/sh_   
>_git ls-files --others --ignored --exclude-standard_   
>

<br>

**Result**   
>_**Create test files**_   
>```diff
>touch .DS_Store   
>touch 'mywork.c~'
>```
>
>_**Create gitignore file**_   
>```diff
>echo '.DS_Store' > .gitignore   
>echo 'mywork.c~' >> .gitignore
>```
>
>_**Command line test**_
>```diff
>bash git_ignore.sh | cat -e   
>```
>_.DS_Store$_    
>_mywork.c~$_    
>

<br>

**Git ls-files options**   
> 
>**--others**  
>_Show other (i.e. untracked) files in the output._
>
>**--ignored**   
>_Show only ignored files in the output._
>
>**--exclude-standard**   
>_Add the standard Git exclusions: .git/info/exclude, .gitignore in each directory, and the user’s global exclusion file_
>
>_https://git-scm.com/docs/git-ls-files_
