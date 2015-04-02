#ifndef __SNEAKY_BUTTON_H__
#define __SNEAKY_BUTTON_H__

#include "cocos2d.h"

class SneakyButton : public cocos2d::CCNode
{
private:
    cocos2d::EventListenerTouchOneByOne * mEventListenerTouch;
    
protected:
	cocos2d::CCPoint center;
	float radiusSq;

	cocos2d::CCRect bounds;

	CC_SYNTHESIZE(bool, status, Status);
	CC_SYNTHESIZE_READONLY(bool, active, IsActive);
	CC_SYNTHESIZE_READONLY(bool, value, Value);
	CC_SYNTHESIZE(bool, isHoldable, IsHoldable);
	CC_SYNTHESIZE(bool, isToggleable, IsToggleable);
	CC_SYNTHESIZE(float, rateLimit, RateLimit);

	CC_SYNTHESIZE_READONLY(float, radius, Radius);

	//Public methods
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	bool initWithRect(cocos2d::CCRect rect);
	void limiter(float delta);
	void setRadius(float r);
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

};

#endif