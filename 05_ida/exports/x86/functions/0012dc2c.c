/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12dc2c. */
int __cdecl sub_12DC2C(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  int result; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  if ( !a2 ) /*0x12dc3a*/
    return 0; /*0x12dc3a*/
  v2 = getvfs(a1); /*0x12dc3d*/
  if ( !v2 ) /*0x12dc49*/
    return 0; /*0x12dc49*/
  if ( (*(int (__stdcall **)(_DWORD *, int *, _DWORD *))(v2[1] + 20))(v2, &v4, a1 + 2) ) /*0x12dc5a*/
    return 0; /*0x12dc5a*/
  result = v4; /*0x12dc60*/
  if ( !v4 ) /*0x12dc65*/
    return 0; /*0x12dc67*/
  return result; /*0x12dc69*/
}
