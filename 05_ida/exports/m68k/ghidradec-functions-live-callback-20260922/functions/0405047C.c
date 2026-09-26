
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_405047C(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  undefined2 uStack_6;
  
  iVar2 = 300;
  do {
    dword_40B3FB2 = 0x2a;
    _kdp_exception(unk_40B39F2,&unk_40B3FB6,&uStack_6,param_1,param_2,param_3);
    sub_404FFA6(uStack_6);
    sub_4050186();
    if (dword_40B3FBA != 0) {
      _kdp_exception_ack(unk_40B39C8 + dword_40B3FB2,_unk_40B3FB6);
    }
    dword_40B3FBA = 0;
    if (dword_40C25AE == 0) {
      dword_40B3FBA = 0;
      return;
    }
    _kdp_us_spin(100000);
    if (dword_40C25AE == 0) {
      return;
    }
    wVar1 = (word)((uint)iVar2 >> 0x10);
    sVar3 = (sword)iVar2 + -1;
    iVar2 = CONCAT22(wVar1,sVar3);
  } while ((sVar3 != -1) || (iVar2 = (uint)wVar1 * 0x10000 + -1, wVar1 != 0));
  if (dword_40C25AE != 0) {
    _safe_prf(aKdpExceptionAc);
    _kdp_reset();
  }
  return;
}

