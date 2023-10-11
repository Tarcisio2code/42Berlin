# 42 Berlin - C Piscine - C 03 - Exercise 00

**Subject**
> * _Reproduce the behavior of the function strcmp (man strcmp)._   
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_strcmp(char *s1, char *s2);_    
>
> * _It should return str._

<br>

**Libraries**        
>
>stdio.h    
>_[C file input/output](https://en.wikipedia.org/wiki/C_file_input/output)_
>

**Used functions**   
>
>printf   
>_[Printf in C](https://www.geeksforgeeks.org/printf-in-c/)_    

**Statements**
>
>while    
>_[While loop in C](https://www.geeksforgeeks.org/c-while-loop/?ref=lbp)_

<br>

**Main steps**
>
>**Prototype function**
>```c
>int	ft_strcmp(char *s1, char *s2)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{   
>	// Start a loop that continues as long as the character at the current position in s1 is not null (indicating end of string)   
>	// and *s1 matches *s2.   
>	while (*s1 && (*s1 == *s2))   
>	{
>		// Move the pointers s1 and s2 to the next characters in their respective strings   
>		s1++;   
>		s2++;   
>	}   
>	// Returns the difference between the last characters compared (*s1 and *s2)
>	return (*s1 - *s2);   
>}   
>```
>_The function takes two pointers to strings, s1 and s2, and returns an integer based on their comparison._    
>
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_  
>
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_    
>
>_[What are pointers](https://youtu.be/2ybLD6_2gKM?si=yLpSffSRbA60G3Se)_    
>
>_[man strcmp](https://www.man7.org/linux/man-pages/man3/strcmp.3.html)_    
>

<br>

**Function call**
>**Include the Library**
>```c
>#include <stdio.h>
>```
>_[Using the library](https://www.gnu.org/software/libc/manual/html_mono/libc.html#Using-the-Library)_
>
>**Create the main function**
>```c
>int main(void)
>{   
>	// Declare two pointers to strings    
>	char *s1;
>	char *s2;
>
>	// Initializes both strings to a sequence of identical characters
>	s1 = "Berlin";
>	s2 = "Berlin";
>
>	// Call the function passing both strings as parameters
>	printf("s1 and s2 are equal (%d)\n", ft_strcmp(s1, s2));
>
>	// Assign a different character sequence to each string
>	s1 = "Berlin a";
>	s2 = "Berlin b";
>
>	// Call the function passing both strings as parameters
>	printf("s1 is less than s2 (%d)\n", ft_strcmp(s1, s2));
>
>	// assign the previous character sequence in reverse order to each string respectively
>	s1 = "Berlin b";
>	s2 = "Berlin a";
>	
>	// Call the function passing both strings as parameters
>	printf("s1 is greater than s2 (%d)\n", ft_strcmp(s1, s2));
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_strcmp.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_strcmp.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_s1 and s2 are equal (0)_   
>_s1 is less than s2 (-1)_   
>_s1 is greater than s2 (1)_     
>_$_   