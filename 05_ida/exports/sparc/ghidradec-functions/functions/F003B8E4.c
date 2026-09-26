
/* WARNING: Removing unreachable block (ram,0xf003b918) */
/* WARNING: Removing unreachable block (ram,0xf003b988) */
/* WARNING: Removing unreachable block (ram,0xf003baec) */
/* WARNING: Removing unreachable block (ram,0xf003bb04) */
/* WARNING: Removing unreachable block (ram,0xf003b8ec) */

undefined8 sub_F003B8E4(int param_1,int *param_2,undefined4 param_3)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
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
  bool bVar9;
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
  iVar2 = param_1;
  sub_F003C020(param_1,param_3);
  if (iVar2 == 0) {
    param_2[1] = 0x46;
    goto locret_F003BB0C;
  }
  if (*(int *)(iVar2 + 0x28) == 2) {
    iVar8 = iVar2;
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x1c))(iVar2,0x100,*(undefined4 *)(_active_u + 0x1c));
    if (iVar8 == 0) {
      uVar3 = *(uint *)(param_1 + 0x24);
      if (uVar3 == 0) {
        param_2[3] = 0;
        param_2[4] = 0;
        param_2[5] = 0;
        *param_2 = 0;
        iVar8 = 0;
      }
      else {
        if (0x2000 < uVar3) {
          uVar3 = 0x2000;
        }
        *(uint *)(param_1 + 0x24) = uVar3;
        while( true ) {
          iVar8 = *(int *)(param_1 + 0x24);
          _kalloc();
          param_2[5] = iVar8;
          param_2[-1] = *(int *)(param_1 + 0x24);
          *param_2 = *(int *)(param_1 + 0x24);
          uVar3 = *(uint *)(param_1 + 0x20) & 0xfffffc00;
          param_2[2] = uVar3;
          *(int *)((int)register0x00000038 + -0x10) = param_2[5];
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x24);
          *(undefined **)((int)register0x00000038 + -0x28) =
               (undefined *)((int)register0x00000038 + -0x10);
          *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
          *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
          *(uint *)((int)register0x00000038 + -0x20) = uVar3;
          *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_1 + 0x24);
          iVar8 = iVar2;
          (**(code **)(*(int *)(iVar2 + 0x1c) + 0x3c))
                    (iVar2,(undefined *)((int)register0x00000038 + -0x28),
                     *(undefined4 *)(_active_u + 0x1c));
          if (iVar8 != 0) break;
          if (*(int *)((int)register0x00000038 + -0x14) == 0) {
            param_2[3] = *(int *)(param_1 + 0x24);
            param_2[4] = 0;
          }
          else {
            param_2[3] = *(int *)(param_1 + 0x24) - *(int *)((int)register0x00000038 + -0x14);
            param_2[4] = 1;
          }
          uVar7 = 0;
          piVar6 = (int *)param_2[5];
          bVar9 = param_2[3] != 0;
          while (bVar9) {
            if (*(uint *)(param_1 + 0x20) < uVar3 + *(word *)(piVar6 + 1)) {
              if (*piVar6 != 0) break;
              wVar1 = *(word *)(piVar6 + 1);
            }
            else {
              wVar1 = *(word *)(piVar6 + 1);
            }
            uVar4 = (uint)wVar1;
            uVar7 = uVar7 + uVar4;
            uVar3 = uVar3 + uVar4;
            piVar6 = (int *)((int)piVar6 + uVar4);
            bVar9 = uVar7 < (uint)param_2[3];
          }
          if (uVar7 == 0) {
            param_2[1] = 0;
            goto loc_F003BB04;
          }
          param_2[2] = uVar3;
          param_2[3] = param_2[3] - uVar7;
          iVar5 = param_2[5];
          *param_2 = *param_2 - uVar7;
          param_2[5] = iVar5 + uVar7;
          if (param_2[3] != 0) goto loc_F003BB00;
          if (param_2[4] != 0) {
            param_2[1] = 0;
            goto loc_F003BB04;
          }
          _kfree((iVar5 + uVar7 + *param_2) - param_2[-1]);
          *(int *)(param_1 + 0x20) = param_2[2];
        }
        param_2[3] = 0;
      }
      goto loc_F003BB00;
    }
    param_2[1] = iVar8;
  }
  else {
    _printf(aRfsReaddirAtte);
    iVar8 = 0x14;
loc_F003BB00:
    param_2[1] = iVar8;
  }
loc_F003BB04:
  _vn_rele(iVar2);
locret_F003BB0C:
  return CONCAT44(param_2,param_1);
}
