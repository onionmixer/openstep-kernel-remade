/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e970. */
int __cdecl get_thread_cthreadstate(int a1, _DWORD *a2, _DWORD *a3)
{
  if ( !*a3 ) /*0x18e97c*/
    return 4; /*0x18e998*/
  *a2 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 232); /*0x18e98a*/
  *a3 = 1; /*0x18e98c*/
  return 0; /*0x18e996*/
}
