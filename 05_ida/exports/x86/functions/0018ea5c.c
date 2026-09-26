/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ea5c. */
int __cdecl thread_entrypoint(int a1, int a2, int a3, unsigned int a4, _DWORD *a5)
{
  if ( !*a5 ) /*0x18ea65*/
    *a5 = *a5; /*0x18ea6c*/
  if ( a2 == -1 ) /*0x18ea72*/
  {
    if ( a4 <= 0xF ) /*0x18ea78*/
      return 4; /*0x18ea82*/
    *a5 = *(_DWORD *)(a3 + 40); /*0x18ea87*/
  }
  return 0; /*0x18ea81*/
}
