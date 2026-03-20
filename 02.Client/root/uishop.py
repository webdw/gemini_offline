##Dopisujemy:

import chr

##Szukamy:

		self.yShopStart = 0
		
##Pod dodajemy:

		self.vid = 0
		
##Szukamy:

		self.titleBar = 0
		
##Pod dodajemy:

		self.vid = 0

##Szukamy i zamieniamy:

	def Open(self, vid, type=0):
		self.vid=int(vid)
		isPrivateShop = False
		isMainPlayerPrivateShop = False
		myshop=False
		for i in xrange(len(constInfo.MyShops)):
			if int(constInfo.MyShops[i]["vid"]) == int(self.vid):
				myshop=True
				self.vid=int(constInfo.MyShops[i]["id"])
		chr.SelectInstance(self.vid)
		if chr.GetRace() == 30000 or not chr.IsNPC(self.vid):
			isPrivateShop = True
		if player.IsMainCharacterIndex(self.vid):
			myshop=True
			self.vid=""
		if myshop == True:
			isMainPlayerPrivateShop = True

			self.btnBuy.Hide()
			self.btnSell.Hide()
			self.btnClose.Show()

		else:

			isMainPlayerPrivateShop = False

			self.btnBuy.Show()
			self.btnSell.Show()
			self.btnClose.Hide()

		shop.Open(isPrivateShop, isMainPlayerPrivateShop)

		self.tabIdx = 0

		if isPrivateShop:
			self.__HideMiddleTabs()
			self.__HideSmallTabs()
		else:
			if shop.GetTabCount() == 1:
				self.__ShowBuySellButton()
				self.__HideMiddleTabs()
				self.__HideSmallTabs()
			elif shop.GetTabCount() == 2:
				self.__HideBuySellButton()
				self.__ShowMiddleTabs()
				self.__HideSmallTabs()
				self.__SetTabNames()
				self.middleRadioButtonGroup.OnClick(0)
			elif shop.GetTabCount() == 3:
				self.__HideBuySellButton()
				self.__HideMiddleTabs()
				self.__ShowSmallTabs()
				self.__SetTabNames()
				self.middleRadioButtonGroup.OnClick(1)

		self.Refresh()
		self.SetTop()
		
		self.Show()

		(self.xShopStart, self.yShopStart, z) = player.GetMainCharacterPosition()
		
##Szukamy i zamieniamy:

	def OnClosePrivateShop(self):
		net.SendChatPacket("/close_shop "+str(self.vid))
		self.OnCloseQuestionDialog()
		return True
