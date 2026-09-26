/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x193e58. */
unsigned __int32 __cdecl pagemove(unsigned int a1, unsigned int a2, int a3)
{
  int v4; // esi
  _DWORD *v5; // ebx
  unsigned __int32 result; // eax

  v4 = a3; /*0x193e61*/
  if ( (a3 & 0xFFF) != 0 ) /*0x193e6a*/
    panic(aPagemove); /*0x193e71*/
  while ( v4 > 0 ) /*0x193ebd*/
  {
    v5 = (_DWORD *)pmap_pt_entry((_DWORD *)kernel_pmap, a1); /*0x193e8c*/
    *(_DWORD *)pmap_pt_entry((_DWORD *)kernel_pmap, a2) = *v5; /*0x193e9d*/
    *v5 = 0; /*0x193e9f*/
    a1 += 4096; /*0x193ea5*/
    a2 += 4096; /*0x193eac*/
    v4 -= 4096; /*0x193eb2*/
  }
  result = __readcr3(); /*0x193ebf*/
  __writecr3(result); /*0x193ec2*/
  return result; /*0x193ec8*/
}
