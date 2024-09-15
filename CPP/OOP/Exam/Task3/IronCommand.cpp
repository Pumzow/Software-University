#include "IronCommand.h"

std::string IronCommand::execute(void) const {
    // Check if the ID exists in the storage
    if (!existsData(getId())) {
        return abortMessage("Iron command failed due to invalid ID \"" + getId() + "\".");
    }

    // Retrieve existing data
    auto data = getData(getId());
    unsigned totalMaterial = data.mat; // Material remains unchanged
    unsigned totalTime = data.time + getTime(); // Adding ironing time

    // Remove the old entry
    eraseData(getId());

    // Insert the updated entry
    Processor::TimeAndMaterial tm(totalTime, totalMaterial);
    if (!insertData(tm)) { // Ensure insert is successful
        return abortMessage("Failed to update data for ID \"" + getId() + "\".");
    }

    return "Piece ironed: " + getId() + ", total time now " + std::to_string(totalTime) + " minutes.";
}
