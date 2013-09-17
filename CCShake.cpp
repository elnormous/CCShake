#include "CCShake.h"

USING_NS_CC;

inline float rangedRand(float min, float max)
{
	return CCRANDOM_0_1() * (max - min) + min;
}

CCShake* CCShake::create(float d, float strength)
{
	return create(d, ccp(strength, strength));
}

CCShake* CCShake::create(float duration, cocos2d::CCPoint strength)
{
	CCShake* action = new CCShake();
	action->initWithDuration(duration, strength);
	action->autorelease();
	
	return action;
}

bool CCShake::initWithDuration(float duration, cocos2d::CCPoint strength)
{
	if (CCActionInterval::initWithDuration(duration))
	{
		_strength = strength;
		return true;
	}
	
	return false;
}

void CCShake::update(float time)
{
	CCPoint rand = ccp(rangedRand(-_strength.x, _strength.x),
					   rangedRand(-_strength.y, _strength.y));
	
	m_pTarget->setPosition(_initial + rand);
}

void CCShake::startWithTarget(CCNode* target)
{
	CCActionInterval::startWithTarget(target);
	
	_initial = target->getPosition();
}

void CCShake::stop(void)
{
	m_pTarget->setPosition(_initial);
	
	CCActionInterval::stop();
}
