
void _kdp_raise_exception(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = _kdp_intr_disbl();
  if (param_4 == 0) {
    _safe_prf(aKdpRaiseExcept);
  }
  if (param_1 != 6) {
    if ((6 < param_1) || (uVar2 = param_1, param_1 == 0)) {
      uVar2 = 0;
    }
    _safe_prf(aSExceptionXXX,*(undefined4 *)(unk_40AF984 + uVar2 * 4),param_1,param_2,param_3);
  }
  _kdp_flush_cache();
  dword_40C25A2 = param_4;
  if (dword_40B3FBA != 0) {
    _kdp_panic(aKdpRaiseExcept_0);
  }
  if (dword_40C259E == 0) {
    sub_405038C();
  }
  else {
    sub_405047C(param_1,param_2,param_3);
  }
  if (dword_40C259E != 0) {
    dword_40C25A6 = 1;
    sub_40502A6(param_4);
    if (dword_40C259E == 0) {
      _safe_prf(aRemoteDebugger);
    }
  }
  _kdp_flush_cache();
  _kdp_intr_enbl(uVar1);
  return;
}

