/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d938. */
int __cdecl fchmod(int a1, mode_t a2)
{
  int v2; // esi
  __int16 v3; // cx
  char v4; // dl
  int result; // eax
  _BYTE v6[4]; // [esp+8h] [ebp-40h] BYREF
  __int16 v7; // [esp+Ch] [ebp-3Ch]

  v2 = *(_DWORD *)(dword_1E875C + 36); /*0x11d945*/
  vattr_null(v6); /*0x11d94c*/
  v3 = *(_WORD *)(v2 + 4); /*0x11d951*/
  HIBYTE(v3) &= 0xFu; /*0x11d955*/
  v7 = v3; /*0x11d958*/
  v4 = fdsetattr(*(_DWORD *)v2, v6); /*0x11d965*/
  result = dword_1E875C; /*0x11d967*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x11d96c*/
  return result; /*0x11d972*/
}
