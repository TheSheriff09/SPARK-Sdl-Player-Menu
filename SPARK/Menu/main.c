#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

int main(int argc, char *argv[]) {
    image backg[24], btn1[2], btn2[2], btn3[2], settings,play, btnv1[2], btnv2[2], vbar[6], f[2] ,back[2];  
    SDL_Surface *screen;
    Mix_Music *backgmusic;
    Mix_Chunk *hover_sound;
    int current_bg = 0;
    int fullscreen = 0;
    int interface = 0;
    int soundPlayed =0;
    SDL_Event event;
    TTF_Init();
    text t;
    int loop = 1, b1 = 0, b2 = 0, b3 = 0, m = 6;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1){
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    screen = SDL_SetVideoMode(1300, 730, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    if(screen == NULL) {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        return -1;
    }

if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
    printf("Unable to initialize SDL Mixer: %s\n", Mix_GetError());
    return -1;
}


    initialize_backg(backg);
    initialize_audio(&backgmusic);
    initialize_btn1(btn1);
    initialize_btn2(btn2);
    initialize_btn3(btn3);
    initialize_btnv1(btnv1);
    initialize_btnv2(btnv2);
    initialize_vbar(vbar,1);
    initialize_back(back);
    initialize_f(f);
    initialize_hover_sound(&hover_sound,&soundPlayed);
    initialize_settings(&settings);
    initialize_play(&play);
    initialize_text(&t);
    while(loop) {
switch(interface){
	case 0:
	display_backg(screen, backg[current_bg]);
	display_btn1(screen, btn1[b1]);
        display_btn2(screen, btn2[b2]);
        display_btn3(screen, btn3[b3]);
        update_background(backg, &current_bg);
	display_text(screen,t);
 while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    loop = 0;
                    break;
case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if ((event.motion.y >= 382 && event.motion.y <= 497) &&
               			(event.motion.x >= 22 && event.motion.x <= 253)) {
                                	// Clicked on the "Interface" button
                                interface = 1;
                        }
	
    if ((event.motion.y >= 245 && event.motion.y <= 360) &&
        (event.motion.x >= 22 && event.motion.x <= 253)) {
		interface = 2;
}

    if ((event.motion.y >= 519 && event.motion.y <= 634) &&
        (event.motion.x >= 22 && event.motion.x <= 253)) {
		loop = 0;
}



}
                    break;
  case SDL_MOUSEMOTION:
    if ((event.motion.y >= 245 && event.motion.y <= 360) && (event.motion.x >= 22 && event.motion.x <= 253)) {
        b1 = 1; b2 = 0; b3 = 0;
        if (!soundPlayed) {
            Mix_PlayChannel(-1, hover_sound, 0); // Use 0 instead of 1 to prevent repeating
            soundPlayed = 1; // Set the flag to indicate the sound has been played
        }
    } else if ((event.motion.y >= 382 && event.motion.y <= 497) && (event.motion.x >= 22 && event.motion.x <= 253)) {
        b1 = 0; b2 = 1; b3 = 0;
        if (!soundPlayed) {
            Mix_PlayChannel(-1, hover_sound, 0); // Use 0 instead of 1 to prevent repeating
            soundPlayed = 1; // Set the flag to indicate the sound has been played
        }
    } else if ((event.motion.y >= 519 && event.motion.y <= 634) && (event.motion.x >= 22 && event.motion.x <= 253)) {
        b1 = 0; b2 = 0; b3 = 1;
        if (!soundPlayed) {
            Mix_PlayChannel(-1, hover_sound, 0); // Use 0 instead of 1 to prevent repeating
            soundPlayed = 1; // Set the flag to indicate the sound has been played
        }
    } else {
        b1 = 0; b2 = 0; b3 = 0;
        soundPlayed = 0; // Reset the flag if the mouse is not over any button
    }
    break;
	

       case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    exit(0);
                    break;
 			case SDLK_UP:
                            if(b1 == 1) {
                                b1 = 0; b3 = 1;
				Mix_PlayChannel(-1, hover_sound, 1);
                            }
                            else if(b2 == 1) {
                                b1 = 1; b2 = 0;
				Mix_PlayChannel(-1, hover_sound, 1);
                            }
                            else if(b3 == 1) {
                                b2 = 1; b3 = 0;
				Mix_PlayChannel(-1, hover_sound, 1);
                            }
                            else {
                                b3 = 1;
                            }
                            break;
                        case SDLK_DOWN:
                            if(b1 == 1) {
                                b1 = 0; b2 = 1;
				Mix_PlayChannel(-1, hover_sound, 1);
                            }
                            else if(b2 == 1) {
                                b2 = 0; b3 = 1;
				Mix_PlayChannel(-1, hover_sound, 1);
                            }
                            else if(b3 == 1) {
                                b1 = 1; b3 = 0;
				Mix_PlayChannel(-1, hover_sound, 1);
                            }
                            else {
                                b1 = 1;
                            }
                            break;
                        case SDLK_RETURN:
                            if (b1 == 1){
				interface = 2;
                            }
			    if (b2 == 1){
				interface = 1;
			    }
			    if (b3 == 1) {
				loop = 0;
			    }
			    break;
                        case SDLK_f:
                            fullscreen = !fullscreen;  // Toggle fullscreen
                            if (fullscreen) {
                                SDL_SetVideoMode(1700, 900, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                            } else {
                                SDL_SetVideoMode(1300, 730, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
                            }
                            break;

}
}
}
		break;
	case 1:
		display_settings(screen, settings);
 		display_btvn1(screen, btnv1[0]);
 		display_btvn2(screen, btnv2[0]);
		display_vbar(screen, vbar[0]);
		display_f(screen, f[0]);
		display_back(screen, back[0]);

 while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    loop = 0;
                    break;
       case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    interface = 0;
                    break;
                        case SDLK_f:
                            fullscreen = !fullscreen;  // Toggle fullscreen
                            if (fullscreen) {
                                SDL_SetVideoMode(1700, 900, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                            } else {
                                SDL_SetVideoMode(1300, 730, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
                            }
                            break;

                    
}//switch event.key
			break;//case SDL_KEYDOWN

case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {

    if ((event.motion.y >= 450 && event.motion.y <= 545) &&
        (event.motion.x >= 311 && event.motion.x <= 406)) {
                fullscreen = !fullscreen;  // Toggle fullscreen
        if (fullscreen) {
                SDL_SetVideoMode(1700, 900, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
     			} else {
                SDL_SetVideoMode(1300, 730, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
            }
	
}

    if ((event.motion.y >= 588 && event.motion.y <= 683) &&
        (event.motion.x >= 55 && event.motion.x <= 150)) {
	interface = 0;
}

    if ((event.motion.y >= 249 && event.motion.y <= 342) &&
        (event.motion.x >= 276 && event.motion.x <= 356)) {
	m--;
	switch (m){
	case 1:
			 Mix_VolumeMusic(0);

    				Mix_Volume(-1, 0);

		    initialize_vbar(vbar,6);
		break;
	case 2:
		 Mix_VolumeMusic(MIX_MAX_VOLUME/5);
			    Mix_PlayChannel(-1, hover_sound, 1);
		    initialize_vbar(vbar,5);
				Mix_Volume(-1, 1);
		break;
	case 3:
		 Mix_VolumeMusic(MIX_MAX_VOLUME/3);
	Mix_Volume(-1, 1);
    	initialize_vbar(vbar,4);
		break;
				
	case 4:
		 Mix_VolumeMusic(MIX_MAX_VOLUME/2);
    initialize_vbar(vbar,3);
				Mix_Volume(-1, 1);
		break;
	case 5:
		 Mix_VolumeMusic(MIX_MAX_VOLUME/1.2);
		     initialize_vbar(vbar,2);
			Mix_Volume(-1, 1);
		break;
	case 6:
		 Mix_VolumeMusic(MIX_MAX_VOLUME);
    		initialize_vbar(vbar,1);
			Mix_Volume(-1, 1);
		break;
	default:
		m=1;
	break;

	}
}
}	
if (event.button.button == SDL_BUTTON_LEFT) {
if ((event.motion.y >= 249 && event.motion.y <= 342) &&
        (event.motion.x >= 1025 && event.motion.x <= 1110)) {
	m++;
	switch (m){
	case 1:
			    Mix_VolumeMusic(0);

    				Mix_Volume(-1, 0);

		    initialize_vbar(vbar,6);
		break;
	case 2:
		 Mix_VolumeMusic(MIX_MAX_VOLUME/5);
		    initialize_vbar(vbar,5);
			Mix_Volume(-1, 1);

		break;
	case 3:
		 Mix_VolumeMusic(MIX_MAX_VOLUME/3);
    	initialize_vbar(vbar,4);
			Mix_Volume(-1, 1);
		break;
	case 4:
		 Mix_VolumeMusic(MIX_MAX_VOLUME/2);
    initialize_vbar(vbar,3);
			Mix_Volume(-1, 1);
		break;

	case 5:
		 Mix_VolumeMusic(MIX_MAX_VOLUME/1.2);
		     initialize_vbar(vbar,2);
			Mix_Volume(-1, 1);
		break;
	case 6:
		 Mix_VolumeMusic(MIX_MAX_VOLUME);
    		initialize_vbar(vbar,1);
			Mix_Volume(-1, 1);
		break;
	default:
		m=6;
	break;

	}
}
}
break;
}//event.type switch
}//while sdl_pollevent
		break;//case 1
	case 2:
		display_play(screen, play);
		display_back(screen, back[0]);
 while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    loop = 0;
                    break;
       case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    interface = 0;
                    break;

}//switch event.key
			break;//case SDL_KEYDOWN
case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
    if ((event.motion.y >= 588 && event.motion.y <= 683) &&
        (event.motion.x >= 55 && event.motion.x <= 150)) {
	interface = 0;
}
}
break;
}//event.type switch
}//while sdl_pollevent
		break;//case 2
}//first switch

	SDL_Flip(screen);
    }//game loop

    free_audio(backgmusic);
    Mix_FreeChunk(hover_sound);
    free_settings(settings);
    free_play(play);
    free_text(t);
    TTF_CloseFont (t.font);
    SDL_Quit();
	return 0;
}
