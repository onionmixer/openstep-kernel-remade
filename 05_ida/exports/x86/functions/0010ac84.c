/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ac84. */
int __cdecl getthetime(_DWORD *a1)
{
  int v1; // esi
  int result; // eax

  do /*0x10aca2*/
  {
    v1 = *((_DWORD *)mtime + 1); /*0x10ac98*/
    result = *((_DWORD *)mtime + 2); /*0x10ac9d*/
  }
  while ( *(_DWORD *)mtime != result ); /*0x10aca2*/
  *a1 = result; /*0x10aca4*/
  a1[1] = v1; /*0x10aca6*/
  return result; /*0x10acac*/
}
