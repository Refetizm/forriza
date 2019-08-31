#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include "CreditsScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. SPRITE SECTION
    //    You can add your sprites below...
	/////////////////////////////
	/*------BACKGROUND IMAGE------*/
	auto menuSprite = Sprite::create("MenuBackground.png");
	menuSprite->setAnchorPoint(Vec2(0.0, 0.0));
	menuSprite->setPosition(Point(0, 0));
	this->addChild(menuSprite);
	/*----------------------------*/


	auto logoSprite = Sprite::create("GameLogo.png");
	logoSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 4 + origin.y));
	this->addChild(logoSprite, 1);

	auto playItem = MenuItemImage::create("NewGame.png", "NewGameClicked.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 3));

	auto creditsItem = MenuItemImage::create("Credits.png", "CreditsClicked.png", CC_CALLBACK_1(MainMenuScene::GoToCreditsScene, this));
	creditsItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 2.7));

	auto exitItem = MenuItemImage::create("Exit.png", "ExitClicked.png", CC_CALLBACK_1(MainMenuScene::GoToExit, this));
	exitItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 2.4));

	auto menu = Menu::create(playItem, creditsItem, exitItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

    /////////////////////////////
    // 3. add your codes below...

    return true;
}
void MainMenuScene::GoToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void MainMenuScene::GoToCreditsScene(cocos2d::Ref* sender)
{
	auto scene = CreditsScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void MainMenuScene::GoToExit(cocos2d::Ref* psender)
{
	Director::getInstance()->end();
}
