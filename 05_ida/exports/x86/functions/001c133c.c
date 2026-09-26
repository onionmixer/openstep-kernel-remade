/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c133c. */
id __cdecl -[IOEISADeviceDescription free](IOEISADeviceDescription *self, SEL a2)
{
  int *eisa_private; // ebx
  int v3; // eax
  int v4; // eax
  objc_super v6; // [esp+8h] [ebp-8h] BYREF

  eisa_private = (int *)self->_eisa_private; /*0x1c1347*/
  v3 = eisa_private[1]; /*0x1c134a*/
  if ( v3 ) /*0x1c134f*/
    IOFree(*eisa_private, 4 * v3); /*0x1c1358*/
  v4 = eisa_private[3]; /*0x1c1360*/
  if ( v4 ) /*0x1c1365*/
    IOFree(eisa_private[2], 8 * v4); /*0x1c136f*/
  IOFree((int)eisa_private, 28); /*0x1c137a*/
  v6.receiver = self; /*0x1c1386*/
  v6.super_class = (Class)stru_1FA564.super_class; /*0x1c138f*/
  return -[IODeviceDescription free](&v6, sel_free); /*0x1c139e*/
}
