/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c80f8. */
id __cdecl -[IOVPCodeDisplay setTransferTable:count:](IOVPCodeDisplay *self, SEL a2, const unsigned int *a3, int a4)
{
  char *redTransferTable; // edx
  char *v5; // eax
  char *v6; // eax
  unsigned int v7; // eax
  int i; // esi
  char *greenTransferTable; // ecx
  char v10; // al
  int v11; // esi
  const unsigned int *v12; // ecx
  char *v14; // [esp+Ch] [ebp-4h]

  redTransferTable = self->redTransferTable; /*0x1c8104*/
  if ( redTransferTable ) /*0x1c810c*/
    IOFree((int)redTransferTable, 3 * self->transferTableCount); /*0x1c8119*/
  self->transferTableCount = a4; /*0x1c8124*/
  v5 = (char *)IOMalloc(3 * a4); /*0x1c812e*/
  self->redTransferTable = v5; /*0x1c8133*/
  v6 = &v5[a4]; /*0x1c8139*/
  self->greenTransferTable = v6; /*0x1c813b*/
  self->blueTransferTable = &v6[a4]; /*0x1c8143*/
  v7 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c815c*/
  if ( v7 <= 1 ) /*0x1c8162*/
  {
    for ( i = 0; a4 > i; ++i ) /*0x1c8171*/
    {
      v14 = self->redTransferTable; /*0x1c817e*/
      greenTransferTable = self->greenTransferTable; /*0x1c8181*/
      v10 = a3[i]; /*0x1c8190*/
      self->blueTransferTable[i] = v10; /*0x1c8193*/
      greenTransferTable[i] = v10; /*0x1c8196*/
      v14[i] = v10; /*0x1c819c*/
    }
  }
  else if ( v7 > 4 ) /*0x1c8167*/
  {
    IOFree((int)self->redTransferTable, 3 * a4); /*0x1c81f0*/
    self->redTransferTable = nullptr; /*0x1c81f5*/
  }
  else
  {
    v11 = 0; /*0x1c81a8*/
    if ( a4 > 0 ) /*0x1c81ad*/
    {
      v12 = a3; /*0x1c81af*/
      do /*0x1c81e1*/
      {
        self->redTransferTable[v11] = *((_BYTE *)v12 + 3); /*0x1c81bd*/
        self->greenTransferTable[v11] = *((_BYTE *)v12 + 2); /*0x1c81c9*/
        self->blueTransferTable[v11++] = BYTE1(*v12++); /*0x1c81d7*/
      }
      while ( a4 > v11 ); /*0x1c81e1*/
    }
  }
  -[IOVPCodeDisplay setGammaTable](self, sel_setGammaTable); /*0x1c820a*/
  return self; /*0x1c8214*/
}
