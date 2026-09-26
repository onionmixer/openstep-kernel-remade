/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1170fc. */
int __cdecl connect(int a1, const sockaddr *a2, socklen_t a3)
{
  _DWORD *v3; // ebx
  int result; // eax
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x117108*/
  result = getsock(*v3); /*0x11710e*/
  if ( result ) /*0x117118*/
  {
    v5 = *(_DWORD *)(result + 24); /*0x117121*/
    if ( (*(_WORD *)(v5 + 6) & 0x104) == 0x104 ) /*0x117133*/
    {
      result = dword_1E875C; /*0x117135*/
      *(_BYTE *)(dword_1E875C + 104) = 37; /*0x11713a*/
      return result; /*0x11713e*/
    }
    *(_BYTE *)(dword_1E875C + 104) = sockargs(&v7, v3[1], v3[2], 8); /*0x11715e*/
    result = dword_1E875C; /*0x117161*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117169*/
    {
      *(_BYTE *)(dword_1E875C + 104) = soconnect(v5, v7); /*0x117187*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117193*/
      {
        if ( (*(_WORD *)(v5 + 6) & 0x104) == 0x104 ) /*0x1171ac*/
        {
          *(_BYTE *)(dword_1E875C + 104) = 36; /*0x1171ae*/
LABEL_18:
          m_freem(v7); /*0x117245*/
          return result; /*0x117249*/
        }
        v6 = splnet(); /*0x1171bd*/
        if ( setjmp((int *)(dword_1E875C + 40)) ) /*0x1171c9*/
        {
          if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x1171da*/
            *(_BYTE *)(dword_1E875C + 104) = 4; /*0x1171e0*/
        }
        else
        {
          while ( (*(_BYTE *)(v5 + 6) & 4) != 0 && !*(_WORD *)(v5 + 86) ) /*0x1171f1*/
            sleep(v5 + 84); /*0x117203*/
          *(_BYTE *)(dword_1E875C + 104) = *(_BYTE *)(v5 + 86); /*0x117226*/
          *(_WORD *)(v5 + 86) = 0; /*0x11722c*/
        }
        splx(v6); /*0x117236*/
      }
      *(_BYTE *)(v5 + 6) &= ~4u; /*0x117241*/
      goto LABEL_18; /*0x117241*/
    }
  }
  return result; /*0x11724e*/
}
