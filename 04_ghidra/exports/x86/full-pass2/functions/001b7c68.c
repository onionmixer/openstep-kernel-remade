/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7c68 */

void FUN_001b7c68(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  int local_c;
  
  piVar1 = (int *)(param_1 + 0x2c);
  piVar2 = *(int **)(param_1 + 0x2c);
  while (piVar2 != piVar1) {
    iVar3 = *(int *)(param_1 + 0x2c);
    piVar2 = *(int **)(iVar3 + 8);
    piVar4 = *(int **)(iVar3 + 0xc);
    piVar6 = piVar1;
    if (piVar1 != piVar2) {
      piVar6 = piVar2 + 2;
    }
    piVar6[1] = (int)piVar4;
    piVar6 = piVar1;
    if (piVar1 != piVar4) {
      piVar6 = piVar4 + 2;
    }
    *piVar6 = (int)piVar2;
    _IOFree(iVar3,0x10);
    piVar2 = *(int **)(param_1 + 0x2c);
  }
  _bzero(*(void **)(param_1 + 0x4c),*(size_t *)(param_1 + 0x38));
  local_c = *(int *)(param_1 + 0x4c);
  uVar8 = 0;
  if (*(int *)(param_1 + 0x3c) != 0) {
    iVar3 = param_1 + 0x2c;
    do {
      puVar7 = (undefined4 *)_IOMalloc(0x10);
      *puVar7 = 0;
      puVar7[1] = local_c;
      local_c = local_c + *(int *)(param_1 + 0x40);
      if (*(int *)(param_1 + 0x2c) == iVar3) {
        *(undefined4 **)(param_1 + 0x2c) = puVar7;
        *(undefined4 **)(param_1 + 0x30) = puVar7;
        puVar7[2] = iVar3;
        puVar7[3] = iVar3;
      }
      else {
        iVar5 = *(int *)(param_1 + 0x30);
        puVar7[3] = iVar5;
        puVar7[2] = iVar3;
        *(undefined4 **)(param_1 + 0x30) = puVar7;
        *(undefined4 **)(iVar5 + 8) = puVar7;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 0x3c));
  }
  return;
}

