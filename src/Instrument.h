#ifndef PNL_INSTRUMENT_H_
#define PNL_INSTRUMENT_H_

#include<string>

class Instrument {
protected:
    std::string symbol_;
    std::string name_;
public:
    Instrument(const std::string& sym, const std::string& nam) :
        symbol_(sym), name_(nam) {}
    ~Instrument() = default;
    std::string& getSymbol() { return symbol_; }
    std::string& getName() { return name_; }
    virtual double calculateUnitPnL(double currentPrice,
                                    double purchaseProce) const = 0;
};

#endif  // PNL_INSTRUMENT_H_

