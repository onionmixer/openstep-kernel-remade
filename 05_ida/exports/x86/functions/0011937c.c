/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11937c. */
int __cdecl cstatfs(int a1, int a2)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[64]; // [esp+8h] [ebp-40h] BYREF

  bzero(v4, 0x40u); /*0x11938d*/
  *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, _BYTE *))(*(_DWORD *)(a1 + 4) + 12))(a1, v4); /*0x1193a3*/
  result = dword_1E875C; /*0x1193a6*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x1193ae*/
  {
    v3 = copyout(v4, a2, 64); /*0x1193c0*/
    result = dword_1E875C; /*0x1193c2*/
    *(_BYTE *)(dword_1E875C + 104) = v3; /*0x1193c7*/
  }
  return result; /*0x1193cd*/
}
