
void _vnode_dealloc(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  puVar2 = (undefined4 *)_vnode_pager_vget(param_1);
  dword_40B06E8 = 0;
  if (-1 < *(char *)(param_1 + 0xc)) {
    *(word *)(puVar2 + 1) = *(word *)(puVar2 + 1) & 0xfffd;
    *(undefined4 *)*puVar2 = 0;
    _vn_rele(puVar2);
    goto loc_4063740;
  }
  iVar4 = *(int *)(param_1 + 4);
  iVar7 = *(int *)(param_1 + 0x10);
  if ((uint)(iVar7 << 2) < 0x41) {
    iVar6 = 0;
    if (0 < iVar7) {
      do {
        sub_40628FA(*(undefined4 *)(*(int *)(param_1 + 8) + iVar6 * 4));
        sub_40635B6(*(undefined4 *)(*(int *)(param_1 + 8) + iVar6 * 4));
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(param_1 + 0x10));
    }
    if (0 < *(int *)(param_1 + 0x10)) {
      iVar7 = *(int *)(param_1 + 0x10) << 2;
      goto loc_406371A;
    }
  }
  else {
    uVar5 = 0;
    if (iVar7 - 1U >> 4 != 0xffffffff) {
      do {
        if (*(int *)(*(int *)(param_1 + 8) + uVar5 * 4) != 0) {
          uVar3 = 0;
          do {
            sub_40628FA(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + uVar5 * 4) + uVar3 * 4));
            sub_40635B6(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + uVar5 * 4) + uVar3 * 4));
            uVar3 = uVar3 + 1;
          } while (uVar3 < 0x10);
          _kfree(*(undefined4 *)(*(int *)(param_1 + 8) + uVar5 * 4),0x40);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < (*(int *)(param_1 + 0x10) - 1U >> 4) + 1);
    }
    iVar7 = (*(int *)(param_1 + 0x10) - 1U >> 4) * 4 + 4;
loc_406371A:
    _kfree(*(undefined4 *)(param_1 + 8),iVar7);
  }
  piVar1 = (int *)(iVar4 + 0xc);
  *piVar1 = *piVar1 + -1;
loc_4063740:
  iVar4 = 0;
  if (0 < dword_40B06E8) {
    puVar2 = (undefined4 *)unk_40B4E40;
    do {
      _vnode_pager_truncate(*puVar2);
      iVar4 = iVar4 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar4 < dword_40B06E8);
  }
  _zfree(_vstruct_zone,param_1);
  return;
}

