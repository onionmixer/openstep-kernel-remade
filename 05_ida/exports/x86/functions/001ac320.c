/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac320. */
void __cdecl -[IODisk registerUnixDisk:](IODisk *self, SEL a2, int a3)
{
  const char *v3; // eax

  if ( a3 <= 6 )
  {
    if ( self->_isPhysical ) /*0x1ac350*/
      *(_DWORD *)self->_devAndIdInfo = self; /*0x1ac35f*/
    else
      *((_DWORD *)self->_devAndIdInfo + a3 + 1) = self; /*0x1ac36a*/
  }
  else
  {
    v3 = -[IODevice name](self, sel_name); /*0x1ac338*/
    IOLog((int)"%s registerUnixDisk: Bogus partition (%d)\n", v3, a3);
  }
}
