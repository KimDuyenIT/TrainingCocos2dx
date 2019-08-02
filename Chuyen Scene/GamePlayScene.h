#pragma once
#ifndef GamePlayScene_h
#define GamePlayScene_h
#include"cocos2d.h"
using namespace cocos2d;
class GamePlayScene:public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GamePlayScene);
private:
	void menuCloseCallback(cocos2d::Ref* pSender);
};

#endif //GamePlayScene(màn hình chơi game)

