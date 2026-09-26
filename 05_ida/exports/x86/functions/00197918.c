/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197918. */
void __cdecl -[kmDevice drawGraphicPanel:](kmDevice *self, SEL a2, int a3)
{
  _WORD v3[4]; // [esp+0h] [ebp-Ch] BYREF
  void *v4; // [esp+8h] [ebp-4h]

  if ( self->fbMode == 2 ) /*0x197928*/
  {
    dword_1E8620 = 312; /*0x19792a*/
    v3[2] = 312; /*0x197934*/
    dword_1E8624 = 176; /*0x19793a*/
    v3[3] = 176; /*0x197944*/
    dword_1E8630 = 164; /*0x19794a*/
    v3[0] = 164; /*0x197954*/
    dword_1E8634 = 152; /*0x19795a*/
    v3[1] = 152; /*0x197964*/
    v4 = &NSPanel; /*0x19796a*/
    (*((void (__stdcall **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, _WORD *))self->fbp[0] + 3))(self->fbp[0], v3); /*0x19797f*/
  }
}
