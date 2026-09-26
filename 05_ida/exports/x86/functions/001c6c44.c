/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6c44. */
id __cdecl -[IOVPCodeDisplay getPixelEncoding](IOVPCodeDisplay *self, SEL a2)
{
  const char *v2; // eax
  const char *v3; // eax
  $514E7C50D28E54AB164B6500F83867A3 *v5; // ebx
  unsigned int var7; // eax
  int var6; // eax
  int j; // eax
  int i; // eax
  const char *v10; // eax
  unsigned int v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  char *var8; // ecx
  int k; // esi
  int m; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  int v20; // [esp-8h] [ebp-34h]
  int v21; // [esp-4h] [ebp-30h]
  int v22; // [esp-4h] [ebp-30h]
  int v23; // [esp-4h] [ebp-30h]
  int v24; // [esp+Ch] [ebp-20h] BYREF
  int v25; // [esp+10h] [ebp-1Ch]
  int v26; // [esp+14h] [ebp-18h]
  int v27; // [esp+18h] [ebp-14h]

  if ( self->_debug )
  {
    v2 = -[IODevice name](self, sel_name); /*0x1c6c64*/
    IOLog((int)"%s: Getting pixel encoding.\n", v2);
  }
  if ( !-[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 6, &v24) )
  {
    v3 = -[IODevice name](self, sel_name); /*0x1c6c9f*/
    IOLog((int)"%s: Can't obtain pixel encoding.\n", v3);
    return nullptr; /*0x1c6cb1*/
  }
  v5 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c6cc8*/
  memset(v5->var8, 0, sizeof(v5->var8)); /*0x1c6cd2*/
  var7 = v5->var7; /*0x1c6cda*/
  if ( var7 <= 1 )
  {
    var6 = v5->var6; /*0x1c6cec*/
    if ( var6 )
    {
      if ( var6 != 1 )
      {
        v21 = v5->var7; /*0x1c6d2f*/
        v20 = v5->var6; /*0x1c6d33*/
        v10 = -[IODevice name](self, sel_name); /*0x1c6d3f*/
        IOLog((int)"%s: invalid `bitsPerPixel' (%d) for color space %d.\n", v10, v20, v21);
        return nullptr; /*0x1c6d54*/
      }
      for ( i = 0; i <= 7; ++i ) /*0x1c6d14*/
        v5->var8[i] = v24; /*0x1c6d1b*/
    }
    else
    {
      for ( j = 0; j <= 1; ++j ) /*0x1c6cfc*/
        v5->var8[j] = v24; /*0x1c6d03*/
    }
    goto LABEL_41; /*0x1c6d23*/
  }
  if ( var7 != 2 )
  {
    v23 = v5->var7; /*0x1c6e67*/
    v18 = -[IODevice name](self, sel_name); /*0x1c6e73*/
    IOLog((int)"%s: Sorry, color space %d is not supported.\n", v18, v23);
    return nullptr; /*0x1c6e88*/
  }
  v11 = v5->var6; /*0x1c6d5c*/
  if ( v11 == 3 )
  {
    if ( v24 != 45 || v25 != 82 || v26 != 71 || v27 != 66 )
    {
      v13 = -[IODevice name](self, sel_name); /*0x1c6df3*/
      IOLog((int)"%s: Sorry, only `-RRRRRGGGGGBBBBB' supported for `IO_15BitsPerPixel'.\n", v13);
      return nullptr; /*0x1c6e05*/
    }
    strcpy(v5->var8, "-RRRRRGGGGGBBBBB"); /*0x1c6e17*/
  }
  else
  {
    if ( v11 > 3 )
    {
      if ( v11 == 4 ) /*0x1c6d73*/
      {
        var8 = v5->var8; /*0x1c6e1c*/
        for ( k = 0; k <= 3; ++k ) /*0x1c6e1e*/
        {
          for ( m = 7; m >= 0; --m ) /*0x1c6e20*/
            *var8++ = *((_BYTE *)&v24 + 4 * k); /*0x1c6e2c*/
        }
        goto LABEL_41; /*0x1c6e36*/
      }
    }
    else if ( v11 == 2 )
    {
      if ( v24 != 82 || v25 != 71 || v26 != 66 || v27 != 45 )
      {
        v12 = -[IODevice name](self, sel_name); /*0x1c6da3*/
        IOLog((int)"%s: Sorry, only `RRRRGGGGBBBB----' supported for `IO_12BitsPerPixel'.\n", v12);
        return nullptr; /*0x1c6db5*/
      }
      strcpy(v5->var8, "RRRRGGGGBBBB----"); /*0x1c6dc7*/
      goto LABEL_41; /*0x1c6dca*/
    }
    v22 = v5->var6; /*0x1c6e3f*/
    v17 = -[IODevice name](self, sel_name); /*0x1c6e4b*/
    IOLog((int)"%s: invalid `bitsPerPixel' (%d) for RGB color space.\n", v17, v22);
  }
LABEL_41:
  if ( self->_debug )
  {
    v19 = -[IODevice name](self, sel_name); /*0x1c6ea7*/
    IOLog((int)"%s: pixelEncoding = `%s'.\n", v19, v5->var8);
  }
  return self; /*0x1c6ec0*/
}
