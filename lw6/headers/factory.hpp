#pragma once

#include "NPC.hpp"
#include "werewolf.hpp"
#include "bear.hpp"
#include "outlaw.hpp"
#include "observers.hpp"


class Factory {
public:
    static std::shared_ptr<NPC> Create(const NPCType& npcType, int x, int y) {
        std::shared_ptr<NPC> result;
        switch (npcType) {
            case NPCType::BearType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Bear>(x, y));
                break;
            case NPCType::OutlawType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Outlaw>(x, y));
                break;
            case NPCType::WerewolfType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(x, y));
                break;
            default:
                result = nullptr;
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
    
    static std::shared_ptr<NPC> Create(const NPCType& npcType, std::istream& is) {
        std::shared_ptr<NPC> result;
        switch (npcType) {
            case NPCType::BearType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Bear>(is));
                break;
            case NPCType::OutlawType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Outlaw>(is));
                break;
            case NPCType::WerewolfType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(is));
                break;
            default:
                result = nullptr;
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
}; 

