/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187b98. */
int __cdecl clock_value(int a1)
{
  int result; // eax

  result = sub_187D48(); /*0x187b9f*/
  if ( a1 ) /*0x187ba6*/
  {
    if ( a1 != 1 ) /*0x187bab*/
      return 0; /*0x187bc0*/
  }
  else
  {
    result += time_of_boot; /*0x187bb6*/
  }
  return result; /*0x187bca*/
}
