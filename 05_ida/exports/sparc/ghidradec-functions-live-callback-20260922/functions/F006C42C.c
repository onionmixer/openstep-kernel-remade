
/* WARNING: Removing unreachable block (ram,0xf006c534) */
/* WARNING: Removing unreachable block (ram,0xf006c4f0) */
/* WARNING: Removing unreachable block (ram,0xf006c4d4) */
/* WARNING: Removing unreachable block (ram,0xf006c504) */
/* WARNING: Removing unreachable block (ram,0xf006c494) */
/* WARNING: Removing unreachable block (ram,0xf006c4cc) */

undefined8 _unmap_vnode(int *param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  word wVar4;
  int *piVar3;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar6 = *param_1;
  if ((*(uint *)(iVar6 + 0x38) & 0x8000000) != 0) {
    sVar1 = *(sword *)(iVar6 + 4);
    wVar4 = sVar1 - 1;
    *(word *)(iVar6 + 4) = wVar4;
    if ((int)((uint)wVar4 * 0x10000) < 1) {
      *(sword *)(iVar6 + 4) = sVar1;
      (**(code **)(param_1[7] + 0x7c))(param_1,(undefined *)((int)register0x00000038 + -0xc));
      sVar1 = *(sword *)(iVar6 + 4);
      iVar5 = *(int *)((int)register0x00000038 + -0xc);
      *(sword *)(iVar6 + 4) = sVar1 + -1;
      if (iVar5 == 0) {
        _mfs_memfree(iVar6,0);
      }
      else {
        iVar5 = *(int *)(iVar6 + 0x24);
        if ((_close_flush != 0) || ((*(uint *)(iVar6 + 0x38) & 0x20000000) != 0)) {
          *(sword *)(iVar6 + 4) = sVar1;
          _vmp_get(iVar6);
          _vmp_push(iVar6);
        }
        do {
          do {
            param_1 = (int *)(iVar5 + 0x10);
          } while (*param_1 != 0);
          piVar3 = param_1;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        _vm_object_deactivate_pages(iVar5);
        iVar2 = _close_flush;
        *(undefined4 *)(iVar5 + 0x10) = 0;
        if ((iVar2 != 0) || ((*(uint *)(iVar6 + 0x38) & 0x20000000) != 0)) {
          _vmp_put(iVar6);
          *(sword *)(iVar6 + 4) = *(sword *)(iVar6 + 4) + -1;
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

