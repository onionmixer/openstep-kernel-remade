/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a909c. */
id __cdecl -[NXLock unlock](NXLock *self, SEL a2)
{
  lock_done(*(_DWORD *)self->_priv); /*0x1a90a9*/
  return self; /*0x1a90b0*/
}
