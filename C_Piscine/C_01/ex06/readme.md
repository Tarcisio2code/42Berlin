# 42 Berlin - C Piscine - C 01 - Exercise 06

**Subject**
> * _Create a function that counts and returns the number of characters in a string._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_strlen(char *str);_   
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
>while    
>_[While loop in C](https://www.geeksforgeeks.org/c-while-loop/?ref=lbp)_

<br>

**Main steps**
>
>**Prototype function**
>```c
>void	ft_strlen(char *str)
>```
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_   
>
>**Body of the function**
>```c
>{
>	// declare an integer counter variable
>	int	i;    
>
>	// initialize the counter variable    
>	i = 0;    
>
>	// increment counter while string value is not a null character
>	while (str[i] != '\0')
>		i++;
>
>	// return the value of the counter variable
>	return (i);
>}  
>```
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_    
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
>	// use the dereference operator(*) to declare the pointer
>	char *a;    
>
>	// declare an integer variable    
>	int total;    
>
>	// assign string value directly to pointer
>	a = "42Berlin is a great good place to learn :)";    
>
>	// pass the pointer as a parameter to the function
>	// initialize the variable with the value returned by the function
>	total = ft_strlen(a);
>
>	// print the value of the variable
>	printf("Number of characters: %d\n", total);
>}  
>```       

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_strlen.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_strlen.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_Number of characters: 42_      
>_$_    
