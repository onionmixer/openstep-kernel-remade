/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c2084. */
id __cdecl -[IOPCMCIADeviceDescription _initWithDelegate:](IOPCMCIADeviceDescription *self, SEL a2, id a3)
{
  _DWORD *v3; // eax
  objc_super v5; // [esp+4h] [ebp-8h] BYREF

  v5.receiver = self; /*0x1c2099*/
  v5.super_class = objc_getOrigClass("IOEISADeviceDescription"); /*0x1c20a9*/
  -[IOPCMCIADeviceDescription _initWithDelegate:](&v5, sel__initWithDelegate_, a3); /*0x1c20b0*/
  v3 = (_DWORD *)IOMalloc(8u); /*0x1c20b7*/
  self->_pcmcia_private = v3; /*0x1c20bc*/
  *v3 = 0; /*0x1c20bf*/
  v3[1] = 0; /*0x1c20c5*/
  return self; /*0x1c20ce*/
}
