/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ef70. */
$85CD2974BE96D4886BB301820D1C36C2 __cdecl -[KernBusRangeResource findFreeRangeWithSize:alignment:](
        KernBusRangeResource *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned int base; // eax
  unsigned int v5; // esi
  $85CD2974BE96D4886BB301820D1C36C2 v6; // rcx
  char *v7; // edx
  void **p_ranges; // [esp+14h] [ebp-4h]

  p_ranges = &self->_ranges; /*0x17ef7f*/
  base = self->_base; /*0x17ef82*/
  v5 = a3 + base; /*0x17ef87*/
  v6 = 0; /*0x17ef8c*/
  if ( base < self->_end ) /*0x17ef93*/
  {
    while ( 1 ) /*0x17efa3*/
    {
      v7 = (char *)*p_ranges; /*0x17efa3*/
      if ( !*p_ranges || *((_DWORD *)v7 + 3) >= v5 ) /*0x17efac*/
        break; /*0x17efac*/
      if ( *((_DWORD *)v7 + 4) > base ) /*0x17efbb*/
      {
LABEL_7:
        if ( v6.var1 ) /*0x17efca*/
          return v6; /*0x17efca*/
        base += a4; /*0x17efcc*/
        v5 += a4; /*0x17efcf*/
        if ( self->_end <= base ) /*0x17efd5*/
          return v6; /*0x17efd5*/
      }
      else
      {
        p_ranges = (void **)(v7 + 4); /*0x17efc0*/
      }
    }
    v6.var0 = base; /*0x17efae*/
    v6.var1 = v5 - base; /*0x17efb0*/
    goto LABEL_7; /*0x17efb3*/
  }
  return v6; /*0x17efde*/
}
