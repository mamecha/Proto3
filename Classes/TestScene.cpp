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

  arr = Array::create();
  arr->retain();

  //putblock();
  //listing();
 
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
  return true;
}

void TestScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
  auto location = pTouch->getLocation();
  CCLog("%f:%f",location.x, location.y);
  ball = Sprite::create("ball.png");
  ball->setPosition(location);
  this->addChild(ball,1,1);
  ball->runAction(MoveTo::create(1.5f, Point(location.x, 0)));
  return;
}

void TestScene::onTouchEnded(Touch* pTouch, Event* pEvent)
{
  return;
}
