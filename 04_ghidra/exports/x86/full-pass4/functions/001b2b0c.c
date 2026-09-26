/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2b0c */

int FUN_001b2b0c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = _objc_msgSend(param_3,PTR_s_becomeOwner__001f9494,param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)_IOMalloc(0xc);
    _bzero(puVar2,0xc);
    *puVar2 = param_3;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_lock_001f9220);
    iVar1 = *(int *)(param_1 + 0x178);
    if (param_1 + 0x174 == iVar1) {
      *(undefined4 **)(param_1 + 0x174) = puVar2;
    }
    else {
      *(undefined4 **)(iVar1 + 4) = puVar2;
    }
    puVar2[2] = iVar1;
    puVar2[1] = param_1 + 0x174;
    *(undefined4 **)(param_1 + 0x178) = puVar2;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_unlock_001f9474);
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

