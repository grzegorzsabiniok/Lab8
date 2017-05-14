#pragma once
#include<list>
#include"Object.h"
#include"Interactive.h"
#include"Enemy.h"
#include"Potion.h"
#include"Player.h"
#include"ItemContainer.h"
#include"Item.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<conio.h>
class Board {
	int x, y;
	std::list<Object*> objects;
	std::list<Interactive*> interactive;
	Player* player;
public:
	void Start() {
		
		
		while (true) {
			char input = _getch();
			if (input == 'q') {
				std::cout << "wyjscie";
				return;
			}
			player->Move(input);
			for (Object* i : objects) {
				if (Enemy* temp = dynamic_cast<Enemy*>(i)) {
					temp->Move(player->GetPosition());
				}
			}
			Show();
			std::cout << "zycie: " << player->GetHp() << " sila: "<<player->GetStrength()
				<<"\n__________________________\nwydarzenia:\n" ;
			int enemyCount = 0;
			for (Interactive* i : interactive) {
				if (dynamic_cast<Enemy*>(i)) {
					enemyCount++;
				}
				if (i->Interact(player)) {

					interactive.remove(i);
					objects.remove(dynamic_cast<Object*>(i));
					break;
				}

			}
			std::cout << "\n___________________________\ndo zabicia " << enemyCount<<"\n";
			if (enemyCount < 1) {
				system("cls");
				std::cout << "Wygrales";
				return;
			}
			if (player->GetHp() <= 0) {
				system("cls");
				std::cout << "koniec gry";
				return;
			}
		}
	}
	void Show() {
		system("cls");
		for (int Y = 0; Y < y; Y++) {
			for (int X = 0; X < x; X++) {
				bool t = false;
				for (Object* i : objects) {
					if (i->GetPosition().x == X && i->GetPosition().y == Y) {
						std::cout << i->GetIcon();
						t = true;
						break;
					}
				}
				if(!t)
				std::cout << " ";
			}
			std::cout <<(char)475<< "\n";
		}
		for (int X = -1; X < x; X++) {
			std::cout << (char)475;
		}
		std::cout << "\n";
	}
	void RandomMap(int _x,int _y,int _enemy,int _potion,int _item,int _max) {
		player = new Player();
		objects.push_front(player);
		x = _x;
		y = _y;
		srand(time(NULL));
		for (int i = 0; i < _enemy; i++) {
			Enemy* temp = new Enemy(_max);
			temp->SetPosition(rand() % x, rand() % y);
			objects.push_back(temp);
			interactive.push_back(temp);
		}
		for (int i = 0; i < _potion; i++) {
			Potion* temp = new Potion(_max);
			temp->SetPosition(rand() % x, rand() % y);
			objects.push_back(temp);
			interactive.push_back(temp);
		}
		for (int i = 0; i < _item; i++) {
			Item* t = new Item(_max);
			ItemContainer* temp = new ItemContainer(t);
			temp->SetPosition(rand() % x, rand() % y);
			objects.push_back(temp);
			interactive.push_back(temp);
		}
	}
	void Write(std::string name) {
		std::ofstream file(name);
		file << objects.size() << " " << x << " " << y <<"\n";
		for (Object* i : objects) {
			file << i->GetIcon() << " " <<i->GetPosition().x << " " << i->GetPosition().y << " " <<i->GetValue()<< "\n";
		}
		file.close();
	}
	void Read(std::string name) {
		std::ifstream file(name);
		int size;
		file >> size;
		file >> x;
		file >> y;
		for (int i = 0; i < size; i++) {
			char type;
			file >> type;
			switch (type)
			{
			case 'X': {
				int tx, ty, t;
				file >> tx;
				file >> ty;
				file >> t;
				player = new Player();
				player->Damage(-t);
				player->SetPosition(tx, ty);
				objects.push_front(player);
			}
					  break;
			case 'P': {
				int tx,ty,t;
				file >> tx;
				file >> ty;
				file >> t;
				Potion* temp = new Potion(t);
				temp->SetPosition(tx,ty);
				objects.push_back(temp);
				interactive.push_back(temp);
			}
					  break;
			case 'E': {
				int tx, ty, t;
				file >> tx;
				file >> ty;
				file >> t;
				Enemy* temp = new Enemy(t);
				temp->SetPosition(tx, ty);
				objects.push_back(temp);
				interactive.push_back(temp);
			}
					  break;
			case 'I': {
				int tx, ty, t;
				file >> tx;
				file >> ty;
				file >> t;
				Item *t2 = new Item(t);
				ItemContainer* temp = new ItemContainer(t2);
				temp->SetPosition(tx, ty);
				objects.push_back(temp);
				interactive.push_back(temp);
			}
					  break;
			default:
				break;
			}
		}
	}
};