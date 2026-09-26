/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142b34 */

void _fragacct(int param_1,int param_2,int *param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint local_14;
  int local_10;
  int *local_c;
  
  iVar5 = *(int *)(param_1 + 0x38);
  bVar1 = *(byte *)(param_2 + *(int *)(&_fragtbl + iVar5 * 4));
  iVar4 = 1;
  local_c = param_3;
  if (1 < iVar5) {
    do {
      local_c = local_c + 1;
      bVar2 = (byte)iVar5;
      if (iVar5 < 0) {
        bVar2 = bVar2 + 7;
      }
      if (((uint)bVar1 * 2 >> ((iVar5 - (uint)(bVar2 & 0xf8)) + iVar4 & 0x1f) & 1) != 0) {
        uVar3 = *(uint *)(&_around + iVar4 * 4);
        local_14 = *(uint *)(&_inside + iVar4 * 4);
        local_10 = iVar4;
        if (iVar4 <= iVar5) {
          do {
            if (local_14 == (param_2 * 2 & uVar3)) {
              *local_c = *local_c + param_4;
              local_10 = local_10 + iVar4;
              uVar3 = uVar3 << ((byte)iVar4 & 0x1f);
              local_14 = local_14 << ((byte)iVar4 & 0x1f);
            }
            uVar3 = uVar3 * 2;
            local_14 = local_14 << 1;
            local_10 = local_10 + 1;
          } while (local_10 <= *(int *)(param_1 + 0x38));
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = *(int *)(param_1 + 0x38);
    } while (iVar4 < iVar5);
  }
  return;
}

