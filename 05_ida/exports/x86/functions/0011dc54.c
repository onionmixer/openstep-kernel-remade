/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11dc54. */
int __cdecl namesetattr(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h] BYREF

  result = lookupname(a1, 0, a2, 0, (int)&v6); /*0x11dc6b*/
  if ( !result ) /*0x11dc75*/
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v6 + 36) + 12) & 1) != 0 ) /*0x11dc81*/
      v4 = 30; /*0x11dc83*/
    else
      v4 = (*(int (__cdecl **)(int, int, _DWORD))(*(_DWORD *)(v6 + 28) + 24))(v6, a3, *(_DWORD *)(active_u + 28)); /*0x11dca1*/
    v5 = v4; /*0x11dcaa*/
    vn_rele(v6); /*0x11dcad*/
    return v5; /*0x11dcb2*/
  }
  return result; /*0x11dcb5*/
}
