/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6154. */
id __cdecl -[IOLogicalDisk free](IOLogicalDisk *self, SEL a2)
{
  id v2; // eax
  objc_super v4; // [esp+4h] [ebp-8h] BYREF

  v2 = -[IODisk nextLogicalDisk](self, sel_nextLogicalDisk); /*0x1a6166*/
  if ( v2 ) /*0x1a6170*/
    objc_msgSend(v2, sel_free); /*0x1a617a*/
  v4.receiver = self; /*0x1a6189*/
  v4.super_class = (Class)stru_1FA104.ext; /*0x1a6192*/
  return -[IODevice free](&v4, sel_free); /*0x1a619e*/
}
