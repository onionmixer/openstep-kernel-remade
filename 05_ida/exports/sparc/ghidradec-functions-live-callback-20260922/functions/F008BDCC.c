
/* WARNING: Removing unreachable block (ram,0xf008bef0) */
/* WARNING: Removing unreachable block (ram,0xf008be98) */
/* WARNING: Removing unreachable block (ram,0xf008bf04) */
/* WARNING: Removing unreachable block (ram,0xf008be00) */

undefined8 _vnode_pager_truncate(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  iVar6 = *(int *)(unk_F0130F70 + (*param_1 >> 0x18) * 4);
  uVar2 = *param_1 & 0xffffff;
  piVar5 = *(int **)(iVar6 + 8);
  if (*(int *)(iVar6 + 0x20) <= (int)uVar2) {
    _lock_write(iVar6 + 0x34);
    iVar1 = uVar2 - 1;
    if (iVar1 < 0) {
      iVar1 = *(int *)(iVar6 + 0x1c);
    }
    else {
      do {
        iVar3 = iVar1;
        if (iVar1 < 0) {
          iVar3 = iVar1 + 7;
        }
        if (((int)*(char *)(*(int *)(iVar6 + 0x10) + (iVar3 >> 3)) >>
             ((char)iVar1 + (char)(iVar3 >> 3) * -8 & 0x1fU) & 1U) != 0) {
          *(int *)(iVar6 + 0x20) = iVar1;
          break;
        }
        iVar1 = iVar1 + -1;
      } while (-1 < iVar1);
      iVar1 = *(int *)(iVar6 + 0x1c);
    }
    iVar3 = *(int *)(iVar6 + 0x20) + 1;
    if (((iVar1 != 0) && (iVar1 < iVar3)) &&
       ((uint)(iVar3 << ((byte)_page_shift & 0x1f)) <= *(uint *)(*piVar5 + 0x14))) {
      _vattr_null((undefined *)((int)register0x00000038 + -0x48));
      *(int *)((int)register0x00000038 + -0x30) = iVar3 << ((byte)_page_shift & 0x1f);
      uVar4 = *(undefined4 *)(_active_u + 0x1c);
      *(undefined4 *)(_active_u + 0x1c) = *(undefined4 *)(*piVar5 + 0x30);
      (**(code **)(piVar5[7] + 0x18))
                (piVar5,(undefined *)((int)register0x00000038 + -0x48),
                 *(undefined4 *)(*piVar5 + 0x30));
      if (piVar5 != (int *)0x0) {
        _printf(aVnodeDeallocpa,*(undefined4 *)(iVar6 + 0x28),piVar5);
      }
      *(undefined4 *)(_active_u + 0x1c) = uVar4;
    }
    _lock_done(iVar6 + 0x34);
  }
  return CONCAT44(param_2,iVar6);
}

