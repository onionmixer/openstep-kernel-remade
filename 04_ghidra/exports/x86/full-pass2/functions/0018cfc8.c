/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cfc8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _md_do_shutdown(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  
  __rebootflag = 1;
  if ((param_2 & 8) != 0) {
    switch(_glLanguage) {
    default:
      pcVar3 = s_It_s_safe_to_turn_off_the_comput_001e22d8;
      break;
    case 1:
      pcVar3 = s_Vous_pouvez_maintenant_eteindre_v_001e22fd;
      break;
    case 2:
      pcVar3 = s_Jetzt_koennen_Sie_Ihren_Computer_001e2342;
      break;
    case 3:
      pcVar3 = s_Ahora_es_seguro_apagar_el_ordena_001e2378;
      break;
    case 4:
      pcVar3 = s_Ora_puoi_spegnere_il_computer__001e239e;
      break;
    case 5:
      pcVar3 = s_Nu_ar_det_sakert_att_stanga_av_d_001e23be;
    }
    FUN_0018cf54(pcVar3);
    _kmDisableAnimation();
    iVar2 = 0;
    do {
      out(0xcaf - (short)iVar2,(&DAT_001e23e6)[iVar2]);
      LOCK();
      _DAT_001e7730 = _DAT_001e7730 + 1;
      UNLOCK();
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    _intr_disbl();
    DAT_001e8e0c = 0;
    if ((param_2 & 0x10000) != 0) {
      _PMSetPowerState(1,3);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_1 == 0) {
    switch(_glLanguage) {
    default:
      pcVar3 = s_It_s_safe_to_turn_off_the_comput_001e22d8;
      break;
    case 1:
      pcVar3 = s_Vous_pouvez_maintenant_eteindre_v_001e22fd;
      break;
    case 2:
      pcVar3 = s_Jetzt_koennen_Sie_Ihren_Computer_001e2342;
      break;
    case 3:
      pcVar3 = s_Ahora_es_seguro_apagar_el_ordena_001e2378;
      break;
    case 4:
      pcVar3 = s_Ora_puoi_spegnere_il_computer__001e239e;
      break;
    case 5:
      pcVar3 = s_Nu_ar_det_sakert_att_stanga_av_d_001e23be;
    }
    FUN_0018cf54(pcVar3);
    _kmDisableAnimation();
    iVar2 = 0;
    do {
      out(0xcaf - (short)iVar2,(&DAT_001e23e6)[iVar2]);
      LOCK();
      _DAT_001e7730 = _DAT_001e7730 + 1;
      UNLOCK();
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    _intr_disbl();
    DAT_001e8e0c = 0;
    if ((param_2 & 0x10000) != 0) {
      _PMSetPowerState(1,3);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 & 0x400000) == 0) {
    if ((param_2 & 0x800000) == 0) goto LAB_0018d1bd;
    out(0x70,6);
    LOCK();
    UNLOCK();
    bVar1 = in(0x71);
    bVar1 = bVar1 | 0x20;
  }
  else {
    out(0x70,6);
    LOCK();
    UNLOCK();
    bVar1 = in(0x71);
    bVar1 = bVar1 | 0x10;
  }
  out(0x70,6);
  LOCK();
  UNLOCK();
  out(0x71,bVar1);
  LOCK();
  _DAT_001e7730 = _DAT_001e7730 + 3;
  UNLOCK();
LAB_0018d1bd:
  _intr_disbl();
  _keyboard_reboot();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

