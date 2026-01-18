/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:48:16 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:52:19 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Comparative test bench for Virtual vs. Static binding.
 * * OBJECTIVE: 
 * This exercise demonstrates how C++ handles late binding (dynamic dispatch)
 * through the use of virtual tables (vtables).
 */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(){
    /** * @section Dynamic Polymorphism
     * Here, even though the pointers are of type 'Animal*', the 'virtual' 
     * keyword triggers a vtable lookup. At runtime, the program finds 
     * the actual derived implementation (Dog or Cat).
     */
    std::cout << "\n#### Correct Polymorphism tests ####" << std::endl;
    std::cout << "Creating an Animal..." << std::endl;
    const Animal* meta = new Animal();

    // Upcasting: Base class pointer referencing a Derived class object.
    // This allows for polymorphic behavior through the virtual table (vtable).
    std::cout << "\nCreating an Dog Animal..." << std::endl;
    const Animal* j = new Dog();
    std::cout << "\nCreating an Cat Animal..." << std::endl;
    const Animal* i = new Cat();

    std::cout << "\n#### Making Sounds ####" << std::endl;
    
    std::cout << j->getType() << " : ";
    j->makeSound();
    std::cout << i->getType() << " : ";
    i->makeSound();
    std::cout << meta->getType() << " : ";
    meta->makeSound();

    /** * @section Static Binding
     * Because 'makeSound' is NOT virtual in WrongAnimal, the compiler 
     * performs Static Binding. It looks at the POINTER type (WrongAnimal*), 
     * not the actual object (WrongCat), and binds the call at compile-time.
     */
    std::cout << "\n#### Wrong Polymorphism tests ####" << std::endl;
    std::cout << "Creating a WrongAnimal..." << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    std::cout << "\nCreating a WrongCat Animal..." << std::endl;
    const WrongAnimal* wrong_i = new WrongCat();

    std::cout << "\n#### Making Sounds ####" << std::endl;
    // Even though it's a WrongCat, it will sound like a WrongAnimal.
    std::cout << wrong_i->getType() << " : ";
    wrong_i->makeSound();
    std::cout << wrong_meta->getType() << " : ";
    wrong_meta->makeSound();

    /** * @section Direct Access
     * When not using pointers, the compiler always knows the exact type.
     * Here, WrongCat will finally behave like a Cat because we aren't 
     * using the base class interface.
     */
    std::cout << "\n#### Direct Class Test ####" << std::endl;
    std::cout << "Creating a Dog..." << std::endl;
    Dog dog;
    std::cout << "\nCreating a Cat..." << std::endl;
    Cat cat;
    std::cout << "\nCreating a WrongCat..." << std::endl;
    WrongCat wrong_cat;

    std::cout << "\n#### Making Sounds ####" << std::endl;
    std::cout << dog.getType() << " : ";
    dog.makeSound();
    std::cout << cat.getType() << " : ";
    cat.makeSound();
    std::cout << wrong_cat.getType() << " : ";
    wrong_cat.makeSound();

    /** * @section Virtual Destructor Check
     * Essential: Since Animal has a virtual destructor, 'delete j' and 'delete i'
     * will correctly call Dog's and Cat's destructors before the Animal part.
     */
    std::cout << "\n#### Clean up ####" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;

    delete wrong_meta;
    delete wrong_i;

    std::cout << std::endl;

    return 0;
}

