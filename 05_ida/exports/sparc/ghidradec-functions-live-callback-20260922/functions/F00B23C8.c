
/* WARNING: Removing unreachable block (ram,0xf00b25bc) */
/* WARNING: Removing unreachable block (ram,0xf00b251c) */
/* WARNING: Removing unreachable block (ram,0xf00b24e8) */
/* WARNING: Removing unreachable block (ram,0xf00b24ac) */
/* WARNING: Removing unreachable block (ram,0xf00b2480) */
/* WARNING: Removing unreachable block (ram,0xf00b24d0) */
/* WARNING: Removing unreachable block (ram,0xf00b2504) */
/* WARNING: Removing unreachable block (ram,0xf00b2524) */
/* WARNING: Removing unreachable block (ram,0xf00b2420) */
/* WARNING: Removing unreachable block (ram,0xf00b2544) */

undefined8 _mmrw(uint param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
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
  iVar4 = 0;
  iVar6 = 0;
  if (0 < (int)param_2[5]) {
    param_1 = param_1 & 0xff;
    piVar3 = (int *)*param_2;
    do {
      iVar1 = piVar3[1];
      if (iVar1 == 0) {
        iVar1 = param_2[1];
        *param_2 = piVar3 + 2;
        param_2[1] = iVar1 + -1;
        if (-1 < iVar1 + -1) goto loc_F00B2598;
        _panic(&aMmrw);
        iVar1 = param_2[5];
      }
      else {
        if (param_1 == 1) {
          iVar6 = param_2[2];
          _uiomove(iVar6,iVar1,param_3,param_2);
          iVar4 = iVar1;
        }
        else {
          if (param_1 < 2) {
            if (param_1 == 0) {
              uVar5 = param_2[2] & ~_page_mask;
              if ((uint)param_2[2] < _mem_size) {
                uVar2 = _page_mask;
                _splvm();
                *(undefined4 *)((int)register0x00000038 + -0xc) =
                     *(undefined4 *)(_kernel_map + 0x14);
                iVar4 = _kernel_map;
                _vm_map_find(_kernel_map,0,0,(undefined *)((int)register0x00000038 + -0xc),
                             _page_size,1);
                if (iVar4 == 0) {
                  _pmap_enter(*(undefined4 *)(_kernel_map + 0x24),
                              *(undefined4 *)((int)register0x00000038 + -0xc),uVar5,3,1);
                  iVar6 = param_2[2] - uVar5;
                  iVar4 = _page_size - iVar6;
                  _min(iVar4,piVar3[1]);
                  iVar6 = *(int *)((int)register0x00000038 + -0xc) + iVar6;
                  _uiomove(iVar6,iVar4,param_3,param_2);
                  _vm_map_remove(_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                                 *(int *)((int)register0x00000038 + -0xc) + _page_size);
                  _splx(uVar2);
                  iVar1 = param_2[5];
                  goto loc_F00B259C;
                }
                _splx(uVar2,*(undefined4 *)((int)register0x00000038 + -0xc));
              }
              iVar6 = 0xe;
              break;
            }
          }
          else if ((param_1 == 2) && (iVar4 = iVar1, param_3 == 0)) {
            iVar6 = 0;
            break;
          }
          if (iVar6 != 0) break;
          *piVar3 = *piVar3 + iVar4;
          piVar3[1] = piVar3[1] - iVar4;
          param_2[2] = param_2[2] + iVar4;
          param_2[5] = param_2[5] - iVar4;
        }
loc_F00B2598:
        iVar1 = param_2[5];
      }
loc_F00B259C:
      if ((iVar1 < 1) || (iVar6 != 0)) break;
      piVar3 = (int *)*param_2;
    } while( true );
  }
  return CONCAT44(param_2,iVar6);
}

