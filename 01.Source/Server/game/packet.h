//Szukamy:

struct packet_shop_item
{   
	DWORD       vnum;
	DWORD       price;
	BYTE        count;
	BYTE		display_pos;
	long	alSockets[ITEM_SOCKET_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
};

//Zamieniamy  na:

struct packet_shop_item
{   
	DWORD       vnum;
#ifdef FULL_YANG
	long long	price;
#else
	DWORD       price;
#endif
    BYTE        count;
	BYTE		display_pos;
	long	alSockets[ITEM_SOCKET_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
};

//Szukamy:

typedef struct SPacketCGMyShop
{
	BYTE	bHeader;
	char	szSign[SHOP_SIGN_MAX_LEN + 1];
	BYTE	bCount;
} TPacketCGMyShop;

//Zamieniamy na:
typedef struct SPacketCGMyShop
{
	BYTE	bHeader;
	char	szSign[SHOP_SIGN_MAX_LEN + 1];
	BYTE	bCount;
	#ifdef OFFLINE_SHOP
	BYTE	days;
	#endif
} TPacketCGMyShop;