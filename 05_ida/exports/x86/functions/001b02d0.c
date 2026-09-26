/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b02d0. */
id __cdecl -[EventDriver initShmem](EventDriver *self, SEL a2)
{
  _DWORD *shmem_addr; // ecx
  unsigned int v3; // eax
  _BYTE *v4; // ebx
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  char *v9; // [esp+Ch] [ebp-Ch]
  unsigned __int64 v10; // [esp+10h] [ebp-8h] BYREF

  self->pointerLoc.x = 100; /*0x1b02dc*/
  self->pointerLoc.y = 100; /*0x1b02e5*/
  shmem_addr = (_DWORD *)self->shmem_addr; /*0x1b02ee*/
  *shmem_addr = 8; /*0x1b02f4*/
  shmem_addr[1] = *shmem_addr + 3600; /*0x1b0302*/
  v3 = self->shmem_addr; /*0x1b0305*/
  v4 = (_BYTE *)(*shmem_addr + v3); /*0x1b030d*/
  self->evs = (void *)(shmem_addr[1] + v3); /*0x1b0315*/
  v4[73] = 1; /*0x1b031b*/
  v4[74] = 1; /*0x1b031f*/
  *((_WORD *)v4 + 38) = 71; /*0x1b0323*/
  self->waitFrameRate = 75000000; /*0x1b0329*/
  self->waitSustain = 300000000; /*0x1b033d*/
  self->waitSusTime = 0; /*0x1b0351*/
  self->waitFrameTime = 0; /*0x1b0365*/
  self->lleqSize = 80; /*0x1b0379*/
  v5 = 79; /*0x1b0383*/
  v9 = v4 + 3476; /*0x1b038e*/
  v6 = 3476; /*0x1b0391*/
  do /*0x1b03ce*/
  {
    *(_DWORD *)&v4[v6 + 88] = 0; /*0x1b0398*/
    *(_DWORD *)&v4[v6 + 100] = 0; /*0x1b03a0*/
    *(_DWORD *)&v4[v6 + 104] = 0; /*0x1b03a8*/
    *((_DWORD *)v9 + 21) = 0; /*0x1b03b3*/
    *(_DWORD *)&v4[v6 + 80] = v5 + 1; /*0x1b03bd*/
    v9 -= 44; /*0x1b03c4*/
    v6 -= 44; /*0x1b03c7*/
    --v5; /*0x1b03ca*/
  }
  while ( v5 != -1 ); /*0x1b03ce*/
  *((_WORD *)v4 + 2) = 0; /*0x1b03d0*/
  *(_DWORD *)&v4[44 * self->lleqSize + 36] = 0; /*0x1b03e6*/
  *(_WORD *)v4 = *(_DWORD *)&v4[44 * *((__int16 *)v4 + 2) + 80]; /*0x1b0402*/
  *((_WORD *)v4 + 1) = *(_DWORD *)&v4[44 * *((__int16 *)v4 + 2) + 80]; /*0x1b0419*/
  *((_DWORD *)v4 + 2) = 0; /*0x1b041d*/
  *((_WORD *)v4 + 3) = 13; /*0x1b0424*/
  *((_DWORD *)v4 + 3) = 0; /*0x1b042a*/
  IOGetTimestamp((int *)&v10); /*0x1b0435*/
  v7 = v10 >> 24; /*0x1b0440*/
  if ( !v7 ) /*0x1b0449*/
    v7 = 1; /*0x1b044b*/
  *((_DWORD *)v4 + 4) = v7; /*0x1b0450*/
  *((_DWORD *)v4 + 6) = self->pointerLoc; /*0x1b0459*/
  v4[51] &= ~0x40u; /*0x1b0462*/
  v4[51] &= ~0x20u; /*0x1b046b*/
  v4[51] &= ~8u; /*0x1b0474*/
  v4[51] &= ~0x10u; /*0x1b047d*/
  v4[51] &= ~0x80u; /*0x1b0486*/
  *((_DWORD *)v4 + 13) = 0; /*0x1b0489*/
  *((_DWORD *)v4 + 5) = 0; /*0x1b0490*/
  *((_DWORD *)v4 + 16) = 0; /*0x1b0497*/
  self->evg = v4; /*0x1b049e*/
  self->eventsOpen = 1; /*0x1b04a4*/
  return self; /*0x1b04b0*/
}
