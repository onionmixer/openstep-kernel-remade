/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cea0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _halt_cpu(uint param_1)

{
  int iVar1;
  char *pcVar2;
  
  switch(_glLanguage) {
  default:
    pcVar2 = s_It_s_safe_to_turn_off_the_comput_001e22d8;
    break;
  case 1:
    pcVar2 = s_Vous_pouvez_maintenant_eteindre_v_001e22fd;
    break;
  case 2:
    pcVar2 = s_Jetzt_koennen_Sie_Ihren_Computer_001e2342;
    break;
  case 3:
    pcVar2 = s_Ahora_es_seguro_apagar_el_ordena_001e2378;
    break;
  case 4:
    pcVar2 = s_Ora_puoi_spegnere_il_computer__001e239e;
    break;
  case 5:
    pcVar2 = s_Nu_ar_det_sakert_att_stanga_av_d_001e23be;
  }
  FUN_0018cf54(pcVar2);
  _kmDisableAnimation();
  iVar1 = 0;
  do {
    out(0xcaf - (short)iVar1,(&DAT_001e23e6)[iVar1]);
    LOCK();
    _DAT_001e7730 = _DAT_001e7730 + 1;
    UNLOCK();
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  _intr_disbl();
  DAT_001e8e0c = 0;
  if ((param_1 & 0x10000) != 0) {
    _PMSetPowerState(1,3);
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

