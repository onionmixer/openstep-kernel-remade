/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cac8. */
_BOOL4 __cdecl check_cpu_subtype(int a1)
{
  if ( dword_1E8E08 == 4 ) /*0x18cad6*/
    goto LABEL_9; /*0x18cad6*/
  if ( dword_1E8E08 > 4 ) /*0x18cad8*/
  {
    if ( dword_1E8E08 == 5 ) /*0x18cae7*/
    {
      if ( (unsigned int)(a1 - 4) <= 1 ) /*0x18cb0e*/
        return 1; /*0x18cb0e*/
LABEL_12:
      if ( a1 != 132 ) /*0x18cb16*/
        return a1 == 3; /*0x18cb16*/
      return 1; /*0x18cafc*/
    }
    if ( dword_1E8E08 != 132 ) /*0x18caee*/
      return 0; /*0x18caee*/
LABEL_9:
    if ( a1 == 4 ) /*0x18cb03*/
      return 1; /*0x18cb03*/
    goto LABEL_12; /*0x18cb03*/
  }
  if ( dword_1E8E08 != 3 ) /*0x18cadd*/
    return 0; /*0x18cadd*/
  return a1 == 3; /*0x18cafb*/
}
