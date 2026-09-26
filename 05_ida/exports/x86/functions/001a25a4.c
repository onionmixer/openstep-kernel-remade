/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a25a4. */
int __cdecl PCemulateREAL(int a1, int a2)
{
  int v2; // eax
  unsigned __int16 v3; // si
  int v4; // ecx
  int (__cdecl *v5)(int, int, int, int); // eax
  int v6; // eax
  __int16 v8; // [esp+Ch] [ebp-1Ch]
  int v9; // [esp+10h] [ebp-18h]
  unsigned __int8 v10; // [esp+1Bh] [ebp-Dh]
  int v11; // [esp+1Ch] [ebp-Ch]

  v2 = *(_DWORD *)(a2 + 48); /*0x1a25b3*/
  if ( v2 != 13 ) /*0x1a25b9*/
  {
    if ( v2 != 6 ) /*0x1a268f*/
      return sub_1A2384(a1, a2); /*0x1a268f*/
    sub_1A1B60(a1, (__int16 *)a2); /*0x1a2696*/
    if ( !v6 ) /*0x1a26a0*/
      return sub_1A2384(a1, a2); /*0x1a26a0*/
    return 1; /*0x1a26a0*/
  }
  v11 = 0; /*0x1a25c9*/
  v9 = 0; /*0x1a25cc*/
  v3 = *(_WORD *)(a2 + 60); /*0x1a25d6*/
  v8 = *(_WORD *)(a2 + 56); /*0x1a25de*/
  v4 = 0; /*0x1a25e2*/
  while ( 1 ) /*0x1a25fc*/
  {
    *(_DWORD *)(a1 + 116) = &loc_1A2614; /*0x1a25fc*/
    v10 = __readfsbyte((unsigned __int16)(v4 + v8) + 16 * v3); /*0x1a2606*/
    *(_DWORD *)(a1 + 116) = 0; /*0x1a2609*/
    if ( v10 == 102 ) /*0x1a2629*/
    {
      LOBYTE(v11) = v11 | 1; /*0x1a2640*/
      goto LABEL_7; /*0x1a2640*/
    }
    if ( v10 != 240 ) /*0x1a2630*/
      break; /*0x1a2630*/
LABEL_7:
    if ( ++v4 > 14 ) /*0x1a2648*/
      goto LABEL_12; /*0x1a2648*/
  }
  v5 = (int (__cdecl *)(int, int, int, int))dword_1E4B80[(unsigned __int8)(v10 + 112)]; /*0x1a2650*/
  if ( v5 ) /*0x1a2659*/
  {
    if ( v5(a1, a2, v4, v11) ) /*0x1a2668*/
      v9 = 1; /*0x1a2671*/
  }
LABEL_12:
  if ( v9 ) /*0x1a267c*/
    return 1; /*0x1a26b1*/
  return sub_1A2384(a1, a2); /*0x1a26c1*/
}
