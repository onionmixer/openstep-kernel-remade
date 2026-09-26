/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc108. */
void __cdecl NXFreeMapTable(void **a1)
{
  NXResetMapTable(a1); /*0x1cc110*/
  free(a1[3]); /*0x1cc119*/
  free(a1); /*0x1cc11f*/
}
