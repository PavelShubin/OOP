#include "bear.hpp"

Bear::Bear(int _x, int _y): NPC(NPCType::BearType, _x, _y) {}

Bear::Bear(std::istream& is): NPC(NPCType::BearType, is) {}

bool Bear::accept(const std::shared_ptr<NPC>& attacker) const {
    auto AttackerVisitor = VisitorFactory::CreateVisitor(attacker -> type);

    std::shared_ptr<NPC> npc = std::const_pointer_cast<NPC>(shared_from_this());
    std::shared_ptr<Bear> defender = std::dynamic_pointer_cast<Bear>(npc);

    bool win = AttackerVisitor -> visit(defender);
    attacker -> fightNotify(defender, win);

    return win;
}

void Bear::print() const {
    std::cout << *this;
}

void Bear::save(std::ostream& os) const {
    os << *this;
}

std::ostream &operator<<(std::ostream& os, const Bear& bear) {
    os << *static_cast<const NPC *>(&bear) << std::endl;
    return os;
}
