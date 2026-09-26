/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a86a4 */

int FUN_001a86a4(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x110) == 0) {
    iVar2 = _objc_msgSend(param_1,PTR_s_attachInterruptPort_001f9bd8);
    if (iVar2 == 0) {
      uVar1 = _IOForkThread(FUN_001a82e8,param_1);
      *(undefined4 *)(param_1 + 0x110) = uVar1;
      if (-1 < param_3) {
        _IOSetThreadPriority(uVar1,param_3);
      }
    }
  }
  return iVar2;
}

