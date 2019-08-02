#include"MainMenuScene.h"

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
	auto label = Label::createWithTTF("MainMenuScene", "fonts/Marker Felt.ttf", 24);        
	label->setPosition(Vec2(250,200));
	this->addChild(label);
	return true;
}