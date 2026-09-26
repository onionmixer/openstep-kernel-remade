/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ce38. */
ssize_t __cdecl writev(int a1, const iovec *a2, int a3)
{
  ssize_t result; // eax
  int v4; // ecx
  _BYTE v5[128]; // [esp+4h] [ebp-98h] BYREF
  int v6[6]; // [esp+84h] [ebp-18h] BYREF

  result = dword_1E875C; /*0x10ce42*/
  v4 = *(_DWORD *)(dword_1E875C + 36); /*0x10ce47*/
  if ( *(_DWORD *)(v4 + 8) <= 0x10u ) /*0x10ce4e*/
  {
    v6[0] = (int)v5; /*0x10ce5e*/
    v6[1] = *(_DWORD *)(v4 + 8); /*0x10ce64*/
    *(_BYTE *)(dword_1E875C + 104) = copyin(*(_DWORD *)(v4 + 4), v5, 8 * *(_DWORD *)(v4 + 8)); /*0x10ce83*/
    result = dword_1E875C; /*0x10ce86*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10ce8e*/
      return rwuio(v6, 1); /*0x10ce9a*/
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10ce50*/
  }
  return result; /*0x10ce9f*/
}
