/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a894c */

undefined4 FUN_001a894c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_attachInterruptPort_001f9bd8);
  if (iVar1 == 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s__changeInterrupt_to__001f9bbc,param_3,1);
  }
  else {
    uVar2 = 0xfffffd27;
  }
  return uVar2;
}

