#include "Slot.hxx"
#include "Signal.hxx"

int slotTest(float _f, double _d)
{
	return _f + _d;
}

int main()
{
	Slot<int(float, double)> slot(slotTest);
	Signal<int(float, double)> sig;

	sig.connect(slot);
	sig.emit(1.f, 2.);

	return 0;
}