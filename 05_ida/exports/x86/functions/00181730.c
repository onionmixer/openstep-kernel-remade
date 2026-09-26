/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181730. */
char __cdecl -[KernDeviceDescription _isShared:](KernDeviceDescription *self, SEL a2, const char *a3)
{
  const char *v3; // eax
  char v4; // al
  char result; // al
  char v6[128]; // [esp+8h] [ebp-80h] BYREF

  sprintf(v6, "Share %s", a3); /*0x18174b*/
  v3 = -[KernDeviceDescription stringForKey:](self, sel_stringForKey_, v6); /*0x181759*/
  result = false; /*0x18176c*/
  if ( v3 ) /*0x181760*/
  {
    v4 = *v3; /*0x181762*/
    if ( v4 == 121 || v4 == 89 ) /*0x18176a*/
      return true; /*0x181760*/
  }
  return result; /*0x18177c*/
}
