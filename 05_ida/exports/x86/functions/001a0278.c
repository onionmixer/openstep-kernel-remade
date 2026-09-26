/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0278. */
id __cdecl -[EventSrcPCPointer setPointerScaling:data:](
        EventSrcPCPointer *self,
        SEL a2,
        unsigned int a3,
        const unsigned int *a4)
{
  unsigned int v4; // esi
  unsigned int i; // eax
  const unsigned int *v7; // ebx

  v4 = a3; /*0x1a0281*/
  if ( a3 > 0x14 ) /*0x1a028a*/
    v4 = 20; /*0x1a028c*/
  objc_msgSend(self->deviceLock, sel_lock); /*0x1a029f*/
  self->pointerScaling.numScaleLevels = v4; /*0x1a02a4*/
  for ( i = 0; i < v4; ++i ) /*0x1a02b1*/
  {
    self->pointerScaling.scaleThresholds[i] = *(_WORD *)a4; /*0x1a02b7*/
    v7 = a4 + 1; /*0x1a02bf*/
    self->pointerScaling.scaleFactors[i] = *(_WORD *)v7; /*0x1a02c5*/
    a4 = v7 + 1; /*0x1a02cd*/
  }
  objc_msgSend(self->deviceLock, sel_unlock); /*0x1a02e3*/
  return self; /*0x1a02ed*/
}
