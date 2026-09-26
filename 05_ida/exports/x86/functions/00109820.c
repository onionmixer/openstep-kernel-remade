/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x109820. */
_DWORD *__cdecl pgsignal(_DWORD *a1, char *a2, int a3)
{
  _DWORD *result; // eax
  unsigned int i; // ebx

  result = a1; /*0x109826*/
  if ( a1 ) /*0x109831*/
  {
    for ( i = a1[1]; i; i = result[3] ) /*0x109838*/
    {
      if ( !a3 || (*(_BYTE *)(i + 43) & 0x40) != 0 ) /*0x109844*/
        psignal(i, a2); /*0x109848*/
      result = get_posix_proc(*(__int16 *)(i + 48)); /*0x109855*/
    }
  }
  return result; /*0x109867*/
}
