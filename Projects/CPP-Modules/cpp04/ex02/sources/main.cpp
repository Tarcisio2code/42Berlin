/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_old.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:48:16 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/18 21:02:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

/**
 * @file main.cpp
 * @brief Test suite for Exercise 02: Abstract Classes and Concrete Implementations.
 * * OBJECTIVE: 
 * This exercise demonstrates that 'AAnimal' acts strictly as a contract.
 * By using 'AAnimal*' pointers, we prove that even though the base class 
 * cannot be instantiated, it can still point to concrete derived objects 
 * (Dog and Cat) and manage them through its interface.
 */
int main() {

    std::cout << "\n=== Polymorphism Test ===\n" << std::endl;

    // Polymorphism through abstract base class
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n=== Deep Copy Test ===\n" << std::endl;

    Dog original;
    original.setIdea("I want a bone", 0);

    Dog copy(original); // copy constructor
    copy.setIdea("I want a squirrel", 0);

    std::cout << "Original idea: " << original.getIdea(0) << std::endl;
    std::cout << "Copied idea  : " << copy.getIdea(0) << std::endl;

    std::cout << "\n=== Assignment Operator Test ===\n" << std::endl;

    Dog assigned;
    assigned = original; // copy assignment
    assigned.setIdea("I want to sleep", 0);

    std::cout << "Original idea: " << original.getIdea(0) << std::endl;
    std::cout << "Assigned idea: " << assigned.getIdea(0) << std::endl;

    std::cout << "\n=== End of Tests ===\n" << std::endl;

    return 0;
}
