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

	const int left_fixed = x_fixed - 5;
	const int right_fixed = x_fixed + 5;
	const int top_fixed = y_fixed - 5;
	const int bottom_fixed = y_fixed + 5;

	const int left_mobile = x_mobile - 5;
	const int right_mobile = x_mobile + 5;
	const int top_mobile = y_mobile - 5;
	const int bottom_mobile = y_mobile + 5;

	colliding =
		left_mobile <= right_fixed &&
		right_mobile >= left_fixed &&
		top_mobile <= bottom_fixed && 
		bottom_mobile >= top_fixed;
}

void Game::ComposeFrame()
{
	// static box
	gfx.PutPixel(x_fixed - 5, y_fixed - 5, 255, 255, 255);
	gfx.PutPixel(x_fixed - 5, y_fixed - 4, 255, 255, 255);
	gfx.PutPixel(x_fixed - 5, y_fixed - 3, 255, 255, 255);
	gfx.PutPixel(x_fixed - 4, y_fixed - 5, 255, 255, 255);
	gfx.PutPixel(x_fixed - 3, y_fixed - 5, 255, 255, 255);				
	gfx.PutPixel(x_fixed + 5, y_fixed - 5, 255, 255, 255);
	gfx.PutPixel(x_fixed + 5, y_fixed - 4, 255, 255, 255);
	gfx.PutPixel(x_fixed + 5, y_fixed - 3, 255, 255, 255);
	gfx.PutPixel(x_fixed + 4, y_fixed - 5, 255, 255, 255);
	gfx.PutPixel(x_fixed + 3, y_fixed - 5, 255, 255, 255);
	gfx.PutPixel(x_fixed - 5, y_fixed + 5, 255, 255, 255);
	gfx.PutPixel(x_fixed - 5, y_fixed + 4, 255, 255, 255);
	gfx.PutPixel(x_fixed - 5, y_fixed + 3, 255, 255, 255);
	gfx.PutPixel(x_fixed - 4, y_fixed + 5, 255, 255, 255);
	gfx.PutPixel(x_fixed - 3, y_fixed + 5, 255, 255, 255);
	gfx.PutPixel(x_fixed + 5, y_fixed + 5, 255, 255, 255);
	gfx.PutPixel(x_fixed + 5, y_fixed + 4, 255, 255, 255);
	gfx.PutPixel(x_fixed + 5, y_fixed + 3, 255, 255, 255);
	gfx.PutPixel(x_fixed + 4, y_fixed + 5, 255, 255, 255);
	gfx.PutPixel(x_fixed + 3, y_fixed + 5, 255, 255, 255);

	int r_mobile, g_mobile, b_mobile;
	if (colliding)
	{
		r_mobile = 255;
		g_mobile = 0;
	}
	else
	{
		r_mobile = 0;
		g_mobile = 255;
	}

	// mobile box
	gfx.PutPixel(x_mobile - 5, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile - 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile - 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 4, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 3, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 4, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 3, y_mobile - 5, r_mobile, g_mobile, b_mobile);	
	gfx.PutPixel(x_mobile - 5, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile + 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile + 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 4, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 3, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 4, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 3, y_mobile + 5, r_mobile, g_mobile, b_mobile);
}
