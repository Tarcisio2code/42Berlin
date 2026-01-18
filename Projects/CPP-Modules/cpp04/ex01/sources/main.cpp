/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:48:16 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:59:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

/**
 * @brief Test suite for Exercise 01: Deep Copies and Memory Management.
 * * OBJECTIVE: 
 * The primary goal of this exercise is to implement and verify "Deep Copies". 
 * In C++, when a class contains a pointer to heap memory (like Brain*), 
 * a simple copy would only copy the memory address (Shallow Copy), leading 
 * to multiple objects sharing the same data and causing crashes upon destruction. 
 * This main proves that each Dog and Cat possesses its own unique Brain.
 */
int main() {

    /** * @section Virtual Destructor Check
     * Deleting a derived object through a base pointer. 
     * If the Animal destructor weren't 'virtual', the Dog/Cat part 
     * (and their Brains) would never be freed, causing a memory leak.
     */
    std::cout << "\n#### Basic tests ####" << std::endl;
    std::cout << "\nCreating Animal 1" << std::endl;
    const Animal* j = new Dog();
    std::cout << "\nCreating Animal 2" << std::endl;
    const Animal* i = new Cat();
    
    std::cout << std::endl;
    delete j; // Must call Dog destructor THEN Animal destructor
    std::cout << std::endl;
    delete i;

    /** * @section Array of Animals
     * Creating a collection of different animals to test mass allocation 
     * and polymorphic destruction.
     */
    std::cout << "\n#### Main tests ####" << std::endl;
    const int size = 2;
    Animal* animals[size];

    for (int i = 0; i < size; ++i) {
        std::cout << "\nCreating Animal " << i + 1 << "..." << std::endl;
        if (i % 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    std::cout << "\n#### Making Sounds ####" << std::endl;;
    for (int i = 0; i < size; ++i) {
        std::cout << animals[i]->getType() << " : " ;
        animals[i]->makeSound();
    }

    std::cout << "\n#### Animal ideas ####" << std::endl;
    for (int i = 0; i < size; ++i) {
        if (Dog* dog = dynamic_cast<Dog*>(animals[i])){
            dog->setIdea("I want a bone!", 0);
            std::cout << dog->getType() << " is tinking: " << dog->getIdea(0) << std::endl;
        }
        else if (Cat* cat = dynamic_cast<Cat*>(animals[i])){
            cat->setIdea("I want to sleep!", 0);
            std::cout << cat->getType() << " is tinking: " << cat->getIdea(0) << std::endl; 
        }
    }

    /** * @section Deep Copy Verification (Scope Test)
     * Using brackets { } to create a temporary scope. 
     * When tmp_dog leaves the scope, its destructor is called. 
     * If it were a Shallow Copy, it would destroy basic_dog's brain too.
     */
    std::cout << "\n#### Deep Copy Test ####" << std::endl;
    Dog basic_dog;
    basic_dog.setIdea("I want a bone!", 0);
    std::cout << std::endl;
    Cat basic_cat;
    basic_cat.setIdea("I want to sleep!", 0);

    std::cout << "\nCopy constructor" << std::endl;
    {
        std::cout << "{" << std::endl;
        Dog tmp_dog = basic_dog; // Deep copy occurs here
        std::cout << std::endl;
        Cat tmp_cat = basic_cat;
        std::cout << "\nIdeas" << std::endl;

        std::cout << "basic_dog : " << basic_dog.getIdea(0) << ", tmp_dog : " << tmp_dog.getIdea(0) << std::endl;
        std::cout << "basic_cat : " << basic_cat.getIdea(0) << ", tmp_cat : " << tmp_cat.getIdea(0) << std::endl;
        std::cout << "\nsetting new idea for tmp_dog and tmp_cat..." << std::endl;        
        // Should NOT affect basic_dog or basic_cat
        tmp_dog.setIdea("Squirrel!", 0);
        tmp_cat.setIdea("The red dot!", 0);
        std::cout << "basic_dog : " << basic_dog.getIdea(0) << ", tmp_dog : " << tmp_dog.getIdea(0) << std::endl;
        std::cout << "basic_cat : " << basic_cat.getIdea(0) << ", tmp_cat : " << tmp_cat.getIdea(0) << std::endl;    
        std::cout << "}" << std::endl;
    }

    std::cout << "\nCopy assignment operator" << std::endl;
    {
        std::cout << "{" << std::endl;
        Dog tmp_dog; 
        tmp_dog = basic_dog;
        std::cout << std::endl;
        Cat tmp_cat;
        tmp_cat = basic_cat;
        std::cout << "\nIdeas" << std::endl;
        std::cout << "basic_dog : " << basic_dog.getIdea(0) << ", tmp_dog : " << tmp_dog.getIdea(0) << std::endl;
        std::cout << "basic_cat : " << basic_cat.getIdea(0) << ", tmp_cat : " << tmp_cat.getIdea(0) << std::endl;    
        std::cout << "\nsetting new idea for tmp_dog and tmp_cat..." << std::endl;        
        tmp_dog.setIdea("Squirrel!", 0);
        tmp_cat.setIdea("The red dot!", 0);
        std::cout << "basic_dog : " << basic_dog.getIdea(0) << ", tmp_dog : " << tmp_dog.getIdea(0) << std::endl;
        std::cout << "basic_cat : " << basic_cat.getIdea(0) << ", tmp_cat : " << tmp_cat.getIdea(0) << std::endl;    
        std::cout << "}" << std::endl;
    }

    /** * @section Clean up
     * Final check to ensure every dynamically allocated animal 
     * in the array is properly released.
     */
    std::cout << "\n#### Removing Animals ####" << std::endl;;
    for (int i = 0; i < size; ++i) {
        std::cout << "Removing Animal " << i + 1 << "..." << std::endl;
        delete animals[i];
    }

    std::cout << std::endl;

    return 0;
}
