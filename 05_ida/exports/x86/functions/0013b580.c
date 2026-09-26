/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13b580. */
int sub_13B580()
{
  char v0; // dl
  int result; // eax

  v0 = copyout(&dword_1E5A34, **(_DWORD **)(dword_1E875C + 36), 100); /*0x13b59a*/
  result = dword_1E875C; /*0x13b59c*/
  *(_BYTE *)(dword_1E875C + 104) = v0; /*0x13b5a1*/
  return result; /*0x13b5a6*/
}
