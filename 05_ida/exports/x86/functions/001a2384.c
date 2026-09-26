/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a2384. */
int __cdecl sub_1A2384(int a1, int a2)
{
  int *v2; // eax
  unsigned int v3; // edx
  signed int v4; // ecx
  int v5; // eax
  int *v6; // eax
  int v7; // ecx
  unsigned int v8; // edx
  int v9; // eax
  unsigned __int16 *v10; // ecx
  int v11; // edx
  int v13; // [esp+Ch] [ebp-20h]
  unsigned __int16 v14; // [esp+Ch] [ebp-20h]
  _DWORD *v15; // [esp+10h] [ebp-1Ch]
  int v16; // [esp+10h] [ebp-1Ch]
  int v17; // [esp+14h] [ebp-18h]
  int v18; // [esp+18h] [ebp-14h]
  unsigned int v19; // [esp+1Ch] [ebp-10h]
  _WORD v20[2]; // [esp+24h] [ebp-8h] BYREF
  __int16 v21; // [esp+28h] [ebp-4h]

  v2 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a2396*/
  v13 = 0; /*0x1a239c*/
  if ( v2 ) /*0x1a23a5*/
    v13 = *v2; /*0x1a23a9*/
  v3 = *(_DWORD *)(v13 + 132); /*0x1a23af*/
  if ( v3 > 7 ) /*0x1a23b8*/
    v15 = nullptr; /*0x1a23d0*/
  else
    v15 = (_DWORD *)(v13 + 132 * v3 + 136); /*0x1a23c8*/
  v4 = *(_DWORD *)(a2 + 48); /*0x1a23dd*/
  if ( (unsigned int)v4 > 0x1F ) /*0x1a23e3*/
    v5 = ((int)*(unsigned __int8 *)(v4 / 8 + v13 + 4) >> (v4 % 8)) & 1; /*0x1a2415*/
  else
    v5 = ((1 << v4) & *(_DWORD *)(v13 + 4)) != 0; /*0x1a23f5*/
  if ( v5 ) /*0x1a241a*/
  {
    v15[19] = *(_DWORD *)(a2 + 48); /*0x1a2422*/
    v15[20] = *(_DWORD *)(a2 + 52); /*0x1a2428*/
    v15[22] = 1; /*0x1a242b*/
    PCcallMonitor(a1, (__int16 *)a2); /*0x1a2437*/
  }
  v18 = *(_DWORD *)(a2 + 48); /*0x1a243f*/
  v6 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a2448*/
  v7 = 0; /*0x1a244e*/
  if ( v6 ) /*0x1a2452*/
    v7 = *v6; /*0x1a2454*/
  if ( v7 ) /*0x1a2458*/
  {
    v8 = *(_DWORD *)(v7 + 132); /*0x1a245a*/
    if ( v8 > 7 ) /*0x1a2463*/
      v9 = 0; /*0x1a2478*/
    else
      v9 = v7 + 132 * v8 + 136; /*0x1a246c*/
    v17 = v9; /*0x1a247a*/
  }
  else
  {
    v17 = 0; /*0x1a2480*/
  }
  v20[0] = *(_WORD *)(a2 + 56); /*0x1a248b*/
  v20[1] = *(_WORD *)(a2 + 60); /*0x1a2493*/
  v21 = *(_WORD *)(a2 + 64); /*0x1a249b*/
  if ( *(_DWORD *)(v17 + 104) ) /*0x1a24a2*/
    v21 |= 0x200u; /*0x1a24a8*/
  else
    v21 &= ~0x200u; /*0x1a24b0*/
  v21 |= *(_WORD *)(v17 + 112) & 0x7000; /*0x1a24c1*/
  v14 = *(_WORD *)(a2 + 68) - 6; /*0x1a24d1*/
  v10 = v20; /*0x1a24d5*/
  v11 = 6; /*0x1a24d8*/
  v16 = 16 * *(unsigned __int16 *)(a2 + 72); /*0x1a24e9*/
  *(_DWORD *)(a1 + 116) = &loc_1A2520; /*0x1a24ef*/
  do /*0x1a2512*/
  {
    __writefsword(v14 + v16, *v10++); /*0x1a2502*/
    v14 += 2; /*0x1a250a*/
    v11 -= 2; /*0x1a250f*/
  }
  while ( v11 ); /*0x1a2512*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a2517*/
  *(_DWORD *)(a1 + 116) = &loc_1A2548; /*0x1a2531*/
  v19 = __readfsdword(4 * v18); /*0x1a253b*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a253e*/
  *(_DWORD *)(a2 + 68) = (unsigned __int16)(*(_WORD *)(a2 + 68) - 6); /*0x1a2561*/
  *(_DWORD *)(a2 + 56) = (unsigned __int16)v19; /*0x1a2568*/
  *(_WORD *)(a2 + 60) = HIWORD(v19); /*0x1a256f*/
  *(_DWORD *)(v17 + 104) = 0; /*0x1a2576*/
  if ( (*(_BYTE *)(v17 + 128) & 1) == 0 ) /*0x1a2584*/
    *(_DWORD *)(a2 + 64) &= ~0x100u; /*0x1a2586*/
  return 1; /*0x1a259c*/
}
