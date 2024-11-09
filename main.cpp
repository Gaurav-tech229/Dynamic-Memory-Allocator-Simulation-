#include "MemoryAllocator.h"
#include <iostream>

int main() {
    try {
        // Create a memory allocator with 1024 bytes using First Fit strategy
        MemoryAllocator allocator(1024, AllocationStrategy::FIRST_FIT);

        std::cout << "Initial memory state:\n";
        allocator.printMemoryMap();

        // Test allocations
        size_t addr1 = allocator.allocate(128);
        size_t addr2 = allocator.allocate(256);
        size_t addr3 = allocator.allocate(64);

        std::cout << "\nAfter allocations:\n";
        allocator.printMemoryMap();

        // Test deallocation
        allocator.deallocate(addr2);
        std::cout << "\nAfter deallocating middle block:\n";
        allocator.printMemoryMap();

        // Try different allocation strategy
        allocator.setAllocationStrategy(AllocationStrategy::BEST_FIT);
        size_t addr4 = allocator.allocate(128);

        std::cout << "\nAfter best-fit allocation:\n";
        allocator.printMemoryMap();

    }
    catch (const MemoryAllocator::AllocationFailedException& e) {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
    catch (const MemoryAllocator::InvalidAddressException& e) {
        std::cerr << "Invalid address: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}