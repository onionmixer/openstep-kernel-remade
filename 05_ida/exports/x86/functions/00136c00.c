/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136c00. */
int __cdecl ku_recvfrom(int a1, _DWORD *a2)
{
  _WORD *v2; // ebx
  int v3; // edi
  int v4; // edx
  int v6; // eax
  int v7; // esi
  __int16 v8; // ax
  int v9; // edx
  __int16 v10; // ax
  int v11; // [esp+Ch] [ebp-4h]

  v2 = (_WORD *)(a1 + 36); /*0x136c0f*/
  v3 = 0; /*0x136c12*/
  v4 = *(_DWORD *)(a1 + 48); /*0x136c14*/
  if ( !v4 ) /*0x136c19*/
    return 0; /*0x136c1b*/
  v11 = *(_DWORD *)(v4 + 124); /*0x136c27*/
  v6 = *(_DWORD *)(v4 + 4); /*0x136c2a*/
  *a2 = *(_DWORD *)(v6 + v4); /*0x136c30*/
  a2[1] = *(_DWORD *)(v6 + v4 + 4); /*0x136c36*/
  a2[2] = *(_DWORD *)(v6 + v4 + 8); /*0x136c3d*/
  a2[3] = *(_DWORD *)(v6 + v4 + 12); /*0x136c44*/
  v7 = v4; /*0x136c47*/
  do /*0x136c83*/
  {
    if ( *(_WORD *)(v7 + 10) == 1 ) /*0x136c51*/
      break; /*0x136c51*/
    *v2 -= *(_WORD *)(v7 + 8); /*0x136c57*/
    v8 = *(_WORD *)(a1 + 40); /*0x136c5a*/
    *(_WORD *)(a1 + 40) = v8 - 128; /*0x136c64*/
    if ( *(_DWORD *)(v7 + 4) > 0x7Cu ) /*0x136c6c*/
      *(_WORD *)(a1 + 40) = v8 - 1152; /*0x136c72*/
    v7 = m_free(v7); /*0x136c7c*/
  }
  while ( v7 ); /*0x136c83*/
  if ( v7 )
  {
    v9 = v7; /*0x136ca0*/
    do /*0x136cd1*/
    {
      *v2 -= *(_WORD *)(v9 + 8); /*0x136ca8*/
      v10 = *(_WORD *)(a1 + 40); /*0x136cab*/
      *(_WORD *)(a1 + 40) = v10 - 128; /*0x136cb5*/
      if ( *(_DWORD *)(v9 + 4) > 0x7Cu ) /*0x136cbd*/
        *(_WORD *)(a1 + 40) = v10 - 1152; /*0x136cc3*/
      v3 += *(__int16 *)(v9 + 8); /*0x136ccb*/
      v9 = *(_DWORD *)v9; /*0x136ccd*/
    }
    while ( v9 ); /*0x136cd1*/
    *(_DWORD *)(a1 + 48) = v11; /*0x136cd6*/
    if ( v3 > 8800 )
      printf("ku_recvfrom: len = %d\n", v3);
    return v7; /*0x136cec*/
  }
  else
  {
    printf("ku_recvfrom: no body!\n");
    *(_DWORD *)(a1 + 48) = v11; /*0x136c96*/
    return 0; /*0x136c99*/
  }
}
