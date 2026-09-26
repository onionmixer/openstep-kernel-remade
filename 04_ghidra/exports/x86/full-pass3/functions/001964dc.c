/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001964dc */

int FUN_001964dc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _IOGetObjectForDeviceName(s_PCKeyboard0_001e391d,param_1 + 0x120);
  if (iVar1 == 0) {
    iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x120),PTR_s_becomeOwner__001f9494,param_1);
    if (iVar1 == 0) {
      iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x120),PTR_s_desireOwnership__001f9498,param_1
                           );
      if (iVar1 != 0) {
        uVar2 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar1);
        _IOLog(s_km_init__desireOwnership_failed___001e3971,uVar2);
        param_1 = 0;
      }
    }
    else {
      uVar2 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar1);
      _IOLog(s_km_init__becomeOwner_failed___s__001e394f,uVar2);
      param_1 = 0;
    }
  }
  else {
    uVar2 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar1);
    _IOLog(s_km_init__Can_t_find_PCKeyboard0___001e3929,uVar2);
    param_1 = 0;
  }
  return param_1;
}

