# 42 Berlin - C Piscine - C 04 - Exercise 03

**Subject**
> * _Write a function that converts the initial portion of the string pointed by str to its int representation._   
> * _The string can start with an arbitray amount of white space (as determined by isspace(3))_   
> * _The string can be followed by an arbitrary amount of + and - signs, - sign will change the sign of the int returned based on the number of - is odd or even._   
> * _Finally the string can be followed by any numbers of the base 10._   
> * _Your function should read the string until the string stop following the rules and return the number found until now._   
> * _You should not take care of overflow or underflow. result can be undefined in that case._   
> * _Here’s an example of a program that prints the atoi return value:_   
>_$>./a.out " ---+--+1234ab567"_   
>_-1234_   
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_atoi(char *str);_    
>

<br>

**Libraries**        
>
>stdio.h    
>_[C file input/output](https://en.wikipedia.org/wiki/C_file_input/output)_

**Used functions**   
>
>printf   
>_[Printf in C](https://www.geeksforgeeks.org/printf-in-c/)_    

**Statements**
>
>if    
>_[The if-else Statement in C](https://www.geeksforgeeks.org/c-if-else-statement/?ref=lbp)_    
>
>while    
>_[While loop in C](https://www.geeksforgeeks.org/c-while-loop/?ref=lbp)_

<br>

**Main steps**
>
>**Use a utility pointer to a function to returns a pointer to the first non-whitespace character in the string.**
>```c
>char	*ft_trimspaces(char *str)
>{
>	// Iterate string while the current character is a whitespace character
>	// Characters with ASCII values between 9 and 13 and the value 32 correspond to horizontal tab,
>	// line feed, vertical tab, form feed, carriage return and space, respectively
>	while ((*str >= 9 && *str <= 13) || *str == 32)
>		// Move the (str) pointer to the next character
>		str++;
>	
>	// Return the pointer to the first non-whitespace character in the string
>	return (str);
>}
>```
>
>**Use a utility function to count the occurrences of the '-' character in a string and determines if the count is even or odd.**
>```c
>int	ft_countminus(char *str)
>{
>	// Declare an integer variable to be used to count the occurrences of '-' characters, then initialize it to 0
>	int	count;
>
>	count = 0;
>
>	// Iterates each character of the input string (str) until the null terminator is encountered
>	while (*str)
>	{
>		// Increment the count variable if the current character in (str) is '-'.
>		if (*str == '-')
>			count++;
>
>		// Move the (str) pointer to the next character for the next iteration.
>		str++;
>	}
>	// Divide the value of (count) by two to determine whether the count of '-' characters is odd or even. 
>	// Return 1 if odd, and 0 if even.
>	return (count % 2);
>}
>```  
>
>**Use a utility pointer to a function to trim leading plus and minus signs from a string and returns a pointer to the first character that is not a plus or minus sign.**
>```c
>char	*ft_trimsigns(char *str)
>{
>	// Iterate the string while the current character is a plus or minus sign
>	while (*str == '-' || *str == '+')
>		// Increment the pointer to move to the next character in the string
>		str++;
>
>	// Return the pointer which now points to the first character that is not a plus or minus sign
>	return (str);
>}
>```  
>
>**Use a utility function to extract a number from the given string and returns it as an integer.**
>```c
>int	ft_getnumbers(char *src, int is_even)
>{
>	// Declare an integer variable that will store the extracted number, then initialize it to 0.
>	int	n;
>
>	n = 0;
>
>	// Iterate through the string while the current character is a numerical digit
>	// (ASCII values between 48 and 57, corresponding to '0' to '9')
>	while (*src >= 48 && *src <= 57)
>	{
>		// Multiply the current value of n by 10 to shift the digits left.
>		// Subtract 48 from the ASCII value of the current character (*src) to convert it from ASCII to the numerical digit 
>		// ASCII value 48 corresponds to '0'
>		// Add this numerical digit to n
>		n = n * 10 + (*src - 48);
>
>		// Increment the pointer to move to the next character in the string
>		src++;
>	}
>	// If is_even is true (nonzero), convert the value of (n) to negative and return it
>	if (is_even)
>		return (-n);
>
>	// If is_even is false (zero), return the value of (n)
>	return (n);
>}
>```  
>
>**Prototype function**
>```c
>int	ft_atoi(char *str)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Declare a pointer to stored the modified string (trimmed of spaces and signs)
>	char	*src;
>
>	// Declare an integer that indicates if the number is negative (1 for odd, indicating negative)
>	int	is_even;
>
>	// Declare an integer to store the final result
>	int	result;
>
>	// Call the ft_trimspaces function to remove leading spaces from the string 
>	// and store the pointer to the modified string in (src)
>	src = ft_trimspaces(str);
>
>	// Call the ft_countminus function to determine if the number is negative
>	is_even = ft_countminus(src);
>
>	// Call the ft_trimsigns function to remove leading plus and minus signs from the string
>	src = ft_trimsigns(src);
>
>	// Call the ft_getnumbers function to extract the numerical value from the modified string
>	// and account for the sign based on (is_even)
>	result = ft_getnumbers(src, is_even);
>
>	// Return the final resulting integer value
>	return (result);
>}   
>```
>_[man atoi](https://man7.org/linux/man-pages/man3/atoi.3.html)_    
>
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_    
>
>_[What are pointers](https://youtu.be/2ybLD6_2gKM?si=yLpSffSRbA60G3Se)_    
>
>_[Pointers to functions](https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-pointers)_    
>
>_[Recursive functions in C](https://www.geeksforgeeks.org/c-recursion/)_   
>
>_[ASCII — Linux manual page](https://man7.org/linux/man-pages/man7/ascii.7.html)_
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
>	// Declare a pointer to a string and initialize it to a string containing minus signs of odd quantity
>	char *str;
>	str = " ---+--+1234ab567";
>
>	// Call the ft_atoi function and pass the string (str) to print the resulting integer
>	printf("%d\n", ft_atoi(str));
>
>	// Reassign (str) with another string containing minus signs of even quantity
>	str = "     ---+-+1234ab567";
>
>	// Call the ft_atoi function and pass the string (str) to print the resulting integer
>	printf("%d", ft_atoi(str));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_   
>

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_atoi.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_atoi.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_-1234_   
>_1234_    
