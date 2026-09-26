/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1d90 */

void FUN_001b1d90(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((undefined4 *)param_3[2] != (undefined4 *)0x0) {
    *(undefined4 *)param_3[2] = 0;
  }
  iVar1 = *param_3;
  if (iVar1 != 1) {
    if (iVar1 == 0) {
      _objc_msgSend(param_3[1],PTR_s_unlockWith__001f9224,2);
      _IOExitThread();
    }
    else if (iVar1 != 2) {
      _IOPanic("EventDriver: Bogus opBuf.op");
      goto LAB_001b1dfd;
    }
    uVar2 = _objc_msgSend(param_1,PTR_s__doPerformInIOThread__001f99bc,param_3 + 3);
    if ((undefined4 *)param_3[2] != (undefined4 *)0x0) {
      *(undefined4 *)param_3[2] = uVar2;
    }
  }
LAB_001b1dfd:
  if (param_3[1] != 0) {
    _objc_msgSend(param_3[1],PTR_s_unlockWith__001f9224,2);
  }
  return;
}

