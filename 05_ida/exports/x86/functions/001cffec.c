/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cffec. */
int __cdecl sub_1CFFEC(int a1)
{
  int zone; // eax
  int result; // eax

  zone = _objc_create_zone(); /*0x1cfff4*/
  result = (*(int (__cdecl **)(int, int))(zone + 4))(zone, a1); /*0x1cfffe*/
  if ( !result ) /*0x1d0007*/
  {
    if ( a1 ) /*0x1d000b*/
      _objc_fatal("unable to allocate space"); /*0x1d0012*/
  }
  return result; /*0x1d001c*/
}
