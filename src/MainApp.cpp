/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of Henry Hudson's Revenge. A Cross Platform project,      **
**  also Known as HHR_X and referd to as such thoughout.						**
**  																			**
**  HHR_X is free software: you can redistribute it and/or modify			  	**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  HHR_X is distributed in the hope that it will be useful,					**
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with HHR_X.  If not, see <http://www.gnu.org/licenses/>.			  	**
**  																			**
**********************************************************************************/


#include "MainApp.h"


/*Singleton Suff */



MainApp* MainApp::m_pInstance = NULL;

MainApp* MainApp::Instance()
{
    if(!m_pInstance)
    {
        m_pInstance = new MainApp();
    }

    return m_pInstance;
}



/****************/




MainApp::MainApp()
{
	MainWindow = NULL;

	Running = true;
}

int MainApp::OnExecute()
{
		if(OnInit() == false)
		{
			return -1;
		}

		SDL_Event Event;


		while (Running)
		{
			while (SDL_PollEvent(&Event))
			{
				OnEvent(&Event);
			}

			OnLoop();

			OnRender();

			//MainRenderTarget.Render();


		}

		OnCleanup();

		return 0;
}


bool MainApp::OnInit()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("failed to initi\n");
		printf("SDL_Init failed: %s\n", SDL_GetError());
        	return false;
	}

	MainWindow = SDL_CreateWindow("HHR_X",
							  SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED,
							  WWIDTH, WHEIGHT,
                              SDL_WINDOW_RESIZABLE );


	if(MainRenderTarget.InitRenderer(MainWindow) == false )
	{
		printf("Main Render Target Failed to Initilize\n");
		return false;
	}

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

	 //CurrentLevel = new GameLevel1();

	 if(CurrentLevel->LoadLevel() == false)
     {
         printf("Level Failed to load!\n");
         return false;

     }






	return true;
}

void MainApp::LoadGame()
{

}


void MainApp::OnEvent(SDL_Event* Event)
{
    Events::OnEvent(Event);

    if(CurrentLevel != NULL)
    {
        CurrentLevel->OnEvent(Event);

    }
}


void MainApp::OnKeyDown(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{
	switch(sym)
	{
		default:
		{

		}
	}
}

void MainApp::OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{
	switch(sym)
	{
		default:
		{

		}
	}
}


void MainApp::OnExit()
{
	Running = false;
}


void MainApp::OnLoop()
{
	if(CurrentLevel != NULL)
    {
        CurrentLevel->OnLoop();

    }
}


void MainApp::OnRender()
{
	MainRenderTarget.CreateDisplayRect();

    if(CurrentLevel != NULL)
    {
        CurrentLevel->OnRender(MainRenderTarget);
    }

	MainRenderTarget.RenderDisplay();
}


MainRender* MainApp::GetMainRenderTarget()
{
	return &MainRenderTarget;
}


void MainApp::OnCleanup()
{
	//SDL_DestroyRenderer(Renderer);
	MainRenderTarget.Clean();
	SDL_DestroyWindow(MainWindow);

	CurrentLevel->OnCleanup();

	delete CurrentLevel;

    TTF_Quit();

    SDL_Quit();
}

MainApp::~MainApp()
{
	delete m_pInstance;
}
