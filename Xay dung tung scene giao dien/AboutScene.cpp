#include"AboutScene.h"

Scene* AboutScene::createScene()
{
	Scene *scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}
bool AboutScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto label = Label::createWithTTF("AboutScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(250, 200));
	this->addChild(label);
	return true;
}