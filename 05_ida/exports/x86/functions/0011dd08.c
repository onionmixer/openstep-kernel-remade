/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11dd08. */
int __cdecl fsync(int a1)
{
  int v1; // eax
  char v2; // dl
  int v3; // eax
  int result; // eax
  int v5; // [esp+0h] [ebp-4h] BYREF

  v1 = getvnodefp(**(_DWORD **)(dword_1E875C + 36), &v5); /*0x11dd1d*/
  v2 = v1; /*0x11dd22*/
  if ( !v1 ) /*0x11dd29*/
  {
    v3 = mfs_fsync(*(_DWORD *)(v5 + 24)); /*0x11dd32*/
    v2 = v3; /*0x11dd37*/
    if ( !v3 ) /*0x11dd3e*/
      v2 = (*(int (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)(*(_DWORD *)(v5 + 24) + 28) + 72))( /*0x11dd53*/
             *(_DWORD *)(v5 + 24),
             *(_DWORD *)(v5 + 32));
  }
  result = dword_1E875C; /*0x11dd55*/
  *(_BYTE *)(dword_1E875C + 104) = v2; /*0x11dd5a*/
  return result; /*0x11dd5d*/
}
