/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x190afc. */
int __cdecl pmap_enter_shared_range(_DWORD *a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // ebx
  int result; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax

  v4 = a2; /*0x190b02*/
  result = ~page_mask; /*0x190b14*/
  v7 = ~page_mask & (page_mask + a3 + a2); /*0x190b18*/
  if ( a2 < v7 ) /*0x190b1c*/
  {
    do /*0x190b4d*/
    {
      v8 = pmap_resident_extract(kernel_pmap, a4); /*0x190b2c*/
      pmap_enter(a1, v4, v8, 3, 1); /*0x190b3a*/
      result = page_size; /*0x190b3f*/
      v4 += page_size; /*0x190b44*/
      a4 += page_size; /*0x190b46*/
    }
    while ( v4 < v7 ); /*0x190b4d*/
  }
  return result; /*0x190b52*/
}
