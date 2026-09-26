/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00141cb8 */

int _indirtrunc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int local_18;
  int local_14;
  
  iVar9 = *(int *)(param_1 + 0x50);
  local_18 = 0;
  local_14 = 1;
  iVar10 = 0;
  if (0 < param_4) {
    do {
      local_14 = local_14 * *(int *)(iVar9 + 0x74);
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_4);
  }
  iVar10 = param_3;
  if (0 < param_3) {
    iVar10 = param_3 / local_14;
  }
  iVar5 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
  iVar1 = *(int *)(iVar9 + 0x30);
  iVar6 = _geteblk(iVar1);
  pbVar7 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                          param_2 << ((byte)*(undefined4 *)(iVar9 + 100) & 0x1f),
                          *(undefined4 *)(iVar9 + 0x30));
  if ((*pbVar7 & 4) == 0) {
    pvVar2 = *(void **)(pbVar7 + 0x20);
    _bcopy(pvVar2,*(void **)(iVar6 + 0x20),*(size_t *)(iVar9 + 0x30));
    _bzero((void *)((int)pvVar2 + iVar10 * 4 + 4),((*(int *)(iVar9 + 0x74) + -1) - iVar10) * 4);
    _bwrite(pbVar7);
    iVar3 = *(int *)(iVar6 + 0x20);
    iVar4 = *(int *)(iVar9 + 0x74);
    while (iVar4 = iVar4 + -1, iVar10 < iVar4) {
      uVar11 = *(uint *)(iVar3 + iVar4 * 4);
      uVar11 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18;
      if (uVar11 != 0) {
        if (0 < param_4) {
          iVar8 = _indirtrunc(param_1,uVar11,0xffffffff,param_4 + -1);
          local_18 = local_18 + iVar8;
        }
        _free_block(param_1,uVar11,*(undefined4 *)(iVar9 + 0x30));
        local_18 = local_18 + iVar1 / iVar5;
      }
    }
    if ((0 < param_4) && (-1 < param_3)) {
      uVar11 = *(uint *)(iVar3 + iVar4 * 4);
      uVar11 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18;
      if (uVar11 != 0) {
        iVar9 = _indirtrunc(param_1,uVar11,param_3 % local_14,param_4 + -1);
        local_18 = local_18 + iVar9;
      }
    }
    _brelse(iVar6);
  }
  else {
    _brelse(iVar6);
    _brelse(pbVar7);
    local_18 = 0;
  }
  return local_18;
}

