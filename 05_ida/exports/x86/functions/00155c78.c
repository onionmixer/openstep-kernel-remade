/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155c78. */
int __cdecl convert_port_type(int a1)
{
  int *v1; // eax

  v1 = (int *)(a1 & 0x1F0000); /*0x155c7e*/
  if ( (a1 & 0x1F0000) == 0x30000 ) /*0x155c88*/
    return 7; /*0x155cc8*/
  if ( (a1 & 0x1F0000u) <= 0x30000 ) /*0x155c8a*/
  {
    if ( v1 != (int *)0x10000 ) /*0x155c91*/
    {
      if ( v1 != (int *)0x20000 ) /*0x155c98*/
        goto LABEL_14; /*0x155c98*/
      return 7; /*0x155c98*/
    }
    return 1; /*0x155cbf*/
  }
  if ( v1 != (int *)0x80000 ) /*0x155ca1*/
  {
    if ( (unsigned int)v1 > 0x80000 ) /*0x155ca3*/
    {
      if ( v1 != &dword_100000 ) /*0x155cb5*/
        goto LABEL_14; /*0x155cb5*/
    }
    else if ( v1 != (int *)0x40000 ) /*0x155caa*/
    {
LABEL_14:
      panic(aConvertPortTyp); /*0x155cd8*/
    }
    return 1; /*0x155caa*/
  }
  return 9; /*0x155cbe*/
}
