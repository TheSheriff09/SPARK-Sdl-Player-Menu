#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

// Initialize
void initialize_backg(image backg[]) {

    for (int i = 0; i < 24; ++i) {
        char filename[20];
        sprintf(filename, "backg%d.png", i + 1);
        backg[i].img = IMG_Load(filename);
        if (backg[i].img == NULL) {
            printf("Unable to load background %s: %s\n", filename, SDL_GetError());
            return;
        }

        backg[i].pos1.x = 0;
        backg[i].pos1.y = 0;
        backg[i].pos2.x = 0;
        backg[i].pos2.y = 0;
        backg[i].pos2.h = 1300;
        backg[i].pos2.w = 730;
    }
    
}

void update_background(image backg[], int *current_bg) {
    // Delay for a short period (e.g., 100 milliseconds)

	SDL_Delay(0);
    // Increment current_bg to move to the next background image
    *current_bg = (*current_bg + 1) % 24;
}



void initialize_audio(Mix_Music **backgmusic) {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
        printf("Unable to load %s\n", SDL_GetError());
    }
    *backgmusic = Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(*backgmusic, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME);
}

void initialize_settings(image *settings) {
settings->img = IMG_Load("settings.png");
    if (settings->img == NULL) {
        printf("Unable to load background %s \n", SDL_GetError());
        return;
    }
    settings->pos1.x = 0;
    settings->pos1.y = 0;
    settings->pos2.x = 0;
    settings->pos2.y = 0;
    settings->pos2.h = 1300;
    settings->pos2.w = 730;
} 

void initialize_play(image *play) {
play->img = IMG_Load("play.png");
    if (play->img == NULL) {
        printf("Unable to load background %s \n", SDL_GetError());
        return;
    }
    play->pos1.x = 0;
    play->pos1.y = 0;
    play->pos2.x = 0;
    play->pos2.y = 0;
    play->pos2.h = 1300;
    play->pos2.w = 730;
} 




