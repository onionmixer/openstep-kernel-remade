
/* WARNING: Removing unreachable block (ram,0xf008b434) */
/* WARNING: Removing unreachable block (ram,0xf008b3f8) */
/* WARNING: Removing unreachable block (ram,0xf008b240) */
/* WARNING: Removing unreachable block (ram,0xf008b2e0) */
/* WARNING: Removing unreachable block (ram,0xf008b2c4) */
/* WARNING: Removing unreachable block (ram,0xf008b1ec) */
/* WARNING: Removing unreachable block (ram,0xf008b1ac) */
/* WARNING: Removing unreachable block (ram,0xf008b374) */
/* WARNING: Removing unreachable block (ram,0xf008b200) */
/* WARNING: Removing unreachable block (ram,0xf008b2d8) */
/* WARNING: Removing unreachable block (ram,0xf008b2f8) */
/* WARNING: Removing unreachable block (ram,0xf008b254) */
/* WARNING: Removing unreachable block (ram,0xf008b4a0) */
/* WARNING: Removing unreachable block (ram,0xf008b47c) */
/* WARNING: Removing unreachable block (ram,0xf008b150) */

undefined8 sub_F008B138(int param_1,int *param_2,int param_3,uint *param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar8;
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
  uVar7 = (uint)param_2 >> ((byte)_page_shift & 0x1f);
  iVar4 = param_1;
  sub_F008B0A8(param_1,param_2,param_4);
  piVar2 = param_2;
  if (param_3 == 1) {
    uVar7 = (iVar4 != 0) - 1 & 5;
    goto locret_F008B4C8;
  }
  if (iVar4 != 0) {
    if ((int)(*param_4 & 0xffffff) <=
        *(int *)(*(int *)(unk_F0130F70 + (uint)*(byte *)param_4 * 4) + 0x24)) {
      uVar7 = 0;
      goto locret_F008B4C8;
    }
    *(uint *)((int)register0x00000038 + -0xc) = *param_4;
    sub_F008AEAC((undefined *)((int)register0x00000038 + -0xc));
  }
  uVar5 = *(uint *)(param_1 + 0x10);
  uVar1 = uVar7 + 1;
  if (uVar5 < uVar1) {
    piVar2 = (int *)(uVar1 * 4);
    if (piVar2 < (int *)0x41) {
      _kalloc_noblock();
      iVar4 = 0;
      if (piVar2 != (int *)0x0) {
        if (*(int *)(param_1 + 0x10) < 1) {
          iVar4 = *(int *)(param_1 + 0x10);
        }
        else {
          iVar6 = 0;
          do {
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar6 + (int)piVar2) = *(undefined4 *)(*(int *)(param_1 + 8) + iVar6);
            iVar6 = iVar6 + 4;
          } while (iVar4 < *(int *)(param_1 + 0x10));
          iVar4 = *(int *)(param_1 + 0x10);
        }
        if (iVar4 < (int)uVar1) {
          iVar6 = iVar4 << 2;
          do {
            *(undefined *)(iVar6 + (int)piVar2) = 0;
            iVar4 = iVar4 + 1;
            iVar6 = iVar6 + 4;
          } while (iVar4 < (int)uVar1);
          iVar4 = *(int *)(param_1 + 0x10);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x10);
        }
        if (iVar4 < 1) {
          *(int **)(param_1 + 8) = piVar2;
        }
        else {
loc_F008B3F4:
          uVar3 = *(undefined4 *)(param_1 + 8);
loc_F008B3F8:
          _kfree(uVar3,iVar4 << 2);
          *(int **)(param_1 + 8) = piVar2;
        }
loc_F008B404:
        *(uint *)(param_1 + 0x10) = uVar1;
        goto loc_F008B408;
      }
    }
    else if (uVar5 == 0) {
      piVar8 = (int *)(((uVar7 >> 4) + 1) * 4);
      piVar2 = piVar8;
      _kalloc_noblock();
      if (piVar2 != (int *)0x0) {
        _bzero(piVar2,piVar8);
        *(int **)(param_1 + 8) = piVar2;
        goto loc_F008B404;
      }
    }
    else if (uVar5 * 4 < 0x41) {
      piVar8 = (int *)(((uVar7 >> 4) + 1) * 4);
      piVar2 = piVar8;
      _kalloc_noblock();
      if (piVar2 != (int *)0x0) {
        _bzero(piVar2,piVar8);
        iVar4 = 0x40;
        _kalloc_noblock();
        *piVar2 = iVar4;
        if (iVar4 != 0) {
          iVar4 = 0;
          if (*(int *)(param_1 + 0x10) < 1) {
            uVar5 = *(uint *)(param_1 + 0x10);
          }
          else {
            iVar6 = *piVar2;
            while( true ) {
              *(undefined4 *)(iVar6 + iVar4 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 8) + iVar4 * 4);
              iVar4 = iVar4 + 1;
              if (*(int *)(param_1 + 0x10) <= iVar4) break;
              iVar6 = *piVar2;
            }
            uVar5 = *(uint *)(param_1 + 0x10);
          }
          if (uVar5 < 0x10) {
            do {
              iVar4 = uVar5 * 4;
              uVar5 = uVar5 + 1;
              *(undefined *)(*piVar2 + iVar4) = 0;
            } while (uVar5 < 0x10);
            iVar4 = *(int *)(param_1 + 0x10);
          }
          else {
            iVar4 = *(int *)(param_1 + 0x10);
          }
          goto loc_F008B3F4;
        }
        _kfree(piVar2,piVar8);
      }
    }
    else {
      piVar8 = (int *)(((uVar7 >> 4) + 1) * 4);
      if (piVar8 + -((uVar5 - 1 >> 4) + 1) == (int *)0x0) {
        *(uint *)(param_1 + 0x10) = uVar1;
        piVar2 = param_2;
        goto loc_F008B408;
      }
      piVar2 = piVar8;
      _kalloc_noblock();
      if (piVar2 != (int *)0x0) {
        _bzero(piVar2,piVar8);
        uVar5 = 0;
        if (*(int *)(param_1 + 0x10) - 1U >> 4 != 0xffffffff) {
          iVar4 = 0;
          do {
            uVar5 = uVar5 + 1;
            *(undefined4 *)(iVar4 + (int)piVar2) = *(undefined4 *)(*(int *)(param_1 + 8) + iVar4);
            iVar4 = iVar4 + 4;
          } while (uVar5 < (*(int *)(param_1 + 0x10) - 1U >> 4) + 1);
        }
        uVar3 = *(undefined4 *)(param_1 + 8);
        iVar4 = (*(int *)(param_1 + 0x10) - 1U >> 4) + 1;
        goto loc_F008B3F8;
      }
    }
