#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Defines.h"

ErrorCode executeCommand(const std::string& command, std::vector<MemoryNode>& memory) {
    // Split the command string into tokens
    std::istringstream iss(command);
    std::string action, type;
    int index;
    iss >> action >> type >> index;

    // Determine the memory type
    MemoryType memType;
    if (type == "Single") {
        memType = MemoryType::SINGLE;
    }
    else if (type == "Multiple") {
        memType = MemoryType::MULTIPLE;
    }
    else {
        // Unknown memory type
        return ErrorCode::EXECUTE_SUCCESS;
    }

    // Check if the index is valid
    if (index < 0 || index >= BUFFER_SIZE) {
        return ErrorCode::EXECUTE_SUCCESS; // Invalid index, just return success
    }

    // Execute the command
    if (action == "Allocate") {
        if (memory[index].rawMemory == nullptr) {
            // Allocate memory
            if (memType == MemoryType::SINGLE) {
                memory[index].rawMemory = new int;
            }
            else {
                memory[index].rawMemory = new int[ALLOCATION_MULTIPLE_SIZE];
            }
            memory[index].memoryType = memType;
            return ErrorCode::EXECUTE_SUCCESS;
        }
        else {
            // Memory already allocated
            return ErrorCode::MEMORY_LEAK;
        }
    }
    else if (action == "Deallocate") {
        if (memory[index].rawMemory != nullptr) {
            // Deallocate memory
            if (memType == MemoryType::SINGLE && memory[index].memoryType != MemoryType::SINGLE) {
                // Trying to deallocate single memory node with deallocate multiple command
                return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
            }
            else if (memType == MemoryType::MULTIPLE && memory[index].memoryType != MemoryType::MULTIPLE) {
                // Trying to deallocate multiple memory nodes with deallocate single command
                return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
            }
            delete[] memory[index].rawMemory;
            memory[index].rawMemory = nullptr;
            memory[index].memoryType = MemoryType::UNKNOWN;
            return ErrorCode::EXECUTE_SUCCESS;
        }
        else {
            // Trying to deallocate unallocated memory
            return ErrorCode::DOUBLE_FREE;
        }
    }
    else {
        // Unknown action
        return ErrorCode::EXECUTE_SUCCESS;
    }
}


void printResult(const ErrorCode errorCode, const std::string& command) {
    switch (errorCode) {
    case ErrorCode::EXECUTE_SUCCESS:
        std::cout << command << " - success\n";
        break;
    case ErrorCode::MEMORY_LEAK:
        std::cout << command << " - memory leak prevented, will not make allocation\n";
        break;
    case ErrorCode::DOUBLE_FREE:
        std::cout << command << " - system crash prevented, will skip this deallocation\n";
        break;
    case ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH:
        std::cout << command << " - Warning allocate/deallocate mismatch, will skip this deallocation\n";
        break;
    default:
        break;
    }
}
