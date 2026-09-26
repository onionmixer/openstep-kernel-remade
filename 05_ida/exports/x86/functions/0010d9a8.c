/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d9a8. */
int __cdecl soo_select(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v7; // eax

  v2 = *(_DWORD *)(a1 + 24); /*0x10d9b4*/
  v3 = splnet(); /*0x10d9b7*/
  v4 = v3; /*0x10d9bc*/
  if ( a2 == 1 ) /*0x10d9c1*/
  {
    if ( *(_WORD *)(v2 + 36) || (*(_BYTE *)(v2 + 6) & 0x20) != 0 || *(_WORD *)(v2 + 32) || *(_WORD *)(v2 + 86) ) /*0x10d9f4*/
      goto LABEL_23; /*0x10d9f9*/
  }
  else
  {
    if ( a2 > 1 ) /*0x10d9c3*/
    {
      if ( a2 != 2 ) /*0x10d9d7*/
        goto LABEL_26; /*0x10d9d7*/
      v5 = *(unsigned __int16 *)(v2 + 62) - *(unsigned __int16 *)(v2 + 60); /*0x10da26*/
      if ( v5 > *(unsigned __int16 *)(v2 + 66) - *(unsigned __int16 *)(v2 + 64) ) /*0x10da2a*/
        v5 = *(unsigned __int16 *)(v2 + 66) - *(unsigned __int16 *)(v2 + 64); /*0x10da2c*/
      if ( v5 > 0 && ((*(_BYTE *)(v2 + 6) & 2) != 0 || (*(_BYTE *)(*(_DWORD *)(v2 + 12) + 10) & 4) == 0) /*0x10da47*/
        || (*(_BYTE *)(v2 + 6) & 0x10) != 0
        || *(_WORD *)(v2 + 86) )
      {
        splx(v4); /*0x10da4f*/
        return 1; /*0x10da59*/
      }
      v7 = v2 + 60; /*0x10da5c*/
      goto LABEL_25; /*0x10da5f*/
    }
    if ( a2 ) /*0x10d9c7*/
      goto LABEL_26; /*0x10d9c7*/
    if ( *(_WORD *)(v2 + 88) || (*(_BYTE *)(v2 + 6) & 0x40) != 0 ) /*0x10da6f*/
    {
LABEL_23:
      splx(v3); /*0x10da71*/
      return 1; /*0x10da7c*/
    }
  }
  v7 = v2 + 36; /*0x10da80*/
LABEL_25:
  sbselqueue(v7); /*0x10da83*/
LABEL_26:
  splx(v4); /*0x10da8c*/
  return 0; /*0x10da97*/
}
