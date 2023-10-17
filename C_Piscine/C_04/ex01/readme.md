# 42 Berlin - C Piscine - C 04 - Exercise 01

**Subject**
> * _Create a function that displays a string of characters on the standard output._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_putstr(char *str);_    
>

<br>

**Libraries**        
>
>unistd.h    
>_[The Unistd.h library](https://en.wikipedia.org/wiki/Unistd.h)_    

**Used functions**   
>
>write   
>_[Write - Linux manual page](https://www.man7.org/linux/man-pages/man2/write.2.html)_    

**Statements**
>
>while    
>_[While loop in C](https://www.geeksforgeeks.org/c-while-loop/?ref=lbp)_

<br>

**Main steps**
>
>**Include the Library**
>```c
>#include <unistd.h>
>```
>_[Using the library](https://www.gnu.org/software/libc/manual/html_mono/libc.html#Using-the-Library)_
>
>**Prototype function**
>```c
>void	ft_putstr(char *str)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Iterate through each character of the input string (str) until the null terminator is encountered.
>	while (*str)
>	{
>		// Use the write system call to write the current character (pointed to by str)
>		// the first parameter is the file descriptor for standard output (1)
>		// the last parameter indicates writing 1 byte (1 character) from the given pointer (str).
>		write(1, str, 1);
>		
>		// Increment the (str) pointer to move to the next character in the string for the next iteration.
>		str++;
>	}
>}   
>```
>
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_    
>
>_[What are pointers](https://youtu.be/2ybLD6_2gKM?si=yLpSffSRbA60G3Se)_    
>

<br>

**Function call**
>**Create the main function**
>```c
>int main(void)
>{
>	// Declare a pointer using the dereference operator(*) and initialize it with a sequence of characters
>	char *s;
>	s = "42 Berlin ;)";
>
>	// Call the ft_putstr function and pass (s) as parameter 
>	ft_putstr(s);
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_putstr.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_putstr.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_42 Berlin ;)_     