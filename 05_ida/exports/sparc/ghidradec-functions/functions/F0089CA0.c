
/* WARNING: Removing unreachable block (ram,0xf0089d78) */
/* WARNING: Removing unreachable block (ram,0xf0089d0c) */
/* WARNING: Removing unreachable block (ram,0xf0089d98) */
/* WARNING: Removing unreachable block (ram,0xf0089cc8) */

undefined8 sub_F0089CA0(undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  bVar1 = true;
  iVar7 = 0;
  if (param_1 == (undefined4 *)0x0) {
    uVar8 = 0;
locret_F0089DC0:
    return CONCAT44(param_2,uVar8);
  }
  do {
    do {
    } while (param_1[4] != 0);
    piVar2 = param_1 + 4;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  puVar6 = (undefined4 *)*param_1;
loc_F0089CE0:
  if (param_1 != puVar6) {
    uVar3 = puVar6[6];
    do {
      if (uVar3 < param_2) {
        puVar6 = (undefined4 *)puVar6[2];
      }
      else if (uVar3 < param_3) {
        puVar4 = param_1;
        sub_F0089A90(param_1,puVar6);
        if (puVar4 == (undefined4 *)0x1) {
          bVar1 = false;
          puVar6 = (undefined4 *)puVar6[2];
        }
        else if (puVar4 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)puVar6[2];
        }
        else {
          if (puVar4 == (undefined4 *)0x2) goto loc_f0089d34;
          puVar6 = (undefined4 *)puVar6[2];
        }
      }
      else {
        puVar6 = (undefined4 *)puVar6[2];
      }
      if (param_1 == puVar6) {
        uVar3 = param_1[5];
        goto loc_F0089D50;
      }
      uVar3 = puVar6[6];
    } while( true );
  }
  uVar3 = param_1[5];
loc_F0089D50:
  param_3 = param_3 - param_2;
  if ((uVar3 != 0) && (uVar3 < param_3)) {
    param_3 = uVar3;
  }
  iVar5 = param_1[8];
  param_2 = param_2 + param_1[9];
  sub_F0089CA0(iVar5,param_2,param_2 + param_3);
  if (iVar5 != 0) {
    iVar7 = 5;
  }
  param_1[4] = 0;
  _thread_wakeup_prim(param_1,0,0);
  if ((iVar7 == 5) || (uVar8 = 0, !bVar1)) {
    uVar8 = 5;
  }
  goto locret_F0089DC0;
loc_f0089d34:
  puVar6 = (undefined4 *)*param_1;
  goto loc_F0089CE0;
}
