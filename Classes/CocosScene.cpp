#include "CocosScene.h"
#include "Definitions.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* CocosScene::createScene()
{
    return CocosScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool CocosScene::init()
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
	this->scheduleOnce(schedule_selector(CocosScene::GoToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);
	auto cocosSprite = Sprite::create("CocosScene.png");
	cocosSprite->setAnchorPoint(Vec2(0.0, 0.0));
	cocosSprite->setPosition(Point(0, 0));
	this->addChild(cocosSprite);

    /////////////////////////////
    // 3. add your codes below...

    return true;
}

void CocosScene::GoToMainMenuScene(float dt)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

