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
	gfx( wnd ),
	rng(rd())
{

	int xd = wid / sz;
	int yd = hih / sz;
	std::uniform_int_distribution<int> xdu(0, xd-1);
	std::uniform_int_distribution<int> ydu(0,yd-1);
	for (int i = 0;i < 12; ++i)
	{
		xdist[i] = xdu(rng)*sz;
		ydist[i] = ydu(rng)*sz;
		xdu.operator()(rng);
		ydu.operator()(rng);
	}
	x1 = xd *sz/2;
	y1 = yd * sz/2;
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

	if (!wnd.kbd.KeyIsEmpty())
	{
		if (wnd.kbd.KeyIsPressed(VK_UP)) { vy =  - (sz); vx = 0; }
		if (wnd.kbd.KeyIsPressed(VK_DOWN)) { vy =  (sz); vx = 0; }
		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) { vx = (sz); vy = 0; }
		if (wnd.kbd.KeyIsPressed(VK_LEFT)) { vx = -(sz); vy = 0; }
	}
	if(speed >60)
	{
		speed = 0;
		y1 = y1 + vy;
		x1 = x1 + vx;
	}

	speed += 5;

	//set boundary to object not to pass graphic boundary

		if ((x1) > wid-sz)x1 = wid -sz;
		if ((y1) > hih-sz) y1 = hih-sz;
		if (x1 < 0)x1 = 0;
		if (y1 < 0)y1 = 0;


}



void Game::drowbox(int x, int y, int r, int g, int b,int size)
{
	for (auto i = 0; i < size; ++i)
		for (auto j = 0; j < size; ++j)
			gfx.PutPixel(x+i,y+j,r,g,b);
		

}

void Game::grad()
{
	for (auto i = 0; i < wid; i += sz)
	{
		for (auto j = 0; j < hih ; j += sz)
			gfx.PutPixel(i, j, 255,255, 255);
	}

}

void Game::eatgen(int xdist,int  ydist)
{

	//int xtemp = xdist;
	//int ytemp = ydist;
	unsigned int xtemp = (xdist );
	unsigned int ytemp = (ydist) ;

	drowbox(xtemp,ytemp, 255, 255, 255, sz);

}


void Game::ComposeFrame()
{
	//Drawing
	grad();
	//draw object 1 
	
	drowbox(x1, y1, coll, 25, 255, sz);
	//draw object 2
	
	//if (cntr)
	//{
	//	if (!(x1 == x2 && y1 == y2))
	//	{
	//		
	//		drowbox(x2, y2, 255, 255, 255,sz);
	//	}

	//	else cntr--;
	//	
	//}
	for (int i = 0; i < 12; ++i)
		eatgen(xdist[i],ydist[i]);
	//drowbox(x2, y2, 255, 255, 255, sz);
	//eatgen(3);
}
