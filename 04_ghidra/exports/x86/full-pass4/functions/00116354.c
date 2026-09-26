/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116354 */

undefined4 _soqremque(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar3 = iVar1;
  while( true ) {
    if (param_2 == 0) {
      iVar2 = *(int *)(iVar3 + 0x14);
    }
    else {
      iVar2 = *(int *)(iVar3 + 0x1c);
    }
    if (iVar2 == param_1) break;
    iVar3 = iVar2;
    if (iVar2 == iVar1) {
      return 0;
    }
  }
  if (param_2 == 0) {
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
    *(short *)(iVar1 + 0x18) = *(short *)(iVar1 + 0x18) + -1;
  }
  else {
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
    *(short *)(iVar1 + 0x20) = *(short *)(iVar1 + 0x20) + -1;
  }
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  return 1;
}

