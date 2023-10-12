# 42 Berlin - C Piscine - C 03 - Exercise 02

**Subject**
> * _Reproduce the behavior of the function strcat (man strcat)._   
>
> * _Here’s how it should be prototyped :_   
>
>_char *ft_strcat(char *dest, char *src);_    
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
>char	*ft_strcat(char *dest, char *src)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Declare a pointer (temp) and initialize it to point to the same location as the destination string (dest)
>	char	*temp;
>	temp = dest;
>
>	// Use the pointer to iterate the destination string until reaching the null terminator, positioning it at the end of the string.
>	while (*temp)
>		temp++;
>
>	// Iterate each character of the source string until the null terminator is found
>	while (*src)
>	{
>		// Copy the character from the source string to the position pointed to by temp
>		*temp = *src;
>
>		// Increment both string pointers to move to the next characters.
>		src++;
>		temp++;
>	}
>
>	// Add a null terminator at the end of the concatenated string to terminate it properly.
>	*temp = '\0';
>
>	// Return a pointer to the concatenated string after the concatenation is complete.
>	return (dest);
>}   
>```
>_The function takes two pointers to strings, (dest) and (src), and returns a pointer to the concatenated string._    
>
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_  
>
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_    
>
>_[What are pointers](https://youtu.be/2ybLD6_2gKM?si=yLpSffSRbA60G3Se)_    
>
>_[man strcat](https://man7.org/linux/man-pages/man3/strcat.3p.html)_    
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
>	// Declare a character array and initialize it with the source string
>	char src[] = "Berlin";
>
>	// Declare a character array and initialize it with the destination string
>	char dest[] = "42 ";
>
>	// Call the ft_strcat function passing both strings as parameters
>	printf("ft_strcat: %s\n", ft_strcat(dest, src));
>
>	// Declare two another character array and initialize them with the same strings as above
>	char src1[] = "Berlin";
>	char dest1[] = "42 ";
>
>	// Call the strcat function passing both strings as parameters
>	printf("strcat: %s\n", strcat(dest1, src1));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_strcat.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_strcat.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_ft_strcat: 42 Berlin_   
>_strcat: 42 Berlin_     
>_$_   
