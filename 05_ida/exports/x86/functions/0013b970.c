/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13b970. */
int __cdecl fssleep(_DWORD *a1, char a2)
{
  int result; // eax

  if ( (a2 & 1) != 0 ) /*0x13b97d*/
  {
    for ( result = a1[51] + (a1[49] << a1[24]); a1[34] >= result; result = a1[51] + (a1[49] << a1[24]) ) /*0x13b996*/
      sleep((unsigned int)(a1 + 51)); /*0x13b9a3*/
  }
  else
  {
    if ( (a2 & 2) == 0 ) /*0x13b9ca*/
      panic(aFssleep); /*0x13ba01*/
    for ( result = a1[36]; a1[50] <= result; result = a1[36] ) /*0x13b9d8*/
      sleep((unsigned int)(a1 + 50)); /*0x13b9e3*/
  }
  return result; /*0x13ba09*/
}
