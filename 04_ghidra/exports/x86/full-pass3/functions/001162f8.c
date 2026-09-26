/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001162f8 */

void _soqinsque(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_2 + 0x10) = param_1;
  if (param_3 == 0) {
    *(short *)(param_1 + 0x18) = *(short *)(param_1 + 0x18) + 1;
    iVar1 = *(int *)(param_1 + 0x14);
    iVar2 = param_1;
    while (iVar1 != param_1) {
      iVar2 = *(int *)(iVar2 + 0x14);
      iVar1 = *(int *)(iVar2 + 0x14);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
    *(int *)(iVar2 + 0x14) = param_2;
  }
  else {
    *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + 1;
    iVar1 = *(int *)(param_1 + 0x1c);
    iVar2 = param_1;
    while (iVar1 != param_1) {
      iVar2 = *(int *)(iVar2 + 0x1c);
      iVar1 = *(int *)(iVar2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
    *(int *)(iVar2 + 0x1c) = param_2;
  }
  return;
}

