#pragma once
#include"Object.h"
#include"Item.h"
#include<list>
class Player :public Object {
	int hp;
	std::list<Item*> items;
	int itemsCount=0;
public:
	Player() {
		icon = 'X';
		hp = 10;
	}
	int GetValue() {
		return hp;
	}
	void Move(char input) {
		switch (input)
		{
		case 'w': {
			position.y--;

		}
				  break;
		case 's': {
			position.y++;

		}
				  break;
		case 'a': {
			position.x--;

		}
				  break;
		case 'd': {
			position.x++;

		}
				  break;
		default:
			break;
		}

	}
	void AddItem(Item *_item) {
		items.push_back(_item);
		itemsCount++;
	}
	int GetStrength() {
		int temp = 0;
		for (Item* i : items) {
			temp += i->GetStrength();
		}
		return temp;
	}
	void Damage(int _value) {
		hp -= _value;
		onMap = false;
	}
	int GetHp() {
		return hp;
	}
};