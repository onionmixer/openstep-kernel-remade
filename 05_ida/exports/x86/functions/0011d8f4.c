/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d8f4. */
int __cdecl chmod(const char *a1, mode_t a2)
{
  int v2; // esi
  __int16 v3; // cx
  char v4; // dl
  int result; // eax
  _BYTE v6[4]; // [esp+8h] [ebp-40h] BYREF
  __int16 v7; // [esp+Ch] [ebp-3Ch]

  v2 = *(_DWORD *)(dword_1E875C + 36); /*0x11d901*/
  vattr_null(v6); /*0x11d908*/
  v3 = *(_WORD *)(v2 + 4); /*0x11d90d*/
  HIBYTE(v3) &= 0xFu; /*0x11d911*/
  v7 = v3; /*0x11d914*/
  v4 = namesetattr(*(_DWORD *)v2, 1, v6); /*0x11d923*/
  result = dword_1E875C; /*0x11d925*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x11d92a*/
  return result; /*0x11d930*/
}
