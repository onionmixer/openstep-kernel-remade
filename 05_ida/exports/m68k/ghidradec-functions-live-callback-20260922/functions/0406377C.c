
void _vnode_uncache(int *param_1)

{
  word wVar1;
  word *pwVar2;
  bool bVar3;
  undefined4 uVar4;
  
  if (((int *)*param_1 != (int *)0x0) && (*(int *)*param_1 != 0)) {
    bVar3 = false;
    if ((undefined *)param_1[7] == _ufs_vnodeops) {
      wVar1 = *(word *)(*(int *)((int)param_1 + 0x2e) + 0x42);
      if ((wVar1 & 1) != 0) {
        bVar3 = true;
        *(word *)(*(int *)((int)param_1 + 0x2e) + 0x42) = wVar1 & 0xfffe;
      }
    }
    else if ((undefined *)param_1[7] == _nfs_vnodeops) {
      wVar1 = *(word *)(*(int *)((int)param_1 + 0x2e) + 0x5e);
      if ((wVar1 & 1) != 0) {
        bVar3 = true;
        *(word *)(*(int *)((int)param_1 + 0x2e) + 0x5e) = wVar1 & 0xfffe;
      }
    }
    _mfs_uncache(param_1);
    uVar4 = _vm_object_lookup(*(undefined4 *)*param_1,0);
    _vm_object_cache_object(uVar4);
    if (bVar3) {
      if ((undefined *)param_1[7] == _ufs_vnodeops) {
        pwVar2 = (word *)(*(int *)((int)param_1 + 0x2e) + 0x42);
        *pwVar2 = *pwVar2 | 1;
      }
      else if ((undefined *)param_1[7] == _nfs_vnodeops) {
        pwVar2 = (word *)(*(int *)((int)param_1 + 0x2e) + 0x5e);
        *pwVar2 = *pwVar2 | 1;
      }
    }
  }
  return;
}

