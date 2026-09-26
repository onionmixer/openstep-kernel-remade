/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a86fc */

int FUN_001a86fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x110) == 0) {
    iVar1 = _objc_msgSend(param_1,PTR_s_startIOThreadWithPriority__001f9bd4,param_3);
    if (iVar1 == 0) {
      _IOSetThreadPolicy(*(undefined4 *)(param_1 + 0x110),2);
    }
  }
  return iVar1;
}

