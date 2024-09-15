#include <iostream>
#include <vector>
#include <algorithm>

// Function to print the current train structure
void printTrain(const std::vector<std::string>& train) {
    std::cout << "|";
    for (const auto& wagon : train) {
        std::cout << wagon << "|";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> train;

    // Read the train composition
    std::string wagonContent;
    while (std::cin >> wagonContent && wagonContent != "end") {
        train.push_back(wagonContent);
    }

    // Process commands
    std::string command;
    while (std::cin >> command) {
        if (command == "P") {
            // Print the current train structure
            printTrain(train);
        }
        else if (command == "M") {
            // Move the wagon
            int oldPosition, newPosition;
            std::cin >> oldPosition >> newPosition;

            if (oldPosition >= 0 && oldPosition < train.size() &&
                newPosition >= 0 && newPosition < train.size()) {
                std::swap(train[oldPosition], train[newPosition]);
            }

            // Print the current train structure
            printTrain(train);
        }
        else if (command == "L") {
            // Leave the wagon at the station
            int wagonPosition;
            std::cin >> wagonPosition;

            if (wagonPosition >= 0 && wagonPosition < train.size()) {
                train.erase(train.begin() + wagonPosition);
            }

            // Print the current train structure
            printTrain(train);
        }
        else if (command == "E") {
            // End of processing commands
            break;
        }
    }

    return 0;
}
