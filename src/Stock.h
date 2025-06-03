#ifndef PNL_STOCK_H_
#define PNL_STOCK_H_

#include "Instrument.h"

class Stock : public Instrument {
public:
    Stock(std::string sym, std::string nam);
    ~Stock() = default;
    double calculateUnitPnL(double currPrice, double purPrice) const override;
};

#endif  // PNL_STOCK_H_

