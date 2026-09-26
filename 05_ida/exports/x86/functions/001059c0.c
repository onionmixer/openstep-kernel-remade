/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1059c0. */
int __cdecl check_exec_access(int a1)
{
  int v1; // esi
  int result; // eax
  _BYTE v3[64]; // [esp+8h] [ebp-40h] BYREF

  v1 = *(_DWORD *)(active_u + 28); /*0x1059d0*/
  result = (*(int (__cdecl **)(int, _BYTE *, int))(*(_DWORD *)(a1 + 28) + 20))(a1, v3, v1); /*0x1059df*/
  if ( !result ) /*0x1059e6*/
  {
    result = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 28) + 28))(a1, 64, v1); /*0x1059f2*/
    if ( !result /*0x105a19*/
      && ((*(_BYTE *)(*(_DWORD *)active_u + 40) & 0x10) == 0
       || (result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)(a1 + 28) + 28))(a1, 256, v1)) == 0) )
    {
      if ( *(_DWORD *)(a1 + 40) == 1 && (v3[4] & 0x49) != 0 ) /*0x105a25*/
        return 0; /*0x105a30*/
      else
        return 13; /*0x105a27*/
    }
  }
  return result; /*0x105a35*/
}
