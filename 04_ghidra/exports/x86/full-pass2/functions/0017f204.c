/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f204 */

int FUN_0017f204(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  int local_c;
  undefined *local_8;
  
  if (param_3 == 0) {
    param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
  }
  else {
    local_c = param_1;
    local_8 = PTR_s_Object_001f9e38;
    _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
    if ((param_5 + param_4 == 0) || (param_4 < param_5 + param_4)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uVar4 = _objc_msgSend(param_3,PTR_s_range_001f9278);
      uVar2 = (uint)uVar4;
      uVar3 = (int)((ulonglong)uVar4 >> 0x20) + uVar2;
      param_4 = param_4 + uVar2;
      if ((param_4 < uVar2) || ((uVar3 != 0 && (uVar3 < param_4 + param_5)))) {
        param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
      }
      else {
        *(int *)(param_1 + 4) = param_3;
        *(uint *)(param_1 + 8) = param_4;
        *(int *)(param_1 + 0xc) = param_5;
        _objc_msgSend(param_3,PTR_s__addMapping_001f927c);
      }
    }
    else {
      param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
    }
  }
  return param_1;
}

