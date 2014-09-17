//
//  ___FILENAME___
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//___COPYRIGHT___
//

#include "___FILEBASENAME___.h"

using namespace cocos2d;
using namespace std;

USING_NS_CC;

___FILEBASENAMEASIDENTIFIER___::___FILEBASENAMEASIDENTIFIER___()
{
}

___FILEBASENAMEASIDENTIFIER___::~___FILEBASENAMEASIDENTIFIER___()
{
}

Scene* ___FILEBASENAMEASIDENTIFIER___::createScene()
{
  auto scene = Scene::create();
  auto layer = ___FILEBASENAMEASIDENTIFIER___::create();
  scene->addChild(layer);

  return scene;
}

bool ___FILEBASENAMEASIDENTIFIER___::init()
{
  if ( !Layer::init() ) return false;

  //Welcome Message
  auto windowSize = Director::getInstance()->getWinSize();
  auto label = LabelTTF::create("___FILEBASENAMEASIDENTIFIER___", "Arial", 24);
  label->setPosition(windowSize.width / 2, windowSize.height / 2);
  this->addChild(label);
 
  // Event
  auto dispatcher = Director::getInstance()->getEventDispatcher();
  eventListener = EventListenerTouchOneByOne::create();
  eventListener->onTouchBegan		= CC_CALLBACK_2(___FILEBASENAMEASIDENTIFIER___::onTouchBegan, this);
  eventListener->onTouchMoved		= CC_CALLBACK_2(___FILEBASENAMEASIDENTIFIER___::onTouchMoved, this);
  eventListener->onTouchEnded		= CC_CALLBACK_2(___FILEBASENAMEASIDENTIFIER___::onTouchEnded, this);
  dispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

  return true;
}
bool ___FILEBASENAMEASIDENTIFIER___::onTouchBegan(Touch* pTouch, Event* pEvent)
{
  return true;
}

void ___FILEBASENAMEASIDENTIFIER___::onTouchMoved(Touch* pTouch, Event* pEvent)
{
  return;
}

void ___FILEBASENAMEASIDENTIFIER___::onTouchEnded(Touch* pTouch, Event* pEvent)
{
  return;
}
