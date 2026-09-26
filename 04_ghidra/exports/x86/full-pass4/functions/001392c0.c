/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001392c0 */

void FUN_001392c0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x38) + 0x1c) + 0x14))
                    (*(int *)(iVar1 + 0x38),param_2,param_3);
  if (iVar2 == 0) {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar1 + 0x4c);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar1 + 0x50);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(iVar1 + 0x54);
    *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(iVar1 + 0x58);
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(iVar1 + 0x5c);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(iVar1 + 0x60);
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x7c);
    *(undefined4 *)(param_2 + 0x1c) = _fifoinfo;
  }
  return;
}

