/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169c64. */
int sub_169C64()
{
  _BOOL4 v0; // ebx
  int result; // eax

  v0 = dword_1E7268 < dword_1E7260 + dword_1E7264; /*0x169c7d*/
  _InterlockedExchange(&dword_1E7244, 0); /*0x169c80*/
  result = thread_wakeup_prim((int)&dword_1E7260, 1, 0); /*0x169c8f*/
  if ( v0 ) /*0x169c99*/
    return thread_wakeup_prim((int)&dword_1E7268, 1, 0); /*0x169ca4*/
  return result; /*0x169ca9*/
}
