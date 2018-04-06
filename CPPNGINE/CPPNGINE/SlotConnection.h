#pragma once

template<class F>
class SlotConnection;

template<class F, class... A>
class SlotConnection< F(A...) >
{

public:

	SlotConnection();

};
