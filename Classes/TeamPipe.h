#ifndef __TEAM_PIPE_H__
#define __TEAM_PIPE_H__

#include "cocos2d.h"

class TeamPipe
{
public:
	TeamPipe(cocos2d::Layer* layer);




private:
	cocos2d::Sprite* teamPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
      
};

class CocosPipe
{
public:
	CocosPipe(cocos2d::Layer* layer);

private:
	cocos2d::Sprite* cocosPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};


#endif // __TEAM_PIPE_H__
