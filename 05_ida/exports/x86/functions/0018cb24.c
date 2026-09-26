/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cb24. */
int __cdecl grade_cpu_subtype(int a1)
{
  if ( dword_1E8E08 == 4 ) /*0x18cb32*/
  {
    if ( a1 == 4 ) /*0x18cb6b*/
      return 3; /*0x18cb6b*/
    if ( a1 <= 4 ) /*0x18cb6d*/
      return a1 == 3; /*0x18cb72*/
    goto LABEL_15; /*0x18cb6d*/
  }
  if ( dword_1E8E08 > 4 ) /*0x18cb34*/
  {
    if ( dword_1E8E08 != 5 ) /*0x18cb43*/
    {
      if ( dword_1E8E08 != 132 ) /*0x18cb4a*/
        return 0; /*0x18cb4a*/
      if ( a1 != 4 ) /*0x18cb9b*/
      {
        if ( a1 > 4 ) /*0x18cb9d*/
        {
          if ( a1 != 132 ) /*0x18cba5*/
            return 0; /*0x18cba5*/
          return 3; /*0x18cb94*/
        }
        return a1 == 3; /*0x18cb9d*/
      }
      return 2; /*0x18cb88*/
    }
    if ( a1 == 4 ) /*0x18cbaf*/
      return 3; /*0x18cbaf*/
    if ( a1 <= 4 ) /*0x18cbb1*/
      return a1 == 3; /*0x18cbb1*/
    if ( a1 == 5 ) /*0x18cbb6*/
      return 4; /*0x18cbc0*/
LABEL_15:
    if ( a1 != 132 ) /*0x18cb7e*/
      return 0; /*0x18cb7e*/
    return 2; /*0x18cb7e*/
  }
  if ( dword_1E8E08 == 3 ) /*0x18cb39*/
    return a1 == 3; /*0x18cb65*/
  return 0; /*0x18cb5c*/
}
