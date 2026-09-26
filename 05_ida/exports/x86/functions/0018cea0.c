/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cea0. */
void __cdecl __noreturn halt_cpu(int a1)
{
  int i; // esi

  switch ( glLanguage ) /*0x18ceb3*/
  {
    case 1: /*0x18ceb3*/
      sub_18CF54(aVousPouvezMain); /*0x18cee1*/
      break; /*0x18cee1*/
    case 2: /*0x18ceb3*/
      sub_18CF54(aJetztKoennenSi); /*0x18cee9*/
      break; /*0x18cee9*/
    case 3: /*0x18ceb3*/
      sub_18CF54(aAhoraEsSeguroA); /*0x18cef1*/
      break; /*0x18cef1*/
    case 4: /*0x18ceb3*/
      sub_18CF54(aOraPuoiSpegner); /*0x18cef9*/
      break; /*0x18cef9*/
    case 5: /*0x18ceb3*/
      sub_18CF54(aNuArDetSakertA); /*0x18cf01*/
      break; /*0x18cf01*/
    default:
      sub_18CF54(aItSSafeToTurnO); /*0x18ced9*/
      break; /*0x18ced9*/
  }
  kmDisableAnimation(); /*0x18cf09*/
  for ( i = 0; i <= 3; ++i ) /*0x18cf0e*/
  {
    __outbyte(3247 - i, byte_1E23E6[i]); /*0x18cf20*/
    _InterlockedIncrement(dword_1E7730); /*0x18cf21*/
  }
  intr_disbl(); /*0x18cf2e*/
  dword_1E8E0C[0] = 0; /*0x18cf33*/
  if ( (a1 & 0x10000) != 0 ) /*0x18cf43*/
    PMSetPowerState(a1, 1u, 3); /*0x18cf49*/
  __halt(); /*0x18cf50*/
}
