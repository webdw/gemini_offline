//Szukamy:

		// Private Shop
		bool SendBuildPrivateShopPacket(const char * c_szName, const std::vector<TShopItemTable> & c_rSellingItemStock);

//Zamieniamy na:

		// Private Shop
		#ifdef ENABLE_OFFLINE_SHOP
		bool SendBuildPrivateShopPacket(const char * c_szName, const std::vector<TShopItemTable> & c_rSellingItemStock,DWORD days);
		#else
		bool SendBuildPrivateShopPacket(const char * c_szName, const std::vector<TShopItemTable> & c_rSellingItemStock);
		#endif