#include "CCShake.h"

USING_NS_CC;

inline float rangedRand(float min, float max)
{
	return CCRANDOM_0_1() * (max - min) + min;
}

Shake* Shake::create(float d, float strength)
{
	return create(d, Point(strength, strength));
}

Shake* Shake::create(float duration, cocos2d::Point strength)
{
	Shake* action = new Shake();
	action->initWithDuration(duration, strength);
	action->autorelease();
	
	return action;
}

bool Shake::initWithDuration(float duration, cocos2d::Point strength)
{
	if (CCActionInterval::initWithDuration(duration))
	{
		_strength = strength;
		return true;
	}
	
	return false;
}

void Shake::update(float time)
{
	Point rand = Point(rangedRand(-_strength.x, _strength.x),
					   rangedRand(-_strength.y, _strength.y));
	
	_target->setPosition(_initial + rand);
}

void Shake::startWithTarget(Node* target)
{
	CCActionInterval::startWithTarget(target);
	
	_initial = target->getPosition();
}

void Shake::stop(void)
{
	_target->setPosition(_initial);
	
	CCActionInterval::stop();
}
