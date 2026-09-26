/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15081c. */
int __cdecl ipc_space_create_special(_DWORD *a1)
{
  _DWORD *v1; // eax

  v1 = (_DWORD *)zalloc(ipc_space_zone); /*0x15082a*/
  if ( !v1 ) /*0x150831*/
    return 6; /*0x150854*/
  *v1 = 0; /*0x150833*/
  v1[1] = 1; /*0x150839*/
  v1[2] = 0; /*0x150840*/
  v1[3] = 0; /*0x150847*/
  *a1 = v1; /*0x15084e*/
  return 0; /*0x150859*/
}
