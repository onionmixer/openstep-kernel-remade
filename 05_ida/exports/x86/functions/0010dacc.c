/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10dacc. */
int __cdecl soo_close(int a1)
{
  int result; // eax

  result = 0; /*0x10dad3*/
  if ( *(_DWORD *)(a1 + 24) ) /*0x10dad5*/
    result = soclose(*(_DWORD *)(a1 + 24)); /*0x10dadd*/
  *(_DWORD *)(a1 + 24) = 0; /*0x10dae2*/
  return result; /*0x10dae9*/
}
