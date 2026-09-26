/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123d50. */
int __cdecl in_iaonnetof(int a1)
{
  int result; // eax

  result = in_ifaddr; /*0x123d56*/
  if ( !in_ifaddr ) /*0x123d5d*/
    return 0; /*0x123d6c*/
  while ( *(_DWORD *)(result + 48) != a1 ) /*0x123d63*/
  {
    result = *(_DWORD *)(result + 64); /*0x123d65*/
    if ( !result ) /*0x123d6a*/
      return 0; /*0x123d6a*/
  }
  return result; /*0x123d70*/
}
