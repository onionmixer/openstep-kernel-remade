/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c16a0. */
id __cdecl -[IOEISADeviceDescription _initWithDelegate:](IOEISADeviceDescription *self, SEL a2, id a3)
{
  id v3; // edi
  void *v4; // eax
  _BYTE *eisa_private; // ebx
  bool v7; // [esp+Ch] [ebp-Ch]
  objc_super v8; // [esp+10h] [ebp-8h] BYREF

  v3 = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, "EISA", 0); /*0x1c16c6*/
  v8.receiver = self; /*0x1c16d3*/
  v8.super_class = objc_getOrigClass("IODeviceDescription"); /*0x1c16e3*/
  -[IOEISADeviceDescription _initWithDelegate:](&v8, sel__initWithDelegate_, a3); /*0x1c16ea*/
  v4 = (void *)IOMalloc(0x1Cu); /*0x1c16f1*/
  self->_eisa_private = v4; /*0x1c16f6*/
  bzero(v4, 0x1Cu); /*0x1c16ff*/
  eisa_private = self->_eisa_private; /*0x1c1704*/
  v7 = 0; /*0x1c170a*/
  if ( v3 ) /*0x1c1710*/
    v7 = objc_msgSend(v3, aGeteisaslotnum_0, eisa_private + 20, eisa_private + 24, a3) == nullptr; /*0x1c172f*/
  eisa_private[16] = v7; /*0x1c1736*/
  return self; /*0x1c173e*/
}
