#pragma once
#ifndef AboutScene_h
#define AboutScene_h
#include"cocos2d.h"
using namespace cocos2d;
class AboutScene :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(AboutScene);
};

#endif //AboutScene(màn hình bản quyền của tác giả)