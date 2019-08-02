/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include<climits>
#include<cstdlib>
#include<iostream>
using namespace std;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//-------------------Đẩy các layer vào
	auto backgroundColor = LayerColor::create(
		Color4B(173, 255, 250, 255),
		visibleSize.width,
		visibleSize.height
	);
	backgroundColor->setPosition(Point::ZERO);
	addChild(backgroundColor, 0);
	//Layer mặt đất
	auto ground = Sprite::create("ground.png");
	ground->setAnchorPoint(Point(0, 0));
	ground->setPosition(Point::ZERO);
	addChild(ground, 1);
	//Tạo 1 đối tượng Parallax
	_backgroundElements = InfiniteParallaxNode::create();
	//Layer đá
	unsigned int rocksQuantity = 7;
	for (unsigned int i = 0; i < rocksQuantity; i++)
	{
		auto rock = Sprite::create("rock.png");
		rock->setAnchorPoint(Point::ZERO);
		rock->setScale(randomValueBetween(0.6, 0.75));
		_backgroundElements->addChild(rock,randomValueBetween(-10, -6),Point(0.95, 1.0),
			Point(
			(visibleSize.width / 5) * (i + 1) + randomValueBetween(0,100),ground->getContentSize().height - 5));
	}
	// Layer tree
	unsigned int treesQuantity = 35;
	for (unsigned int i = 0; i < treesQuantity; i++)
	{
		auto tree = Sprite::create("tree.png");
		tree->setAnchorPoint(Point::ZERO);
		tree->setScale(randomValueBetween(0.5, 0.75));
		_backgroundElements->addChild(
			tree,
			randomValueBetween(-5, -1),
			Point(0.5, 1),
			Point(visibleSize.width / (treesQuantity - 5) * (i + 1) +
				randomValueBetween(25, 50),
				ground->getContentSize().height - 8));
	}
	// Thêm Parallax vào :Layer, update Scene 
	addChild(_backgroundElements, 2);
	schedule(schedule_selector(HelloWorld::update), 0.01);

	//-------------------Kết thúc đẩy layer

    return true;
}

//----------------Thêm các hàm 
void HelloWorld::update(float delta)
{
	Point scrollDecrement = Point(7, 0);
	_backgroundElements->setPosition(_backgroundElements->getPosition() - scrollDecrement);
	_backgroundElements->updatePosition();
}
float HelloWorld::randomValueBetween(float low, float hight)
{
	return (((float)rand() / RAND_MAX)*(hight - low)) + low;
}
//----------------Kết thúc thêm các hàm

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
