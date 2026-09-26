/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca868. */
int __cdecl sub_1CA868(int *a1, int a2)
{
  int v2; // edx

  if ( !a1 ) /*0x1ca874*/
    return 0; /*0x1ca874*/
  v2 = 0; /*0x1ca876*/
  if ( *a1 <= 0 ) /*0x1ca87a*/
    return 0; /*0x1ca895*/
  while ( a1[2 * v2 + 1] != a2 ) /*0x1ca887*/
  {
    if ( *a1 <= ++v2 ) /*0x1ca893*/
      return 0; /*0x1ca893*/
  }
  return (int)&a1[2 * v2 + 1]; /*0x1ca897*/
}
