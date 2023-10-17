# 42 Berlin - C Piscine - C 04 - Exercise 02

**Subject**
> * _Create a function that displays the number entered as a parameter. The function
has to be able to display all possible values within an int type variable._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_putnbr(int nb);_    
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
>**Use a utility function to display a character to standard output**
>```c
>void	ft_putchar(char c)
>{
>	write(1, &c, 1);
>}
>```
>_[Write a character to standard output](https://github.com/Tarcisio2code/42Berlin/tree/master/C_Piscine/C_00/ex00)_
>
>**Prototype function**
>```c
>void	ft_putnbr(int nb)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Declare a long integer (nbl) and initialize it with the value of the input integer (nb)
>	// This is done to handle the case where (nb) is the minimum possible integer
>	long	nbl = nb;
>
>	// Check if the number (nbl) is negative	
>	if (nbl < 0)
>	{
>		// Print a minus sign (-) to indicate a negative number
>		ft_putchar('-');
>
>		// Convert nbl to a positive value
>		nbl = -nbl;
>	}
>
>	// Check if the number has multiple digits
>	if (nbl > 9)
>		// Recursively call ft_putnbr to print the digits of the number
>		// The recursion proceeds by dividing the number by 10 to shift to the next digit
>		ft_putnbr(nbl / 10);
>
>	// After the recursion (which handles all but the last digit), print the last digit of the number. 
>	// add 48 to the result of dividing by 10 to convert a numerical digit to its ASCII representation
>	// ex. If the last digit is 1, 48 + 1 gives the ASCII value for '1', which is 49.
>	ft_putchar(48 + nbl % 10);
>}   
>```
>_[The long keyword in C](https://www.geeksforgeeks.org/c-long/)_
>
>_[Recursive functions in C](https://www.geeksforgeeks.org/c-recursion/)_   
>
>_[ASCII — Linux manual page](https://man7.org/linux/man-pages/man7/ascii.7.html)_
>

<br>

**Function call**
>**Create the main function**
>```c
>int main(void)
>{
>	// Declare an integer variable
>	int nb;
>
>	// Test the function with a positive number less than 10
>	nb  = 0;		// Initialize the variable
>	ft_putnbr(nb);	// Pass the variable as parameter to the function
>	write(1, "\n", 1);	// Print a newline character to separate the output
>
>	// Test the function with a multiple digit number	
>	nb  = 42;
>	ft_putnbr(nb);
>	write(1, "\n", 1);
>
>	// Test the function with a negative number	
>	nb  = -42;
>	ft_putnbr(nb);
>	write(1, "\n", 1);
>
>	// Test the function with the maximum possible signed integer value
>	nb  = 2147483647;
>	ft_putnbr(nb);
>	write(1, "\n", 1);
>
>	// Test the function with the minimum possible signed integer value	
>	nb  = -2147483648;
>	ft_putnbr(nb);
>	write(1, "\n", 1);
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_   
>
>_[C and C++ Integer Limits](https://learn.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170)_   
>

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_putnbr.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_putnbr.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_0_    
>_42_    
>_-42_    
>_2147483647_    
>_-2147483648_     
>_$_    
