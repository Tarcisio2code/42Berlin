# 42 Berlin - C Piscine - C 00 - Exercise 00

**Subject**
> * _Write a function that displays the character passed as a parameter._   
>
> * _It will be prototyped as follows :_   
>
>_void ft_putchar(char c)_
>
>_To display the character, you must use the text write function as follows._
>
>_write(1, &c, 1);_
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
>void ft_putchar(char c)
>```
>
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_
>
>
>**The function Write**
>```c
>write(1, &c, 1)
>```
>_[Access the memory address with the **&** reference operator](https://www.w3schools.com/c/c_memory_address.php)_

<br>

**Function call**
>```c
>int	main(void) {ft_putchar('T');}   
>```    

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_putchar.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_putchar.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```