##Szukamy 2x:

		self.eventOverInItem = None
		
##Pod dodajemy w 2 miejscach:

		self.eventOverInItem2 = None
		self.eventOverInItem3 = None
		
##Szukamy:

	def SetOverInItemEvent(self, event):
		self.eventOverInItem = event
		
##Pod dodajemy:
		
	def SetOverInItemEvent2(self, event):
		self.eventOverInItem2 = event
		
	def SetOverInItemEvent3(self, event):
		self.eventOverInItem3 = event
		
##Szukamy i zamieniamy:

	def SetItemSlot(self, renderingSlotNumber, ItemIndex, ItemCount = 0, diffuseColor = (1.0, 1.0, 1.0, 1.0),id=0):
		if 0 == ItemIndex or None == ItemIndex:
			wndMgr.ClearSlot(self.hWnd, renderingSlotNumber)
			return

		item.SelectItem(ItemIndex)
		itemIcon = item.GetIconImage()

		item.SelectItem(ItemIndex)
		(width, height) = item.GetItemSize()	
		wndMgr.SetSlot(self.hWnd, renderingSlotNumber, ItemIndex, width, height, itemIcon, diffuseColor)	
		wndMgr.SetSlotCount(self.hWnd, renderingSlotNumber, ItemCount)
		wndMgr.SetSlotID(self.hWnd, renderingSlotNumber, id)

##Szukamy i zamieniamy:

	def OnOverInItem(self, slotNumber,vnum=0,itemID=0):
		if self.eventOverInItem:
			self.eventOverInItem(slotNumber)
		if self.eventOverInItem2 and vnum>0:
			self.eventOverInItem2(vnum)
		if self.eventOverInItem3 and itemID>0:
			self.eventOverInItem3(itemID)

##Szukamy i zamieniamy:

class ImageBox(Window):

	def __init__(self, layer = "UI"):
		Window.__init__(self, layer)

		self.eventDict = {}

	def __del__(self):
		Window.__del__(self)

	def RegisterWindow(self, layer):
		self.hWnd = wndMgr.RegisterImageBox(self, layer)

	def LoadImage(self, imageName):
		self.name = imageName
		wndMgr.LoadImage(self.hWnd, imageName)

		if len(self.eventDict)!=0:
			print "LOAD IMAGE", self, self.eventDict

	def SetAlpha(self, alpha):
		wndMgr.SetDiffuseColor(self.hWnd, 1.0, 1.0, 1.0, alpha)

	def GetWidth(self):
		return wndMgr.GetWidth(self.hWnd)

	def GetHeight(self):
		return wndMgr.GetHeight(self.hWnd)

	def OnMouseOverIn(self):
		try:
			self.eventDict["MOUSE_OVER_IN"]()
		except KeyError:
			pass

	def OnMouseOverOut(self):
		try:
			self.eventDict["MOUSE_OVER_OUT"]()
		except KeyError:
			pass

	def SAFE_SetStringEvent(self, event, func,isa=FALSE):
		if not isa:
			self.eventDict[event]=__mem_func__(func)
		else:
			self.eventDict[event]=func
			

##Szukamy:

RegisterToolTipWindow("TEXT", TextLine)

##Przed dodajemy:
	
def MakeText(parent, textlineText, x, y, color):
	textline = TextLine()
	if parent != None:
		textline.SetParent(parent)
	textline.SetPosition(x, y)
	if color != None:
		textline.SetFontColor(color[0], color[1], color[2])
	textline.SetText(textlineText)
	textline.Show()
	return textline
def MakeThinBoard(parent,  x, y, width, heigh, moveable=FALSE,center=FALSE):
	thin = ThinBoard()
	if parent != None:
		thin.SetParent(parent)
	if moveable == TRUE:
		thin.AddFlag('movable')
		thin.AddFlag('float')
	thin.SetSize(width, heigh)
	thin.SetPosition(x, y)
	if center == TRUE:
		thin.SetCenterPosition()
	thin.Show()
	return thin