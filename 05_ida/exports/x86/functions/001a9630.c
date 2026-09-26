/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9630. */
id __cdecl sub_1A9630(int a1)
{
  void *v1; // eax

  v1 = (void *)if_private(a1); /*0x1a9637*/
  if ( v1 ) /*0x1a9641*/
    return objc_msgSend(v1, sel_allocateNetbuf); /*0x1a964b*/
  else
    return nullptr; /*0x1a9654*/
}
