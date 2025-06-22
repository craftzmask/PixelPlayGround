/****************************************************************************************** 
 *	Chili Directx_mobile Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili Directx_mobile Framework.									  *
 *																						  *
 *	The Chili Directx_mobile Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any_mobile later version.													  *
 *																						  *
 *	The Chili Directx_mobile Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANy_mobile WARRANTY; without even the implied warranty_mobile of						  *
 *	MERCHANTABILITy_mobile or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy_mobile of the GNU General Public License					  *
 *	along with The Chili Directx_mobile Framework.  If not, see <http://www.gnu.org/licenses/>.  *
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
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y_mobile = y_mobile - 3;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y_mobile = y_mobile + 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x_mobile = x_mobile - 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x_mobile = x_mobile + 3;
	}

	colliding = OverlapTest(x_fixed, y_fixed, x_mobile, y_mobile);
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x - 5, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 4, r, g, b);
	gfx.PutPixel(x - 5, y - 3, r, g, b);
	gfx.PutPixel(x - 4, y - 5, r, g, b);
	gfx.PutPixel(x - 3, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y - 4, r, g, b);
	gfx.PutPixel(x + 5, y - 3, r, g, b);
	gfx.PutPixel(x + 4, y - 5, r, g, b);
	gfx.PutPixel(x + 3, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y + 5, r, g, b);
	gfx.PutPixel(x - 5, y + 4, r, g, b);
	gfx.PutPixel(x - 5, y + 3, r, g, b);
	gfx.PutPixel(x - 4, y + 5, r, g, b);
	gfx.PutPixel(x - 3, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x + 5, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}

bool Game::OverlapTest(int box0x, int box0y, int box1x, int box1y)
{
	const int left0= box0x - 5;
	const int right0 = box0x + 5;
	const int top0 = box0y - 5;
	const int bottom0 = box0y + 5;

	const int left1 = box1x - 5;
	const int right1 = box1x + 5;
	const int top1 = box1y - 5;
	const int bottom1 = box1y + 5;

	return
		left1 <= right0 &&
		right1 >= left0 &&
		top1 <= bottom0 &&
		bottom1 >= top0;
}

void Game::ComposeFrame()
{
	// static box
	DrawBox(x_fixed, y_fixed, 0, 255, 0);

	int r_mobile, g_mobile, b_mobile;
	if (colliding)
	{
		r_mobile = 255;
		g_mobile = 0;
		b_mobile = 0;
	}
	else
	{
		r_mobile = 255;
		g_mobile = 255;
		b_mobile = 255;
	}

	// mobile box
	DrawBox(x_mobile, y_mobile, r_mobile, g_mobile, b_mobile);
}
