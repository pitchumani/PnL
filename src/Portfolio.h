#ifndef PNL_PORTFOLIO_H_
#define PNL_PORTFOLIO_H_
#include <vector>
#include <string>
#include <map>
#include <optional>
#include "Position.h"

class Portfolio {
    std::vector<Position> positions_;

public:
    Portfolio() = default;
    ~Portfolio() = default;

    void addPosition(const Position& position);
    double getTotalPnL(const std::map<std::string, double>& currentPrices) const;
    const std::vector<Position>& getPositions() const { return positions_; }
    void clear() { positions_.clear(); }
    std::optional<Position> getPosition(const std::string& symbol) const;
    bool removePosition(const std::string& symbol);
    size_t size() const { return positions_.size(); }
};

#endif // PNL_PORTFOLIO_H_