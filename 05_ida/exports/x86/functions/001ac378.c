/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac378. */
void __cdecl -[IODisk unregisterUnixDisk:](IODisk *self, SEL a2, int a3)
{
  const char *v3; // eax

  if ( a3 <= 6 )
  {
    if ( self->_isPhysical ) /*0x1ac3a8*/
      *(_DWORD *)self->_devAndIdInfo = 0; /*0x1ac3b7*/
    else
      *((_DWORD *)self->_devAndIdInfo + a3 + 1) = 0; /*0x1ac3ca*/
  }
  else
  {
    v3 = -[IODevice name](self, sel_name); /*0x1ac38f*/
    IOLog((int)"%s unregisterUnixDisk: Bogus partition (%d)\n", v3, a3);
  }
}
