#include "SewCommand.h"
#include<vector>

using namespace std;

std::string SewCommand::execute(void) const {
    std::vector<std::string> missingIds;
    for (const auto& id : elements) {
        if (!existsData(id)) {
            missingIds.push_back(id);
        }
    }

    if (!missingIds.empty()) {
        return abortMessage("Sew command failed due to invalid ID \"" + missingIds.front() + "\".");
    }

    // Calculate total time and material used for the new piece
    unsigned totalMaterial = 0, totalTime = 0;
    for (const auto& id : elements) {
        auto data = getData(id);
        totalMaterial += data.mat;
        totalTime += data.time;
    }

    // Adding the time for sewing itself
    totalTime += getTime();

    Processor::TimeAndMaterial tm(totalTime, totalMaterial);
    insertData(tm); // insert the new sewn piece into the storage

    return "Piece sewn: " + getId() + " using " + std::to_string(totalMaterial) + " materials in " + std::to_string(totalTime) + " minutes.";
}