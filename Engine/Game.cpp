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
#include <cctype>
#include <cassert>

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
	//keyss1 = wnd.kbd.ReadChar();




	

	//test1 = wnd.kbd.KeyIsEmpty();
	//test2 = wnd.kbd.KeyIsPressed('j');
	//test2 = wnd.kbd.
	if (!wnd.kbd.KeyIsEmpty())
	{
		if (wnd.kbd.KeyIsPressed(VK_UP)) { vy = -1; vx = 0; }
		if (wnd.kbd.KeyIsPressed(VK_DOWN)) { vy = 1; vx = 0; }
		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) { vx = 1; vy = 0; }
		if (wnd.kbd.KeyIsPressed(VK_LEFT)) { vx = -1; vy = 0; }
	}

	if(speed < 0)
		{
			y1 = y1 + vy;
			x1 = x1 + vx;
			keypress = false;
			speed = sz;
		}	
	else
		{
		speed-=sz;
		}
	
	//set boundary to object not to pass graphic boundary

		if ((x1) > wid-sz)x1 = wid -sz;
		if ((y1) > hih-sz) y1 = hih-sz;
		if (x1 < 0)x1 = 0;
		if (y1 < 0)y1 = 0;

	//object two color red when cross tow object collesion ;) 
		if ((x2 > x1 - sz && x2 < x1 + sz) && (y2 > y1 - sz && y2 < y1 + sz))coll = 0;
		else coll = 255;



}



void Game::drowbox(int x, int y, int r, int g, int b,int size)
{
	for (auto i = 0; i < size; ++i)
		for (auto j = 0; j < size; ++j)
			gfx.PutPixel(x+i,y+j,r,g,b);
		

}

void Game::ComposeFrame()
{
	//Drawing

	//draw object 1 
	drowbox(x1, y1, 255, 255, 255,sz);
	//draw object 2
	drowbox(x2, y2, coll, 25, 255, sz);

}
