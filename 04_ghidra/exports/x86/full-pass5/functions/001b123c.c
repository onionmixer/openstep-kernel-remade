/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b123c */

int FUN_001b123c(int param_1,undefined4 param_2,undefined4 param_3,void *param_4,undefined4 *param_5
                ,undefined4 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    *param_5 = 0;
    *param_6 = 0;
    iVar2 = -1;
  }
  else {
    if (*(int *)(param_1 + 0x184) == 0) {
      *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x164);
    }
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x180) + *(int *)(param_1 + 0x188) * 0x14);
    *puVar1 = param_3;
    if (puVar1[2] != 0) {
      puVar1[1] = *(undefined4 *)(param_1 + 0x184);
    }
    *(int *)(param_1 + 0x184) = *(int *)(param_1 + 0x184) + puVar1[2];
    *param_5 = puVar1[1];
    *param_6 = puVar1[2];
    _bcopy(puVar1 + 3,param_4,8);
    iVar2 = *(int *)(param_1 + 0x188) + 0x100;
    *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + 1;
  }
  return iVar2;
}

