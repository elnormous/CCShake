#pragma once

#include <CCActionInterval.h>

class Shake : public cocos2d::ActionInterval
{
public:
	static Shake* create(float d, float strength);
	static Shake* create(float d, cocos2d::Point strength);
	
	bool initWithDuration(float d, cocos2d::Point strength);
	
	virtual void startWithTarget(cocos2d::Node* target);
	virtual void update(float time);
	virtual void stop(void);
	
protected:
	cocos2d::Point _initial;
	cocos2d::Point _strength;
};
