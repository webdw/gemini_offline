##Szukamy:

			self.gameButtonDict={
			
##Pod dodajemy:

				"GIFT" : self.GetChild("GiftIcon"),


##Dodajemy na końcu:
	
	def ShowGiftButton(self):
		self.gameButtonDict["GIFT"].Show()

	def HideGiftButton(self):
		self.gameButtonDict["GIFT"].Hide()



	
