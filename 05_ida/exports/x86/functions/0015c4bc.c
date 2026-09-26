/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c4bc. */
int __cdecl nextseg(int a1)
{
  int result; // eax

  result = nextsegfromheader(&dword_100000, a1); /*0x15c4c9*/
  if ( !result && a1 != fvm_seg ) /*0x15c4da*/
    return fvm_seg; /*0x15c4dc*/
  return result; /*0x15c4de*/
}
