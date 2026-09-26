/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c7f58. */
void __cdecl -[IOVPCodeDisplay enterLinearMode](IOVPCodeDisplay *self, SEL a2)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  $514E7C50D28E54AB164B6500F83867A3 *v5; // eax
  unsigned int videoRamAddress; // [esp-4h] [ebp-28h]
  _DWORD v7[8]; // [esp+4h] [ebp-20h] BYREF

  if ( self->_debug )
  {
    v2 = -[IODevice name](self, sel_name); /*0x1c7f73*/
    IOLog((int)"%s: Initializing video mode.\n", v2);
  }
  if ( -[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 1, 0) )
  {
    -[IOVPCodeDisplay setGammaTable](self, sel_setGammaTable); /*0x1c7fc4*/
    if ( self->_debug )
    {
      videoRamAddress = self->_videoRamAddress; /*0x1c7fdb*/
      v4 = -[IODevice name](self, sel_name); /*0x1c7fe4*/
      IOLog((int)"%s: Enabling linear framebuffer: 0x%08x\n", v4, videoRamAddress);
    }
    v7[0] = self->_videoRamAddress; /*0x1c8000*/
    v7[1] = self->_videoRamSize; /*0x1c8009*/
    if ( -[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 2, v7) ) /*0x1c801a*/
    {
      v5 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c802e*/
      memset(v5->var5, 0, v5->var1 * v5->var3); /*0x1c8043*/
    }
  }
  else
  {
    v3 = -[IODevice name](self, sel_name); /*0x1c7fa6*/
    IOLog((int)"%s: Failed to initialize mode.\n", v3);
  }
}
