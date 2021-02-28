#include "Character.h"

#include "Texture2D.h"//Upholds forward decloration

Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	m_texture->LoadFromFile(imagePath);

	m_collision_radius = 15.0f;

	bool m_moving_right = false;
	bool m_moving_left = false;

	bool m_can_jump = true;
	bool m_jumping = false;
}

Character::~Character()
{
	m_renderer = nullptr;
}

Rect2D Character::GetCollisionBox()
{
	
		return Rect2D(m_position.x, m_position.y,
			m_texture->GetWidth(), m_texture->GetHeight());
	
}


void Character::Render()
{

	//These do not need changing 
	m_texture->Render(m_position, SDL_FLIP_NONE);

	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
	

}

void Character::Update(float deltaTime, SDL_Event e)
{
	JumpConditions(deltaTime);
	MovementHandler(deltaTime);	



	
	
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}


Vector2D Character::GetPosition()
{
	return m_position;
}

float Character::GetCollisionRadius()
{
	return m_collision_radius;
}

void Character::MoveRight(float deltaTime)
{
	m_position.x += deltaTime * MOVEMENT_SPEED;
	m_facing_direction = FACING_RIGHT;
}
	void Character::MoveLeft(float deltaTime)
{
	m_position.x -= deltaTime * MOVEMENT_SPEED;
	m_facing_direction = FACING_LEFT;
	
}



void Character::Gravity(float deltaTime)
{
	m_position.y += GRAVITY * deltaTime;
	m_can_jump = true;
	
}

void Character::JumpConditions(float deltaTime)
{
	//deal with jumping first
	if (m_jumping)
	{
		//adjust position
		m_position.y -= m_jump_force * deltaTime;

		//reduce jump force
		m_jump_force -= JUMP_FORCE_DECREMENT * deltaTime;

		//is jump force 0?
		if (m_jump_force <= 0.0f)
			m_jumping = false;
		Gravity(deltaTime);//Call gravity to enable chracter to fall down
	}
}

void Character::MovementHandler(float deltaTime)
{
	if (m_moving_left)
	{
		MoveLeft(deltaTime);

	}
	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
}

void Character::jump()//This does not need changing
{
	if (!m_jumping)
	{
		m_jump_force = INITIAL_JUMP_FORCE;
		m_jumping = true;
		m_can_jump = false;
	}

}
