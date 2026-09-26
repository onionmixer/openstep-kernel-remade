/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11f51c. */
int loattach()
{
  int result; // eax

  result = if_attach(0, 0, looutput, logetbuf, locontrol, &unk_1DB81C, 0, "Internet Protocol", 1536, 2056, 4096, 0); /*0x11f54f*/
  loifp = result; /*0x11f554*/
  return result; /*0x11f55b*/
}
