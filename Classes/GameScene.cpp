#include "GameScene.h"
#include "GameOverScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;


Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vect(0, 0));
	auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	edgeBody->setContactTestBitmask(false);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);


    /////////////////////////////
    // 2. SCENE SECTION
    //    You can add your scene materials below...
	/////////////////////////////

	/*----------2.1 NON-PHYSICAL SECTION----------*/
	/* You can add non-physical materials to this section(Background, Roads etc.) */
	auto moverSprite = Sprite::create("Mover.png");
	moverSprite->setAnchorPoint(Vec2(0.0, 0.0));
	moverSprite->setPosition(Point(0, 0));
	this->addChild(moverSprite, 3);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	moverSprite->runAction(moverAction);

	auto backgroundMap = TMXTiledMap::create("Background.tmx");
	backgroundMap->setAnchorPoint(Vec2(0.0, 0.0));
	backgroundMap->setPosition(Point(0, 0));
	this->addChild(backgroundMap, 1);
	auto backgroundAction = RepeatForever::create(MoveBy::create(1, Point(BACKGROUND_MOVEMENT_SPEED, 0)));
	backgroundMap->runAction(backgroundAction);

	auto roadMap = TMXTiledMap::create("Road.tmx");
	roadMap->setAnchorPoint(Vec2(0.0, 0.0));
	roadMap->setPosition(Point(0, 0));
	moverSprite->addChild(roadMap, 2);

	auto mountainSprite = Sprite::create("Mountain.png");
	mountainSprite->setAnchorPoint(Vec2(0.0, 0.0));
	mountainSprite->setPosition(Point(0, 186));
	this->addChild(mountainSprite, 2);

	auto bushMap = TMXTiledMap::create("Bushes.tmx");
	bushMap->setAnchorPoint(Vec2(0.0, 0.0));
	bushMap->setPosition(Point(0, 186));
	moverSprite->addChild(bushMap, 3);

	auto office1Sprite = Sprite::create("Office1.png");
	office1Sprite->setAnchorPoint(Vec2(0.0, 0.0));
	office1Sprite->setPosition(Point(0, 186));
	moverSprite->addChild(office1Sprite, 4);

	auto office2Sprite = Sprite::create("Office2.png");
	office2Sprite->setAnchorPoint(Vec2(0.0, 0.0));
	office2Sprite->setPosition(Point(500, 186));
	moverSprite->addChild(office2Sprite, 4);
	

	

	/*----------2.1 PHYSICAL SECTION----------*/
	/* You can add physical materials to this section(Characters, Pipes etc.) */
	
	
	


	/////////////////////////////
	// 2. CHARACTER SECTION
	//    You can add your character materials below...
	/////////////////////////////

	character = new Character(this);

	roadBlock = new RoadBlock(this);

	teamPipe = new TeamPipe(this);

	cocosPipe = new CocosPipe(this);

	englishPipe = new EnglishPipe(this);

	cleanPipe = new CleanPipe(this);

	unityPipe = new UnityPipe(this);

	csharpPipe = new CsharpPipe(this);

	gamesPipe = new GamesPipe(this);

	cppPipe = new CppPipe(this);
	


	
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->scheduleUpdate();



    return true;
}


bool GameScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	//Check if the bodies have collided

	if (( CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && PIPE_COLLISION_BITMASK == b->getCollisionBitmask() ) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && PIPE_COLLISION_BITMASK == a->getCollisionBitmask()))
	{
		auto scene = GameOverScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		CCLOG("CRUSH");
	}

	return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	
	character->Fly();
	this->scheduleOnce(schedule_selector(GameScene::StopFlying), CHAR_FLY_DURATION);
	CCLOG("EVENT BEGAN");
	
	return true;
}


void GameScene::StopFlying(float dt)
{
	character->StopFlying();
}
void GameScene::update(float dt)
{
	character->Fall();
}