loc_F008B300:
    uVar7 = 5;
  }
  else {
loc_F008B408:
    uVar1 = uVar7 >> 4;
    if ((uint)(*(int *)(param_1 + 0x10) * 4) < 0x41) {
      iVar4 = *(int *)(param_1 + 4);
      _vnode_pager_findpage(iVar4,param_4);
      if (iVar4 == 5) {
        uVar7 = 5;
        goto locret_F008B4C8;
      }
      iVar4 = *(int *)(param_1 + 8);
    }
    else {
      piVar2 = (int *)(uVar1 * 4);
      uVar7 = uVar7 & 0xf;
      if (*(int *)(*(int *)(param_1 + 8) + (int)piVar2) == 0) {
        uVar3 = 0x40;
        _kalloc_noblock();
        *(undefined4 *)(*(int *)(param_1 + 8) + (int)piVar2) = uVar3;
        uVar5 = 0;
        if (*(int *)(*(int *)(param_1 + 8) + (int)piVar2) == 0) goto loc_F008B300;
        do {
          iVar4 = uVar5 * 4;
          uVar5 = uVar5 + 1;
          *(undefined *)(*(int *)(*(int *)(param_1 + 8) + (int)piVar2) + iVar4) = 0;
        } while (uVar5 < 0x10);
      }
      iVar4 = *(int *)(param_1 + 4);
      _vnode_pager_findpage(iVar4,param_4);
      if (iVar4 == 5) goto loc_F008B300;
      iVar4 = *(int *)(*(int *)(param_1 + 8) + uVar1 * 4);
    }
    *(uint *)(iVar4 + uVar7 * 4) = *param_4;
    uVar7 = 0;
  }
locret_F008B4C8:
  return CONCAT44(piVar2,uVar7);
}

