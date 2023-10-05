# 42 Berlin - C Piscine - C 02 - Exercise 03

**Subject**
> * _Create a function that returns 1 if the string given as a parameter contains only digits, and 0 if it contains any other character._   
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_str_is_numeric(char *str);_    
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
>int	ft_str_is_numeric(char *str)
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
>	// Declare an integer to tracking whether the characters are numeric (1) or not (0), respectively.
>	int	digit;
>
>	// Initialize the index variable
>	i = 0;
>
>	// Initialize digit to 1, assuming the string is numeric until proven otherwise or empty
>	digit = 1;
>
>	// Iterate through each character of the input string until the null terminator is encountered
>
>	while (str[i] != '\0')
>	{
>
>		// Check if the current character is not a numeric character
>		// (ASCII values 48-57, which correspond to the digits '0' to '9')
>		if (!(str[i] >= 48 && str[i] <= 57))
>		{
>			// Set digit to 0 (indicating the string is not numeric)
>			digit = 0;
>
>			// Break out of the loop
>			break ;
>		}
>
>		//Increment the index
>		i++;
>	}
>
>	// Return the value of digit
>	return (digit);
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
>	// Declares a character array and initializes it with an numeric string
>	char digits[] = "42";
>
>	// Declares a character array and initializes it with to a non-numeric string
>	char not_digits[] = "berlin";
>
>	// Declares a character array and initializes it to an empty string
>	char empty[] = "";
>
>	// Call the function with the numeric string and print the result
>	printf("%d\n", ft_str_is_numeric(not_digits));
>
>	// Call the function with the non-numeric string and print the result
>	printf("%d\n", ft_str_is_numeric(not_digits));
>
>	// Call the function with the empty string and print the result
>	printf("%d\n", ft_str_is_numeric(empty));
>}  
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_str_is_numeric.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_str_is_numeric.c
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
