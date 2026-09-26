/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11325c. */
unsigned int __cdecl b_to_q(char *a1, signed __int32 a2, int *a3)
{
  unsigned int v3; // edi
  int v5; // esi
  _DWORD *v6; // ebx
  int *v7; // eax
  int *v8; // ebx
  size_t v9; // ebx
  int v10; // [esp+10h] [ebp-4h]

  v3 = a2; /*0x113265*/
  if ( a2 <= 0 ) /*0x11326a*/
    return 0; /*0x11326c*/
  v10 = spltty(); /*0x11327c*/
  v5 = a3[2]; /*0x113282*/
  if ( v5 && *a3 >= 0 ) /*0x11328c*/
  {
LABEL_13:
    while ( v3 ) /*0x113339*/
    {
      if ( (v5 & 0x3F) == 0 ) /*0x1132d6*/
      {
        v7 = (int *)cfreelist; /*0x1132d8*/
        *(_DWORD *)(v5 - 64) = cfreelist; /*0x1132dd*/
        if ( !v7 ) /*0x1132e2*/
          break; /*0x1132e2*/
        v8 = v7; /*0x1132e4*/
        cfreelist = *v7; /*0x1132e8*/
        cfreecount -= 52; /*0x1132ee*/
        bzero(v7 + 1, 8u); /*0x1132fb*/
        *v8 = 0; /*0x113300*/
        v5 = (int)(v8 + 3); /*0x113306*/
      }
      v9 = v3; /*0x11331a*/
      if ( v3 >= 64 - (v5 & 0x3Fu) ) /*0x11331e*/
        v9 = 64 - (v5 & 0x3F); /*0x113320*/
      bcopy(a1, (void *)v5, v9); /*0x113328*/
      a1 += v9; /*0x11332d*/
      v5 += v9; /*0x113330*/
      v3 -= v9; /*0x113332*/
    }
  }
  else
  {
    v6 = (_DWORD *)cfreelist; /*0x113292*/
    if ( cfreelist ) /*0x11329a*/
    {
      cfreelist = *(_DWORD *)cfreelist; /*0x1132a2*/
      cfreecount -= 52; /*0x1132a8*/
      bzero(v6 + 1, 8u); /*0x1132b5*/
      *v6 = 0; /*0x1132ba*/
      v5 = (int)(v6 + 3); /*0x1132c0*/
      a3[1] = (int)(v6 + 3); /*0x1132c6*/
      goto LABEL_13; /*0x1132cc*/
    }
  }
  a3[2] = v5; /*0x11333b*/
  *a3 += a2 - v3; /*0x113346*/
  splx(v10); /*0x11334c*/
  return v3; /*0x113356*/
}
