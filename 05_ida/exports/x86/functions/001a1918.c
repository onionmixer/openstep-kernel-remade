/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1918. */
void __cdecl PCbopFC(int a1, int a2, unsigned __int16 *a3)
{
  if ( (a3[1] & 4) != 0 ) /*0x1a1926*/
  {
    *(_DWORD *)(a2 + 56) = *a3; /*0x1a192f*/
    *(_WORD *)(a2 + 60) = a3[1]; /*0x1a1936*/
    *(_DWORD *)(a2 + 64) = a3[2] & 0xFD7 | 0x202; /*0x1a1948*/
    *(_DWORD *)(a2 + 68) = a3[3]; /*0x1a194f*/
    *(_WORD *)(a2 + 72) = a3[4]; /*0x1a1956*/
    thread_exception_return(); /*0x1a195a*/
  }
}
