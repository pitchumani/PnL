#ifndef PNL_POSITION_H_
#define PNL_POSITION_H_

class Position {
    std::shared_ptr<Instrument> instrument;
    double purchasePrice;
    int quantity;  // TODO: fractional (decimal) quantities support?

public:
    Position() {}
    const std::string& getInstrumentSymbol() const;
    double calculatePnL(double currentPrice) const;
};

#endif  // PNL_POSITION_H_

