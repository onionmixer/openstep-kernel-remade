/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6ec8. */
id __cdecl -[IOVPCodeDisplay getDisplayInfo](IOVPCodeDisplay *self, SEL a2)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  $514E7C50D28E54AB164B6500F83867A3 *v5; // eax
  const char *v6; // eax
  const char *v8; // [esp-Ch] [ebp-30h]
  const char *v9; // [esp-Ch] [ebp-30h]
  const char *v10; // [esp-Ch] [ebp-30h]
  _DWORD v11[8]; // [esp+4h] [ebp-20h] BYREF

  if ( self->_debug )
  {
    v2 = -[IODevice name](self, sel_name); /*0x1c6ee3*/
    IOLog((int)"%s: verifying selected mode.\n", v2);
  }
  if ( -[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 0, v11) )
  {
    if ( !v11[0]
      || (v3 = -[IODevice name](self, sel_name),
          IOLog((int)"%s: Selected mode is invalid.\n", v3),
          -[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 4, 0)) )
    {
      if ( self->_debug )
      {
        v4 = -[IODevice name](self, sel_name); /*0x1c6f89*/
        IOLog((int)"%s: Getting display info.\n", v4);
      }
      if ( -[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 5, v11) )
      {
        v5 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c6fbe*/
        v5->var0 = v11[0]; /*0x1c6fc6*/
        v5->var1 = v11[1]; /*0x1c6fcb*/
        v5->var2 = v11[2]; /*0x1c6fd1*/
        v5->var3 = v11[3]; /*0x1c6fd7*/
        v5->var4 = v11[4]; /*0x1c6fdd*/
        v5->var6 = v11[5]; /*0x1c6fe3*/
        v5->var7 = v11[6]; /*0x1c6fe9*/
        v5->var9 = v11[7]; /*0x1c6fef*/
        if ( -[IOVPCodeDisplay getPixelEncoding](self, sel_getPixelEncoding) )
        {
          v6 = -[IODevice name](self, sel_name); /*0x1c700e*/
          IOLog((int)"%s: IOVPCodeDisplay: Initialized.\n", v6);
          return self; /*0x1c7020*/
        }
      }
      else
      {
        v10 = -[IODevice name](self, sel_name); /*0x1c7031*/
        IOLog((int)"%s: Failed to obtain display info.\n", v10);
      }
    }
    else
    {
      v9 = -[IODevice name](self, sel_name); /*0x1c6f6b*/
      IOLog((int)"%s: Failed to set default mode.\n", v9);
    }
  }
  else
  {
    v8 = -[IODevice name](self, sel_name); /*0x1c6f1d*/
    IOLog((int)"%s: Failed to verify mode.\n", v8);
  }
  return nullptr; /*0x1c703e*/
}
