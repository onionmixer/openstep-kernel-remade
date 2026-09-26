/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107898. */
_DWORD *__cdecl get_posix_proc(int a1)
{
  _DWORD *result; // eax
  char v2[80]; // [esp+4h] [ebp-50h] BYREF

  result = (_DWORD *)posix_proc_hash[a1 & 0x3F]; /*0x1078a7*/
  if ( !result )
  {
LABEL_4:
    sprintf(v2, "get_posix_proc(): no posix proc struct for pid %d", a1);
    panic(v2); /*0x1078cf*/
  }
  while ( *result != a1 ) /*0x1078b6*/
  {
    result = (_DWORD *)result[7]; /*0x1078b8*/
    if ( !result ) /*0x1078bd*/
      goto LABEL_4; /*0x1078bd*/
  }
  return result; /*0x1078d4*/
}
