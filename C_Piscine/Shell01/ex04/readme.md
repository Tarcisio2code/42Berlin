# 42 Berlin - C Piscine - Schell01 - Exercise 03

**Subject**
> * _Write a command line that displays your machine’s MAC addresses. Each address
must be followed by a line break._   
>
>_man ifconfing_    

<br>

**Commands used**   
>
>_touch, echo, cat, ifconfing, awk_   

<br>

**Solution**    
>
>**Create file**
>```diff 
>touch MAC.sh
>```
>
>**Place the command line**        
>```diff
>echo "ifconfig | awk '/ether/{print \$2}'" > MAC.sh
>```
>
>**Print file**
>
>```diff
>cat MAC.sh
>```
>_$>_    
>_ifconfig | awk '/ether/{print $2}'_   
>_$>_    
>
>**Make the script executable**   
>```diff
>chmod +x MAC.sh
>```

<br>

**Result**   
>_**Command line test**_ 
>```diff
>./MAC.sh
>```
>_$_    
>_01:05:1d:a1:0f:g2_    
>_$_    

<br>

**ifconfig options**  
>```diff
>man ifconfig
>```
**awk options**  
>```diff
>man awk
>```
>_pattern scanning and processing language_    
>
>**/ether/**    
>_filter out all rows that match ether._    
>
>**{print $2}**    
>_print second column in corresponding row_
