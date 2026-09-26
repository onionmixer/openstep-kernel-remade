/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8ed0. */
id __cdecl -[NXConditionLock lock](NXConditionLock *self, SEL a2)
{
  lock_write(*((_DWORD *)self->_priv + 1)); /*0x1a8ede*/
  return self; /*0x1a8ee5*/
}
