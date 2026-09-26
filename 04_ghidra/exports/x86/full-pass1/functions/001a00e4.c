/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a00e4 */

int FUN_001a00e4(int param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar3 = *param_3;
  iVar1 = *param_4;
  local_10 = iVar3;
  if (iVar3 < 0) {
    local_10 = -iVar3;
  }
  local_14 = iVar1;
  if (iVar1 < 0) {
    local_14 = -iVar1;
  }
  if (param_5 == 0) {
    param_5 = 1;
  }
  uVar2 = (uint)((local_10 + local_14) * 0x3b9b) / (uint)(param_5 * param_6);
  local_1c = *(int *)(param_1 + 0x138);
  if ((uint)(int)*(short *)(param_1 + 0x14c) < uVar2) {
    iVar4 = 1;
    if (1 < *(int *)(param_1 + 0x148)) {
      do {
        if (uVar2 <= (uint)(int)*(short *)(param_1 + 0x14c + iVar4 * 2)) break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x148));
    }
    local_1c = *(short *)(param_1 + 0x172 + iVar4 * 2) * local_1c;
  }
  if (iVar3 < 0) {
    uVar2 = local_10 * local_1c - (*(int *)(param_1 + 0x13c) + -0x80);
    *param_3 = -((int)uVar2 >> 8);
    iVar3 = 0x80 - (uVar2 & 0xff);
  }
  else {
    uVar2 = *(int *)(param_1 + 0x13c) + 0x80 + iVar3 * local_1c;
    *param_3 = (int)uVar2 >> 8;
    iVar3 = (uVar2 & 0xff) - 0x80;
  }
  *(int *)(param_1 + 0x13c) = iVar3;
  if (iVar1 < 0) {
    uVar2 = local_14 * local_1c - (*(int *)(param_1 + 0x140) + -0x80);
    *param_4 = -((int)uVar2 >> 8);
    iVar3 = 0x80 - (uVar2 & 0xff);
  }
  else {
    uVar2 = *(int *)(param_1 + 0x140) + 0x80 + iVar1 * local_1c;
    *param_4 = (int)uVar2 >> 8;
    iVar3 = (uVar2 & 0xff) - 0x80;
  }
  *(int *)(param_1 + 0x140) = iVar3;
  return param_1;
}

