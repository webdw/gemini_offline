//Szukamy:

			case HEADER_GD_LOGIN_BY_KEY:
				QUERY_LOGIN_BY_KEY(peer, dwHandle, (TPacketGDLoginByKey *) data);
				break;

//Pod dodajemy:				
				
#ifdef OFFLINE_SHOP
			case HEADER_GD_SHOP_NAME:
				ShopName(peer, (TPacketShopName *)data);
				break;
			case HEADER_GD_SHOP_CLOSE:
				ShopClose(peer, (TPacketShopClose *)data);
				break;
			case HEADER_GD_SHOP_UPDATE_ITEM:
				ShopUpdateItem(peer, (TPacketShopUpdateItem *)data);
				break;
#endif

//Dodajemy na końcu pliku:

#ifdef OFFLINE_SHOP
void CClientManager::ShopName(CPeer * peer, TPacketShopName * p)
{
	for (TPeerList::iterator i = m_peerList.begin(); i != m_peerList.end(); ++i)
	{
		CPeer * tmp = *i;

		if (tmp == peer)
			continue;
		if (0 == tmp->GetChannel())
			continue;
		TPacketShopName packet;
		packet.shop_id = p->shop_id;
		strlcpy(packet.szSign, p->szSign, sizeof(packet.szSign) - 1);
		tmp->EncodeHeader(HEADER_DG_SHOP_NAME, 0, sizeof(packet));
		tmp->Encode(&packet, sizeof(packet));
	}
}

void CClientManager::ShopClose(CPeer * peer, TPacketShopClose *p)
{
	for (TPeerList::iterator i = m_peerList.begin(); i != m_peerList.end(); ++i)
	{
		CPeer * tmp = *i;

		if (tmp == peer)
			continue;

		if (0 == tmp->GetChannel())
			continue;

		TPacketShopClose packet;
		packet.shop_id = p->shop_id;
		packet.pid = p->pid;
		tmp->EncodeHeader(HEADER_DG_SHOP_CLOSE, 0, sizeof(packet));
		tmp->Encode(&packet, sizeof(packet));
	}
}
void CClientManager::ShopUpdateItem(CPeer * peer, TPacketShopUpdateItem *p)
{
	for (TPeerList::iterator i = m_peerList.begin(); i != m_peerList.end(); ++i)
	{
		CPeer * tmp = *i;

		if (tmp == peer)
			continue;

		if (0 == tmp->GetChannel())
			continue;
		TPacketShopUpdateItem packet;
		packet.shop_id = p->shop_id;
		packet.shop_locked = p->shop_locked;
		tmp->EncodeHeader(HEADER_DG_SHOP_UPDATE_ITEM, 0, sizeof(packet));
		tmp->Encode(&packet, sizeof(packet));
	}
}
#endif

