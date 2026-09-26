/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd3b0. */
int __cdecl sub_1CD3B0(int a1)
{
  int v1; // ebx
  int zone; // eax
  int result; // eax

  v1 = ((int (*)(void))_objc_create_zone)(); /*0x1cd3bd*/
  zone = _objc_create_zone(a1); /*0x1cd3c0*/
  result = (*(int (__cdecl **)(int))(v1 + 4))(zone); /*0x1cd3c9*/
  if ( !result ) /*0x1cd3d2*/
  {
    if ( a1 ) /*0x1cd3d6*/
      _objc_fatal("unable to allocate space"); /*0x1cd3dd*/
  }
  return result; /*0x1cd3e7*/
}
