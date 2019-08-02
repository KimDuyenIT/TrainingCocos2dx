#pragma once
#ifndef MainMenuScene_h
#define MainMenuScene_h
#include"cocos2d.h"
using namespace cocos2d;

class MainMenuScene:public Layer
{
public:
	static Scene* createScene();//màn hình giữ suốt từ đầu đến hết chương trình nên phải dùng static.
	virtual bool init();
	CREATE_FUNC(MainMenuScene);
private:
	void menuCloseCallback(cocos2d::Ref* pSender);
};

#endif//MainMenuScene(màn hình 1)
