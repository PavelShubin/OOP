#pragma once

#include "NPC.hpp"
#include "visitor.hpp"

class Bear final : public NPC {
public:
    Bear(int, int);
    explicit Bear(std::istream&);

    void print() const override;
    void save(std::ostream&) const override;
    bool accept(const std::shared_ptr<NPC>&) const override;

    friend std::ostream& operator<<(std::ostream&, const Bear&);

    ~Bear() = default;
}; 

