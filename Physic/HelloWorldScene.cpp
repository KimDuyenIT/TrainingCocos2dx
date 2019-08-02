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

USING_NS_CC;
static const float scrollSpeed = 80.f;

Scene* HelloWorld::createScene()
{
	// CREATE SCENE WITH PHYSICS
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld() ->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	// scene->getPhysicsWorld()->setGravity(Vec2(0, - 9.8f));
	auto layer = HelloWorld::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
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
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto adgeBody = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT, 4);
	auto adgeNode = Node::create();
	adgeNode->setPosition(Vec2(visibleSize.width / 2 + origin.x,visibleSize.height / 2 + origin.y));
	adgeNode->setPhysicsBody(adgeBody);
	this->addChild(adgeNode);

	auto player = Sprite::create("egg.png");
	player->setScale(0.2);
	player->setPosition(Vec2(visibleSize.width / 2 + origin.x,visibleSize.height / 2 + origin.y));
	playerBody = PhysicsBody::createCircle(player ->getContentSize().width / 2, PhysicsMaterial(0, 1, 0));
	playerBody->setCollisionBitmask(1);
	playerBody->setContactTestBitmask(true);
	playerBody->setMass(4.0);
	playerBody->setMoment(PHYSICS_INFINITY);
	player->setPhysicsBody(playerBody);

	playerBody->applyForce(Vec2(0, 20000));

	//player->addComponent(playerBody);
	this->addChild(player);

	auto spriteTerraza = Sprite::create("Plank.png");
	spriteTerraza->setScale(0.2);
	spriteTerraza->setPosition(visibleSize.width /2, spriteTerraza->getContentSize().height / 2);
	terrazaBody =PhysicsBody::createBox(spriteTerraza ->getContentSize(), PhysicsMaterial(0, 1.0f, 0));
	terrazaBody->setCollisionBitmask(2);
	terrazaBody->setContactTestBitmask(true);
	spriteTerraza->setPhysicsBody(terrazaBody);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
	getEventDispatcher() ->addEventListenerWithSceneGraphPriority(contactListener,this);

	auto listenerTouch = EventListenerTouchOneByOne::create();
	listenerTouch->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerTouch, this);
	scheduleUpdate();
	isAddForce = false;
	this->addChild(spriteTerraza);

    return true;
}
void HelloWorld::update(float dt)
{
	if (isAddForce == true)
	{

	}
}
bool HelloWorld::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	CCLOG("Apply Force");
	playerBody->applyForce(Vec2(0, 20000));
	return true;
}
bool HelloWorld::onContactBegin(PhysicsContact &contact)
{
	PhysicsBody *bodyA = contact.getShapeA()->getBody();
	PhysicsBody *bodyB = contact.getShapeB()->getBody();
	if ((bodyA->getCollisionBitmask() == 1 && bodyB->getCollisionBitmask() == 2) || 
		(bodyA->getCollisionBitmask() == 2 && bodyB->getCollisionBitmask() == 1))
	{
		if (bodyA->getCollisionBitmask() == 1)
		{

		}
		else
		{
			CCLOG("Collision!");
		}
	}
	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
