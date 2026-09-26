/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8f84. */
id __cdecl -[NXConditionLock unlockWith:](NXConditionLock *self, SEL a2, int a3)
{
  void *priv; // ebx
  volatile __int32 *v4; // edx

  priv = self->_priv; /*0x1a8f8c*/
  v4 = *(volatile __int32 **)priv; /*0x1a8f8f*/
  do /*0x1a8fa6*/
  {
    while ( *v4 ) /*0x1a8f94*/
      ; /*0x1a8f96*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1a8fa6*/
  *((_DWORD *)priv + 2) = a3; /*0x1a8fab*/
  _InterlockedExchange(*(volatile __int32 **)priv, 0); /*0x1a8fb2*/
  thread_wakeup_prim((int)priv + 8, 1, 0); /*0x1a8fbc*/
  lock_done(*((_DWORD *)priv + 1)); /*0x1a8fc5*/
  return self; /*0x1a8fcf*/
}
