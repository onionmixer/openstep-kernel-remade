/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12359c. */
int __cdecl in_lnaof(unsigned int a1)
{
  int v1; // edx
  int v2; // ecx
  _DWORD *v4; // eax

  v1 = _byteswap_ulong(a1); /*0x1235a4*/
  if ( v1 < 0 ) /*0x1235a8*/
  {
    if ( (v1 & 0xC0000000) == 0x80000000 ) /*0x1235c3*/
    {
      v2 = v1 & 0xFFFF0000; /*0x1235cc*/
      v1 = (unsigned __int16)v1; /*0x1235d2*/
    }
    else if ( (v1 & 0xE0000000) == 0xC0000000 ) /*0x1235e8*/
    {
      v2 = v1; /*0x1235ea*/
      LOBYTE(v2) = 0; /*0x1235ec*/
      v1 = (unsigned __int8)v1; /*0x1235ee*/
    }
    else
    {
      if ( (v1 & 0xF0000000) != 0xE0000000 ) /*0x123604*/
        return v1; /*0x12360b*/
      v2 = -536870912; /*0x123618*/
      v1 &= 0xFFFFFFFu; /*0x12361d*/
    }
  }
  else
  {
    v2 = v1 & 0x7F000000; /*0x1235ac*/
    v1 &= 0xFFFFFFu; /*0x1235b2*/
  }
  v4 = (_DWORD *)in_ifaddr; /*0x123623*/
  if ( !in_ifaddr ) /*0x12362a*/
    return v1; /*0x123638*/
  while ( v4[10] != v2 ) /*0x12362f*/
  {
    v4 = (_DWORD *)v4[16]; /*0x123631*/
    if ( !v4 ) /*0x123636*/
      return v1; /*0x123636*/
  }
  return v1 & ~v4[13]; /*0x12360a*/
}
