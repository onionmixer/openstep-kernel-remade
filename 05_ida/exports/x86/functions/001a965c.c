/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a965c. */
int __cdecl sub_1A965C(int a1, int a2, int a3)
{
  void *v3; // eax

  v3 = (void *)if_private(a1); /*0x1a9663*/
  if ( v3 ) /*0x1a966d*/
    return (int)objc_msgSend(v3, sel_performCommand_data_, a2, a3); /*0x1a967f*/
  else
    return -1; /*0x1a9688*/
}
