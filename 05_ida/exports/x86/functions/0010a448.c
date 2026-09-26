/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a448. */
int __cdecl ureadc(char a1, _DWORD *a2)
{
  _DWORD *v2; // ebx
  int v3; // eax
  int v4; // eax

  while ( 1 ) /*0x10a454*/
  {
    if ( !a2[1] ) /*0x10a454*/
      panic(aUreadc); /*0x10a45f*/
    v2 = (_DWORD *)*a2; /*0x10a467*/
    if ( *(int *)(*a2 + 4) > 0 && (int)a2[5] > 0 ) /*0x10a473*/
      break; /*0x10a473*/
    --a2[1]; /*0x10a475*/
    *a2 += 8; /*0x10a478*/
  }
  v3 = a2[3]; /*0x10a480*/
  if ( v3 == 1 ) /*0x10a486*/
  {
    *(_BYTE *)*v2 = a1; /*0x10a4a8*/
  }
  else
  {
    if ( v3 > 1 ) /*0x10a488*/
    {
      if ( v3 != 2 ) /*0x10a493*/
        goto LABEL_17; /*0x10a493*/
      v4 = suibyte(*v2, a1); /*0x10a4b0*/
    }
    else
    {
      if ( v3 ) /*0x10a48c*/
        goto LABEL_17; /*0x10a48c*/
      v4 = subyte(*v2, a1); /*0x10a49c*/
    }
    if ( v4 < 0 ) /*0x10a4b7*/
      return 14; /*0x10a4be*/
  }
LABEL_17:
  ++*v2; /*0x10a4c0*/
  --v2[1]; /*0x10a4c2*/
  --a2[5]; /*0x10a4c5*/
  ++a2[2]; /*0x10a4c8*/
  return 0; /*0x10a4d0*/
}
