
int _vfs_add(int param_1,undefined4 *param_2,word param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = _vfs_lock(param_2);
  if (iVar2 == 0) {
    if (param_1 == 0) {
      _rootvfs = param_2;
      *param_2 = 0;
    }
    else {
      if (*(int *)(param_1 + 0xc) != 0) {
        _vfs_unlock(param_2);
        return 0x10;
      }
      if ((sword)param_3 < 0) {
        param_2[0x48] = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = param_2;
        _microtime(param_1 + 0x14);
      }
      else {
        *(undefined4 **)(param_1 + 0xc) = param_2;
      }
      puVar1 = _rootvfs;
      *param_2 = *_rootvfs;
      *puVar1 = param_2;
    }
    param_2[2] = param_1;
    if ((param_3 & 1) == 0) {
      param_2[3] = param_2[3] & 0xfffffffe;
    }
    else {
      param_2[3] = param_2[3] | 1;
    }
    if ((param_3 & 2) == 0) {
      param_2[3] = param_2[3] & 0xfffffff7;
    }
    else {
      param_2[3] = param_2[3] | 8;
    }
    if ((param_3 & 8) == 0) {
      param_2[3] = param_2[3] & 0xffffffef;
    }
    else {
      param_2[3] = param_2[3] | 0x10;
    }
    if ((param_3 & 0x20) == 0) {
      param_2[3] = param_2[3] & 0xffffffdf;
    }
    else {
      param_2[3] = param_2[3] | 0x20;
    }
    *(word *)((int)param_2 + 0xe) = *(word *)((int)param_2 + 0xe) & 0xff7f;
    iVar2 = 0;
  }
  return iVar2;
}