void initialize_btn1(image btn1[]) {
    btn1[0].img = IMG_Load("1.png");
    btn1[1].img = IMG_Load("4.png");
    if (btn1[0].img == NULL || btn1[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    btn1[0].pos2.x = 22;
    btn1[0].pos2.y = 245; // Y position of the first button
    btn1[0].pos2.h = 120;
    btn1[0].pos2.w = 300;
    btn1[1].pos2.x = 22;
    btn1[1].pos2.y = 245; // Y position of the second button
    btn1[1].pos2.h = 120;
    btn1[1].pos2.w = 300;
}


void initialize_btn2(image btn2[]) {
    btn2[0].img = IMG_Load("2.png");
    btn2[1].img = IMG_Load("5.png");
    if (btn2[0].img == NULL || btn2[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    btn2[0].pos2.x = 22;
    btn2[0].pos2.y = 382; // Y position of the first button
    btn2[0].pos2.h = 120;
    btn2[0].pos2.w = 300;
    btn2[1].pos2.x = 22;
    btn2[1].pos2.y = 382; // Y position of the second button
    btn2[1].pos2.h = 120;
    btn2[1].pos2.w = 300;
}

void initialize_btn3(image btn3[]) {
    btn3[0].img = IMG_Load("3.png");
    btn3[1].img = IMG_Load("6.png");
    if (btn3[0].img == NULL || btn3[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    btn3[0].pos2.x = 22;
    btn3[0].pos2.y = 519; // Y position of the first button
    btn3[0].pos2.h = 120;
    btn3[0].pos2.w = 300;
    btn3[1].pos2.x = 22;
    btn3[1].pos2.y = 519; // Y position of the second button
    btn3[1].pos2.h = 120;
    btn3[1].pos2.w = 300;
}

void initialize_btnv1(image btnv1[]) {
    btnv1[0].img = IMG_Load("+.png");
    btnv1[1].img = IMG_Load("+1.png");
    if (btnv1[0].img == NULL || btnv1[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    btnv1[0].pos2.x = 1025;
    btnv1[0].pos2.y = 249; // Y position of the first button
    btnv1[0].pos2.h = 95;
    btnv1[0].pos2.w = 95;
    btnv1[1].pos2.x = 1025;
    btnv1[1].pos2.y = 249; // Y position of the second button
    btnv1[1].pos2.h = 95;
    btnv1[1].pos2.w = 95;
}

void initialize_btnv2(image btnv2[]) {
    btnv2[0].img = IMG_Load("-.png");
    btnv2[1].img = IMG_Load("-1.png");
    if (btnv2[0].img == NULL || btnv2[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    btnv2[0].pos2.x = 276;
    btnv2[0].pos2.y = 249; // Y position of the first button
    btnv2[0].pos2.h = 95;
    btnv2[0].pos2.w = 95;
    btnv2[1].pos2.x = 276;
    btnv2[1].pos2.y = 249; // Y position of the second button
    btnv2[1].pos2.h = 95;
    btnv2[1].pos2.w = 95;
}

void initialize_back(image back[]) {
    back[0].img = IMG_Load("back.png");
    back[1].img = IMG_Load("back1.png");
    if (back[0].img == NULL || back[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    back[0].pos2.x = 55;
    back[0].pos2.y = 588; // Y position of the first button
    back[0].pos2.h = 95;
    back[0].pos2.w = 95;
    back[1].pos2.x = 55;
    back[1].pos2.y = 588; // Y position of the second button
    back[1].pos2.h = 95;
    back[1].pos2.w = 95;
}

void initialize_f(image f[]) {
    f[0].img = IMG_Load("f.png");
    f[1].img = IMG_Load("f1.png");
    if (f[0].img == NULL || f[1].img == NULL) {
        printf("Unable to load play button %s \n", SDL_GetError());
    }
    f[0].pos2.x = 311;
    f[0].pos2.y = 450; // Y position of the first button
    f[0].pos2.h = 95;
    f[0].pos2.w = 95;
    f[1].pos2.x = 311;
    f[1].pos2.y = 450; // Y position of the second button
    f[1].pos2.h = 95;
    f[1].pos2.w = 95;
}

void initialize_text(text *t)
{
	t->pos.x =30;
	t->pos.y =80;
	t->textcolor.r =255;
	t->textcolor.g =255;
	t->textcolor.b =255;

	t->font = TTF_OpenFont("arial.ttf", 70);
}


void initialize_vbar(image vbar[],int i) {
 	char filename[20];
        sprintf(filename, "bar%d.png",i);
    vbar[0].img = IMG_Load(filename);
    if (vbar[0].img == NULL || vbar[1].img == NULL) {
        printf("Unable to load the bar %s \n", SDL_GetError());
    }
    vbar[0].pos2.x = 380;
    vbar[0].pos2.y = 288; // Y position of the first button
    vbar[0].pos2.h = 818;
    vbar[0].pos2.w = 73;
    vbar[1].pos2.x = 380;
    vbar[1].pos2.y = 288; // Y position of the second button
    vbar[1].pos2.h = 818;
    vbar[1].pos2.w = 73;
}



void initialize_hover_sound(Mix_Chunk **hover_sound, int *soundPlayed) {
    *hover_sound = Mix_LoadWAV("click.wav");
    if (*hover_sound == NULL) {
        printf("Unable to load hover sound: %s\n", Mix_GetError());
    }
    *soundPlayed = 0; // Initialize the flag to 0 (not played)
}



//display
void display_backg(SDL_Surface *screen, image backg) {
    SDL_BlitSurface(backg.img, NULL, screen, &backg.pos2);
}

void display_settings(SDL_Surface *screen, image settings) {
    SDL_BlitSurface(settings.img, NULL, screen, &settings.pos2);
}

void display_play(SDL_Surface *screen, image play) {
    SDL_BlitSurface(play.img, NULL, screen, &play.pos2);
}

void display_btn1(SDL_Surface *screen, image btn1) {
    SDL_BlitSurface(btn1.img, NULL, screen, &btn1.pos2);
}

void display_btn2(SDL_Surface *screen, image btn2) {
    SDL_BlitSurface(btn2.img, NULL, screen, &btn2.pos2);
}

void display_btn3(SDL_Surface *screen, image btn3) {
    SDL_BlitSurface(btn3.img, NULL, screen, &btn3.pos2);
}
void display_btvn1(SDL_Surface *screen, image btnv1) {
    SDL_BlitSurface(btnv1.img, NULL, screen, &btnv1.pos2);
}

void display_btvn2(SDL_Surface *screen, image btnv2) {
    SDL_BlitSurface(btnv2.img, NULL, screen, &btnv2.pos2);
}

void display_vbar(SDL_Surface *screen, image vbar) {
    SDL_BlitSurface(vbar.img, NULL, screen, &vbar.pos2);
}

void display_f(SDL_Surface *screen, image f) {
    SDL_BlitSurface(f.img, NULL, screen, &f.pos2);
}

void display_back(SDL_Surface *screen, image back) {
    SDL_BlitSurface(back.img, NULL, screen, &back.pos2);
}

void display_text(SDL_Surface *screen, text t) {
    t.surfacetext = TTF_RenderText_Solid(t.font, "FOLLOW THE JOURNEY", t.textcolor);
    SDL_BlitSurface(t.surfacetext, NULL, screen, &t.pos);
}


//free
void free_backg(image backg) {
    SDL_FreeSurface(backg.img);
}

void free_settings(image settings) {
    SDL_FreeSurface(settings.img);
}

void free_play(image play) {
    SDL_FreeSurface(play.img);
}


void free_audio(Mix_Music *backgmusic) {
    Mix_FreeMusic(backgmusic);
}

void free_text(text t) {
    SDL_FreeSurface(t.surfacetext);
}




