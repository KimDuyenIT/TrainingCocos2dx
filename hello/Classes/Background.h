#ifndef __Background_H__
#define __Background_H__

#include "cocos2d.h"

class Background : public cocos2d::Node
{
public:
	static Background* create(const char* nameTextureBackground, const char* nameTextureBorder, cocos2d::Vec2 pos);

    virtual bool init(const char* nameTextureBackground, const char* nameTextureBorder, cocos2d::Vec2 pos);

	cocos2d::Sprite *background;

	inline cocos2d::Sprite * getBorderLeft() { return borderLeft; }
	inline cocos2d::Sprite * getBorderRight() { return borderRight; }
private:
	cocos2d::Sprite *borderLeft, *borderRight;
};

#endif // __Background_H__
