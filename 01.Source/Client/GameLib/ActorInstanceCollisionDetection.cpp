//Szukamy:

BOOL CActorInstance::TestActorCollision(CActorInstance & rVictim)
{

//Zamieniamy na:

#include "../UserInterface/Locale_inc.h"
BOOL CActorInstance::TestActorCollision(CActorInstance & rVictim)
{
#ifdef ENABLE_OFFLINE_SHOP
	if (rVictim.GetRace() == 30000)
		return FALSE;
#endif