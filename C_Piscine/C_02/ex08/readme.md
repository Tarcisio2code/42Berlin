# 42 Berlin - C Piscine - C 02 - Exercise 08

**Subject**
> * _Create a function that transforms every letter to uppercase._   
>
> * _Here’s how it should be prototyped :_   
>
>_char *ft_strlowcase(char *str);_    
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
>char	*ft_strlowcase(char *str)
>```  
>
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_     
>
>**Body of the function**
>```c
>{
>	// Declare an integer variable to be used as an index
>	int	i;
>
>	// Declare a character to be used for iterating through the string and storing temporary characters during the conversion.
>	char	c;
>
>	// Initialize the index variable
>	i = 0;
>
>	// Iterate through each character of the input string until the null terminator is encountered
>	while (str[i] != '\0')
>	{
>		// Check if the current character is uppercase
>		// (ASCII values 65-90, which correspond to all uppercase characters)
>		if (str[i] >= 65 && str[i] <= 90)
>		{
>			// add 32 to the character's ASCII value to convert it to uppercase
>			c = str[i] + 32;
>
>			// Update the character in the string.
>			str[i] = c;
>		}
>		//Increment the index to move to the next character in the string
>		i++;
>	}
>	// Return a pointer to the modified string, which is now in uppercase.
>	return (str);
>}    
>```
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_      
>_[Pointers to functions](https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-pointers)_   
>


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
>	// Declare a character array and initialize it to a string that contains at least one uppercase character
>	char c[] = "42 BerLiN.";
>
>	// Call the function with the string and print the result
>	printf("%s\n", ft_strlowcase(c));
>}  
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_strlowcase.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_strlowcase.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_42 berlin._     
>_$_   