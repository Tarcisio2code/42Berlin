# 42 Berlin - C Piscine - C 05 - Exercise 04

**Subject**
> * _Create a function ft_fibonacci that returns the n-th element of the Fibonacci sequence, the first element being at the 0 index. We’ll consider that the Fibonacci sequence starts like this: 0, 1, 1, 2._   
>
> * _Overflows must not be handled, the function return will be undefined._    
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_fibonacci(int index);_    
>
> * _Obviously, ft_fibonacci has to be recursive._    
>
> * _If the index is less than 0, the function should return -1._    
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
>if    
>_[The if-else Statement in C](https://www.geeksforgeeks.org/c-if-else-statement/?ref=lbp)_   

<br>

**Main steps**
>
>**Prototype function**
>```c
>int	ft_fibonacci(int index);
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	if (index < 0)
>		// Return -1 when (index) is less than 0
>		return (-1);
>	else if (index == 0)
>		// Return 0 when (index) is 0
>		return (0);
>	else if (index == 1)
>		// Return 1 when (index) is 1
>		return (1);
>	else
>		// Returns the result of the sum of two recursive function calls
>		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
>}   
>```
>_[Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence)_
>
>_[Recursive functions in C](https://www.geeksforgeeks.org/c-recursion/)_   
>
>_[Operators in C](https://www.geeksforgeeks.org/operators-in-c/)_   
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
>	// Function test with number greater than 0
>	int index = 10;
>	printf("%d\n", ft_fibonacci(index));
>
>	// Function test with number less than 0
>	index = -1;
>	printf("%d\n", ft_fibonacci(index));
>
>	// Function test with number equal to 0
>	index = 0;
>	printf("%d\n", ft_fibonacci(index));
>
>	// Function test with number equal to 1
>	index = 1;
>	printf("%d\n", ft_fibonacci(index));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_fibonacci.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_fibonacci.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_   
>_55_  
>_-1_   
>_0_   
>_1_   
>_$_   