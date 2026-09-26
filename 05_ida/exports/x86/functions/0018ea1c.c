/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ea1c. */
int __cdecl thread_userstack(int a1, int a2, int a3, unsigned int a4, int *a5)
{
  int v6; // eax

  if ( !*a5 ) /*0x18ea25*/
    *a5 = -1073741824; /*0x18ea2a*/
  if ( a2 == -1 ) /*0x18ea34*/
  {
    if ( a4 <= 0xF ) /*0x18ea3a*/
      return 4; /*0x18ea44*/
    v6 = *(_DWORD *)(a3 + 28); /*0x18ea48*/
    if ( !v6 ) /*0x18ea4d*/
      v6 = -1073741824; /*0x18ea4f*/
    *a5 = v6; /*0x18ea54*/
  }
  return 0; /*0x18ea43*/
}
