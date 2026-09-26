/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196b74. */
int __cdecl -[kmDevice getScreenSize:](kmDevice *self, SEL a2, ConsoleSize *a3)
{
  $8EF4127CF77ECA3DDB612FCF233DC3A8 *v3; // eax

  v3 = self->fbp[0]; /*0x196b7a*/
  if ( !v3 ) /*0x196b82*/
    return 22; /*0x196b94*/
  (*((void (__stdcall **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, ConsoleSize *))v3 + 6))(v3, a3); /*0x196b8c*/
  return 0; /*0x196b92*/
}
