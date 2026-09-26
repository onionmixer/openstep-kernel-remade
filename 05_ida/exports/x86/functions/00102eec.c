/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x102eec. */
_DWORD *bhinit()
{
  char *v0; // edx
  int v1; // ecx
  _DWORD *result; // eax

  v0 = (char *)&bufhash; /*0x102eef*/
  v1 = 0; /*0x102ef4*/
  result = &unk_1E8884; /*0x102ef6*/
  do /*0x102f0b*/
  {
    result[1] = v0; /*0x102efc*/
    *result = v0; /*0x102eff*/
    ++v1; /*0x102f01*/
    result += 3; /*0x102f02*/
    v0 += 12; /*0x102f05*/
  }
  while ( v1 <= 15 ); /*0x102f0b*/
  return result; /*0x102f0f*/
}
