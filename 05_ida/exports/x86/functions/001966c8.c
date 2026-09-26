/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1966c8. */
int __cdecl -[kmDevice kmGetc](kmDevice *self, SEL a2)
{
  $06E236A3989EA52BCBC585244E9C0693 *p_inBufLock; // edx
  $06E236A3989EA52BCBC585244E9C0693 *v3; // ebx
  int outDex; // eax
  int v5; // edx
  int v6; // eax

  p_inBufLock = &self->inBufLock; /*0x1966d0*/
  do /*0x1966ea*/
  {
    while ( p_inBufLock->locked ) /*0x1966d8*/
      ; /*0x1966da*/
  }
  while ( _InterlockedExchange((volatile __int32 *)p_inBufLock, 1) == 1 ); /*0x1966ea*/
  *((_BYTE *)self + 292) |= 1u; /*0x1966ec*/
  if ( self->inDex == self->outDex ) /*0x1966ff*/
  {
    v3 = &self->inBufLock; /*0x196701*/
    do /*0x19673c*/
    {
      thread_sleep((int)self->inBuf, (volatile __int32 *)&self->inBufLock, 1); /*0x196712*/
      do /*0x19672e*/
      {
        while ( v3->locked ) /*0x19671c*/
          ; /*0x19671e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x19672e*/
    }
    while ( self->inDex == self->outDex ); /*0x19673c*/
  }
  outDex = self->outDex; /*0x19673e*/
  v5 = self->inBuf[outDex]; /*0x196744*/
  v6 = outDex + 1; /*0x19674b*/
  if ( v6 == 16 ) /*0x19674f*/
    v6 = 0; /*0x196751*/
  self->outDex = v6; /*0x196753*/
  *((_BYTE *)self + 292) &= ~1u; /*0x196759*/
  _InterlockedExchange((volatile __int32 *)&self->inBufLock, 0); /*0x196762*/
  return v5; /*0x19676d*/
}
