#include "PackCommand.h"
#include "Processor.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

std::string join(const std::vector<std::string>& vec, const std::string& delim) {
    std::ostringstream oss;
    for (const auto& item : vec) {
        if (&item != &vec.front()) {
            oss << delim;
        }
        oss << item;
    }
    return oss.str();
}



std::string PackCommand::execute(void) const {
    if (proc.storage.empty()) {
        return "No items to pack.";  // Handle the case where there are no items
    }

    std::vector<std::string> itemIDs;
    unsigned totalMaterial = 0, totalTime = 0;

    // Iterate through the storage to summarize the materials and time
    for (const auto& entry : proc.storage) {
        itemIDs.push_back(entry.first);  // Collect all item IDs
        totalMaterial += entry.second.mat;  // Sum up all materials used
        totalTime += entry.second.time;  // Sum up all time spent
    }

    // Sort the item IDs for consistent output
    std::sort(itemIDs.begin(), itemIDs.end());

    // Create a string to join all item IDs into one comma-separated string
    std::string itemIDsStr = join(itemIDs, ", ");

    // Prepare the final message to output the packed items
    std::string packedItems = "Packing and shipping new order: \"" +
        itemIDsStr +
        "\". Production material: " + std::to_string(totalMaterial) +
        ", production time: " + std::to_string(totalTime) + ".";

    return packedItems;
}