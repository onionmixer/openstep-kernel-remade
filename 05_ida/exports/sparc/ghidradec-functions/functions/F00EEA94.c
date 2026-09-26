
/* WARNING: Removing unreachable block (ram,0xf00eecb0) */
/* WARNING: Removing unreachable block (ram,0xf00eed04) */
/* WARNING: Removing unreachable block (ram,0xf00eebb4) */
/* WARNING: Removing unreachable block (ram,0xf00eeadc) */

undefined8 _NXMapInsert(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
  int iVar8;
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
  iVar8 = param_1[3];
  while( true ) {
    piVar7 = param_1;
    (**(code **)*param_1)(param_1,param_2);
    uVar1 = ((uint)piVar7 & 0xffff ^ (uint)piVar7 >> 0x10) * 0xfff1 + (int)piVar7;
    .urem(uVar1,param_1[2]);
    piVar7 = (int *)(iVar8 + uVar1 * 8);
    if (param_2 == -1) break;
    dword_F012F0C0 = dword_F012F0C0 + 1;
    if (*piVar7 == -1) {
      dword_F012F0C4 = dword_F012F0C4 + 1;
      *piVar7 = param_2;
      piVar7[1] = param_3;
      param_1[1] = param_1[1] + 1;
      goto loc_F00EED0C;
    }
    if (*piVar7 == param_2) {
      piVar3 = (int *)0x1;
    }
    else {
      piVar3 = param_1;
      (**(code **)(*param_1 + 4))(param_1,*piVar7,param_2);
    }
    if (piVar3 != (int *)0x0) {
      iVar8 = piVar7[1];
      dword_F012F0C4 = dword_F012F0C4 + 1;
      goto loc_F00EEB90;
    }
    uVar6 = uVar1;
    if (param_1[1] != param_1[2]) goto loc_F00EEBCC;
    sub_F00EE9B0(param_1);
    iVar8 = param_1[3];
  }
  puVar2 = aNxmapinsertInv;
loc_F00EED04:
  __NXLogError(puVar2);
loc_F00EED0C:
  iVar8 = 0;
  goto locret_F00EED10;
  while( true ) {
    DAT_f012f0c8 = DAT_f012f0c8 + 1;
    piVar7 = (int *)(iVar8 + uVar4 * 8);
    if (*(int *)(iVar8 + uVar4 * 8) == -1) {
      *(int *)((int)register0x00000038 + -0x10) = param_2;
      *(int *)((int)register0x00000038 + -0xc) = param_3;
      iVar5 = param_2;
      while (iVar5 != -1) {
        iVar5 = uVar1 * 8;
        *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(iVar8 + iVar5);
        *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(iVar8 + iVar5 + 4);
        *(undefined4 *)(iVar8 + iVar5) = *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)(iVar8 + iVar5 + 4) = *(undefined4 *)((int)register0x00000038 + -0xc);
        *(undefined4 *)((int)register0x00000038 + -0x10) =
             *(undefined4 *)((int)register0x00000038 + -0x18);
        *(undefined4 *)((int)register0x00000038 + -0xc) =
             *(undefined4 *)((int)register0x00000038 + -0x14);
        uVar6 = uVar1 + 1;
        uVar1 = 0;
        if (uVar6 < (uint)param_1[2]) {
          uVar1 = uVar6;
        }
        iVar5 = *(int *)((int)register0x00000038 + -0x10);
      }
      iVar8 = param_1[1];
      param_1[1] = iVar8 + 1;
      uVar1 = (iVar8 + 1) * 4;
      if (uVar1 < (uint)(param_1[2] * 3) || uVar1 + param_1[2] * -3 == 0) {
        iVar8 = 0;
      }
      else {
        sub_F00EE9B0(param_1);
        iVar8 = 0;
      }
      goto locret_F00EED10;
    }
    if (*piVar7 == param_2) {
      piVar3 = (int *)0x1;
    }
    else {
      piVar3 = param_1;
      (**(code **)(*param_1 + 4))(param_1,*piVar7,param_2);
    }
    uVar6 = uVar4;
    if (piVar3 != (int *)0x0) break;
loc_F00EEBCC:
    uVar4 = 0;
    if (uVar6 + 1 < (uint)param_1[2]) {
      uVar4 = uVar6 + 1;
    }
    if (uVar4 == uVar1) {
      puVar2 = aNxmapinsertBug;
      goto loc_F00EED04;
    }
  }
  iVar8 = piVar7[1];
loc_F00EEB90:
  if (iVar8 != param_3) {
    piVar7[1] = param_3;
  }
locret_F00EED10:
  return CONCAT44(param_2,iVar8);
}
