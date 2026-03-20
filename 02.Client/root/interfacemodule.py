##Szukamy:

		self.bigBoard = None
		
##Pod dodajemy:

		self.wndGiftBox = None
		
		

##Szukamy:

		self.wndEnergyBar = None
		
##Nad dodajemy:

		import uiGift
		wndGiftBox=uiGift.GiftDialog()
		wndGiftBox.Hide()
		self.wndGiftBox=wndGiftBox

##Szukamy:

		self.wndGameButton = wndGameButton

##Nad dodajemy:

		wndGameButton.SetButtonEvent("GIFT", ui.__mem_func__(self.__OnClickGiftButton))
		
		
##Szukamy:

		uiChat.DestroyChatInputSetWindow()
	
##Nad dodajemy:
	
		if self.wndGiftBox:
			self.wndGiftBox.Clear()
			self.wndGiftBox.Hide()
			self.wndGiftBox.Destroy()
		del self.wndGiftBox
	
##Szukamy:

	def EmptyFunction(self):
		pass
		
##Dodajemy nad:

	def __OnClickGiftButton(self):
		if self.wndGameButton:
			if not self.wndGiftBox.IsShow():
				self.wndGiftBox.Open()
			else:
				self.wndGiftBox.Close()

	def ClearGift(self):
		if self.wndGameButton:
			self.wndGameButton.HideGiftButton()
		if self.wndGiftBox:
			self.wndGiftBox.Clear()
			self.wndGiftBox.Refresh()
			
	def OpenGift(self):
		if self.wndGameButton:
			self.wndGameButton.ShowGiftButton()
	