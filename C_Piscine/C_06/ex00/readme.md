# 42 Berlin - C Piscine - C 06 - Exercise 00

**Subject**
> * _We’re dealing with a program here, you should therefore have a function main in your .c file._   
>
> * _Create a program that displays its own name._   
>
> * _Example :_    
>_$>./a.out_    
>_./a.out_    
$>_    
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
>
>if    
>_[The if-else Statement in C](https://www.geeksforgeeks.org/c-if-else-statement/?ref=lbp)_    

<br>

**Main steps**
>
>**Include the Library**
>```c
>#include <unistd.h>
>```
>_[Using the library](https://www.gnu.org/software/libc/manual/html_mono/libc.html#Using-the-Library)_
>
>
>**Create the main function**
>```c
>// Define a main function that accept two arguments 
>// argc (the number of command-line arguments) 
>// and argv (an array of strings containing the command-line arguments)
>int	main(int argc, char **argv)
>{
>	// Declare a pointer to a character str
>	char	*str;
>
>	// Check if there are at least one or more command-line arguments
>	if (argc > 0)
>	{
>		// Assign the value of argv[0] (the program's name) to the str pointer
>		str = argv[0];
>
>		// Iterate each character of the string pointed to by the str pointer
>		while (*str)
>			// Print each character to the standard output
>			// Use the post-increment operator(++) to move to the next character in the string
>			write(1, str++, 1);
>
>		// Print a newline character to separate the output
>		write(1, "/n", 2);
>	}
>}
>```    
>_[Main Function in C](https://www.geeksforgeeks.org/main-function-in-c/)_    
>	
>_[Command Line Arguments](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)_   
>
>_[C Arrays](https://www.geeksforgeeks.org/c-arrays/?ref=lbp)_    
>	    
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_        
>	    
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_   
>
>_[Pre-increment and Post-increment](https://www.geeksforgeeks.org/pre-increment-and-post-increment-in-c/)_    

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_print_program_name.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_print_program_name.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_./a.out_    
>_$_    