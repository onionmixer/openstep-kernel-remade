/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013c010 */

int _dirpref(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_24;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  local_24 = *(int *)(param_1 + 0xb8);
  local_8 = 0;
  uVar5 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = *(int *)(param_1 + 0x2d8 +
                      ((int)uVar5 >> ((byte)*(undefined4 *)(param_1 + 0x70) & 0x1f)) * 4);
      iVar4 = (~*(uint *)(param_1 + 0x6c) & uVar5) * 0x10;
      iVar3 = *(int *)(iVar2 + iVar4);
      if ((iVar3 < local_24) && (*(int *)(param_1 + 200) / iVar1 <= *(int *)(iVar2 + 8 + iVar4))) {
        local_24 = iVar3;
        local_8 = uVar5;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < iVar1);
  }
  return local_8 * *(int *)(param_1 + 0xb8);
}

