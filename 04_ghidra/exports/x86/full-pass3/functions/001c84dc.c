/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c84dc */

int FUN_001c84dc(int param_1,undefined4 param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_24 [32];
  
  if ((*(int *)(param_1 + 0x23c) == 0) || (*(uint *)(param_1 + 0x240) == 0)) {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: No vpcode to run.\n",uVar2);
    param_1 = 0;
  }
  else if (param_3 < *(uint *)(param_1 + 0x240)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x23c) + param_3 * 4);
    if (iVar1 != 0) {
      if (*(char *)(param_1 + 0x250) != '\0') {
        uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar1);
        _IOLog("%s: Running vpcode at 0x%x\n",uVar2);
      }
      if (param_4 == (undefined1 *)0x0) {
        param_4 = local_24;
        _memset(param_4,0,0x20);
      }
      param_1 = _objc_msgSend(param_1,PTR_s_jumpTo_withInitialSRegs__001f9578,
                              *(undefined4 *)(*(int *)(param_1 + 0x23c) + param_3 * 4),param_4);
    }
  }
  else {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
    _IOLog("%s: entry point is out of range: 0x%x.\n",uVar2);
    param_1 = 0;
  }
  return param_1;
}

