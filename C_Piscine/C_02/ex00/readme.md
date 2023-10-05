# 42 Berlin - C Piscine - C 02 - Exercise 00

**Subject**
> * _Reproduce the behavior of the function strcpy (man strcpy)._   
>
> * _Here’s how it should be prototyped :_   
>
>_char *ft_strcpy(char *dest, char *src);_    
>

<br>

**Libraries**        
>
>stdio.h    
>_[C file input/output](https://en.wikipedia.org/wiki/C_file_input/output)_
>
>string.h   
>_[C string library](https://en.wikibooks.org/wiki/C_Programming/string.h)_    

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
>char	*ft_strcpy(char *dest, char *src)
>```
>_This function takes two parameters:_    
>_dest: A pointer to the destination string where the copied string will be stored._    
>_src: A pointer to the source string that needs to be copied._
>
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_   
>
>**Body of the function**
>```c
>{    
>	// declare an integer index variable
>	int	i;
>
>	// initialize the index variable
>	i = 0;
>
>	// Iterate through each character of the source string until the null character is encountered.
>	while (src[i] != '\0')
>	{
>		// Copy the character from the source string to the corresponding position in the destination string
>		dest[i] = src[i];
>
>		// Increment the index
>		i++;
>	}
>
>	// Add a null character at the end of the destination string to terminate it properly.
>	dest[i] = '\0';
>
>	// Return a pointer to the destination string 
>	return (dest); 
>}    
>```
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_    
>_[Pointers to functions](https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-pointers)_   
>


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
>
>	// Declares a character array src[] and initializes it with a string.
>	char src[] = "42 Berlin";
>
>	// Declares a character array with space for 10 characters.   
>	char dest[10];
>
>	// Pass the destination and source strings to the function   
> 	ft_strcpy(dest, src);
>
>	// Prints the contents of destination string
>	printf("ft_strcpy: %s\n", dest);
>	
>	// Pass the destination and source strings to the standard C library function.
> 	strcpy(dest, src);
>
>	// Prints the contents of destination string
>	printf("strcpy...: %s\n", dest);
>}  
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_   
>_[strcpy() — Linux manual page](https://man7.org/linux/man-pages/man3/strcpy.3.html)_    

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_strcpy.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_strcpy.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_ft_strcpy: 42 Berlin_   
>_strcpy...: 42 Berlin_   
>_$_    
