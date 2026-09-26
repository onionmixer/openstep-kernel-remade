/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1280c4. */
int __cdecl ip_getmoptions(int a1, int a2, int **a3)
{
  int *v3; // edx
  int *v4; // eax
  _DWORD *v5; // ecx
  int v6; // edx
  _DWORD *v7; // eax
  int *v8; // eax
  _BYTE *v9; // ecx
  int *v10; // eax

  *a3 = m_get(1, 14); /*0x1280dc*/
  if ( a2 ) /*0x1280e0*/
    v3 = (int *)(*(_DWORD *)(a2 + 4) + a2); /*0x1280e4*/
  else
    v3 = nullptr; /*0x1280ec*/
  if ( a1 == 4 ) /*0x1280f1*/
  {
    v8 = *a3; /*0x128148*/
    v9 = (char *)v8 + v8[1]; /*0x12814c*/
    *((_WORD *)v8 + 4) = 1; /*0x12814f*/
    if ( v3 ) /*0x128157*/
    {
      *v9 = *((_BYTE *)v3 + 4); /*0x12815c*/
      return 0; /*0x12817d*/
    }
LABEL_22:
    *v9 = 1; /*0x128178*/
    return 0; /*0x128178*/
  }
  if ( a1 > 4 ) /*0x1280f3*/
  {
    if ( a1 != 5 ) /*0x128103*/
      return 45; /*0x128103*/
    v10 = *a3; /*0x128160*/
    v9 = (char *)v10 + v10[1]; /*0x128164*/
    *((_WORD *)v10 + 4) = 1; /*0x128167*/
    if ( v3 ) /*0x12816f*/
    {
      *v9 = *((_BYTE *)v3 + 5); /*0x128174*/
      return 0; /*0x128176*/
    }
    goto LABEL_22; /*0x12816f*/
  }
  if ( a1 == 3 ) /*0x1280f8*/
  {
    v4 = *a3; /*0x128108*/
    v5 = (int *)((char *)v4 + v4[1]); /*0x12810c*/
    *((_WORD *)v4 + 4) = 4; /*0x12810f*/
    if ( !v3 ) /*0x128117*/
      goto LABEL_17; /*0x128117*/
    v6 = *v3; /*0x128119*/
    if ( !v6 ) /*0x12811d*/
      goto LABEL_17; /*0x12811d*/
    v7 = (_DWORD *)in_ifaddr; /*0x12811f*/
    if ( !in_ifaddr ) /*0x128126*/
      goto LABEL_17; /*0x128126*/
    do /*0x128132*/
    {
      if ( v7[8] == v6 ) /*0x12812b*/
        break; /*0x12812b*/
      v7 = (_DWORD *)v7[16]; /*0x12812d*/
    }
    while ( v7 ); /*0x128132*/
    if ( v7 ) /*0x128136*/
      *v5 = v7[1]; /*0x12813b*/
    else
LABEL_17:
      *v5 = 0; /*0x128140*/
    return 0; /*0x12813d*/
  }
  return 45; /*0x128188*/
}
