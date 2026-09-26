/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11efd4. */
int __cdecl ifunit(char *a1)
{
  char *v1; // esi
  int i; // ebx
  int v4; // [esp+Ch] [ebp-4h]

  v1 = a1; /*0x11efe0*/
  if ( a1 < a1 + 16 ) /*0x11efe7*/
  {
    while ( *v1 ) /*0x11eff0*/
    {
      if ( (unsigned __int8)(*v1 - 48) > 9u && ++v1 < a1 + 16 ) /*0x11effb*/
        continue; /*0x11effb*/
      goto LABEL_5; /*0x11effb*/
    }
    return 0; /*0x11eff0*/
  }
LABEL_5:
  if ( !*v1 || v1 == a1 + 16 ) /*0x11f008*/
    return 0; /*0x11f00c*/
  v4 = *v1 - 48; /*0x11f016*/
  for ( i = ifnet; i; i = *(_DWORD *)(i + 92) ) /*0x11f021*/
  {
    if ( !bcmp(*(const void **)i, a1, v1 - a1) && *(_DWORD *)(i + 20) == 4096 && v4 == *(__int16 *)(i + 8) ) /*0x11f049*/
      break; /*0x11f049*/
  }
  return i; /*0x11f057*/
}
