# 42 Berlin - C Piscine - C 06 - Exercise 03

**Subject**
> * _We’re dealing with a program here, you should therefore have a function main in your .c file._   
>
> * _Create a program that displays its given arguments sorted by ascii order._   
>
> * _It should display all arguments, except for argv[0]._
>
> * _One argument per line._
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
>**Utility function that compares two strings character by character and returns the difference between the ASCII values**    
>```c
>int	ft_comp(char *str1, char *str2)
>{
>	// Iterates through both strings while (str1) is not the null terminator and the characters in both strings match
>	while (*str1 && (*str1 == *str2))
>	{
>		// Increment pointers to move to next characters in both strings  
>		str1++;
>		str2++;
>	}
>	// Returns the difference between the ASCII values of the first differing characters in the two strings
>	// If the strings are equal, this difference will be 0
>	return (*str1 - *str2);
>}
>```
>
>**Utility function to swap values between pointers**    
>```c
>void	ft_swap(char **str1, char **str2)
>{
>	char	*temp;
>
>	temp = *str1;
>	*str1 = *str2;
>	*str2 = temp;
>}
>```
>_[Swap values between pointers](https://github.com/Tarcisio2code/42Berlin/tree/master/C_Piscine/C_01/ex02)_
>
>_[C – Pointer to Pointer (Double Pointer)](https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/)_
>
>**Utility function to effectively sorting an array of strings in lexicographical (alphabetical) order**
>```c
>// The function takes three arguments: 
>// arg_pos (the position of the first argument to be sorted)
>// size (the number of arguments in the array)
>// argv (the array of command-line arguments)
>void	ft_sort(int arg_pos, int size, char **argv)
>{
>	// Declare an integer variable that is used to track the current position in the (argv) array
>	int	str_pos;
>
>	// Initialize the variable (pos) with 1 to ignore the first argument
>	str_pos = 1;
>
>	// Iterate the elements in the array while the current position of the string (str_pos)
>	// is less than the difference between the number of arguments (size) 
>	// and the position of the current argument (arg_pos)
>	while (str_pos < (size - arg_pos))
>	{
>		// Use the ft_comp utility function to check if the current argument is greater than the next argument
>		if (ft_comp(argv[str_pos], argv[str_pos + 1]) > 0)
>		{
>			// Call the ft_swap function to swap the two strings in the (argv) array
>			ft_swap(&argv[str_pos], &argv[str_pos + 1]);
>		}
>
>		// Increment the (str_pos) variable to move to the next pair for comparison.
>		str_pos++;
>	}
>}
>```
>
>**Create the main function**
>```c
>// This function is the entry point of the program and takes two arguments: 
>// argc (the number of command-line arguments) 
>// argv (an array of strings representing the command-line arguments).
>int	main(int argc, char **argv)
>{
>	// Declare a pointer to a character str which will be used to iterate the characters in each command-line argument
>	char	*str;
>
>	// Declare an integer to keep track of the current position in the (argv) array.
>	int	arg_pos;
>
>	// Initialize the variable (arg_pos) with 1 to ignore the first argument
>	arg_pos = 1;
>
>	// Start a loop that iterates through the arguments
>	while (arg_pos < argc)
>	{
>		// Call the ft_sort function to sort the elements in the (argv) array
>		ft_sort(arg_pos, argc, argv);
>
>		// Increment (arg_pos) to move to the next position in the array
>		arg_pos++;
>	}
>
>	// Reset (arg_pos) to 1
>	arg_pos = 1;
>
>	// Start a loop that iterates through the arguments
>	while (arg_pos < argc)
>	{
>		// Assign the current command-line argument to the (str) pointer
>		// Use the post-increment operator(++) to move to the next argument in the (argv) array
>		str = argv[arg_pos++];
>
>		// Iterate each character of the string pointed to by the (str) pointer
>		while (*str)
>		{
>			// Print each character to the standard output
>			// Use the post-increment operator(++) to move to the next character in the string
>			write(1, str++, 1);
>		}
>		// Print a newline character to separate the output
>		write(1, "\n", 2);
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
>norminette -R CheckForbiddenSourceHeader ft_sort_params.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_sort_params.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_./a.out test3 test2 test1 Berlin 42_    
>_42_   
>_Berlin_   
>_test1_   
>_test2_   
>_test3_   
>_$_    