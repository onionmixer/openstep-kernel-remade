/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4dec. */
id __cdecl -[IOFrameBufferDisplay initFromDeviceDescription:](IOFrameBufferDisplay *self, SEL a2, id a3)
{
  int v4; // [esp-10h] [ebp-34h]
  objc_super v5; // [esp+8h] [ebp-1Ch] BYREF
  char v6[20]; // [esp+10h] [ebp-14h] BYREF

  v5.receiver = self; /*0x1c4e02*/
  v5.super_class = (Class)stru_1FA604.super_class; /*0x1c4e0b*/
  if ( -[IODirectDevice initFromDeviceDescription:](&v5, sel_initFromDeviceDescription_, a3) ) /*0x1c4e12*/
  {
    self->_pendingDisplayMode = -1; /*0x1c4e3c*/
    self->_currentDisplayMode = -1; /*0x1c4e46*/
    self->_displayModeCount = -1; /*0x1c4e50*/
    self->_displayModes = nullptr; /*0x1c4e5a*/
    sprintf(v6, "Display%d", dword_1E53D4); /*0x1c4e74*/
    v4 = dword_1E53D4++; /*0x1c4e7f*/
    -[IODevice setUnit:](self, sel_setUnit_, v4); /*0x1c4e8e*/
    -[IODevice setName:](self, sel_setName_, v6); /*0x1c4e9c*/
    return self; /*0x1c4ea1*/
  }
  else
  {
    v5.receiver = self; /*0x1c4e25*/
    v5.super_class = (Class)stru_1FA604.super_class; /*0x1c4e2e*/
    return -[IODirectDevice free](&v5, sel_free); /*0x1c4e32*/
  }
}
