#pragma once
#include"Object.h"
#include"Interactive.h"
#include"Item.h"

class ItemContainer :public Object, public Interactive {
	Item *item;
public:
	int GetValue() {
		return item->GetStrength();
	}
	ItemContainer(Item *_item) {
		item = _item;
		icon = 'I';
	}
	bool Interact(Player *_player) {
		if (_player->GetPosition().x == position.x && _player->GetPosition().y == position.y) {
			_player->AddItem(item);
			std::cout << "zebrales item";
			return true;
		}
		return false;
	}
	Item* GetItem() {
		return item;
	}
};
