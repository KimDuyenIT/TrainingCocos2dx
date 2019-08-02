#include"MainMenuScene.h"
#include"GamePlayScene.h"

Scene* MainMenuScene::createScene()
{
	Scene* scene = Scene::create();//khởi tạo Scene
	auto layer = MainMenuScene::create();//tạo ra lớp layer của Scene hiện tại      
	scene->addChild(layer);//Thêm layer vào Scene
	return scene;
}

bool MainMenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("MainMenuScene", "fonts/Marker Felt.ttf", 24);        
	label->setPosition(Vec2(250,200));
	this->addChild(label);

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));

		closeItem->setPosition(visibleSize/2);

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void MainMenuScene::menuCloseCallback(Ref* pSender)
{
	CCLOG("menuCloseCallback clicked");
	Director::getInstance()->replaceScene(GamePlayScene::createScene());//chuyển sang Scene GamePlay
}
