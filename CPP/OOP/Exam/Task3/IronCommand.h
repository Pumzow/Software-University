#ifndef IRONCOMMAND_H
#define IRONCOMMAND_H

#include "TimedCommand.h"

class IronCommand : public TimedCommand {

public:
    IronCommand(Processor& proc) : Command(proc), TimedCommand(proc) {}

    virtual std::string getName(void) const override { return "iron"; }

    virtual void read(std::istream& istr) override {
        Command::read(istr);  // Read the main Command (ID of the piece to iron)
        TimedCommand::read(istr);  // Read the TimedCommand (time to iron)
    }

    virtual std::string execute(void) const override;

};

#endif
