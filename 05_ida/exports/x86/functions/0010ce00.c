/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ce00. */
ssize_t __cdecl write(int __fd, const void *__buf, size_t __nbyte)
{
  int v3; // eax
  _DWORD v5[2]; // [esp+0h] [ebp-20h] BYREF
  int v6[6]; // [esp+8h] [ebp-18h] BYREF

  v3 = *(_DWORD *)(dword_1E875C + 36); /*0x10ce0b*/
  v6[0] = (int)v5; /*0x10ce11*/
  v6[1] = 1; /*0x10ce14*/
  v5[0] = *(_DWORD *)(v3 + 4); /*0x10ce1e*/
  v5[1] = *(_DWORD *)(v3 + 8); /*0x10ce24*/
  return rwuio(v6, 1); /*0x10ce32*/
}
