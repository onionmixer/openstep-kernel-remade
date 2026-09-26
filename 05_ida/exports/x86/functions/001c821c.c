/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c821c. */
id __cdecl -[IOVPCodeDisplay _setDefaultGammaTable:](IOVPCodeDisplay *self, SEL a2, unsigned int *a3)
{
  unsigned int i; // ebx
  unsigned int v5; // ecx
  unsigned int j; // eax
  unsigned int m; // ebx
  unsigned int v8; // ecx
  unsigned int n; // eax
  unsigned int ii; // ebx
  unsigned int v11; // ecx
  unsigned int jj; // eax
  unsigned int k; // ebx
  id result; // eax

  switch ( *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6) ) /*0x1c8244*/
  {
    case 0: /*0x1c8244*/
      for ( i = 0; i <= 3; ++i ) /*0x1c8260*/
      {
        v5 = ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5420[i]) >> 6 << 8) /*0x1c8286*/
           | ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5420[i]) >> 6 << 16)
           | ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5420[i]) >> 6);
        for ( j = 0; j <= 0x3F; ++j ) /*0x1c8288*/
          *a3++ = v5; /*0x1c828c*/
      }
      goto LABEL_19; /*0x1c829b*/
    case 1: /*0x1c8244*/
    case 4: /*0x1c8244*/
      for ( k = 0; k <= 0xFF; ++k ) /*0x1c8324*/
        *a3++ = ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1D637C[k]) >> 6) /*0x1c834c*/
              | ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1D637C[k]) >> 6 << 8)
              | ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1D637C[k]) >> 6 << 16);
      goto LABEL_19; /*0x1c8358*/
    case 2: /*0x1c8244*/
      for ( m = 0; m <= 0xF; ++m ) /*0x1c82a4*/
      {
        v8 = ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5424[m]) >> 6 << 8) /*0x1c82ca*/
           | ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5424[m]) >> 6 << 16)
           | ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5424[m]) >> 6);
        for ( n = 0; n <= 0xF; ++n ) /*0x1c82cc*/
          *a3++ = v8; /*0x1c82d0*/
      }
      goto LABEL_19; /*0x1c82df*/
    case 3: /*0x1c8244*/
      for ( ii = 0; ii <= 0x1F; ++ii ) /*0x1c82e4*/
      {
        v11 = ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5434[ii]) >> 6 << 8) /*0x1c830a*/
            | ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5434[ii]) >> 6 << 16)
            | ((self->brightnessLevel * (unsigned int)(unsigned __int8)byte_1E5434[ii]) >> 6);
        for ( jj = 0; jj <= 7; ++jj ) /*0x1c830c*/
          *a3++ = v11; /*0x1c8310*/
      }
LABEL_19:
      if ( -[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 7, 0) ) /*0x1c8369*/
        goto LABEL_20; /*0x1c8370*/
      result = nullptr; /*0x1c8378*/
      break; /*0x1c8378*/
    default:
LABEL_20:
      result = self; /*0x1c8372*/
      break; /*0x1c8375*/
  }
  return result; /*0x1c837d*/
}
