//
//  TestScene.cpp
//  Proto3
//
//  Created by 矢島 新太郎 on 2014/09/17.
//
//

#include "TestScene.h"

using namespace cocos2d;
using namespace std;

USING_NS_CC;

Scene* TestScene::createScene()
{
  auto scene = Scene::create();
  auto layer = TestScene::create();
  scene->addChild(layer);

  return scene;
}

bool TestScene::init()
{
  if ( !Layer::init() ) return false;

  Size view = Director::sharedDirector()->getWinSize();

  auto rect = Sprite::create();
  rect->setTextureRect(Rect(0,0, 10,20));
  rect->setColor(Color3B(0, 255, 128));
  rect->setPosition(100, 300);
  this->addChild(rect);
  auto cir = DrawNode::create();
  cir->drawDot(ccp(300, 300), 10, ccc4FFromccc3B(ccWHITE));
  this->addChild(cir);
  
  auto cache = CCSpriteFrameCache::getInstance();
  cache->addSpriteFramesWithFile("sprite-0001-default.plist");
  auto cache_ui = CCSpriteFrameCache::getInstance();
  cache_ui->addSpriteFramesWithFile("ui-0001-default.plist");

  log("w: %f, h: %f", view.width, view.height);

  // ui
  auto btn_a = Sprite::createWithSpriteFrameName("button1.png");
  btn_a->setPosition(Point(view.width - 128, 64));
  this->addChild(btn_a);
  auto btn_b = Sprite::createWithSpriteFrameName("button1.png");
  btn_b->setPosition(Point(view.width - 128*2, 64));
  this->addChild(btn_b);
  auto btn_left = Sprite::createWithSpriteFrameName("button3.png");
  btn_left->setPosition(Point(128, 64));
  this->addChild(btn_left);
  auto btn_right = Sprite::createWithSpriteFrameName("button3.png");
  btn_right->setPosition(Point(128*2, 64));
  this->addChild(btn_right);
 
  
  
  
  
  
  auto sprite = Sprite::createWithSpriteFrameName("sprite_1.png");
  sprite->setPosition(Point(500, 500));
  this->addChild(sprite);
  sprite->setTag(1);
  
 
  auto anime = Animation::create();
  
  for (int i=2; i < 5; i++) {
    auto str = __String::createWithFormat("sprite_%i.png", i);
    SpriteFrame *sprite = cache->getSpriteFrameByName(str->getCString());
    anime->addSpriteFrame(sprite);
    log("filename: %s", str->getCString());
  }
  anime->setDelayPerUnit(0.2f);
  anime->setRestoreOriginalFrame(true);

  auto action = Animate::create(anime);
  auto ani = RepeatForever::create(action);
  sprite->runAction(ani);
  
  // Event
  auto dispatcher = Director::getInstance()->getEventDispatcher();
  eventListener = EventListenerTouchOneByOne::create();
  eventListener->onTouchBegan		= CC_CALLBACK_2(TestScene::onTouchBegan, this);
  eventListener->onTouchMoved		= CC_CALLBACK_2(TestScene::onTouchMoved, this);
  eventListener->onTouchEnded		= CC_CALLBACK_2(TestScene::onTouchEnded, this);
  dispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

  return true;
}
bool TestScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
  auto location = pTouch->getLocation();
  auto move = MoveTo::create(1.5f, Point(location.x ,location.y ));
  auto sprite = this->getChildByTag(1);
  sprite->runAction(move);
  return true;
}

void TestScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
  return;
}

void TestScene::onTouchEnded(Touch* pTouch, Event* pEvent)
{
  return;
}
