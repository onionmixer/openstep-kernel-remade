/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b123c. */
int __cdecl -[EventDriver registerScreen:bounds:shmem:size:](
        EventDriver *self,
        SEL a2,
        id a3,
        $5AA1BCF8DE96AA981A61391AFB670A9F *a4,
        void **a5,
        int *a6)
{
  int result; // eax
  char *v7; // edx

  if ( self->eventsOpen ) /*0x1b124b*/
  {
    if ( !self->lastShmemPtr ) /*0x1b1268*/
      self->lastShmemPtr = self->evs; /*0x1b1277*/
    v7 = (char *)self->evScreen + 20 * self->screens; /*0x1b128c*/
    *(_DWORD *)v7 = a3; /*0x1b1292*/
    if ( *((_DWORD *)v7 + 2) ) /*0x1b1294*/
      *((_DWORD *)v7 + 1) = self->lastShmemPtr; /*0x1b12a1*/
    self->lastShmemPtr = (char *)self->lastShmemPtr + *((_DWORD *)v7 + 2); /*0x1b12a7*/
    *a5 = *((void **)v7 + 1); /*0x1b12b0*/
    *a6 = *((_DWORD *)v7 + 2); /*0x1b12b5*/
    bcopy(v7 + 12, a4, 8u); /*0x1b12c1*/
    result = self->screens + 256; /*0x1b12cc*/
    ++self->screens; /*0x1b12d1*/
  }
  else
  {
    *a5 = nullptr; /*0x1b1254*/
    *a6 = 0; /*0x1b125a*/
    return -1; /*0x1b1260*/
  }
  return result; /*0x1b12da*/
}
