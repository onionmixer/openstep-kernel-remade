
/* WARNING: Removing unreachable block (ram,0xf0023fcc) */
/* WARNING: Removing unreachable block (ram,0xf0023ff0) */
/* WARNING: Removing unreachable block (ram,0xf0023f98) */

undefined8 _vfs_add(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar2 = param_2;
  _vfs_lock();
  if (puVar2 == (undefined4 *)0x0) {
    if (param_1 == 0) {
      _rootvfs = param_2;
      *param_2 = 0;
    }
    else {
      if (*(int *)(param_1 + 0xc) != 0) {
        _vfs_unlock(param_2);
        puVar2 = (undefined4 *)0x10;
        goto locret_F00240B8;
      }
      if ((param_3 & 0x8000) == 0) {
        *(undefined4 **)(param_1 + 0xc) = param_2;
      }
      else {
        param_2[0x48] = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = param_2;
        _microtime(param_1 + 0x14);
      }
      puVar2 = _rootvfs;
      *param_2 = *_rootvfs;
      *puVar2 = param_2;
    }
    param_2[2] = param_1;
    if ((param_3 & 1) == 0) {
      uVar1 = param_2[3] & 0xfffffffe;
    }
    else {
      uVar1 = param_2[3] | 1;
    }
    param_2[3] = uVar1;
    if ((param_3 & 2) == 0) {
      uVar1 = param_2[3] & 0xfffffff7;
    }
    else {
      uVar1 = param_2[3] | 8;
    }
    param_2[3] = uVar1;
    if ((param_3 & 8) == 0) {
      uVar1 = param_2[3] & 0xffffffef;
    }
    else {
      uVar1 = param_2[3] | 0x10;
    }
    param_2[3] = uVar1;
    if ((param_3 & 0x20) == 0) {
      uVar1 = param_2[3] & 0xffffffdf;
    }
    else {
      uVar1 = param_2[3] | 0x20;
    }
    param_2[3] = uVar1;
    puVar2 = (undefined4 *)0x0;
    param_2[3] = param_2[3] & 0xffffff7f;
  }
locret_F00240B8:
  return CONCAT44(param_2,puVar2);
}

