/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181500. */
char __cdecl -[KernDeviceDescription removeStringForKey:](KernDeviceDescription *self, SEL a2, const char *a3)
{
  const char *v3; // edx

  v3 = (const char *)objc_msgSend(self->_stringTable, sel_removeKey_, a3); /*0x18151c*/
  if ( !v3 ) /*0x181523*/
    return 0; /*0x181525*/
  IOFree((int)v3, strlen(v3) + 1); /*0x18153e*/
  return 1; /*0x18154b*/
}
