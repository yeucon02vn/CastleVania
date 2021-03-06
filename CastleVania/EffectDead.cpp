#include "EffectDead.h"



void EffectDead::Render()
{
	if(state == 1)
		animations[0]->Render(x, y);
	else if (state == 2)
	{
		for(int i=-1; i < 2;i++)
		animations[1]->Render(x + i*20, y + i*10);
	}
	else
		animations[2]->Render(x, y);
}

void EffectDead::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	if (count >= 35)
	{
		isEnable = false;
	}
	else
	{
		if (state == 2)
		{
			if (count < 5)
				vy -= WATER_SPLASSING_SPEED;
			else
			{
				vy += GRAVITY * 20;
				vx += 0.005f;
			}

		}
		GameObject::Update(dt);
		x += dx;
		y += dy;
		count++;
	}
}

void EffectDead::LoadResources()
{
	count = 0;
	Sprites * sprites = Sprites::GetInstance();
	Animations * animations = Animations::GetInstance();
	Textures * textures = Textures::GetInstance();

	textures->Add(ID_TEX_DEAD1, L"Resource\\sprites\\Effect\\0.png", D3DCOLOR_XRGB(255, 0, 255));
	LPDIRECT3DTEXTURE9 texDead1 = textures->Get(ID_TEX_DEAD1);
	sprites->Add(190001, 0, 0, 16, 20, texDead1);

	textures->Add(ID_TEX_DEAD2, L"Resource\\sprites\\Effect\\2.png", D3DCOLOR_XRGB(255, 0, 255));
	LPDIRECT3DTEXTURE9 texDead2 = textures->Get(ID_TEX_DEAD2);
	sprites->Add(190002, 0, 0, 14, 28, texDead2);

	textures->Add(ID_TEX_DEAD3, L"Resource\\sprites\\Effect\\DEAD.png", D3DCOLOR_XRGB(255, 0, 255));
	LPDIRECT3DTEXTURE9 texDead3 = textures->Get(ID_TEX_DEAD3);
	sprites->Add(190003, 0, 0, 42, 44, texDead3);
	sprites->Add(190004, 42, 0, 84, 44, texDead3);
	sprites->Add(190005, 84, 0, 126, 44, texDead3);


	LPANIMATION ani;

	ani = new Animation(100);		// ngoi sao
	ani->Add(190001);
	animations->Add(1901, ani);

	ani = new Animation(100);		// giot nước
	ani->Add(190002);
	animations->Add(1902, ani);

	ani = new Animation(100);
	ani->Add(190003);
	ani->Add(190004);
	ani->Add(190005);
	animations->Add(1903, ani);

	AddAnimation(1901);
	AddAnimation(1902);
	AddAnimation(1903);
}

void EffectDead::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	/*l = x;
	t = y;
	if (state == 1)
	{
		r = x + 16;
		b = y + 20;
	}
	else if (state == 2)
	{
		r = x + 14;
		b = y + 28;
	}
	else
	{
		r = x + 42;
		b = y + 44;
	}*/
}

