/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184178. */
int __cdecl sgopen(__int16 a1)
{
  void *v1; // eax

  v1 = (void *)sub_18447C(a1); /*0x184180*/
  if ( !v1 ) /*0x18418a*/
    return 6; /*0x18418c*/
  if ( objc_msgSend(v1, sel_acquire_, v1) ) /*0x1841a1*/
    return 16; /*0x1841b0*/
  return 0; /*0x184193*/
}
