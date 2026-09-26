/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ec84 */

int FUN_0017ec84(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5,
                undefined4 param_6)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  int local_c;
  undefined *local_8;
  
  uVar1 = param_4 + param_3;
  local_c = param_1;
  local_8 = PTR_s_Object_001f9e88;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  if ((uVar1 == 0) || (param_3 < uVar1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    *(undefined4 *)(param_1 + 4) = param_6;
    if (param_5 == 0) {
      uVar3 = _objc_msgSend(PTR_s_KernBusRange_001f9d70,PTR_s_class_001f9234);
      *(undefined4 *)(param_1 + 0x10) = uVar3;
    }
    else {
      *(int *)(param_1 + 0x10) = param_5;
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(uint *)(param_1 + 0xc) = uVar1;
    *(uint *)(param_1 + 8) = param_3;
  }
  else {
    param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
  }
  return param_1;
}

