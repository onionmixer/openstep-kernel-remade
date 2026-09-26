/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a95c8. */
int __cdecl sub_1A95C8(int a1)
{
  void *v1; // eax

  v1 = (void *)if_private(a1); /*0x1a95cf*/
  if ( v1 ) /*0x1a95d9*/
    return (int)objc_msgSend(v1, sel_finishInitialization); /*0x1a95e3*/
  else
    return -1; /*0x1a95ec*/
}
