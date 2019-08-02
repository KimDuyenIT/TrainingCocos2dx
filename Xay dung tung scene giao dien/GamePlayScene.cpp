#include"GamePlayScene.h"

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
	auto label = Label::createWithTTF("GamePlayScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(250, 200));
	this->addChild(label);
	return true;
}