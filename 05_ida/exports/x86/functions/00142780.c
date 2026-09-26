/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142780. */
int __cdecl sub_142780(int a1, int a2)
{
  int *v2; // edx
  int v3; // eax

  v2 = &a1; /*0x142786*/
  if ( !a1 ) /*0x14278d*/
    return 0; /*0x1427ad*/
  while ( 1 ) /*0x142790*/
  {
    v3 = *v2; /*0x142790*/
    if ( *v2 == a2 ) /*0x142794*/
      break; /*0x142794*/
    v2 = (int *)(v3 + 24); /*0x1427a4*/
    if ( !*(_DWORD *)(v3 + 24) ) /*0x1427a7*/
      return 0; /*0x1427ab*/
  }
  *v2 = *(_DWORD *)(v3 + 24); /*0x142799*/
  return 1; /*0x1427a2*/
}
