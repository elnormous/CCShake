#pragma once

#include <actions/CCActionInterval.h>

class CCShake : public cocos2d::CCActionInterval
{
public:
	static CCShake* create(float d, float strength);
	static CCShake* create(float d, cocos2d::CCPoint strength);
	
	bool initWithDuration(float d, cocos2d::CCPoint strength);
	
	virtual void startWithTarget(cocos2d::CCNode* target);
	virtual void update(float time);
	virtual void stop(void);
	
protected:
	cocos2d::CCPoint _initial;
	cocos2d::CCPoint _strength;
};
