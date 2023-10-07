# 42 Berlin - C Piscine - C 02 - Exercise 06

**Subject**
> * _Create a function that returns 1 if the string given as a parameter contains only printable characters, and 0 if it contains any other character._   
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_str_is_printable(char *str);_    
>
> * _It should return 1 if str is empty._

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
>int	ft_str_is_printable(char *str)
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
>	// Declare an integer to tracking whether the characters are printable (1) or not (0), respectively.
>	int	is_print;
>
>	// Initialize the index variable
>	i = 0;
>
>	// Initialize is_print to 1, assuming the string is printable until proven otherwise or empty
>	is_print = 1;
>
>	// Iterate through each character of the input string until the null terminator is encountered
>	while (str[i] != '\0')
>	{
>		// Check if the current character is not printable
>		// (ASCII values 32-126, which correspond to all printables characters)
>		if (!(str[i] >= 32 && str[i] <= 126))
>		{
>			// Set is_print to 0 (indicating that the string is not printable)
>			is_print = 0;
>
>			// Break out of the loop
>			break ;
>		}
>		//Increment the index
>		i++;
>	}
>	// Return the value of is_print
>	return (is_print);
>}    
>```
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_      
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
>	// Declares a character array and initializes it to a printable string
>	char printable[] = " !'/2<?T[^`t{~";
>
>	// Declares a character array and initializes it to a non-printable string
>	char not_printable[] = "!'/2<?T[^`t{~\1F";
>
>	// Declares a character array and initializes it to an empty string
>	char empty[] = "";
>
>	// Call the function with the printable string and print the result
>	printf("%d\n", ft_str_is_printable(printable));
>
>	// Call the function with the non-printable string and print the result
>	printf("%d\n", ft_str_is_printable(not_printable));
>
>	// Call the function with the empty string and print the result
>	printf("%d\n", ft_str_is_printable(empty));
>}  
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_str_is_printable.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_str_is_printable.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_1_   
>_0_   
>_1_   
>_$_   
