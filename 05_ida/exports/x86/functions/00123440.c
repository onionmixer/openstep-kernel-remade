/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123440. */
unsigned __int32 __cdecl inet_hash(int a1, unsigned __int32 *a2)
{
  unsigned __int32 v2; // eax
  unsigned __int32 result; // eax

  v2 = in_netof(*(_DWORD *)(a1 + 4)); /*0x12344f*/
  if ( v2 && !(_BYTE)v2 ) /*0x12345a*/
  {
    do /*0x123461*/
      v2 >>= 8; /*0x12345c*/
    while ( !(_BYTE)v2 ); /*0x123461*/
  }
  a2[1] = v2; /*0x123463*/
  result = _byteswap_ulong(*(_DWORD *)(a1 + 4)); /*0x123469*/
  *a2 = result; /*0x12346b*/
  return result; /*0x123470*/
}
