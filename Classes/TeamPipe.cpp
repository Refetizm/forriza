#include "TeamPipe.h"
#include "GameScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

TeamPipe::TeamPipe(cocos2d::Layer* layer)
{
	teamPipeSprite = Sprite::create("TeamPipe.png");
	teamPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	teamPipeSprite->setPosition(Point(1200, 100));
	auto teamPipeBody = PhysicsBody::createBox(teamPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	teamPipeBody->setCollisionBitmask(2);
	teamPipeBody->setContactTestBitmask(true);
	teamPipeBody->setDynamic(false);
	teamPipeSprite->setPhysicsBody(teamPipeBody);
	layer->addChild(teamPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	teamPipeSprite->runAction(moverAction);

	

}
CocosPipe::CocosPipe(cocos2d::Layer* layer)
{
	cocosPipeSprite = Sprite::create("Thrash.png");
	cocosPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	cocosPipeSprite->setPosition(Point(1600, 100));
	auto cocosPipeBody = PhysicsBody::createBox(cocosPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	cocosPipeBody->setCollisionBitmask(2);
	cocosPipeBody->setContactTestBitmask(true);
	cocosPipeBody->setDynamic(false);
	cocosPipeSprite->setPhysicsBody(cocosPipeBody);
	layer->addChild(cocosPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	cocosPipeSprite->runAction(moverAction);
}