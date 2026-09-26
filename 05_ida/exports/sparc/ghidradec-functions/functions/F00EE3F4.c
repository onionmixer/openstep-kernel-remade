
/* WARNING: Removing unreachable block (ram,0xf00ee4f8) */
/* WARNING: Removing unreachable block (ram,0xf00ee4b4) */
/* WARNING: Removing unreachable block (ram,0xf00ee49c) */
/* WARNING: Removing unreachable block (ram,0xf00ee4c8) */
/* WARNING: Removing unreachable block (ram,0xf00ee508) */
/* WARNING: Removing unreachable block (ram,0xf00ee450) */

undefined8 _NXCreateMapTableFromZone(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
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
  piVar6 = param_3;
  (*(code *)param_3[1])(param_3,0x10);
  if (dword_F012F0A8 == (undefined *)0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x18) = unk_F012F098._0_4_;
    *(undefined4 *)((int)register0x00000038 + -0x14) = unk_F012F098._4_4_;
    *(undefined4 *)((int)register0x00000038 + -0x10) = unk_F012F098._8_4_;
    *(undefined4 *)((int)register0x00000038 + -0xc) = unk_F012F098._12_4_;
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    _NXCreateHashTable(puVar2,0,0);
    iVar1 = *param_1;
    dword_F012F0A8 = puVar2;
  }
  else {
    iVar1 = *param_1;
  }
  if ((((iVar1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) || (param_1[3] != 0)) {
    __NXLogError(aNxcreatemaptab);
    piVar6 = (int *)0x0;
  }
  else {
    puVar2 = dword_F012F0A8;
    _NXHashGet(dword_F012F0A8,param_1);
    if (puVar2 == (undefined *)0x0) {
      piVar3 = (int *)0x10;
      _malloc();
      *piVar3 = *param_1;
      piVar3[1] = param_1[1];
      piVar3[2] = param_1[2];
      piVar3[3] = param_1[3];
      _NXHashInsert(dword_F012F0A8,piVar3);
      *piVar6 = (int)piVar3;
    }
    else {
      *piVar6 = (int)puVar2;
    }
    piVar6[1] = 0;
    uVar4 = param_2;
    sub_F00EE32C();
    iVar1 = 1 << ((char)uVar4 + 1U & 0x1f);
    iVar5 = iVar1 + -1;
    piVar6[2] = iVar5;
    (*(code *)param_3[1])(param_3,iVar5 * 8);
    piVar3 = param_3;
    for (iVar1 = iVar1 + -2; iVar1 != -1; iVar1 = iVar1 + -1) {
      *piVar3 = -1;
      piVar3[1] = 0;
      piVar3 = piVar3 + 2;
    }
    piVar6[3] = (int)param_3;
  }
  return CONCAT44(param_2,piVar6);
}
