#include "werewolf.hpp"

Werewolf::Werewolf(int _x, int _y): NPC(NPCType::WerewolfType, _x, _y) {}

Werewolf::Werewolf(std::istream& is): NPC(NPCType::WerewolfType, is) {}

bool Werewolf::accept(const std::shared_ptr<NPC>& attacker) const {
    auto AttackerVisitor = VisitorFactory::CreateVisitor(attacker->type);

    std::shared_ptr<NPC> npc = std::const_pointer_cast<NPC>(shared_from_this());
    std::shared_ptr<Werewolf> defender = std::dynamic_pointer_cast<Werewolf>(npc);

    bool win = AttackerVisitor->visit(defender);
    attacker->fightNotify(defender, win);

    return win;
}

void Werewolf::print() const {
    std::cout << *this;
}

void Werewolf::save(std::ostream& os) const {
    os << *this;
}

std::ostream &operator<<(std::ostream& os, const Werewolf& werewolf) {
    os << *static_cast<const NPC *>(&werewolf) << std::endl;
    return os;
}
