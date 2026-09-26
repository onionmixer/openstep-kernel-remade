/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c22d0. */
id __cdecl -[IOPCMCIATuple free](IOPCMCIATuple *self, SEL a2)
{
  _DWORD *v2; // ebx
  int v3; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  v2 = self->_private; /*0x1c22db*/
  v3 = v2[3]; /*0x1c22de*/
  if ( v3 ) /*0x1c22e3*/
    IOFree(v3, v2[2]); /*0x1c22ea*/
  IOFree((int)v2, 16); /*0x1c22f5*/
  v5.receiver = self; /*0x1c2301*/
  v5.super_class = (Class)stru_1FA5B4.ext; /*0x1c230a*/
  return -[Object free](&v5, sel_free); /*0x1c2319*/
}
