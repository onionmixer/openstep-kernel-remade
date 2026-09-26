/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8dc4. */
id __cdecl -[NXSpinLock unlock](NXSpinLock *self, SEL a2)
{
  _InterlockedExchange(*(volatile __int32 **)self->_priv, 0); /*0x1a8dd1*/
  return self; /*0x1a8dd7*/
}
