/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ea90. */
int __cdecl thread_dup(int a1, int a2)
{
  int v2; // eax
  const void *v3; // ebx
  int v4; // edx
  int v5; // edx
  _DWORD *v6; // edx
  int result; // eax

  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112); /*0x18ea9f*/
  if ( v2 ) /*0x18eaa4*/
  {
    v3 = (const void *)(v2 + 132); /*0x18eaa6*/
  }
  else
  {
    v4 = kalloc(0xE0u); /*0x18eaba*/
    *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112) = v4; /*0x18eabf*/
    qmemcpy((void *)(v4 + 132), &unk_1D15E0, 0x5Cu); /*0x18ead5*/
    *(_DWORD *)(v4 + 196) = 512; /*0x18ead7*/
    *(_WORD *)(v4 + 192) = 99; /*0x18eae1*/
    *(_WORD *)(v4 + 204) = 107; /*0x18eaea*/
    *(_WORD *)(v4 + 144) = 107; /*0x18eaf3*/
    *(_WORD *)(v4 + 140) = 107; /*0x18eafc*/
    *(_WORD *)(v4 + 136) = 0; /*0x18eb05*/
    *(_WORD *)(v4 + 132) = 0; /*0x18eb0e*/
    v3 = (const void *)(v4 + 132); /*0x18eb17*/
  }
  v5 = *(_DWORD *)(*(_DWORD *)(a2 + 40) + 112); /*0x18eb22*/
  if ( !v5 ) /*0x18eb27*/
  {
    v5 = kalloc(0xE0u); /*0x18eb33*/
    *(_DWORD *)(*(_DWORD *)(a2 + 40) + 112) = v5; /*0x18eb38*/
    qmemcpy((void *)(v5 + 132), &unk_1D15E0, 0x5Cu); /*0x18eb51*/
    *(_DWORD *)(v5 + 196) = 512; /*0x18eb53*/
    *(_WORD *)(v5 + 192) = 99; /*0x18eb5d*/
    *(_WORD *)(v5 + 204) = 107; /*0x18eb66*/
    *(_WORD *)(v5 + 144) = 107; /*0x18eb6f*/
    *(_WORD *)(v5 + 140) = 107; /*0x18eb78*/
    *(_WORD *)(v5 + 136) = 0; /*0x18eb81*/
    *(_WORD *)(v5 + 132) = 0; /*0x18eb8a*/
  }
  v6 = (_DWORD *)(v5 + 132); /*0x18eb93*/
  qmemcpy(v6, v3, 0x5Cu); /*0x18ebaa*/
  result = *(__int16 *)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 60) + 48); /*0x18ebb5*/
  v6[11] = result; /*0x18ebb9*/
  v6[9] = 1; /*0x18ebbc*/
  v6[16] &= ~1u; /*0x18ebc3*/
  return result; /*0x18ebca*/
}
