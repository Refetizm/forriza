#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Character.h"
#include "TeamPipe.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);


private:
	cocos2d::PhysicsWorld* sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };

	bool onContactBegin(cocos2d::PhysicsContact &contact);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void StopFlying(float dt);
	void update(float dt);

	Character* character;

	TeamPipe* teamPipe;

	CocosPipe* cocosPipe;

	

	



	

};




#endif // __GAME_SCENE_H__