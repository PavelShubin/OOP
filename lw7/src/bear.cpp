#include "bear.hpp"

Bear::Bear(const std::string& _name, int _x, int _y): NPC(NPCType::BearType, _name, _x, _y) {
    moveDistance = 5, killDistance = 10;
}

Bear::Bear(std::istream& is): NPC(NPCType::BearType, is) {
    moveDistance = 5, killDistance = 10;
}

bool Bear::accept(const std::shared_ptr<NPC>& attacker) const {
    auto AttackerVisitor = VisitorFactory::CreateVisitor(attacker -> getType());

    std::shared_ptr<NPC> npc = std::const_pointer_cast<NPC>(shared_from_this());
    std::shared_ptr<Bear> defender = std::dynamic_pointer_cast<Bear>(npc);

    bool win = (AttackerVisitor -> visit(defender));
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
