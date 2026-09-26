/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123514. */
int __cdecl in_netof(unsigned int a1)
{
  int v1; // edx
  int v2; // ecx
  _DWORD *v4; // eax

  v1 = _byteswap_ulong(a1); /*0x12351c*/
  if ( v1 < 0 ) /*0x123520*/
  {
    if ( (v1 & 0xC0000000) == 0x80000000 ) /*0x123533*/
    {
      v2 = v1 & 0xFFFF0000; /*0x12353c*/
    }
    else if ( (v1 & 0xE0000000) == 0xC0000000 ) /*0x123550*/
    {
      v2 = v1; /*0x123552*/
      LOBYTE(v2) = 0; /*0x123554*/
    }
    else
    {
      if ( (v1 & 0xF0000000) != 0xE0000000 ) /*0x123564*/
        return 0; /*0x12356b*/
      v2 = -536870912; /*0x123578*/
    }
  }
  else
  {
    v2 = v1 & 0x7F000000; /*0x123524*/
  }
  v4 = (_DWORD *)in_ifaddr; /*0x12357d*/
  if ( !in_ifaddr ) /*0x123584*/
    return v2; /*0x123594*/
  while ( v4[10] != v2 ) /*0x12358b*/
  {
    v4 = (_DWORD *)v4[16]; /*0x12358d*/
    if ( !v4 ) /*0x123592*/
      return v2; /*0x123592*/
  }
  return v4[13] & v1; /*0x12356a*/
}
