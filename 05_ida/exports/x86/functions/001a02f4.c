/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a02f4. */
id __cdecl -[EventSrcPCPointer pointerScaling:data:](
        EventSrcPCPointer *self,
        SEL a2,
        unsigned int *a3,
        unsigned int *a4)
{
  unsigned int numScaleLevels; // eax
  unsigned int i; // eax
  unsigned int *v7; // ebx

  objc_msgSend(self->deviceLock, sel_lock); /*0x1a0311*/
  numScaleLevels = self->pointerScaling.numScaleLevels; /*0x1a0316*/
  if ( *a3 > numScaleLevels ) /*0x1a0321*/
    *a3 = numScaleLevels; /*0x1a0323*/
  for ( i = 0; *a3 > i; ++i ) /*0x1a0327*/
  {
    *a4 = self->pointerScaling.scaleThresholds[i]; /*0x1a0334*/
    v7 = a4 + 1; /*0x1a0336*/
    *v7 = self->pointerScaling.scaleFactors[i]; /*0x1a0341*/
    a4 = v7 + 1; /*0x1a0343*/
  }
  objc_msgSend(self->deviceLock, sel_unlock); /*0x1a0359*/
  return self; /*0x1a0363*/
}
