/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x193ed0. */
int __cdecl kernacc(int a1, int a2, int a3)
{
  unsigned int v3; // ebx
  char *v4; // eax
  char v5; // al

  v3 = ~page_mask & a1; /*0x193ee8*/
  if ( v3 >= a2 + a1 ) /*0x193eec*/
    return 1; /*0x193f22*/
  while ( 1 ) /*0x193ef8*/
  {
    v4 = (char *)pmap_pt_entry((_DWORD *)kernel_pmap, v3); /*0x193ef8*/
    if ( !v4 ) /*0x193f02*/
      break; /*0x193f02*/
    v5 = *v4; /*0x193f04*/
    if ( (v5 & 1) == 0 || !a3 && (v5 & 6) == 0 ) /*0x193f10*/
      break; /*0x193f10*/
    v3 += page_size; /*0x193f18*/
    if ( v3 >= a2 + a1 ) /*0x193f20*/
      return 1; /*0x193f20*/
  }
  return 0; /*0x193f2a*/
}
