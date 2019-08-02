#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cityscene.plist");

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::createWithSpriteFrameName("background.png");
	background->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    this->addChild(background);
 
	// sprite
	auto frames = getAnimation("capguy/walk/%04d.png", 8);//gọi hàm getAnimation()
	auto sprite = Sprite::createWithSpriteFrame(frames.front());
	background->addChild(sprite);
	sprite->setPosition(100, 620);
	//Sử dụng gọi anim
	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 8);//chạy 8 ảnh frame trong 1 giây
	sprite->runAction(RepeatForever::create(Animate::create(animation)));

	auto movement = MoveTo::create(7, Vec2(2148, 620));//chỉnh thông số
	auto resetPosition = MoveTo::create(0, Vec2(-150, 620));
	auto sequence = Sequence::create(movement, resetPosition, NULL);
	sprite->runAction(RepeatForever::create(sequence));

    return true;
}


Vector<SpriteFrame*> HelloWorld::getAnimation(const char *format, int count)//truyền capguy/walk/%04d và 8
{
	auto spritecache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> animFrames;//tạo mảng vector để chứa 8 tấm hình
	char str[100];
	//Tạo frame
	for (int i = 1; i <= count; i++)
	{
		sprintf(str, format, i);//(1.png,capguy/walk/000.png,1->8)
								//Lấy ra 1.png rồi thêm vào vector, cứ thế tương tự...
		//log("%s", str);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	return animFrames;//trả về mảng 8 tấm hình
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
