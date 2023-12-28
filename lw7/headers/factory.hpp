#pragma once
#include "NPC.hpp"
#include "werewolf.hpp"
#include "outlaw.hpp"
#include "bear.hpp"
#include "observers.hpp"

class Factory {
public:
    static std::shared_ptr<NPC> Create(const NPCType& type, const std::string& name, int x, int y) {
        std::shared_ptr<NPC> result;

        switch (type) {
            case NPCType::WerewolfType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(name, x, y));
                break;

            case NPCType::OutlawType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Outlaw>(name, x, y));
                break;

            case NPCType::BearType: // заменено с SquirrelType на BearType
                result = std::static_pointer_cast<NPC>(std::make_shared<Bear>(name, x, y));
                break;

            default:
                break;
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }

    static std::shared_ptr<NPC> Create(const NPCType& type, std::istream& is) {
        std::shared_ptr<NPC> result;
        switch (type) {
            case NPCType::WerewolfType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(is));

            case NPCType::OutlawType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Outlaw>(is));
                break;

            case NPCType::BearType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Bear>(is));
                break;

            default:
                break;
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
};
