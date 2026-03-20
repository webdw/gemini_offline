//Szukamy:

BOOL CSlotWindow::OnMouseLeftButtonUp()

//Przed dodajemy:

void CSlotWindow::SetSlotID(DWORD dwIndex, DWORD dwID)
{
	TSlot * pSlot;
	if (!GetSlotPointer(dwIndex, &pSlot))
		return;

	if (dwID <= 0)
	{
		return;
	}
	else
	{
		
		pSlot->dwItemID=dwID;
	}
}

//Szukamy:

BOOL CSlotWindow::OnOverInItem(DWORD dwSlotNumber)
{
	TSlot * pSlot;
	if (!GetSlotPointer(dwSlotNumber, &pSlot))
		return FALSE;

	if (!pSlot->isItem)
		return FALSE;

	if (pSlot->dwSlotNumber == m_dwToolTipSlotNumber)
		return TRUE;

	m_dwToolTipSlotNumber = dwSlotNumber;
	PyCallClassMemberFunc(m_poHandler, "OnOverInItem", Py_BuildValue("(i)", dwSlotNumber));

	return TRUE;
}

//Zamieniamy na:

BOOL CSlotWindow::OnOverInItem(DWORD dwSlotNumber)
{
	TSlot * pSlot;
	if (!GetSlotPointer(dwSlotNumber, &pSlot))
		return FALSE;

	if (!pSlot->isItem)
		return FALSE;

	if (pSlot->dwSlotNumber == m_dwToolTipSlotNumber)
		return TRUE;

	m_dwToolTipSlotNumber = dwSlotNumber;
	PyCallClassMemberFunc(m_poHandler, "OnOverInItem", Py_BuildValue("(iii)", dwSlotNumber,pSlot->dwItemIndex,pSlot->dwItemID));

	return TRUE;
}