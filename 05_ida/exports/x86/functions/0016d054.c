/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d054. */
int __cdecl sub_16D054(int *a1)
{
  int result; // eax

  result = kfree(*a1, ~page_mask & (page_mask + a1[2] - *a1)); /*0x16d06f*/
  a1[1] = 0; /*0x16d074*/
  a1[2] = 0; /*0x16d07b*/
  *a1 = 0; /*0x16d082*/
  return result; /*0x16d088*/
}
