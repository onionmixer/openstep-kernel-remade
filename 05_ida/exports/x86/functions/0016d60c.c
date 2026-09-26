/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d60c. */
int __cdecl get_kern_port(int a1, int a2, _DWORD *a3)
{
  if ( a2 ) /*0x16d617*/
  {
    if ( object_copyin(a1, a2, 6, 0, (int)a3) ) /*0x16d632*/
      return 0; /*0x16d63b*/
    else
      return 4; /*0x16d644*/
  }
  else
  {
    *a3 = 0; /*0x16d619*/
    return 0; /*0x16d61f*/
  }
}
