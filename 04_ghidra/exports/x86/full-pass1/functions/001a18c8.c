/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a18c8 */

undefined4 _PCbopFA(undefined4 param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((*(byte *)(param_3 + 1) & 4) == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(param_2 + 0x38) = *param_3;
    *(undefined2 *)(param_2 + 0x3c) = *(undefined2 *)(param_3 + 1);
    uVar1 = param_3[2];
    *(uint *)(param_2 + 0x40) = uVar1;
    *(uint *)(param_2 + 0x40) = uVar1 & 0x50fd7 | 0x202;
    *(undefined4 *)(param_2 + 0x44) = param_3[3];
    *(undefined2 *)(param_2 + 0x48) = *(undefined2 *)(param_3 + 4);
    uVar2 = _thread_exception_return();
  }
  return uVar2;
}

