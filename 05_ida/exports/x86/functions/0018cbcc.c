/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cbcc. */
_BYTE *ldt_init()
{
  _BYTE *v0; // eax
  _BYTE *result; // eax

  v0 = ldt; /*0x18cbcf*/
  *((_WORD *)ldt + 5) = 0; /*0x18cbd4*/
  v0[12] = 0; /*0x18cbda*/
  v0[15] = 0; /*0x18cbde*/
  v0[13] = -6; /*0x18cbe2*/
  v0[14] |= 0xC0u; /*0x18cbe6*/
  *((_WORD *)v0 + 4) = -1; /*0x18cbea*/
  v0[14] = v0[14] & 0xF0 | 0xB; /*0x18cbf9*/
  result = ldt; /*0x18cbfc*/
  *((_WORD *)ldt + 9) = 0; /*0x18cc01*/
  result[20] = 0; /*0x18cc07*/
  result[23] = 0; /*0x18cc0b*/
  result[21] = -14; /*0x18cc0f*/
  result[22] |= 0xC0u; /*0x18cc13*/
  *((_WORD *)result + 8) = -1; /*0x18cc17*/
  result[22] |= 0xFu; /*0x18cc1d*/
  return result; /*0x18cc23*/
}
