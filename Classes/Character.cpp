#include "Character.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Character::Character(cocos2d::Layer* layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	charBatchNode = SpriteBatchNode::create("Character.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("Character.plist");
	mainChar = Sprite::createWithSpriteFrameName("wlk1.png");
	mainChar->setAnchorPoint(Vec2(0.5f, 0.0));
	charBatchNode->addChild(mainChar);
	charBatchNode->setScale(0.5);
	charBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	charBatchNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y));
	auto charBody = PhysicsBody::createBox(mainChar->getContentSize(), PhysicsMaterial(0, 1, 0));
	charBody->setCollisionBitmask(CHARACTER_COLLISION_BITMASK);
	charBody->setContactTestBitmask(true);
	mainChar->setPhysicsBody(charBody);
	layer->addChild(charBatchNode, 5);
	

	Vector<SpriteFrame*>frames;
	for (int i = 1; i <= 6; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("wlk%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(frames, 0.1f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	mainChar->runAction(animate);
	
	isFalling = true;
		

}

void Character::Fall()
{
	if (true == isFalling)
	{
		charBatchNode->setPositionX(visibleSize.width / 2 + origin.x);
		charBatchNode->setPositionY(charBatchNode->getPositionY() - (CHAR_FALLING_SPEED * visibleSize.height));
		CCLOG("Downing");
	}
	else
	{
		charBatchNode->setPositionX(visibleSize.width / 2 + origin.x);
		charBatchNode->setPositionY(charBatchNode->getPositionY() + (CHAR_FALLING_SPEED * visibleSize.height));
		CCLOG("FLYING");
	}
	
}

