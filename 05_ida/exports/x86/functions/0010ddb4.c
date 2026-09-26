/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ddb4. */
int __cdecl ttywflush(FILE *a1)
{
  ttywait(a1); /*0x10ddbc*/
  return ttyflush(a1, 1); /*0x10ddc9*/
}
