# 42 Berlin - C Piscine - C 00 - Exercise 03

**Subject**
> * _Create a function that displays all digits, on a single line, by ascending order._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_print_numbers(void);_
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
>
>**Prototype function**
>```c
>void ft_print_numbers(void)
>```
>
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_
>
>**Create and initialize variable**
>```c
>char	number;   
>    
>number = '0';
>```    
>_[Variables in C](https://www.geeksforgeeks.org/variables-in-c/?ref=lbp)_
>
>**The while loop**
>```c
>while (number <= '9')
>```
>
>**The function Write**
>```c
>write(1, &number, 1)
>```
>_[Access the memory address with the **&** reference operator](https://www.w3schools.com/c/c_memory_address.php)_
>
>**Increment decimal code**
>```c
>number++;
>```
>_[ASCII — Linux manual page](https://man7.org/linux/man-pages/man7/ascii.7.html)_

<br>

**Function call**
>```c
>int	main(void) {ft_print_numbers();}   
>```    

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_print_numbers.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_print_numbers.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```
