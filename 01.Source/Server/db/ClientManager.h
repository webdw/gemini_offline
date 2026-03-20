//Szukamy: 

	void AuctionBidCancel (CPeer * peer, DWORD bidder_id, DWORD item_id);
#endif

//Pod dodajemy:

#ifdef OFFLINE_SHOP
	void		ShopName(CPeer * peer, TPacketShopName * p);
	void		ShopClose(CPeer * peer, TPacketShopClose *p);
	void		ShopUpdateItem(CPeer * peer, TPacketShopUpdateItem *p);
#endif
