/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10abb0. */
int __cdecl gettimeofday(timeval *a1, void *a2)
{
  int result; // eax
  _DWORD *v3; // esi
  char v4; // dl
  _DWORD v5[2]; // [esp+8h] [ebp-8h] BYREF

  result = dword_1E875C; /*0x10abb8*/
  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x10abbd*/
  if ( *v3 ) /*0x10abc0*/
  {
    microtime(v5); /*0x10abc9*/
    v4 = copyout(v5, *v3, 8); /*0x10abd9*/
    result = dword_1E875C; /*0x10abdb*/
    *(_BYTE *)(dword_1E875C + 104) = v4; /*0x10abe0*/
  }
  return result; /*0x10abe6*/
}
