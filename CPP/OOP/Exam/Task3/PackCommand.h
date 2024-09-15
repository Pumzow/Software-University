#ifndef PACKCOMMAND_H
#define PACKCOMMAND_H

#include "Command.h"

class PackCommand : public Command {
public:
    PackCommand(Processor& proc) : Command(proc) {}

    virtual std::string getName(void) const override { return "pack"; }

    virtual void read(std::istream& istr) override {
        // Pack command does not need to read anything, it just triggers packaging
    }

    virtual std::string execute(void) const override;
};

#endif
