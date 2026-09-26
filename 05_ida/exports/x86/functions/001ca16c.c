/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca16c. */
char __cdecl +[Object conformsTo:](id a1, SEL a2, id a3)
{
  _DWORD *v3; // edi
  _DWORD *v4; // esi
  int v5; // ebx

  v3 = a1; /*0x1ca172*/
  if ( !a1 ) /*0x1ca177*/
    return 0; /*0x1ca1d3*/
  while ( 1 ) /*0x1ca17c*/
  {
    if ( *(int *)(*v3 + 12) > 2 ) /*0x1ca182*/
    {
      v4 = (_DWORD *)v3[9]; /*0x1ca184*/
      if ( v4 ) /*0x1ca189*/
        break; /*0x1ca189*/
    }
LABEL_10:
    v3 = (_DWORD *)v3[1]; /*0x1ca1cc*/
    if ( !v3 ) /*0x1ca1d1*/
      return 0; /*0x1ca1d1*/
  }
  while ( 1 ) /*0x1ca18c*/
  {
    v5 = 0; /*0x1ca18c*/
    if ( (int)v4[1] > 0 ) /*0x1ca191*/
      break; /*0x1ca191*/
LABEL_8:
    if ( *(int *)(*v3 + 12) > 4 ) /*0x1ca1c4*/
    {
      v4 = (_DWORD *)*v4; /*0x1ca1c6*/
      if ( v4 ) /*0x1ca1ca*/
        continue; /*0x1ca1ca*/
    }
    goto LABEL_10; /*0x1ca1ca*/
  }
  while ( !(unsigned __int8)objc_msgSend((id)v4[v5 + 2], sel_conformsTo_, a3) ) /*0x1ca1ae*/
  {
    if ( v4[1] <= ++v5 ) /*0x1ca1bc*/
      goto LABEL_8; /*0x1ca1bc*/
  }
  return 1; /*0x1ca1d8*/
}
