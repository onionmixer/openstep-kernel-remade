/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ef70 */

undefined8 FUN_0017ef70(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *local_8;
  
  local_8 = (int *)(param_1 + 0x18);
  uVar4 = *(uint *)(param_1 + 8);
  uVar7 = uVar4 + param_3;
  iVar2 = 0;
  uVar3 = 0;
  for (; uVar5 = uVar3, iVar6 = iVar2, uVar4 < *(uint *)(param_1 + 0xc); uVar4 = uVar4 + param_4) {
    while (((iVar1 = *local_8, uVar5 = uVar4, iVar6 = uVar7 - uVar4, iVar1 != 0 &&
            (*(uint *)(iVar1 + 0xc) < uVar7)) &&
           (uVar5 = uVar3, iVar6 = iVar2, *(uint *)(iVar1 + 0x10) <= uVar4))) {
      local_8 = (int *)(iVar1 + 4);
    }
    if (iVar6 != 0) break;
    uVar7 = uVar7 + param_4;
    iVar2 = iVar6;
    uVar3 = uVar5;
  }
  return CONCAT44(iVar6,uVar5);
}

