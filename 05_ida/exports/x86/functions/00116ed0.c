/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116ed0. */
int __cdecl listen(int a1, int a2)
{
  _DWORD *v2; // ebx
  int result; // eax
  char v4; // dl

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x116ed9*/
  result = getsock(*v2); /*0x116edf*/
  if ( result ) /*0x116ee9*/
  {
    v4 = solisten(*(_DWORD *)(result + 24), v2[1]); /*0x116ef8*/
    result = dword_1E875C; /*0x116efa*/
    *(_BYTE *)(dword_1E875C + 104) = v4; /*0x116eff*/
  }
  return result; /*0x116f02*/
}
