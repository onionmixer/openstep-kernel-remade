/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125c80. */
int __cdecl ifptoia(int a1)
{
  int result; // eax

  result = in_ifaddr; /*0x125c86*/
  if ( !in_ifaddr ) /*0x125c8d*/
    return 0; /*0x125c9c*/
  while ( *(_DWORD *)(result + 32) != a1 ) /*0x125c93*/
  {
    result = *(_DWORD *)(result + 64); /*0x125c95*/
    if ( !result ) /*0x125c9a*/
      return 0; /*0x125c9a*/
  }
  return result; /*0x125ca0*/
}
