#pragma once
class Debuff
{
private:
protected:
	int debuffResult[4]; //argument 0: duration; arguments 1-3 - decreasing s/a/i
public:
	Debuff(int duration, int eff_strength, int eff_agility, int eff_intelligence);
	virtual void inflict(int arr[4]) = 0;
};

class GooedSpider : public Debuff
{
private:
protected:
public:
	GooedSpider();
	void inflict(int arr[4]);
};
