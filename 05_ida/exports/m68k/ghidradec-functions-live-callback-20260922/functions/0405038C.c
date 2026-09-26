
void sub_405038C(void)

{
  int iVar1;
  undefined *puVar2;
  undefined2 uStack_e;
  char cStack_c;
  char cStack_b;
  
  _safe_prf(aWaitingForRemo);
  _safe_prf(aTypeCToContinu);
  byte_40B39C6 = '\0';
  do {
    while (dword_40B3FBA == 0) {
      iVar1 = _kmtrygetc();
      if (iVar1 == 99) {
        puVar2 = aContinuing_0;
        goto loc_405046C;
      }
      if (iVar1 == 0x72) {
        _safe_prf(aRebooting_0);
        _kdp_reboot();
      }
      sub_4050186();
    }
    _bcopy(unk_40B39C8 + dword_40B3FB2,&cStack_c,8);
    if (((cStack_c == '\0') && (cStack_b == byte_40B39C6)) &&
       (iVar1 = _kdp_packet(unk_40B39C8 + dword_40B3FB2,&unk_40B3FB6,&uStack_e), iVar1 != 0)) {
      sub_404FD9A(uStack_e);
    }
    dword_40B3FBA = 0;
  } while (dword_40C259E == 0);
  puVar2 = aConnectedToRem;
loc_405046C:
  _safe_prf(puVar2);
  return;
}

