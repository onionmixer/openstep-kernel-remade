/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cfc8. */
void __cdecl __noreturn md_do_shutdown(int a1, int a2)
{
  int i; // esi
  int j; // esi
  unsigned __int8 v4; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al

  rebootflag = 1; /*0x18cfd3*/
  if ( (a2 & 8) != 0 ) /*0x18cfe0*/
  {
    switch ( glLanguage ) /*0x18cff1*/
    {
      case 1: /*0x18cff1*/
        sub_18CF54(aVousPouvezMain); /*0x18d01d*/
        break; /*0x18d01d*/
      case 2: /*0x18cff1*/
        sub_18CF54(aJetztKoennenSi); /*0x18d025*/
        break; /*0x18d025*/
      case 3: /*0x18cff1*/
        sub_18CF54(aAhoraEsSeguroA); /*0x18d02d*/
        break; /*0x18d02d*/
      case 4: /*0x18cff1*/
        sub_18CF54(aOraPuoiSpegner); /*0x18d035*/
        break; /*0x18d035*/
      case 5: /*0x18cff1*/
        sub_18CF54(aNuArDetSakertA); /*0x18d03d*/
        break; /*0x18d03d*/
      default:
        sub_18CF54(aItSSafeToTurnO); /*0x18d015*/
        break; /*0x18d015*/
    }
    kmDisableAnimation(); /*0x18d045*/
    for ( i = 0; i <= 3; ++i ) /*0x18d04a*/
    {
      __outbyte(3247 - i, byte_1E23E6[i]); /*0x18d05c*/
      _InterlockedIncrement(dword_1E7730); /*0x18d05d*/
    }
    intr_disbl(); /*0x18d06a*/
    dword_1E8E0C[0] = 0; /*0x18d06f*/
    if ( (a2 & 0x10000) != 0 ) /*0x18d07f*/
      PMSetPowerState(a2, 1u, 3); /*0x18d085*/
    __halt(); /*0x18d08c*/
  }
  if ( !a1 ) /*0x18d094*/
  {
    switch ( glLanguage ) /*0x18d0a5*/
    {
      case 1: /*0x18d0a5*/
        sub_18CF54(aVousPouvezMain); /*0x18d0d1*/
        break; /*0x18d0d1*/
      case 2: /*0x18d0a5*/
        sub_18CF54(aJetztKoennenSi); /*0x18d0d9*/
        break; /*0x18d0d9*/
      case 3: /*0x18d0a5*/
        sub_18CF54(aAhoraEsSeguroA); /*0x18d0e1*/
        break; /*0x18d0e1*/
      case 4: /*0x18d0a5*/
        sub_18CF54(aOraPuoiSpegner); /*0x18d0e9*/
        break; /*0x18d0e9*/
      case 5: /*0x18d0a5*/
        sub_18CF54(aNuArDetSakertA); /*0x18d0f1*/
        break; /*0x18d0f1*/
      default:
        sub_18CF54(aItSSafeToTurnO); /*0x18d0c9*/
        break; /*0x18d0c9*/
    }
    kmDisableAnimation(); /*0x18d0f9*/
    for ( j = 0; j <= 3; ++j ) /*0x18d0fe*/
    {
      __outbyte(3247 - j, byte_1E23E6[j]); /*0x18d110*/
      _InterlockedIncrement(dword_1E7730); /*0x18d111*/
    }
    intr_disbl(); /*0x18d11e*/
    dword_1E8E0C[0] = 0; /*0x18d123*/
    if ( (a2 & 0x10000) != 0 ) /*0x18d133*/
      PMSetPowerState(a2, 1u, 3); /*0x18d139*/
    __halt(); /*0x18d140*/
  }
  if ( (a2 & 0x400000) != 0 ) /*0x18d14a*/
  {
    __outbyte(0x70u, 6u); /*0x18d153*/
    _InterlockedIncrement(dword_1E7730); /*0x18d154*/
    v4 = __inbyte(0x71u); /*0x18d160*/
    v5 = v4 | 0x10; /*0x18d16b*/
  }
  else
  {
    if ( (a2 & 0x800000) == 0 ) /*0x18d176*/
      goto LABEL_32; /*0x18d176*/
    __outbyte(0x70u, 6u); /*0x18d17f*/
    _InterlockedIncrement(dword_1E7730); /*0x18d180*/
    v6 = __inbyte(0x71u); /*0x18d18c*/
    v5 = v6 | 0x20; /*0x18d197*/
  }
  __outbyte(0x70u, 6u); /*0x18d1a3*/
  _InterlockedIncrement(dword_1E7730); /*0x18d1a4*/
  __outbyte(0x71u, v5); /*0x18d1b5*/
  _InterlockedIncrement(dword_1E7730); /*0x18d1b6*/
LABEL_32:
  intr_disbl(); /*0x18d1bd*/
  keyboard_reboot(); /*0x18d1c2*/
  __halt(); /*0x18d1c8*/
}
