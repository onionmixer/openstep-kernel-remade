/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x112614. */
int __cdecl ptcselect(unsigned __int8 a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v9; // edx

  v2 = 8 * a1; /*0x112620*/
  v3 = *(_DWORD *)&word_1E56C8[v2 + 4]; /*0x112628*/
  v4 = *(_DWORD *)&word_1E56C8[v2 + 6]; /*0x11262c*/
  v5 = *(_DWORD *)(v3 + 64); /*0x112630*/
  if ( (v5 & 0x10) == 0 ) /*0x112635*/
    return 1; /*0x112635*/
  if ( a2 == 1 ) /*0x11263e*/
  {
    v6 = spltty(); /*0x112658*/
    v7 = *(_DWORD *)(v3 + 64); /*0x11265d*/
    if ( (v7 & 4) != 0 && *(_DWORD *)(v3 + 24) && (v7 & 0x100) == 0 ) /*0x11266e*/
    {
      splx(v6); /*0x112671*/
      return 1; /*0x11267b*/
    }
    splx(v6); /*0x112681*/
    goto LABEL_13; /*0x112681*/
  }
  if ( a2 > 1 ) /*0x112640*/
  {
    if ( a2 != 2 ) /*0x11264f*/
      return 0; /*0x11264f*/
    if ( (v5 & 4) != 0 ) /*0x1126ba*/
    {
      if ( (*(_BYTE *)v4 & 0x20) != 0 ) /*0x1126bf*/
      {
        if ( !*(_DWORD *)(v3 + 12) ) /*0x1126c1*/
          return 1; /*0x1126c5*/
      }
      else
      {
        v9 = *(_DWORD *)(v3 + 12); /*0x1126d0*/
        if ( v9 + *(_DWORD *)v3 <= 1021 || !v9 && (*(_BYTE *)(v3 + 60) & 0x22) == 0 ) /*0x1126e6*/
          return 1; /*0x1126e6*/
      }
    }
    if ( selthreadcache((thread_act_t *)(v4 + 8)) ) /*0x1126ec*/
      *(_BYTE *)v4 |= 2u; /*0x1126f5*/
    return 0; /*0x1126f5*/
  }
  if ( !a2 ) /*0x112644*/
  {
LABEL_13:
    if ( (*(_BYTE *)(v3 + 64) & 4) == 0 /*0x11269f*/
      || ((*(_DWORD *)v4 & 8) == 0 || !*(_BYTE *)(v4 + 12)) && ((*(_DWORD *)v4 & 0x80u) == 0 || !*(_BYTE *)(v4 + 13)) )
    {
      if ( selthreadcache((thread_act_t *)(v4 + 4)) ) /*0x1126a9*/
        *(_BYTE *)v4 |= 1u; /*0x1126b2*/
      return 0; /*0x1126b5*/
    }
    return 1; /*0x1126cc*/
  }
  return 0; /*0x1126fd*/
}
