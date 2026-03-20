//Szukamy:

PyObject * poModule = Py_InitModule("chrmgr", s_methods);

//Pod dodajemy:

#ifdef ENABLE_OFFLINE_SHOP
	PyModule_AddIntConstant(poModule, "NAMECOLOR_SHOP", CInstanceBase::NAMECOLOR_SHOP);
#endif

