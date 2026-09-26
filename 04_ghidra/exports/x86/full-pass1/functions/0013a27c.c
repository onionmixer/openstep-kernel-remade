/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a27c */

int _spec_setattr(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(iVar1 + 0x38);
  if (iVar2 != 0) {
    *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))(iVar2,param_2,param_3);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  cVar3 = *(int *)(param_2 + 0x28) != -1;
  if ((bool)cVar3) {
    *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(param_2 + 0x2c);
  }
  if (*(int *)(param_2 + 0x20) != -1) {
    *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(param_2 + 0x20);
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(param_2 + 0x24);
    cVar3 = cVar3 + '\x01';
  }
  if (cVar3 != '\0') {
    _getthetime(&local_c);
    *(undefined4 *)(iVar1 + 0x5c) = local_c;
    *(undefined4 *)(iVar1 + 0x60) = local_8;
  }
  return 0;
}

