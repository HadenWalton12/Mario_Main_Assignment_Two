#pragma once
#include "SDL.h"
#include "Commons.h"
#include "constants.h"
#include "LevelMap.h"

#include <iostream>
#include <string>

class Texture2D; //Forward decleration
class Character
{
public:
	Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~Character();
	
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();

Rect2D GetCollisionBox();
	float GetCollisionRadius();


	bool isJumping() { return m_jumping; };
	bool CancelJump() { return m_jumping = false; };

protected://we use the idnetifier protecto	r so only child classes and this class can inherit/use thes variables

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	FACING m_facing_direction;



	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void Gravity(float deltaTime);

	void JumpConditions(float deltaTime);
	void MovementHandler(float deltaTime);
	void jump();
	bool m_moving_left;
	bool m_moving_right;

	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;
	float m_collision_radius;

private:
	LevelMap* m_current_level_map;
};

