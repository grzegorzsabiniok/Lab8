#pragma once
#include"Player.h"
#include<iostream>
class Interactive {
public:
	virtual bool Interact(Player *_player) { return false; }
};


