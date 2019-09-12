#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"

class Character
{
public:
	Character(cocos2d::Layer* layer);
	void Fall();
	void Fly() { isFalling = false;}
	void StopFlying() { isFalling = true;}

private:
	cocos2d::Sprite* mainChar;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	bool isFalling;

	cocos2d::SpriteBatchNode* charBatchNode;

	
	
};


#endif // __CHARACTER_H__
