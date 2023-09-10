# 42 Berlin - C Piscine - Schell00 - Exercise 03


**Subject**
>_Create your own SSH key. Once it is done:_
>  
> * _Add your public key to your repository, in a file name id_rsa_pub._
>
> * _Update your ssh key on the intranet. This will allow you to push the repository to our git server._
>
>_The file's name was not chosen randomly._   
>_Make sure you understand the difference between the public key and Ithe private key._

<br>

**Commands used**   
>
>_echo, cat_   

**Solution**    
>
>_Copy your ssh key_
>
>**Create file**   
>```diff
>echo [your ssh key] > id_rsa_pub   
>```
>
>**Print file**    
>```diff
>cat id_rsa_pub   
>```

<br>

**Difference between the public key and Ithe private key**    
>_Each SSH key pair includes two keys:_    
>_A **public key** that is copied to the SSH server(s). Anyone with a copy of the public key can encrypt data which can then only be read by the person who holds the corresponding private key. Once an SSH server receives a public key from a user and considers the key trustworthy, the server marks the key as authorized in its authorized_keys file. Such keys are called authorized keys._    
>_A **private key** that remains (only) with the user. The possession of this key is proof of the user's identity. Only a user in possession of a private key that corresponds to the public key at the server will be able to authenticate successfully. The private keys need to be stored and handled carefully, and no copies of the private key should be distributed. The private keys used for user authentication are called identity keys._
>
>_https://www.ssh.com/academy/ssh/public-key-authentication_
