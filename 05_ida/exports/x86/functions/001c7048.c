/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c7048. */
id __cdecl -[IOVPCodeDisplay setGammaTable](IOVPCodeDisplay *self, SEL a2)
{
  const char *v2; // eax
  unsigned int *vpCode; // edx
  unsigned int vpCodeCount; // ecx
  const char *v5; // eax
  unsigned int v6; // edx
  const char *v7; // eax
  const char *v8; // eax
  unsigned int v10; // edi
  int transferTableCount; // ecx
  unsigned int v12; // esi
  unsigned int i; // eax
  const char *v14; // eax
  unsigned int j; // edi
  const char *v16; // eax
  unsigned int k; // esi
  unsigned int v18; // [esp-4h] [ebp-34h]
  int v19; // [esp-4h] [ebp-34h]
  unsigned int *v20; // [esp+28h] [ebp-8h]
  unsigned int *v21; // [esp+28h] [ebp-8h]
  unsigned int v22; // [esp+2Ch] [ebp-4h]

  if ( self->_debug )
  {
    v2 = -[IODevice name](self, sel_name); /*0x1c7065*/
    IOLog((int)"%s: setting transfer table.\n", v2);
  }
  vpCode = self->_vpCode; /*0x1c707d*/
  if ( vpCode && (vpCodeCount = self->_vpCodeCount, vpCodeCount > 8) )
  {
    v6 = vpCode[8]; /*0x1c70b8*/
    v22 = v6; /*0x1c70bb*/
    if ( v6 < vpCodeCount )
    {
      if ( !v6 ) /*0x1c70ec*/
        return self; /*0x1c70ec*/
      if ( self->_debug )
      {
        v8 = -[IODevice name](self, sel_name); /*0x1c710d*/
        IOLog((int)"%s: using transfer table at 0x%08x.\n", v8, v22);
      }
      v20 = &self->_vpCode[v22]; /*0x1c7134*/
      if ( !self->redTransferTable ) /*0x1c713a*/
        return -[IOVPCodeDisplay _setDefaultGammaTable:](self, sel__setDefaultGammaTable_, &self->_vpCode[v22]); /*0x1c7152*/
      v10 = 0; /*0x1c7158*/
      transferTableCount = self->transferTableCount; /*0x1c715d*/
      if ( transferTableCount ) /*0x1c7165*/
      {
        do /*0x1c71f9*/
        {
          v12 = 0; /*0x1c716c*/
          for ( i = 256 / transferTableCount; v12 < i; i = 256 / self->transferTableCount ) /*0x1c7176*/
          {
            *v20++ = ((self->brightnessLevel * (unsigned int)(unsigned __int8)self->blueTransferTable[v10]) >> 6) /*0x1c71cf*/
                   | ((self->brightnessLevel * (unsigned int)(unsigned __int8)self->greenTransferTable[v10]) >> 6 << 8)
                   | ((self->brightnessLevel * (unsigned int)(unsigned __int8)self->redTransferTable[v10]) >> 6 << 16);
            ++v12; /*0x1c71d7*/
          }
          ++v10; /*0x1c71ed*/
          transferTableCount = self->transferTableCount; /*0x1c71f1*/
        }
        while ( v10 < transferTableCount ); /*0x1c71f9*/
      }
      if ( self->_debug )
      {
        v21 = &self->_vpCode[v22]; /*0x1c721b*/
        v14 = -[IODevice name](self, sel_name); /*0x1c7228*/
        IOLog((int)"%s: Transfer table:\n", v14);
        for ( j = 0; j <= 0x3F; ++j )
        {
          v16 = -[IODevice name](self, sel_name); /*0x1c724a*/
          IOLog((int)"%s: ", v16);
          for ( k = 0; k <= 3; ++k ) /*0x1c725c*/
          {
            v19 = *v21++; /*0x1c7269*/
            IOLog((int)"%08x ", v19); /*0x1c7273*/
          }
          IOLog((int)"\n"); /*0x1c7286*/
        }
      }
      if ( -[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 7, 0) ) /*0x1c72a3*/
        return self; /*0x1c72b1*/
    }
    else
    {
      v18 = v6; /*0x1c70c2*/
      v7 = -[IODevice name](self, sel_name); /*0x1c70ce*/
      IOLog((int)"%s: transfer table address is out of range: 0x%x.\n", v7, v18);
    }
  }
  else
  {
    v5 = -[IODevice name](self, sel_name); /*0x1c70a1*/
    IOLog((int)"%s: Can't set transfer table: no vpcode present.\n", v5);
  }
  return nullptr; /*0x1c72b9*/
}
