# 42 Berlin - C Piscine - C 05 - Exercise 06

**Subject**  
> * _Create a function that returns 1 if the number given as a parameter is a prime
number, and 0 if it isn’t._    
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_is_prime(int nb);_    
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
>   
>if    
>_[The if-else Statement in C](https://www.geeksforgeeks.org/c-if-else-statement/?ref=lbp)_   

<br>

**Main steps**
>
>**Prototype function**
>```c
>int	ft_is_prime(int nb)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Declare an integer variable that will be used to search for divisors of (nb)
>	int i;
>
>	// Return 0 when it is not a positive integer greater than 1
>	if (nb < 2)
>		return(0);
>
>	// Initialize the integer variable (i) to 2.
>	i = 2;
>
>	// Iterates as long as (i) is less than (nb)
>	while(i < nb)
>	{
>		// Checks if (nb) is divisible by the current value of (i)
>		if (nb % i == 0)
>			// Return 0 indicating that (nb) is not a prime number
>			return(0);
>
>		// Increment (i) by 1 to continue to the next iteration
>		i++;
>	}
>	// Return 1, indicating that (nb) is a prime number
>	return(1);
>}   
>```
>_[Prime number](https://en.wikipedia.org/wiki/Prime_number)_
>
>_[Operators in C](https://www.geeksforgeeks.org/operators-in-c/)_   
>
>_[Pre-increment and Post-increment](https://www.geeksforgeeks.org/pre-increment-and-post-increment-in-c/)_    
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
>	// Declare and initialize an integer variable to 0
>	int number = 0;
>	
>	// Declare an integer variable that will be used to store the return of the ft_is_prime function
>	int result;
>
>	// Iterates as long as (number) is less than or equal to 12 
>	while (number <= 12)
>	{
>		// Call the ft_is_prime function passing the current (number) as an argument
>		// store the return of the primality check in the (result) variable
>		result = ft_is_prime(number);
>
>		// Use ternary conditional operator (?) to print if current (number) is a prime number or not
>		printf("%d is %s (%d)\n", number, (result == 1) ? "prime" : "not prime", result);
>
>		// Increment (number) to move on to the next number in the loop
>		number++;
>	}
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_     
>
>_[Ternary operator in C](https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c/)_    
>

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_is_prime.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_is_prime.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_   
>_0 is not prime (0)_   
>_1 is not prime (0)_   
>_2 is prime (1)_   
>_3 is prime (1)_   
>_4 is not prime (0)_   
>_5 is prime (1)_   
>_6 is not prime (0)_   
>_7 is prime (1)_   
>_8 is not prime (0)_   
>_9 is not prime (0)_   
>_10 is not prime (0)_   
>_11 is prime (1)_   
>_12 is not prime (0)_   
>_$_   