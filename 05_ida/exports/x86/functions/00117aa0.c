/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117aa0. */
int __cdecl shutdown(int a1, int a2)
{
  _DWORD *v2; // ebx
  int result; // eax
  char v4; // dl

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x117aa9*/
  result = getsock(*v2); /*0x117aaf*/
  if ( result ) /*0x117ab9*/
  {
    v4 = soshutdown(*(_DWORD *)(result + 24), v2[1]); /*0x117ac8*/
    result = dword_1E875C; /*0x117aca*/
    *(_BYTE *)(dword_1E875C + 104) = v4; /*0x117acf*/
  }
  return result; /*0x117ad2*/
}
