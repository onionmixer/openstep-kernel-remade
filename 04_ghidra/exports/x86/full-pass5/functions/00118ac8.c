/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118ac8 */

undefined4 _unp_internalize(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  
  uVar6 = (uint)(int)*(short *)(param_1 + 8) >> 2;
  puVar4 = (undefined4 *)(param_1 + *(int *)(param_1 + 4));
  iVar3 = 0;
  if (uVar6 != 0) {
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      iVar2 = _getf(uVar1);
      if (iVar2 == 0) {
        return 9;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar6);
  }
  piVar5 = (int *)(param_1 + *(int *)(param_1 + 4));
  iVar3 = 0;
  if (uVar6 != 0) {
    do {
      iVar2 = _getf(*piVar5);
      *piVar5 = iVar2;
      piVar5 = piVar5 + 1;
      *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + 1;
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + 1;
      _unp_rights = _unp_rights + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar6);
  }
  return 0;
}

