/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137994. */
int __cdecl sub_137994(int *a1)
{
  int result; // eax
  int v2; // ecx

  result = *a1; /*0x13799a*/
  v2 = *a1; /*0x13799c*/
  LOBYTE(v2) = *a1 & 0xFE; /*0x13799e*/
  *a1 = v2; /*0x1379a1*/
  if ( (result & 2) != 0 ) /*0x1379a5*/
  {
    LOBYTE(result) = result & 0xFC; /*0x1379a7*/
    *a1 = result; /*0x1379a9*/
    return wakeup((int)a1); /*0x1379ac*/
  }
  return result; /*0x1379b3*/
}
