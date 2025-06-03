#ifndef PNL_POSITION_H_
#define PNL_POSITION_H_

#include <memory>
#include <string>
#include <stdexcept>
#include <utility>

#include "Instrument.h"

class Position {
    std::shared_ptr<Instrument> instrument;
    double purchasePrice;
    int quantity;  // TODO: fractional (decimal) quantities support?

public:
    Position(std::shared_ptr<Instrument> instr, double price, int qty);
    ~Position() = default;
    const std::string& getInstrumentSymbol() const;
    double calculatePnL(double currentPrice) const;
    double getPurchasePrice() const { return purchasePrice; }
    int getQuantity() const { return quantity; }
};

#endif  // PNL_POSITION_H_
