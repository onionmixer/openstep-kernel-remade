/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19668c. */
int __cdecl -[kmDevice kmPutc:](kmDevice *self, SEL a2, int a3)
{
  int fbMode; // eax
  $8EF4127CF77ECA3DDB612FCF233DC3A8 *v4; // eax

  fbMode = self->fbMode; /*0x196695*/
  if ( fbMode == 1 ) /*0x19669e*/
  {
    v4 = self->fbp[0]; /*0x1966a8*/
  }
  else
  {
    if ( fbMode != 3 ) /*0x1966a3*/
      return 0; /*0x1966a3*/
    v4 = self->fbp[1]; /*0x1966c0*/
  }
  (*((void (__stdcall **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, _DWORD))v4 + 5))(v4, (char)a3); /*0x1966b6*/
  return 0; /*0x1966bc*/
}
