#include"MainObject.h"

MAINOBJECT::MAINOBJECT()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val = 0;
	y_val = 0;
}

MAINOBJECT::~MAINOBJECT()
{
	;
}

void MAINOBJECT::HandleInputAction(SDL_Event events,Mix_Chunk * bullet_sound[2])
{
	if (events.type == SDL_KEYDOWN) // bát sư kiện pím nhấn xuống
	{
		switch (events.key.keysym.sym)
		{
		
		case SDLK_UP:
			y_val -= HEIGHT_MAIN_OBJECT / 6;
			break;
		case SDLK_DOWN:
			y_val += HEIGHT_MAIN_OBJECT / 6;
			break;
		case SDLK_LEFT:
			x_val -= WIDTH_MAIN_OBJECT / 6;

			break;
		case SDLK_RIGHT:
			x_val += WIDTH_MAIN_OBJECT/6;
			break;
		default:
			break;
		}
		
	}
	else if (events.type == SDL_KEYUP) // phím nhả ra
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val += HEIGHT_MAIN_OBJECT / 6;
			break;
		case SDLK_DOWN:
			y_val -= HEIGHT_MAIN_OBJECT / 6;
			break;
		case SDLK_RIGHT:
			x_val -= WIDTH_MAIN_OBJECT / 6;
			break;
		case SDLK_LEFT:
			x_val += WIDTH_MAIN_OBJECT / 6;
		default:
			break;
		}
	}

	
	else if (events.type == SDL_MOUSEBUTTONDOWN) // chuột bấm xuống
	{
		AMOOBJECT* p_amo = new AMOOBJECT();
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			p_amo->SetwwidthHeight(WIDTH_LASER, HEIGHT_LASER);
			p_amo->loadImg("laser.png");
			p_amo->SET_type(AMOOBJECT::LASER);
			Mix_PlayChannel(-1, bullet_sound[0], 0);
		}
		else if (events.button.button==SDL_BUTTON_RIGHT)
		{
			p_amo->SetwwidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
			p_amo->loadImg("sphere.png");
			p_amo->SET_type(AMOOBJECT::SPHERE);
			Mix_PlayChannel(-1, bullet_sound[1], 0);
		}

		p_amo->SETrect(this->rect_.x+this->rect_.w-30, this->rect_.y +this->rect_.h*0.75);
		p_amo->SET_is_move(true);
		p_amo->SET_x_val(20);
		p_amo_list_.push_back(p_amo);
	}
	else if (events.type == SDL_MOUSEBUTTONUP)
	{


	}
	else
	{

	}
}

void MAINOBJECT::MakeAmo(SDL_Surface *des)
{
	for (int i = 0; i < p_amo_list_.size(); i++)
	{
		
		AMOOBJECT* p_amo = p_amo_list_.at(i);
		if (p_amo != NULL)
		{
			if (p_amo->GET_is_move())
			{
				p_amo->show(des);
				p_amo->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			else
			{
				if (p_amo != NULL)
				{
					p_amo_list_.erase(p_amo_list_.begin() + i);

					
					delete p_amo;
					p_amo = NULL;
				}

			}
		}
	}
}

void MAINOBJECT::HandleMove()
{
	rect_.x += x_val;

	if (rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH )
	{
		rect_.x -= x_val;
	}
	rect_.y += y_val;
	if (rect_.y <0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT -200)
	{
		rect_.y -= y_val;
	}
}


void MAINOBJECT::remove_amo(const int& index)
{
		for (int i = 0; i < p_amo_list_.size(); i++)
		{
			if(index < p_amo_list_.size())
			{
				AMOOBJECT* p_amo = p_amo_list_.at(index);
				p_amo_list_.erase(p_amo_list_.begin() + index);
				if (p_amo != NULL)
				{
					delete p_amo;
					p_amo = NULL;
				}
			}
		} 
}