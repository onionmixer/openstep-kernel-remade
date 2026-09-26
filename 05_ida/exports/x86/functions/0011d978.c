/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d978. */
int __cdecl chown(const char *a1, uid_t a2, gid_t a3)
{
  int v3; // ebx
  char v4; // dl
  int result; // eax
  _BYTE v6[6]; // [esp+8h] [ebp-40h] BYREF
  __int16 v7; // [esp+Eh] [ebp-3Ah]
  __int16 v8; // [esp+10h] [ebp-38h]

  v3 = *(_DWORD *)(dword_1E875C + 36); /*0x11d985*/
  vattr_null(v6); /*0x11d98c*/
  v7 = *(_WORD *)(v3 + 4); /*0x11d995*/
  v8 = *(_WORD *)(v3 + 8); /*0x11d99d*/
  v4 = namesetattr(*(_DWORD *)v3, 0, v6); /*0x11d9ac*/
  result = dword_1E875C; /*0x11d9ae*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x11d9b3*/
  return result; /*0x11d9b9*/
}
