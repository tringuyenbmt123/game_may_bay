#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "Common_function.h"
#include "baseObject.h"
#include<vector>
#include"AmoObject.h"

#define WIDTH_MAIN_OBJECT 77
#define HEIGHT_MAIN_OBJECT 52

class MAINOBJECT :public BASE_OBJECT
{
private:
	int x_val;
	int y_val; 
	std::vector<AMOOBJECT*> p_amo_list_;

public:


	MAINOBJECT();
	~MAINOBJECT();

	void HandleInputAction(SDL_Event events, Mix_Chunk* bullet_sound[2]);
	void HandleMove();
	void SetAmoList(std::vector<AMOOBJECT*> amo_list)
	{
		p_amo_list_ = amo_list;
	}

	std::vector<AMOOBJECT*> GetAmoList() const
	{
		return p_amo_list_;
	}

	void MakeAmo(SDL_Surface* des);
	void remove_amo(const int& index);


};
#endif // !MAIN_OBJECT_H_ 
