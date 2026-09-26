/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8eec. */
id __cdecl -[NXConditionLock unlock](NXConditionLock *self, SEL a2)
{
  _DWORD *priv; // ebx

  priv = self->_priv; /*0x1a8ef4*/
  thread_wakeup_prim((int)(priv + 2), 1, 0); /*0x1a8eff*/
  lock_done(priv[1]); /*0x1a8f08*/
  return self; /*0x1a8f12*/
}
