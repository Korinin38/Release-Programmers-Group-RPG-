#include "debuff.h"

Debuff::Debuff(int duration, int eff_strength, int eff_agility, int eff_intelligence)
{
	debuffResult[0] = duration;
	debuffResult[1] = eff_strength;
	debuffResult[2] = eff_agility;
	debuffResult[3] = eff_intelligence;
}

GooedSpider::GooedSpider() : Debuff(3, 0, -3, 0){}


void GooedSpider::inflict(int arr[4])
{
	arr[0] = debuffResult[0];
	arr[1] = 0;
	arr[2] = debuffResult[0];
	arr[3] = 0;
	debuffResult[0]--;
}
