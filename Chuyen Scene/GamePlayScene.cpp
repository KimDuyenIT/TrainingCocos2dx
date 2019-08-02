#include"GamePlayScene.h"
#include"AboutScene.h"

Scene* GamePlayScene::createScene()
{
	Scene *scene = Scene::create();
	auto layer = GamePlayScene::create();
	scene->addChild(layer);
	return scene;
}
bool GamePlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("GamePlayScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(250, 200));
	this->addChild(label);

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GamePlayScene::menuCloseCallback, this));

	closeItem->setPosition(visibleSize / 2);

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	return true;
}
void GamePlayScene::menuCloseCallback(Ref* pSender)
{
	CCLOG("menuCloseCallback clicked");
	Director::getInstance()->replaceScene(AboutScene::createScene());//chuyển sang Scene AboutScene
}