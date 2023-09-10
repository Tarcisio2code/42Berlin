# 42 Berlin - C Piscine - Schell00 - Exercise 06


**Subject**
>  
> * _In this exercice, you will write a short shell script that lists all the existing files ignored by your GiT repository. Example:_    
>>_&> bash git_ignore.sh | cat -e_   
>>_.DS_Store$_   
>>_mywork.c~$_   
>>_&>_   
>

<br>

**Commands used**   
>
>_touch, echo, cat, git, bash_   

**Solution**    
>
>**Create file**   
>>_$ **touch** git_ignore.sh_      
>
>**Place the command lines**    
>>_$ **echo '#!/bin/sh'** > git_ignore.sh_   
>>_$ **echo 'git ls-files --others --ignored --exclude-standard'** >> git_ignore.sh_   
>
>**Print file**
>>_$ **cat** git_ignore.sh_   
>>_#!/bin/sh_   
>>_git ls-files --others --ignored --exclude-standard_   
>

**Result**   
>>_**Create test files**_   
>>>_touch .DS_Store_   
>>>_touch 'mywork.c~'_   
>>
>>_**Create gitignore file**_   
>>>_echo '.DS_Store' > .gitignore_   
>>>_echo 'mywork.c~' >> .gitignore_
>
>_$ **bash** git_ignore.sh | cat -e_   
>_.DS_Store$_    
>_mywork.c~$_    
>

**Git ls-files options**   
> 
>--others  
>_Show other (i.e. untracked) files in the output._
>
>--ignored   
>_Show only ignored files in the output._
>
>--exclude-standard   
>_Add the standard Git exclusions: .git/info/exclude, .gitignore in each directory, and the user’s global exclusion file_
>
>_https://git-scm.com/docs/git-ls-files_
