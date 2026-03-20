//Szukamy:
		DWORD	GetSIGVnum() const
		{
			return m_dwSIGVnum;
		}

//Pod dodajemy:

#ifdef OFFLINE_SHOP
	public:
		void		SetRealID(DWORD id)		{ m_dwRealID = id; }
		DWORD		GetRealID()			{ return m_dwRealID; }
	protected:
		DWORD			m_dwRealID;
#endif