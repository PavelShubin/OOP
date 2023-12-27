#pragma once

#include "NPC.hpp"
#include "werewolf.hpp"
#include "outlaw.hpp"
#include "bear.hpp"

class NPCVisitor {
public:
    [[nodiscard]] virtual bool visit(const std::shared_ptr<Bear>&) const = 0;
    [[nodiscard]] virtual bool visit(const std::shared_ptr<Werewolf>&) const = 0;
    [[nodiscard]] virtual bool visit(const std::shared_ptr<Outlaw>&) const = 0;
};

class WerewolfVisitor : public NPCVisitor {
public:
    [[nodiscard]] bool visit(const std::shared_ptr<Bear>&) const override { return false; }
    [[nodiscard]] bool visit(const std::shared_ptr<Werewolf>&) const override { return false; }
    [[nodiscard]] bool visit(const std::shared_ptr<Outlaw>&) const override { return true; }
};

class OutlawVisitor : public NPCVisitor {
public:
    [[nodiscard]] bool visit(const std::shared_ptr<Bear>&) const override { return true; }
    [[nodiscard]] bool visit(const std::shared_ptr<Werewolf>&) const override { return false; }
    [[nodiscard]] bool visit(const std::shared_ptr<Outlaw>&) const override { return false; }
};

class BearVisitor : public NPCVisitor {
public:
    [[nodiscard]] bool visit(const std::shared_ptr<Bear>&) const override { return false; }
    [[nodiscard]] bool visit(const std::shared_ptr<Werewolf>&) const override { return true; }
    [[nodiscard]] bool visit(const std::shared_ptr<Outlaw>&) const override { return false; }
};

class VisitorFactory {
public:
    static std::shared_ptr<NPCVisitor> CreateVisitor(const NPCType& type) {
        std::shared_ptr<NPCVisitor> result;
        switch (type) {
            case NPCType::WerewolfType:
                result = std::static_pointer_cast<NPCVisitor>(std::make_shared<WerewolfVisitor>());
                break;

            case NPCType::OutlawType:
                result = std::static_pointer_cast<NPCVisitor>(std::make_shared<OutlawVisitor>());
                break;

            case NPCType::BearType:
                result = std::static_pointer_cast<NPCVisitor>(std::make_shared<BearVisitor>());
                break;
            default:
                break;
        }
        return result;
    }
};

