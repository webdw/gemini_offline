//Szukamy:

typedef struct packet_shop_item
{
    DWORD       vnum;
    DWORD       price;
    BYTE        count;
	BYTE		display_pos;
	long		alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TShopItemData;

//Zamieniamy na:

typedef struct packet_shop_item
{
    DWORD       vnum;
#ifdef ENABLE_FULL_YANG
	long long	price;			// PC 상점에만 이용
#else
	DWORD		price;
#endif
    BYTE        count;
	BYTE		display_pos;
	long		alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TShopItemData;