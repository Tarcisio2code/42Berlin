# 42 Berlin - C Piscine - C 03 - Exercise 04

**Subject**
> * _Create a function that counts and returns the number of characters in a string._   
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_strlen(char *str);_    
>

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
>int	ft_strlen(char *str)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Declare an integer (count) to be used to count the characters in the string.
>	int	count;
>
>	// Initialize the integer with 0 which represents the beginning of the string 
>	count = 0;
>
>	// Start a loop that iterates through each character of the input string (str) until the null terminator is encountered.
>	while (str[count])
>		// Increment the count variable to move to the next character pointed to by the pointer (str)
>		count++;
>
>	// Return the final value of (count), which represents the length of the string (excluding the null terminator).
>	return (count);
>}   
>```
>_The function takes a pointer to a string (str) and returns an integer representing the length of the string._    
>
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_  
>
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_    
>
>_[What are pointers](https://youtu.be/2ybLD6_2gKM?si=yLpSffSRbA60G3Se)_    
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
>
>	// Declare a pointer using the dereference operator(*) and initialize it with a sequence of characters to be counted
>	char *str;
>	str = "42Berlin is an excellent place to learn :)";
>
>	// Call the ft_strlen function and pass (str) as parameter 
>	printf("number of char = %d\n", ft_strlen(str));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_strlen.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_strlen.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_number of char = 42_   
>_$_   