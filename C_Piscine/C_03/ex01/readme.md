# 42 Berlin - C Piscine - C 03 - Exercise 01

**Subject**
> * _Reproduce the behavior of the function strncmp (man strncmp)._   
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_strncmp(char *s1, char *s2, unsigned int n);_    
>

<br>

**Libraries**        
>
>stdio.h    
>_[C file input/output](https://en.wikipedia.org/wiki/C_file_input/output)_
>
>string.h    
>_[String Library](https://en.wikibooks.org/wiki/C_Programming/string.h)_    

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
>int	ft_strncmp(char *s1, char *s2, unsigned int n)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{   
>	// Return 0 since there are no characters to compare.
>	if (n == 0)
>		return (n);
>	// Decrement n to track the remaining characters to compare.
>	n--;
>	// Start a loop that continues as long as the character at the current position in s1 is not null (indicating end of string),   
>	// *s1 matches *s2 and n is greater than zero. 
>	while (*s1 && (*s1 == *s2) && n--)  
>	{
>		// Move the pointers s1 and s2 to the next characters in their respective strings   
>		s1++;   
>		s2++;   
>	}   
>	// Returns the difference between the last characters compared (*s1 and *s2)
>	return (*s1 - *s2);   
>}   
>```
>_The function takes two pointers to strings, s1 and s2, and an unsigned integer n representing the maximum number of characters to compare. It returns an integer based on their comparison._    
>
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_  
>
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_    
>
>_[What are pointers](https://youtu.be/2ybLD6_2gKM?si=yLpSffSRbA60G3Se)_    
>
>_[man strncmp](https://www.man7.org/linux/man-pages/man3/strncmp.3.html)_    
>
>_[Difference Between Unsigned Int and Signed Int in C](https://www.geeksforgeeks.org/difference-between-unsigned-int-and-signed-int-in-c/)_    
>

<br>

**Function call**
>**Include the Library**
>```c
>#include <stdio.h>
>#include <string.h>
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
>	// Declare and initialize an integer with the maximum number of characters to compare
>	int size = 3;
>
>	// Test ft_strcmp function call
>	printf("--- ft_strncmp ---\n");
>
>	// Initializes strings with a sequence of identical characters whose length is equal to the value of the size variable
>	s1 = "Berlin";
>	s2 = "Ber lin";
>
>	// Call the function passing the strings and integer as parameters
>	printf("s1 and s2 are equal     (%d)\n", ft_strncmp(s1, s2, size));
>
>	// Assign a different character sequence to each strings
>	s1 = "abcd";
>	s2 = "abdd";
>
>	// Call the function passing the strings and integer as parameters
>	printf("s1 is less than s2      (%d)\n", ft_strncmp(s1, s2, size));
>
>	// assign the previous character sequence in reverse order to each string respectively
>	s1 = "abdd";
>	s2 = "abcd";
>
>	// Call the function passing the strings and integer as parameters
>	printf("s1 is greater than s2   (%d)\n", ft_strncmp(s1, s2, size));
>
>	// Reset the variables to the same values and pass them as parameters to the strncmp function.
>	printf("\n--- strncmp ---\n");
>	s1 = "Berlin";
>	s2 = "Ber lin";
>	printf("s1 and s2 are equal     (%d)\n", strncmp(s1, s2, size));
>
>	s1 = "abcd";
>	s2 = "abdd";
>	printf("s1 is less than s2      (%d)\n", strncmp(s1, s2, size));
>
>	s1 = "abdd";
>	s2 = "abcd";
>	printf("s1 is greater than s2   (%d)\n", strncmp(s1, s2, size));
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_strncmp.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_strncmp.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_--- ft_strcmp ---_    
>_s1 and s2 are equal     (0)_   
>_s1 is less than s2      (-1)_   
>_s1 is greater than s2   (1)_   
>    
>_--- strcmp ---_   
>_s1 and s2 are equal     (0)_   
>_s1 is less than s2      (-1)_    
>_s1 is greater than s2   (1)_     
>_$_   