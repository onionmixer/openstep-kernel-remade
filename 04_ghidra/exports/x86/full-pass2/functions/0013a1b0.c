/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a1b0 */

int FUN_0013a1b0(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  iVar2 = *(int *)(param_1 + 0x30);
  iVar1 = *(int *)(iVar2 + 0x38);
  if (iVar1 == 0) {
    _getthetime(&local_c);
    _bzero(param_2,0x40);
    param_2[6] = *(int *)(iVar2 + 0x48);
    param_2[8] = local_c;
    param_2[9] = local_8;
    param_2[10] = local_c;
    param_2[0xb] = local_8;
    param_2[0xc] = local_c;
    param_2[0xd] = local_8;
    iVar2 = *(int *)(param_1 + 0x28);
  }
  else {
    iVar1 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))(iVar1,param_2,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(iVar2 + 0x50);
    param_2[8] = *(int *)(iVar2 + 0x4c);
    param_2[9] = iVar1;
    iVar1 = *(int *)(iVar2 + 0x58);
    param_2[10] = *(int *)(iVar2 + 0x54);
    param_2[0xb] = iVar1;
    iVar1 = *(int *)(iVar2 + 0x60);
    param_2[0xc] = *(int *)(iVar2 + 0x5c);
    param_2[0xd] = iVar1;
    iVar2 = *param_2;
  }
  if (iVar2 == 3) {
    iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x80))(param_1);
    param_2[7] = iVar2;
  }
  else if (iVar2 == 4) {
    param_2[7] = 0x2000;
  }
  return 0;
}

