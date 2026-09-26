/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae854. */
int __cdecl -[SCSIGeneric sgInit:controller:](SCSIGeneric *self, SEL a2, unsigned int a3, id a4)
{
  id v4; // eax
  char v6[20]; // [esp+Ch] [ebp-14h] BYREF

  self->_controller = a4; /*0x1ae863*/
  self->_controllerNum = 0; /*0x1ae869*/
  *((_BYTE *)self + 284) &= ~1u; /*0x1ae873*/
  self->_isReserved = 0; /*0x1ae87a*/
  *((_BYTE *)self + 292) &= ~1u; /*0x1ae884*/
  self->_openLock = +[Object new](aNxlock, sel_new); /*0x1ae89e*/
  self->_owner = nullptr; /*0x1ae8a4*/
  sprintf(v6, "sg%d", a3); /*0x1ae8bb*/
  -[IODevice setName:](self, sel_setName_, v6); /*0x1ae8c9*/
  -[IODevice setDeviceKind:](self, sel_setDeviceKind_, "SCSIGeneric"); /*0x1ae8de*/
  v4 = objc_msgSend(a4, sel_name); /*0x1ae8eb*/
  -[IODevice setLocation:](self, sel_setLocation_, v4); /*0x1ae8f9*/
  -[IODevice setUnit:](self, sel_setUnit_, a3); /*0x1ae90d*/
  -[IODevice registerDevice](self, sel_registerDevice); /*0x1ae91a*/
  return 0; /*0x1ae924*/
}
