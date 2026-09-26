/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9080. */
id __cdecl -[NXLock lock](NXLock *self, SEL a2)
{
  lock_write(*(_DWORD *)self->_priv); /*0x1a908d*/
  return self; /*0x1a9094*/
}
