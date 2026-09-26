/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196918. */
int __cdecl -[kmDevice eraseRect:](kmDevice *self, SEL a2, const km_drawrect *a3)
{
  if ( self->fbMode == 3 ) /*0x196925*/
    return 16; /*0x19693c*/
  else
    return (*((int (__stdcall **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, const km_drawrect *))self->fbp[0] + 4))( /*0x196935*/
             self->fbp[0],
             a3);
}
