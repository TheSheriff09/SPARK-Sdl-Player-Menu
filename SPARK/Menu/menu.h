#ifndef MENU_H
#define MENU_H

#include <SDL/SDL.h> 
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h> 

#define SCREEN_W 1300
#define SCREEN_H 730


typedef struct{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface* img;
}image;

typedef struct {
    SDL_Surface *surfacetext;
    SDL_Rect pos;
    TTF_Font *font;
    SDL_Color textcolor;
    char message [50];
} text;


//initialize
void initialize_backg(image backg[]);
void update_background(image backg[], int *current_bg);
void initialize_audio(Mix_Music **backgmusic);
void initialize_btn1(image btn1[]);
void initialize_btn2(image btn2[]);
void initialize_btn3(image btn3[]);
void initialize_btnv1(image btnv1[]);
void initialize_btnv2(image btnv2[]);
void initialize_vbar(image vbar[],int i);
void initialize_back(image back[]);
void initialize_f(image f[]);
void initialize_hover_sound(Mix_Chunk **hover_sound, int *soundPlayed);
void initialize_settings(image *settings);
void initialize_play(image *play);
void initialize_text(text *t);


//display
void display_backg(SDL_Surface *screen,image backg);
void display_btn1(SDL_Surface *screen,image btn1);
void display_btn2(SDL_Surface *screen,image btn2);
void display_btn3(SDL_Surface *screen,image btn3);
void display_btvn1(SDL_Surface *screen, image btnv1);
void display_btvn2(SDL_Surface *screen, image btnv2);
void display_vbar(SDL_Surface *screen, image vbar);
void display_settings(SDL_Surface *screen, image settings);
void display_play(SDL_Surface *screen, image play);
void display_f(SDL_Surface *screen, image f);
void display_back(SDL_Surface *screen, image back);
void display_text(SDL_Surface *screen, text t);


//free
void free_backg(image backg);
void free_audio(Mix_Music *backgmusic);
void free_settings(image settings);
void free_play(image play);
void free_text(text t);

#endif
