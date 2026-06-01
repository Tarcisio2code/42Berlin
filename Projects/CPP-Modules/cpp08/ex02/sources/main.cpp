/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:27:45 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/30 16:53:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "---- Test: MutantStack ----" << std::endl; 
    {   
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Last pushed Element: " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "\nSize after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "\nIterating " << mstack.size() << " elements;" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
             std::cout << "  Element [" << std::distance(mstack.begin(), it) << "] = " << *it << std::endl;
            ++it;
        }

        std::cout << "\nCompatible with std::stack" << std::endl;
        std::stack<int> s(mstack);
        std::cout << " Size of copy    : " << s.size() << std::endl;

        std::cout << "\nDeep copy test" << std::endl;
        MutantStack<int> originalStack;
        originalStack.push(1);
        originalStack.push(2);

        MutantStack<int> copyStack = originalStack;
        
        copyStack.push(3);
        std::cout << " Size of original : " << originalStack.size() << std::endl;
        std::cout << " Size of copy     : " << copyStack.size() << std::endl;

        std::cout << "\nConst iterators" << std::endl;
        const MutantStack<int> constStack(originalStack);
        MutantStack<int>::const_iterator constIt = constStack.begin();
        MutantStack<int>::const_iterator constIte = constStack.end();
        std::cout << " const stack size : " << std::distance(constIt, constIte) << std::endl;
    }

    std::cout << "\n---- Test: std::list ----" << std::endl; 
    {
        std::list<int> stdList;
        stdList.push_back(5);
        stdList.push_back(17);

        std::cout << "Last pushed Element: " << stdList.back() << std::endl;

        stdList.pop_back();
        std::cout << "\nSize after pop: " << stdList.size() << std::endl;

        stdList.push_back(3);
        stdList.push_back(5);
        stdList.push_back(737);
        stdList.push_back(0);

        std::cout << "\nIterating;" << std::endl;
        std::list<int>::iterator it = stdList.begin();
        std::list<int>::iterator ite = stdList.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << "  Element [" << std::distance(stdList.begin(), it) << "] = " << *it << std::endl;
            ++it;
        }
    }

    return 0;
}