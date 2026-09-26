/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135d94. */
int __cdecl sub_135D94(int *a1)
{
  int result; // eax
  int v2; // edx
  int v3; // ecx

  result = (int)a1; /*0x135d97*/
  v2 = *a1; /*0x135d9a*/
  v3 = *a1; /*0x135d9c*/
  LOBYTE(v3) = *a1 & 0xF7; /*0x135d9e*/
  *a1 = v3; /*0x135da1*/
  if ( (v2 & 0x10) != 0 ) /*0x135da6*/
  {
    LOBYTE(v2) = v2 & 0xE7; /*0x135da8*/
    *a1 = v2; /*0x135dab*/
    return wakeup((int)(a1 + 26)); /*0x135db1*/
  }
  return result; /*0x135db8*/
}
