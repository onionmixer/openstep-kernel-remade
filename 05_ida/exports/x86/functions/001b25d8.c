/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b25d8. */
int __cdecl -[EventDriver pointToScreen:](EventDriver *self, SEL a2, $9B414A52084CF78D000E95AF47DF0AD5 *a3)
{
  char *evScreen; // esi
  int v4; // ebx
  int i; // ecx
  signed __int16 var1; // dx

  evScreen = (char *)self->evScreen; /*0x1b25e4*/
  v4 = self->screens - 1; /*0x1b25f0*/
  if ( !self->screens ) /*0x1b25f1*/
    return -1; /*0x1b2645*/
  for ( i = 20 * v4; ; i -= 20 ) /*0x1b25f9*/
  {
    if ( *(_DWORD *)&evScreen[i] ) /*0x1b2600*/
    {
      if ( a3->var0 >= *(_WORD *)&evScreen[i + 12] && a3->var0 < *(_WORD *)&evScreen[i + 14] ) /*0x1b261c*/
      {
        var1 = a3->var1; /*0x1b261e*/
        if ( var1 >= *(__int16 *)&evScreen[i + 16] && var1 < *(__int16 *)&evScreen[i + 18] ) /*0x1b2634*/
          break; /*0x1b2634*/
      }
    }
    if ( --v4 == -1 ) /*0x1b2643*/
      return -1; /*0x1b2643*/
  }
  return v4; /*0x1b264d*/
}
