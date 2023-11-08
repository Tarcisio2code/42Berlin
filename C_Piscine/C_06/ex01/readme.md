# 42 Berlin - C Piscine - C 06 - Exercise 01

**Subject**
> * _We’re dealing with a program here, you should therefore have a function main in your .c file._   
>
> * _Create a program that displays its given arguments._   
>
> * _One per line, in the same order as in the command line._
>
> * _It should display all arguments, except for argv[0]._
>
> * _Example :_    
>_$>./a.out test1 test2 test3_   
>_test1_  
>_test2_  
>_test3_  
>_$>_    
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
>	// Declare um número inteiro (pos) que será usado para rastrear a posição atual no array (argv)
>	int	pos;
>
>	// Initialize the variable (pos) to 1 to ignore the program name itself
>	pos = 1;
>
>	// Iterates through each command-line argument while (pos) is less than (argc)
>	while (pos < argc)
>	{
>		// Assign the value of the command-line argument at the current position (pos) to the (str) pointer. 
>		// Use the post-increment operator(++) to increment (pos) to move to the next argument in the (argv) array.
>		str = argv[pos++];
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
>norminette -R CheckForbiddenSourceHeader ft_print_params.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_print_params.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out test1 test2 test3 42 Berlin
>```

**Result**
>_$_    
>_./a.out test1 test2 test3 42 Berlin_    
>_test1_   
>_test2_   
>_test3_   
>_42_   
>_Berlin_   
>_$_    
