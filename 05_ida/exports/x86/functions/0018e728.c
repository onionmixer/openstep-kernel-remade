/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e728. */
int __cdecl get_thread_state(int a1, _DWORD *a2, _DWORD *a3)
{
  int v4; // eax
  unsigned __int16 *v5; // eax
  int v6; // edx
  int v7; // eax

  if ( *a3 <= 0xFu ) /*0x18e737*/
    return 4; /*0x18e739*/
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112); /*0x18e74a*/
  if ( v4 ) /*0x18e74f*/
  {
    v5 = (unsigned __int16 *)(v4 + 132); /*0x18e751*/
  }
  else
  {
    v6 = kalloc(0xE0u); /*0x18e762*/
    *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112) = v6; /*0x18e767*/
    v5 = (unsigned __int16 *)(v6 + 132); /*0x18e76a*/
    qmemcpy((void *)(v6 + 132), &unk_1D15E0, 0x5Cu); /*0x18e77d*/
    *(_DWORD *)(v6 + 196) = 512; /*0x18e77f*/
    *(_WORD *)(v6 + 192) = 99; /*0x18e789*/
    *(_WORD *)(v6 + 204) = 107; /*0x18e792*/
    *(_WORD *)(v6 + 144) = 107; /*0x18e79b*/
    *(_WORD *)(v6 + 140) = 107; /*0x18e7a4*/
    *(_WORD *)(v6 + 136) = 0; /*0x18e7ad*/
    *(_WORD *)(v6 + 132) = 0; /*0x18e7b6*/
  }
  *a2 = *((_DWORD *)v5 + 11); /*0x18e7c2*/
  a2[1] = *((_DWORD *)v5 + 8); /*0x18e7c7*/
  a2[2] = *((_DWORD *)v5 + 10); /*0x18e7cd*/
  a2[3] = *((_DWORD *)v5 + 9); /*0x18e7d3*/
  a2[4] = *((_DWORD *)v5 + 4); /*0x18e7d9*/
  a2[5] = *((_DWORD *)v5 + 5); /*0x18e7df*/
  a2[6] = *((_DWORD *)v5 + 6); /*0x18e7e5*/
  a2[7] = *((_DWORD *)v5 + 17); /*0x18e7eb*/
  a2[8] = v5[36]; /*0x18e7f2*/
  a2[9] = *((_DWORD *)v5 + 16); /*0x18e7f8*/
  a2[10] = *((_DWORD *)v5 + 14); /*0x18e7fe*/
  a2[11] = v5[30]; /*0x18e805*/
  if ( (v5[33] & 2) != 0 ) /*0x18e80c*/
  {
    a2[12] = v5[40]; /*0x18e82c*/
    a2[13] = v5[38]; /*0x18e833*/
    a2[14] = v5[42]; /*0x18e83a*/
    v7 = v5[44]; /*0x18e83d*/
  }
  else
  {
    a2[12] = v5[6]; /*0x18e812*/
    a2[13] = v5[4]; /*0x18e819*/
    a2[14] = v5[2]; /*0x18e820*/
    v7 = *v5; /*0x18e823*/
  }
  a2[15] = v7; /*0x18e841*/
  *a3 = 16; /*0x18e847*/
  return 0; /*0x18e852*/
}
