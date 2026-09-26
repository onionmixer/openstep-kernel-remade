/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8d9c. */
id __cdecl -[NXSpinLock lock](NXSpinLock *self, SEL a2)
{
  volatile __int32 *v2; // edx

  v2 = *(volatile __int32 **)self->_priv; /*0x1a8da5*/
  do /*0x1a8dba*/
  {
    while ( *v2 ) /*0x1a8da8*/
      ; /*0x1a8daa*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x1a8dba*/
  return self; /*0x1a8dc0*/
}
