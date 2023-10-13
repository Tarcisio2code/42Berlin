# 42 Berlin - C Piscine - C 03 - Exercise 04

**Subject**
> * _Reproduce the behavior of the function strstr (man strstr)._   
>
> * _Here’s how it should be prototyped :_   
>
>_char *ft_strstr(char *str, char *to_find);_    
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
>char	*ft_strstr(char *str, char *to_find)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Declare an integer to keep track of the position in (to_find)
>	int	pos;
>
>	// Returns the string pointed to by pointer (str) if (to_find) is empty
>	if (!*to_find)
>		return (str);
>
>	// Initialize the integer to 0
>	pos = 0;
>
>	// Iterate each character of the string pointed to by pointer (str) until the null terminator is found
>	while (*str)
>	{
>		// So the comparison if the current character in (to_find) matches the current character in (str)
>		if (*to_find == *str)
>		{
>			// Increment the pointer (to_find) to move to the next character to be compared
>			to_find++;
>
>			// If the next character in the string pointed to by (to_find) is a null terminator 
>			if (*to_find == '\0')
>				// Return the character sequence in (str) from the current position minus (pos)
>				return (str - pos);
>
>			// If there is a mismatch in characters
>			if (*to_find != str[1])
>			{
>				// Reset the (to_find) pointer back to the original position
>				to_find = to_find - pos;
>
>				// Reset (pos) to 0
>				pos = 0;
>			}
>			// Increment (pos)
>			pos++;
>		}
>		// Move the (str) pointer to the next character for the next iteration.
>		str++;
>	}
>	// If the loop ends and the substring is not found, return NULL 
>	// indicating that (to_find) does not exist in (str).
>	return (0);
>}   
>```
>_The function takes two pointers to strings, (str) and (to_find), and returns a pointer to the first occurrence of (to_find) within (str) or NULL if (to_find) is not found._    
>
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_  
>
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_    
>
>_[What are pointers](https://youtu.be/2ybLD6_2gKM?si=yLpSffSRbA60G3Se)_    
>
>_[man strstr](https://man7.org/linux/man-pages/man3/strncat.3p.html)_    
>
>_[Pointers to functions](https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-pointers)_       
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
>	// Declare a pointer using the dereference operator(*) and initialize it to a sequence of characters
>	char *str = "42BeBerlin";
>
>	// Declare a pointer using the dereference operator(*) and initialize it with the sequence of characters to be found
>	char *to_find = "Ber";
>
>	// Call ft_strstr and strstr function and pass them (str) and (to_find) as parameters to compare the result of both functions   
>
>	// Testing functions when (to_find) exists in (str)
>	printf("test 01\n");
>	printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
>	printf("strstr      : %s\n", strstr( str, to_find));
>
>	// Testing functions when (to_find) does not exist in (str)
>	printf("\ntest 02\n");
>	to_find = "ber";
>	printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
>	printf("strstr      : %s\n", strstr( str, to_find));
>
>	// Testing functions when (to_find) is NULL
>	printf("\ntest 03\n");
>	to_find = "";
>	printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
>	printf("strstr      : %s\n", strstr( str, to_find));
>
>	// Testing functions when (to_find) is empty
>	printf("\ntest 04\n");
>	to_find = " ";
>	printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
>	printf("strstr      : %s\n", strstr( str, to_find));
>
>	// Testing functions when (str) and (to_find) are empty
>	printf("\ntest 05\n");
>	str = "";
>	to_find = "";
>	printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
>	printf("strstr      : %s\n", strstr( str, to_find));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_strstr.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_strstr.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_test 01_   
>_ft_strstr   : Berlin_   
>_strstr      : Berlin_   
>
>_test 02_   
>_ft_strstr   : (null)_   
>_strstr      : (null)_   
>
>_test 03_   
>_ft_strstr   : 42BeBerlin_   
>_strstr      : 42BeBerlin_   
>
>_test 04_   
>_ft_strstr   : (null)_   
>_strstr      : (null)_   
>
>_test 05_   
>_ft_strstr   :_   
>_strstr      :_     
>_$_   