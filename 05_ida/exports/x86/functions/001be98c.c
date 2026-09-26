/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be98c. */
int __cdecl audio_add_peak(int a1, int a2, int *a3, int a4)
{
  int result; // eax

  if ( a4 ) /*0x1be99c*/
  {
    *(_DWORD *)(a1 + 4 * *a3) = a2; /*0x1be9a3*/
    result = *a3 + 1; /*0x1be9a8*/
    *a3 = result; /*0x1be9a9*/
    if ( result == a4 ) /*0x1be9ad*/
      *a3 = 0; /*0x1be9af*/
  }
  return result; /*0x1be9b8*/
}
