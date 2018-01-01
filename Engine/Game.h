/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <iostream>
#include  <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void drowbox(int x, int y, int r, int g, int b, int size);
	void grad();
	void eatgen(int xdist, int ydist);


	
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

	int xdist[12], ydist[12];
	int x1, x2;
	int y1,y2;
	int vx = 0;
	int vy = 0;
	int coll = 0;
	double speed = 0.1;
	static const int sz = 20;
	int fps = 60;
	int wid = gfx.ScreenWidth;
	int hih = gfx.ScreenHeight;
	int cntr = 3;

	std::random_device rd;
	std::mt19937 rng;
	//std::uniform_int_distribution<int> xdist;
	//std::uniform_int_distribution<int> ydist;

	/********************************/
};