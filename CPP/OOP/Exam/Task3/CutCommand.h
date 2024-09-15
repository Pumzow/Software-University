#ifndef CUTCOMMAND_H
#define CUTCOMMAND_H

#include "TimedCommand.h"
#include "MaterialCommand.h"

class CutCommand : public TimedCommand, public MaterialCommand {

    public:

        CutCommand(Processor & proc) : Command(proc), TimedCommand(proc), MaterialCommand(proc) {}

        virtual std::string getName(void) const override { return "cut"; }

        virtual void read(std::istream & istr) override {
            Command::read(istr); // read the main Command (virtual inheritance!)
            TimedCommand::read(istr); // read the TimedCommand
            MaterialCommand::read(istr); // read the MaterialCommand
        }

        virtual std::string execute(void) const override;

};

#endif