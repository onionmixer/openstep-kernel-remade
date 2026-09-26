/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1813e0. */
id __cdecl -[KernDeviceDescription setString:forKey:](
        KernDeviceDescription *self,
        SEL a2,
        const char *a3,
        const char *a4)
{
  char *v4; // eax
  char *v5; // eax
  const char *v6; // eax

  v4 = (char *)IOMalloc(strlen(a3) + 1); /*0x181403*/
  v5 = strcpy(v4, a3); /*0x18140e*/
  v6 = (const char *)objc_msgSend(self->_stringTable, sel_insertKey_value_, a4, v5); /*0x181424*/
  if ( v6 ) /*0x181430*/
    IOFree((int)v6, strlen(v6) + 1); /*0x181445*/
  return self; /*0x18144f*/
}
