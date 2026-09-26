
/* WARNING: Removing unreachable block (ram,0xf00787c8) */
/* WARNING: Removing unreachable block (ram,0xf00785e4) */

undefined8 _zone_free_space_reclaim(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l3;
  int *piVar7;
  undefined4 unaff_l4;
  int *piVar8;
  undefined4 unaff_l5;
  int *piVar9;
  undefined4 unaff_l6;
  int iVar10;
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
  piVar6 = &_zone_free_space;
  iVar10 = 1;
  piVar9 = (int *)0x0;
  if (1 < _zone_free_space_count) {
    do {
      piVar6 = piVar6 + 1;
      piVar4 = *(int **)(*piVar6 + 8);
      if (piVar4 != (int *)0x0) {
        uVar3 = piVar4[1];
        piVar8 = (int *)(*piVar6 + 8);
        do {
          piVar2 = piVar4;
          if (_page_size <= uVar3) {
            piVar5 = (int *)((int)piVar4 + _page_mask & ~_page_mask);
            piVar7 = (int *)((int)piVar4 + uVar3 & ~_page_mask);
            if (((piVar5 < piVar7) && (_zone_min <= piVar5)) && (piVar7 <= _zone_max)) {
              sub_F0077B04(*piVar6,piVar4);
              if ((int *)((int)piVar4 + piVar4[1]) == piVar7) {
                if (piVar4 == piVar5) {
                  iVar1 = *piVar4;
                  *piVar8 = iVar1;
                  if (iVar1 != 0) {
                    *(int **)(*piVar4 + 8) = piVar8;
                  }
                  *(int *)(*piVar6 + 0xc) = *(int *)(*piVar6 + 0xc) + -1;
                }
                else {
                  piVar4[1] = (int)piVar5 - (int)piVar4;
                  iVar1 = *piVar6;
                  uVar3 = (uint)((int)piVar5 - (int)piVar4) >>
                          ((byte)*(undefined4 *)(iVar1 + 0x10) & 0x1f);
                  if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar3) {
                    uVar3 = *(uint *)(iVar1 + 0x18);
                  }
                  iVar1 = *(int *)(iVar1 + 0x14) + uVar3 * 0x10;
                  piVar2 = *(int **)(iVar1 + -0x10);
                  if ((piVar2 == (int *)0x0) || (piVar4 < piVar2)) {
                    *(int **)(iVar1 + -0x10) = piVar4;
                  }
                }
              }
              else {
                piVar7[1] = ((int)piVar4 + piVar4[1]) - (int)piVar7;
                iVar1 = *piVar4;
                *piVar7 = iVar1;
                if (iVar1 != 0) {
                  *(int **)(iVar1 + 8) = piVar7;
                }
                if (piVar4 == piVar5) {
                  *piVar8 = (int)piVar7;
                  piVar7[2] = (int)piVar8;
loc_F0078698:
                  iVar1 = *piVar6;
                }
                else {
                  piVar4[1] = (int)piVar5 - (int)piVar4;
                  *piVar4 = (int)piVar7;
                  piVar7[2] = (int)piVar4;
                  *(int *)(*piVar6 + 0xc) = *(int *)(*piVar6 + 0xc) + 1;
                  iVar1 = *piVar6;
                  uVar3 = (uint)piVar4[1] >> ((byte)*(undefined4 *)(iVar1 + 0x10) & 0x1f);
                  if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar3) {
                    uVar3 = *(uint *)(iVar1 + 0x18);
                  }
                  iVar1 = *(int *)(iVar1 + 0x14) + uVar3 * 0x10;
                  piVar2 = *(int **)(iVar1 + -0x10);
                  if ((piVar2 == (int *)0x0) || (piVar4 < piVar2)) {
                    *(int **)(iVar1 + -0x10) = piVar4;
                    goto loc_F0078698;
                  }
                  iVar1 = *piVar6;
                }
                uVar3 = (uint)piVar7[1] >> ((byte)*(undefined4 *)(iVar1 + 0x10) & 0x1f);
                if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar3) {
                  uVar3 = *(uint *)(iVar1 + 0x18);
                }
                iVar1 = *(int *)(iVar1 + 0x14) + uVar3 * 0x10;
                piVar4 = *(int **)(iVar1 + -0x10);
                if ((piVar4 == (int *)0x0) || (piVar7 < piVar4)) {
                  *(int **)(iVar1 + -0x10) = piVar7;
                }
              }
              piVar5[1] = (int)piVar7 - (int)piVar5;
              *piVar5 = (int)piVar9;
              piVar2 = piVar8;
              piVar9 = piVar5;
            }
          }
          piVar4 = (int *)*piVar2;
          if (piVar4 == (int *)0x0) break;
          uVar3 = piVar4[1];
          piVar8 = piVar2;
        } while( true );
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < _zone_free_space_count);
  }
  _zget_space_lock = 0;
  if (piVar9 != (int *)0x0) {
    for (piVar6 = (int *)*piVar9; _kmem_free(_zone_map,piVar9,piVar9[1]), piVar6 != (int *)0x0;
        piVar6 = (int *)*piVar6) {
      piVar9 = piVar6;
    }
  }
  return CONCAT44(param_2,param_1);
}

