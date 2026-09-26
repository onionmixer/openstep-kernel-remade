/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c50fc. */
char __cdecl -[IOFrameBufferDisplay setPendingDisplayMode:](IOFrameBufferDisplay *self, SEL a2, int a3)
{
  $514E7C50D28E54AB164B6500F83867A3 *v3; // edi
  const char *v4; // eax
  const char *v6; // eax
  unsigned int var17; // [esp-4h] [ebp-10h]

  v3 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c5115*/
  if ( a3 >= 0 && a3 < -[IOFrameBufferDisplay displayModeCount](self, sel_displayModeCount) )
  {
    if ( v3->var17 )
    {
      var17 = v3->var17; /*0x1c515e*/
      v6 = -[IODevice name](self, sel_name); /*0x1c5168*/
      IOLog((int)"%s: Display mode %d not available (error 0x%0x)\n", v6, a3, var17);
      return 0; /*0x1c517b*/
    }
    else
    {
      self->_pendingDisplayMode = a3; /*0x1c5180*/
      return 1; /*0x1c5186*/
    }
  }
  else
  {
    v4 = -[IODevice name](self, sel_name); /*0x1c513b*/
    IOLog((int)"%s: Invalid display mode: %d\n", v4, a3);
    return 0; /*0x1c514e*/
  }
}
