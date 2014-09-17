//
//  TestScene.h
//  Proto3
//
//  Created by 矢島 新太郎 on 2014/09/17.
//
//

#ifndef __Proto3__TestScene__
#define __Proto3__TestScene__
#define BALL_SIZE 5;
#define BLOCK_SIZE 30;
#define BLOCK_QUENTITY 30; // ブロック量
#define DEIVISION BLOCK_SIZE/2*1.5 //基準メモリ

#include "cocos2d.h"
typedef cocos2d::Point VECTOR;

class TestScene : public cocos2d::Layer
{
  private:
    cocos2d::Point currentpos, prevpos;
    VECTOR velocity; // 座標保存変数と速度ベクトル管理
    cocos2d::Sprite* ball;
    cocos2d::Sprite* block;
    cocos2d::Sprite* bar; // 画像
    cocos2d::Array *arr;
    cocos2d::Point blockpos[30];
    std::vector<int>* list;
  
    cocos2d::EventListenerTouchOneByOne *eventListener;

  public:
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(TestScene);
    void spritecheck(void);
    void putblock(void);
    void listing(void);
    void collision(void);
    bool reflection(int i);
  
    // EVENT
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
};

#endif /* defined(__Proto3__TestScene__) */
