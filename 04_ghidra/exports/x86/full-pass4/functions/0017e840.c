/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e840 */

int FUN_0017e840(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,
                undefined4 param_6)

{
  undefined4 uVar1;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_Object_001f9ed8;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  if ((param_3 < 0x401) && (param_4 < param_4 + param_3)) {
    *(undefined4 *)(param_1 + 4) = param_6;
    if (param_5 == 0) {
      uVar1 = _objc_msgSend(PTR_s_KernBusItem_001f9d6c,PTR_s_class_001f9234);
      *(undefined4 *)(param_1 + 0x10) = uVar1;
    }
    else {
      *(int *)(param_1 + 0x10) = param_5;
    }
    uVar1 = _IOMalloc(param_3 * 4);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    *(undefined4 *)(param_1 + 0x14) = 0;
    _bzero(*(void **)(param_1 + 0x18),param_3 * 4);
    *(uint *)(param_1 + 8) = param_3;
    *(uint *)(param_1 + 0xc) = param_4;
  }
  else {
    param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
  }
  return param_1;
}

