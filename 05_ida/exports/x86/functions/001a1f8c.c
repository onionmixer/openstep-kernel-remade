/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1f8c. */
int __cdecl sub_1A1F8C(int a1, int a2)
{
  int *v2; // eax
  int v3; // ecx
  unsigned int v4; // edx
  int v5; // eax
  int v6; // esi
  int *v7; // ecx
  int v8; // edx
  int v10; // [esp+Ch] [ebp-18h]
  unsigned __int16 v11; // [esp+10h] [ebp-14h]
  int v12; // [esp+18h] [ebp-Ch] BYREF
  __int16 v13; // [esp+1Ch] [ebp-8h]
  int v14; // [esp+20h] [ebp-4h]

  v2 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a1f9b*/
  v3 = 0; /*0x1a1fa1*/
  if ( v2 ) /*0x1a1fa5*/
    v3 = *v2; /*0x1a1fa7*/
  if ( v3 ) /*0x1a1fab*/
  {
    v4 = *(_DWORD *)(v3 + 132); /*0x1a1fad*/
    if ( v4 > 7 ) /*0x1a1fb6*/
      v5 = 0; /*0x1a1fc8*/
    else
      v5 = v3 + 132 * v4 + 136; /*0x1a1fbf*/
    v6 = v5; /*0x1a1fca*/
  }
  else
  {
    v6 = 0; /*0x1a1fd0*/
  }
  v11 = *(_WORD *)(a2 + 68); /*0x1a1fdd*/
  v7 = &v12; /*0x1a1fe1*/
  v8 = 12; /*0x1a1fe4*/
  v10 = 16 * *(unsigned __int16 *)(a2 + 72); /*0x1a1ff5*/
  *(_DWORD *)(a1 + 116) = &loc_1A202C; /*0x1a1ffb*/
  do /*0x1a201e*/
  {
    *(_WORD *)v7 = __readfsword(v11 + v10); /*0x1a2010*/
    v7 = (int *)((char *)v7 + 2); /*0x1a2013*/
    v11 += 2; /*0x1a2016*/
    v8 -= 2; /*0x1a201b*/
  }
  while ( v8 ); /*0x1a201e*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a2023*/
  *(_DWORD *)(a2 + 56) = v12; /*0x1a2046*/
  *(_WORD *)(a2 + 60) = v13; /*0x1a204d*/
  if ( (*(_BYTE *)(v6 + 128) & 1) != 0 ) /*0x1a2058*/
    v14 |= *(_DWORD *)(a2 + 64) & 0x100; /*0x1a2062*/
  *(_DWORD *)(a2 + 64) = v14; /*0x1a206b*/
  *(_DWORD *)(a2 + 64) = *(_DWORD *)(a2 + 64) & 0x50DD5 | 0x20202; /*0x1a207b*/
  *(_DWORD *)(a2 + 68) = (unsigned __int16)(*(_WORD *)(a2 + 68) + 12); /*0x1a208b*/
  *(_WORD *)(v6 + 112) = v14 & 0x7000; /*0x1a2097*/
  if ( (v14 & 0x200) != 0 ) /*0x1a209f*/
  {
    if ( !*(_DWORD *)(v6 + 104) ) /*0x1a20a1*/
      *(_DWORD *)(v6 + 116) |= *(_DWORD *)(v6 + 92) & 1; /*0x1a20ad*/
    *(_DWORD *)(v6 + 104) = 1; /*0x1a20b0*/
  }
  else
  {
    *(_DWORD *)(v6 + 104) = 0; /*0x1a20bc*/
  }
  return 1; /*0x1a20cb*/
}
