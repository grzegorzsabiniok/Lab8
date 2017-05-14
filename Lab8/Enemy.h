#pragma once
#include"Object.h"
#include"Interactive.h"
class Enemy :public Object,public Interactive {

	int strength;
	bool dead=false;
public:
	int GetValue() {
		return strength;
	}
	Enemy(int _strength) {
		icon = 'E';
		strength = _strength;
	}
	void Move(Position _position) {
		int temp = abs(_position.x - position.x) ^ 2 + abs(_position.y - position.y) ^ 2;
		if (temp < 5) {
			if (position.x > _position.x) {
				position.x--;
			}
			else {
				if (position.x < _position.x) {
					position.x++;
				}
			}
			if (position.y > _position.y) {
				position.y--;
			}
			else {
				if (position.y < _position.y) {
					position.y++;
				}
			}
		}
	}
	bool Interact(Player *_player) {
		if (_player->GetPosition().x == position.x && _player->GetPosition().y == position.y) {
			int temp = strength - _player->GetStrength();

			if (temp > 0) {
				_player->Damage(temp);
			}
			std::cout << "walka";
			return true;
		}
		return false;

	}
};