/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192c74. */
unsigned __int32 __cdecl byte_swap_superblock(unsigned int *a1)
{
  int v1; // ecx
  unsigned int *v2; // edx
  int v3; // ecx
  _WORD *v4; // edx
  unsigned __int32 result; // eax

  v1 = 0; /*0x192c7b*/
  v2 = a1 + 2; /*0x192c7d*/
  do /*0x192c8d*/
  {
    *v2 = _byteswap_ulong(*v2); /*0x192c84*/
    ++v2; /*0x192c86*/
    ++v1; /*0x192c89*/
  }
  while ( v1 < 50 ); /*0x192c8d*/
  a1[181] = _byteswap_ulong(a1[181]); /*0x192c97*/
  a1[214] = _byteswap_ulong(a1[214]); /*0x192ca5*/
  v3 = 0; /*0x192cab*/
  v4 = a1 + 215; /*0x192cad*/
  do /*0x192cc8*/
  {
    *v4 = __ROR2__(*v4, 8); /*0x192cbb*/
    ++v4; /*0x192cbe*/
    ++v3; /*0x192cc1*/
  }
  while ( v3 < 256 ); /*0x192cc8*/
  result = _byteswap_ulong(a1[343]); /*0x192cd0*/
  a1[343] = result; /*0x192cd2*/
  return result; /*0x192cd8*/
}
