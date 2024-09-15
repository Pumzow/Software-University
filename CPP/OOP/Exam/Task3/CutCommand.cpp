#include "CutCommand.h"

std::string CutCommand::execute(void) const {
    // check if this ID already exists in the storage
    if (existsData(getId())) {
        // if yes - abort with that error
        return abortMessage("Cut command failed due to duplicate ID \"" + getId() + "\".");
    }

    // we can create a new element now:
    Processor::TimeAndMaterial tm(getTime(), getMaterial());
    insertData(tm); // insert the new element in the storage

    return "Piece created: " + getId() + " using " + std::to_string(getMaterial()) + " materials in " + std::to_string(getTime()) + " minutes.";
}
