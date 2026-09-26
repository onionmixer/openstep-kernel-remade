
int _vnode_pageout(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uStack_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x24);
  piVar3 = (int *)_vnode_pager_vget(iVar1);
  uVar5 = *(int *)(*(int *)(param_1 + 0x14) + 0x28) + *(int *)(param_1 + 0x18);
  iVar6 = _page_size;
  if ((-1 < *(char *)(iVar1 + 0xc)) &&
     (uVar2 = *(uint *)(*piVar3 + 0x14), uVar2 < _page_size + uVar5)) {
    if (uVar2 < uVar5) {
      iVar6 = 0;
    }
    else {
      iVar6 = uVar2 - uVar5;
    }
  }
  if (*(char *)(iVar1 + 0xc) < '\0') {
    iVar4 = sub_4062AD4(iVar1,uVar5,0,&uStack_8);
    if (iVar4 == 5) {
      _vnode_pager_vput(iVar1);
      return 2;
    }
    uVar5 = (uStack_8 & 0xffffff) << (_page_shift & 0x3f);
    piVar3 = *(int **)((&unk_40B4E00)[uStack_8 >> 0x18] + 8);
    if (*(uint *)(*piVar3 + 0x14) < iVar6 + uVar5) {
      *(uint *)(*piVar3 + 0x14) = iVar6 + uVar5;
    }
  }
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (**(code **)(piVar3[7] + 0x78))(piVar3,*(undefined4 *)(param_1 + 0x22),iVar6,uVar5);
  }
  if (iVar6 == 0) {
    *(byte *)(param_1 + 0x1e) = *(byte *)(param_1 + 0x1e) | 4;
    _pmap_clear_modify(*(undefined4 *)(param_1 + 0x22));
  }
  else {
    _printf(aVnodePageoutFa);
  }
  _vnode_pager_vput(iVar1);
  return iVar6;
}

