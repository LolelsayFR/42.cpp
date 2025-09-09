/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_safety_guide.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@github.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:00:00 by copilot           #+#    #+#             */
/*   Updated: 2024/09/09 14:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ARGUMENT SAFETY GUIDE FOR 42.CPP PROJECT
 * ========================================
 * 
 * This document demonstrates safe argument handling practices
 * to prevent segfaults when programs are launched without arguments.
 * 
 * DANGEROUS PATTERN (causes segfault):
 * -----------------------------------
 * int main(int argc, char **argv) {
 *     argc = 2;  // ❌ NEVER DO THIS! Forces argc but argv[1] may be invalid
 *     std::cout << argv[1] << std::endl; // ❌ Segfault if no args passed
 *     return 0;
 * }
 * 
 * SAFE PATTERNS:
 * -------------
 * 
 * 1. Check argc before accessing argv elements:
 */
#include <iostream>

int safe_main_pattern1(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1;
    }
    std::cout << "Argument: " << argv[1] << std::endl;
    return 0;
}

/*
 * 2. Handle specific expected argument counts:
 */
int safe_main_pattern2(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <arg1> <arg2>" << std::endl;
        return 1;
    }
    std::cout << "Args: " << argv[1] << " " << argv[2] << std::endl;
    return 0;
}

/*
 * 3. Handle optional arguments safely:
 */
int safe_main_pattern3(int argc, char **argv) {
    std::cout << "Program: " << argv[0] << std::endl;
    
    if (argc >= 2) {
        std::cout << "First arg: " << argv[1] << std::endl;
    } else {
        std::cout << "No arguments provided" << std::endl;
    }
    
    return 0;
}

/*
 * MEMORY SAFETY RULES:
 * -------------------
 * 
 * 1. Every 'new' must have a corresponding 'delete'
 * 2. Every 'new[]' must have a corresponding 'delete[]'
 * 3. Check for allocation failures when appropriate
 * 4. Use RAII principles (constructors/destructors)
 * 
 * EXAMPLE:
 */
void safe_memory_example() {
    // Safe dynamic allocation
    int *ptr = new(std::nothrow) int[100];
    if (!ptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        return;
    }
    
    // Use the memory...
    
    // Always cleanup
    delete[] ptr;
}

/*
 * CURRENT PROJECT STATUS:
 * =====================
 * All programs in this project correctly implement these patterns:
 * 
 * ✅ cpp00/ex00/megaphone.cpp - Safe argc handling
 * ✅ cpp01/ex04/main.cpp (nsed) - Safe argc validation  
 * ✅ cpp01/ex06/main.cpp (harlFilter) - Safe argc checking
 * ✅ cpp04/ex01/main.cpp - Safe argc with fallback behavior
 * ✅ cpp04/ex02/main.cpp - Safe argc with fallback behavior
 * 
 * All dynamic memory allocations are properly managed with
 * corresponding delete operations.
 */