/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108a48. */
int __cdecl getrlimit(int a1, rlimit *a2)
{
  int result; // eax
  char v3; // dl

  result = *(_DWORD *)(dword_1E875C + 36); /*0x108a51*/
  if ( *(_DWORD *)result <= 5u ) /*0x108a59*/
  {
    v3 = copyout(active_u + 8 * *(_DWORD *)result + 612, *(_DWORD *)(result + 4), 8); /*0x108a7c*/
    result = dword_1E875C; /*0x108a7e*/
    *(_BYTE *)(dword_1E875C + 104) = v3; /*0x108a83*/
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x108a5b*/
  }
  return result; /*0x108a61*/
}
