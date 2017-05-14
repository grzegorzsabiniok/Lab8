#pragma once
class Item {
	int strength;
public:
	Item(int _strength) {

		strength = _strength;
	}
	/*
	void Interact(Player *_player) {
		onMap = false;
		_player->AddItem(this);
		onMap = false;
	}
	*/
	int GetStrength() {
		return strength;
	}
};
