#include "Slot.hxx"
#include "Signal.hxx"
#include "InitializationLists.h"
#include "Ref.hxx"
#include "Generic.hxx"
#include "xintrin.h"

int slotTest(float& _f, double _d)
{
	return _f + _d;
}

int main()
{
	Slot<int(float&, double)> slot(slotTest);
	Signal<int(float&, double)> sig;

	sig.connect(slot);
	float ref = 1.f;
	sig.emit(Ref<float>(ref), 2.);

	InitializationLists in1(1);
	if (in1.isList())
	{
		return -1;
	}
	InitializationLists in2{ 1, 2, 3 };
	if (!in2.isList())
	{
		return -2;
	}

	xintrin();

	return 0;
}