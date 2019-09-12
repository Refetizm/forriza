#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Character.h"
#include "TeamPipe.h"
#include "RoadBlock.h"

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
	RoadBlock* roadBlock;
	TeamPipe* teamPipe;

	CocosPipe* cocosPipe;

	EnglishPipe* englishPipe;
	CleanPipe* cleanPipe;
	UnityPipe* unityPipe;
	CsharpPipe* csharpPipe;
	GamesPipe* gamesPipe;
	CppPipe* cppPipe;

	

	



	

};




#endif // __GAME_SCENE_H__