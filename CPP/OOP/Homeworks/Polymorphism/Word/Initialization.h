#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <memory>
#include "CommandInterface.h"

class CutTransform : public TextTransform {
private:
    std::string lastCut;

public:
    virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
        if (startIndex != endIndex) {
            lastCut = text.substr(startIndex, endIndex - startIndex);
            text.erase(startIndex, endIndex - startIndex);
        }
        else {
            // If startIndex == endIndex, clear the last cut
            lastCut.clear();
        }
    }

    const std::string& getLastCut() const {
        return lastCut;
    }
};

class PasteTransform : public TextTransform {
private:
    std::string lastCut;

public:
    PasteTransform(const std::string& lastCut) : lastCut(lastCut) {}

    virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
        if (!lastCut.empty()) {
            text.replace(startIndex, endIndex - startIndex, lastCut);
        }
    }
};

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
    // Create CommandInterface instance
    std::shared_ptr<CommandInterface> interface = std::make_shared<CommandInterface>(text);

    // Initialize commands
    interface->init();

    // Add cut command
    interface->addCommand("cut", std::make_shared<CutTransform>());

    // Add paste command
    std::shared_ptr<CutTransform> cutTransform = std::make_shared<CutTransform>();
    std::shared_ptr<PasteTransform> pasteTransform = std::make_shared<PasteTransform>(cutTransform->getLastCut());
    interface->addCommand("paste", pasteTransform);

    return interface;
}

#endif // INITIALIZATION_H
