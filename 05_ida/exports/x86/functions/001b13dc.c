/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b13dc. */
int __cdecl -[EventDriver evSetScreen:](EventDriver *self, SEL a2, unsigned int *a3)
{
  signed int v3; // esi
  unsigned int v5; // eax
  void *v6; // eax
  char *v7; // edx

  v3 = a3[1]; /*0x1b13e8*/
  if ( !self->evOpenCalled ) /*0x1b13eb*/
    return -705; /*0x1b13f4*/
  if ( !self->evScreen ) /*0x1b1400*/
  {
    v5 = 20 * *a3; /*0x1b140e*/
    self->evScreenSize = v5; /*0x1b1411*/
    v6 = (void *)IOMalloc(v5); /*0x1b1418*/
    self->evScreen = v6; /*0x1b141d*/
    bzero(v6, self->evScreenSize); /*0x1b142b*/
    self->shmem_size = 3608; /*0x1b1430*/
    self->lastShmemPtr = nullptr; /*0x1b143a*/
    self->screens = 0; /*0x1b1444*/
    self->workSpace.maxy = 0; /*0x1b144e*/
    self->workSpace.maxx = 0; /*0x1b1457*/
    self->workSpace.miny = 0; /*0x1b1460*/
    self->workSpace.minx = 0; /*0x1b1469*/
  }
  if ( v3 < 0 || v3 >= self->evScreenSize / 0x14 ) /*0x1b1487*/
    return -706; /*0x1b1489*/
  v7 = (char *)self->evScreen + 20 * v3; /*0x1b149d*/
  *((_WORD *)v7 + 6) = a3[3]; /*0x1b14a3*/
  *((_WORD *)v7 + 7) = a3[4]; /*0x1b14aa*/
  *((_WORD *)v7 + 8) = a3[5]; /*0x1b14b1*/
  *((_WORD *)v7 + 9) = a3[6]; /*0x1b14b8*/
  *((_DWORD *)v7 + 2) = a3[2]; /*0x1b14bf*/
  self->shmem_size += a3[2]; /*0x1b14c5*/
  if ( self->workSpace.minx > *((_WORD *)v7 + 6) ) /*0x1b14d6*/
    self->workSpace.minx = *((_WORD *)v7 + 6); /*0x1b14dc*/
  if ( self->workSpace.miny > *((_WORD *)v7 + 8) ) /*0x1b14ee*/
    self->workSpace.miny = *((_WORD *)v7 + 8); /*0x1b14f4*/
  if ( self->workSpace.maxx > *((_WORD *)v7 + 7) ) /*0x1b1506*/
    self->workSpace.maxx = *((_WORD *)v7 + 7); /*0x1b150c*/
  if ( self->workSpace.maxy > *((_WORD *)v7 + 9) ) /*0x1b151e*/
    self->workSpace.maxy = *((_WORD *)v7 + 9); /*0x1b1524*/
  return 0; /*0x1b1530*/
}
