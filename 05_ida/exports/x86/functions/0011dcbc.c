/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11dcbc. */
int __cdecl fdsetattr(int a1, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // [esp+4h] [ebp-4h] BYREF

  result = getvnodefp(a1, &v4); /*0x11dccb*/
  if ( !result ) /*0x11dcd5*/
  {
    v3 = *(_DWORD *)(v4 + 24); /*0x11dcda*/
    if ( (*(_BYTE *)(*(_DWORD *)(v3 + 36) + 12) & 1) != 0 ) /*0x11dce4*/
      return 30; /*0x11dce6*/
    else
      return (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)(v3 + 28) + 24))(v3, a2, *(_DWORD *)(v4 + 32)); /*0x11dcff*/
  }
  return result; /*0x11dd01*/
}
