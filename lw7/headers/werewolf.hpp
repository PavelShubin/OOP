#pragma once

#include "NPC.hpp"
#include "visitor.hpp"

class Werewolf : public NPC{
public:
    Werewolf(const std::string&, int, int);
    explicit Werewolf(std::istream&);

    void print() const override;
    void save(std::ostream&) const override;
    bool accept(const std::shared_ptr<NPC>&) const override;

    friend std::ostream& operator<<(std::ostream&, const Werewolf&);

    ~Werewolf() = default;
};
