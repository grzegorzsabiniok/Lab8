#pragma once
#include"Object.h"
#include"Interactive.h"
class Potion :public Object,public Interactive {
	int vitality;
public:
	int GetValue() {
		return vitality;
	}
	Potion(int _vitality) {
		vitality = _vitality;
		icon = 'P';
	}
	bool Interact(Player *_player) {
		if (_player->GetPosition().x == position.x && _player->GetPosition().y == position.y) {
			_player->Damage(-vitality);
			std::cout << "wypiles miksturke";
			return true;
		}
		return false;
	}
};