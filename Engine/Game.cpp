/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{		
	//keyboard press logic key(up,down ,left ,right)//
		if (wnd.kbd.KeyIsPressed(VK_UP)) { vy -= 1; keyp = true; }
		if (wnd.kbd.KeyIsPressed(VK_DOWN)) { vy += 1; keyp = true; }
		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) { vx += 1; keyp = true; }
		if (wnd.kbd.KeyIsPressed(VK_LEFT)) { vx -= 1; keyp = true; }

	// control velocity of speed of object
		if (!(keyp))
		{
			vx = 0;
			vy = 0;
		}
		else 
		{
			y = y + vy;
			x = x + vx;
			keyp = false;
		}
			
	//set boundary to object not to pass graphic boundary
		auto wid = gfx.ScreenWidth;
		auto hih = gfx.ScreenHeight;
		if ((x) > wid-20)x = wid -20;
		if ((y) > hih-20) y = hih-20;
		if (x < 0)x = 0;
		if (y < 0)y = 0;

	//object two color red when cross tow object collesion ;) 
		if ((x2 > x - 20 && x2 < x + 20) && (y2 > y - 20 && y2 < y + 20))coll = 0;
		else coll = 255;



}

void Game::ComposeFrame()
{
	//Draw .....

	//draw object 1 
	for (auto i = 0; i < 20; ++i)
		for (auto j = 0; j < 20; ++j)
		{
			gfx.PutPixel(x + i, y + j, 255, 255, 255);
		}
	//draw object 2
	for (auto i = 0; i < 20; ++i)
		for (auto j = 0; j < 20; ++j)
		{
			gfx.PutPixel(x2 + i, y2 + j, 255, coll, coll);
		}
}