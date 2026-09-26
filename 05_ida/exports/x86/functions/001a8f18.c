/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8f18. */
id __cdecl -[NXConditionLock lockWhen:](NXConditionLock *self, SEL a2, int a3)
{
  volatile __int32 **priv; // ebx
  volatile __int32 *v4; // edx

  priv = (volatile __int32 **)self->_priv; /*0x1a8f24*/
  lock_write((int)priv[1]); /*0x1a8f2b*/
  while ( priv[2] != (volatile __int32 *)a3 ) /*0x1a8f36*/
  {
    v4 = *priv; /*0x1a8f38*/
    do /*0x1a8f4e*/
    {
      while ( *v4 ) /*0x1a8f3c*/
        ; /*0x1a8f3e*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1a8f4e*/
    lock_done((int)priv[1]); /*0x1a8f54*/
    thread_sleep((int)(priv + 2), *priv, 0); /*0x1a8f62*/
    lock_write((int)priv[1]); /*0x1a8f6b*/
  }
  return self; /*0x1a8f7d*/
}
