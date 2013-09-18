/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of SDL2_Pong.                                    			**
**  																			**
**  SDL2_Pong is free software: you can redistribute it and/or modify			**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  SDL2_Pong is distributed in the hope that it will be useful,			    **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with SDL2_Pong.  If not, see <http://www.gnu.org/licenses/>.			**
**  																			**
**********************************************************************************/


#include "MainApp.h"


/*Singleton Suff */


//Singleton pointer
MainApp* MainApp::m_pInstance = NULL;

//Create out instence or retreave it.
MainApp* MainApp::Instance()
{
    if(!m_pInstance)
    {
        m_pInstance = new MainApp();
    }

    return m_pInstance;
}

//constructor set needed stuff
//to null set running to true
MainApp::MainApp()
{
	MainWindow = NULL;

	Running = true;
}

//Main Loop for the whole application
int MainApp::OnExecute()
{
        //Did we initilize correcrlt
		if(OnInit() == false)
		{
			return -1;
		}

		SDL_Event Event; //holding for events from SDL

        //While we are running
		while (Running)
		{
		    //check we did not hit our max millisecond Hz
		     if(!MainRenderTarget.FrameRateControl.TargetRateHit())
             {

                //Get latest events
                while (SDL_PollEvent(&Event))
                {
                    //Update Events
                    OnEvent(&Event);
                }


                //Update game logic
                OnLoop();

                //Draw
                OnRender();

			//MainRenderTarget.Render();
            }
            else
			{
			    //if we reached our target Hz sleep for one millisecond
				Sleep(1);
			}


		}

        //clean everything up
		OnCleanup();

		return 0;
}


bool MainApp::OnInit()
{
    //Did SDL initalize correctly
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("failed to initi\n");
		printf("SDL_Init failed: %s\n", SDL_GetError());
        	return false;
	}


    //Create out SDL window centered at said with and height

	MainWindow = SDL_CreateWindow("SDL2_PONG",
							  SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED,
							  WWIDTH, WHEIGHT,
                              SDL_WINDOW_RESIZABLE );


    //Create our renderer
	if(MainRenderTarget.InitRenderer(MainWindow) == false )
	{
		printf("Main Render Target Failed to Initilize\n");
		return false;
	}

	if(IMG_Init(IMG_INIT_PNG) < 0)
    {
        return false;

    }

    //initalize our audio interface
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) <0)
    {
        return false;
    }

    //Start our ttf helper
    if( TTF_Init() < 0 )
    {
        return false;
    }

    //create a new game level
    CurrentLevel = new PongLevel();

    //Load up the level
	 if(CurrentLevel->LoadLevel() == false)
     {
         printf("Level Failed to load!\n");
         return false;

     }

    //If we got there then everything worked
	return true;
}

void MainApp::LoadGame()
{

}


void MainApp::OnEvent(SDL_Event* Event)
{
    //Have main app take care of levels we care about
    Events::OnEvent(Event);

    //if the current level is not null
    if(CurrentLevel != NULL)
    {
        //Tell the current level about the event
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

//Exit event
void MainApp::OnExit()
{
    //if we get an exit event we will stop the main stop clean then return causing the application to finish and
    //quit
	Running = false;
}


void MainApp::OnLoop()
{
	if(CurrentLevel != NULL)
    {
        //if the current level is not null
        //then update its logic
        CurrentLevel->OnLoop();

    }
}




void MainApp::OnRender()
{
    //Have our renderer create out display rect
	MainRenderTarget.CreateDisplayRect();


    if(CurrentLevel != NULL)
    {
        //if we have a level have it render it self
        CurrentLevel->OnRender(MainRenderTarget);
    }

    //flip the display
	MainRenderTarget.RenderDisplay();
}

//get this main apps render target (SOmetimes used to load textures)
MainRender* MainApp::GetMainRenderTarget()
{
	return &MainRenderTarget;
}


void MainApp::OnCleanup()
{
	//clean the level
	CurrentLevel->OnCleanup();

    //delete the level
	delete CurrentLevel;


    //Kill ttf extersion
    TTF_Quit();

    //Unload Image libs
    IMG_Quit();

    //Kill Audio
    Mix_CloseAudio();

    //Clean up the renderer
	MainRenderTarget.Clean();

	//Kill the window
	SDL_DestroyWindow(MainWindow);

    //Quit SDL
    SDL_Quit();
}

MainApp::~MainApp()
{
	delete m_pInstance;
}
