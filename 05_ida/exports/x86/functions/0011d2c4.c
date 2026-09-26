/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d2c4. */
int __cdecl getfakedirentries(int a1, _DWORD *a2)
{
  unsigned int v2; // esi
  unsigned int v3; // edx
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // edx
  unsigned __int16 v8; // cx
  __int16 v9; // ax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ebx
  int v15; // [esp+14h] [ebp-11Ch]
  unsigned int v16; // [esp+18h] [ebp-118h]
  int v17; // [esp+1Ch] [ebp-114h]
  int v18; // [esp+20h] [ebp-110h]
  unsigned int v19; // [esp+24h] [ebp-10Ch]

  if ( !*(_DWORD *)(a1 + 16) ) /*0x11d2d3*/
    return 0; /*0x11d2d3*/
  v16 = a2[5]; /*0x11d2e4*/
  v19 = -1024 - a2[2]; /*0x11d2f5*/
  if ( !v16 ) /*0x11d302*/
    return 0; /*0x11d302*/
  v2 = 0; /*0x11d308*/
  v15 = *(_DWORD *)(a1 + 16); /*0x11d30a*/
  if ( v19 ) /*0x11d316*/
  {
    while ( v15 ) /*0x11d327*/
    {
      v3 = (((unsigned __int16)strlen((const char *)(v15 + 32)) + 4) & 0xFFFFFFFC) + 8; /*0x11d365*/
      if ( v3 + (v2 & 0xFFFFFC00) <= 0x400 ) /*0x11d378*/
        v2 += v3; /*0x11d384*/
      else
        v2 = (v2 & 0xFFFFFC00) + 1024; /*0x11d37a*/
      v15 = *(_DWORD *)(v15 + 288); /*0x11d392*/
      if ( v19 <= v2 ) /*0x11d39e*/
        goto LABEL_9; /*0x11d39e*/
    }
    return 0; /*0x11d327*/
  }
LABEL_9:
  if ( !v15 ) /*0x11d3a7*/
    return 0; /*0x11d544*/
  v17 = a2[5]; /*0x11d3b3*/
  v18 = kalloc(v16); /*0x11d3bf*/
  v4 = v18; /*0x11d3c5*/
  v5 = 0; /*0x11d3cb*/
  while ( 1 ) /*0x11d3e0*/
  {
    *(_DWORD *)v4 = -1; /*0x11d3e0*/
    *(_WORD *)(v4 + 6) = strlen((const char *)(v15 + 32)); /*0x11d412*/
    strcpy((char *)(v4 + 8), (const char *)(v15 + 32)); /*0x11d41b*/
    v6 = *(_DWORD *)(v15 + 288); /*0x11d426*/
    v15 = v6; /*0x11d42c*/
    if ( !v6 ) /*0x11d437*/
      break; /*0x11d437*/
    v7 = (unsigned __int16)strlen((const char *)(v6 + 32)) + 4; /*0x11d469*/
    LOBYTE(v7) = v7 & 0xFC; /*0x11d46c*/
    v8 = *(_WORD *)(v4 + 6); /*0x11d473*/
    if ( ((v8 + 4) & 0xFFFFFFFC) + v5 + v7 + 16 <= 0x400 ) /*0x11d488*/
    {
      v9 = v8 + 4; /*0x11d49e*/
      LOBYTE(v9) = (v8 + 4) & 0xFC; /*0x11d4a2*/
      *(_WORD *)(v4 + 4) = v9 + 8; /*0x11d4a8*/
      v10 = *(unsigned __int16 *)(v4 + 6) + 4; /*0x11d4b0*/
      LOBYTE(v10) = v10 & 0xFC; /*0x11d4b3*/
      v5 += v10 + 8; /*0x11d4b5*/
    }
    else
    {
      *(_WORD *)(v4 + 4) = 1024 - v5; /*0x11d492*/
      v5 = 0; /*0x11d496*/
    }
    v11 = *(unsigned __int16 *)(v4 + 4); /*0x11d4b9*/
    v16 -= v11; /*0x11d4bd*/
    v19 += v11; /*0x11d4c3*/
    v4 += *(unsigned __int16 *)(v4 + 4); /*0x11d4f0*/
    if ( !v16 ) /*0x11d4f9*/
      goto LABEL_18; /*0x11d4f9*/
  }
  *(_WORD *)(v4 + 4) = 1024 - v5; /*0x11d4d4*/
  v12 = (unsigned __int16)(1024 - v5); /*0x11d4d8*/
  v16 -= v12; /*0x11d4dd*/
  v19 += v12; /*0x11d4e3*/
LABEL_18:
  v13 = uiomove(v18, a2[5] - v16, 0, a2); /*0x11d4ff*/
  kfree(v18, v17); /*0x11d525*/
  if ( !v13 ) /*0x11d52c*/
  {
    a2[2] = -(v19 + 1024); /*0x11d53f*/
    return 0; /*0x11d53f*/
  }
  return v13; /*0x11d550*/
}
