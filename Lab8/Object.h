#pragma once
#include"Position.h"
class Object {
	protected:
	Position position;
	bool onMap = true;
	char icon='$';
public:
	Object() {}
	virtual void SetPosition(int _x, int _y) {
		position.x = _x;
		position.y = _y;
	}
	virtual Position GetPosition() {
		return position;
	}
	char GetIcon() {
		return icon;
	}
	virtual int GetValue() { return 0; }
};