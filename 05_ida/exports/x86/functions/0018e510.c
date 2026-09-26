/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e510. */
int __cdecl sub_18E510(int a1, int a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // edx
  int v5; // ecx
  int result; // eax

  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112); /*0x18e51f*/
  if ( v2 ) /*0x18e524*/
  {
    v3 = v2 + 132; /*0x18e526*/
  }
  else
  {
    v4 = kalloc(0xE0u); /*0x18e53a*/
    *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112) = v4; /*0x18e53f*/
    qmemcpy((void *)(v4 + 132), &unk_1D15E0, 0x5Cu); /*0x18e555*/
    *(_DWORD *)(v4 + 196) = 512; /*0x18e557*/
    *(_WORD *)(v4 + 192) = 99; /*0x18e561*/
    *(_WORD *)(v4 + 204) = 107; /*0x18e56a*/
    *(_WORD *)(v4 + 144) = 107; /*0x18e573*/
    *(_WORD *)(v4 + 140) = 107; /*0x18e57c*/
    *(_WORD *)(v4 + 136) = 0; /*0x18e585*/
    *(_WORD *)(v4 + 132) = 0; /*0x18e58e*/
    v3 = v4 + 132; /*0x18e597*/
  }
  *(_DWORD *)(v3 + 44) = *(_DWORD *)a2; /*0x18e59b*/
  *(_DWORD *)(v3 + 32) = *(_DWORD *)(a2 + 4); /*0x18e5a1*/
  *(_DWORD *)(v3 + 40) = *(_DWORD *)(a2 + 8); /*0x18e5a7*/
  *(_DWORD *)(v3 + 36) = *(_DWORD *)(a2 + 12); /*0x18e5ad*/
  *(_DWORD *)(v3 + 16) = *(_DWORD *)(a2 + 16); /*0x18e5b3*/
  *(_DWORD *)(v3 + 20) = *(_DWORD *)(a2 + 20); /*0x18e5b9*/
  *(_DWORD *)(v3 + 24) = *(_DWORD *)(a2 + 24); /*0x18e5bf*/
  *(_DWORD *)(v3 + 68) = *(_DWORD *)(a2 + 28); /*0x18e5c5*/
  *(_WORD *)(v3 + 72) = *(_WORD *)(a2 + 32); /*0x18e5cc*/
  v5 = *(_DWORD *)(a2 + 36); /*0x18e5d0*/
  *(_DWORD *)(v3 + 64) = v5; /*0x18e5d3*/
  result = v5 & 0x50DD5 | 0x20202; /*0x18e5dd*/
  *(_DWORD *)(v3 + 64) = result; /*0x18e5e2*/
  *(_DWORD *)(v3 + 56) = *(_DWORD *)(a2 + 40); /*0x18e5e8*/
  *(_WORD *)(v3 + 60) = *(_WORD *)(a2 + 44); /*0x18e5ef*/
  *(_WORD *)(v3 + 12) = 0; /*0x18e5f3*/
  *(_WORD *)(v3 + 8) = 0; /*0x18e5f9*/
  *(_WORD *)(v3 + 4) = 0; /*0x18e5ff*/
  *(_WORD *)v3 = 0; /*0x18e605*/
  *(_WORD *)(v3 + 80) = *(_WORD *)(a2 + 48); /*0x18e60e*/
  *(_WORD *)(v3 + 76) = *(_WORD *)(a2 + 52); /*0x18e616*/
  *(_WORD *)(v3 + 84) = *(_WORD *)(a2 + 56); /*0x18e61e*/
  *(_WORD *)(v3 + 88) = *(_WORD *)(a2 + 60); /*0x18e626*/
  return result; /*0x18e62d*/
}
