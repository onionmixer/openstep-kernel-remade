/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104a08 */

int _rewhence(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined1 local_44 [24];
  int local_2c;
  
  if (((*(short *)(param_1 + 2) == 2) || (param_3 == 2)) &&
     (iVar2 = (**(code **)(*(int *)(*(int *)(param_2 + 0x18) + 0x1c) + 0x14))
                        (*(int *)(param_2 + 0x18),local_44,*(undefined4 *)(_active_u + 0x1c)),
     iVar2 != 0)) {
    return iVar2;
  }
  sVar1 = *(short *)(param_1 + 2);
  if (sVar1 == 1) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + *(int *)(param_2 + 0x1c);
LAB_00104a78:
    sVar1 = (short)param_3;
    *(short *)(param_1 + 2) = sVar1;
    if (sVar1 == 1) {
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - *(int *)(param_2 + 0x1c);
    }
    else if (sVar1 == 2) {
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - local_2c;
    }
    iVar2 = 0;
  }
  else {
    if (sVar1 < 2) {
      if (sVar1 == 0) goto LAB_00104a78;
    }
    else if (sVar1 == 2) {
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + local_2c;
      goto LAB_00104a78;
    }
    iVar2 = 0x16;
  }
  return iVar2;
}

