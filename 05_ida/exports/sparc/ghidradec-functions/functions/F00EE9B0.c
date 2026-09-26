
/* WARNING: Removing unreachable block (ram,0xf00eea7c) */
/* WARNING: Removing unreachable block (ram,0xf00eea50) */
/* WARNING: Removing unreachable block (ram,0xf00eea84) */
/* WARNING: Removing unreachable block (ram,0xf00ee9d4) */

undefined8 sub_F00EE9B0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  int iVar7;
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
  piVar6 = (int *)param_1[3];
  iVar4 = param_1[2];
  iVar7 = param_1[1];
  param_1[2] = iVar4 * 2 + 1;
  param_1[1] = 0;
  puVar1 = param_1;
  _NXZoneFromPtr();
  iVar3 = param_1[2];
  (*(code *)puVar1[1])();
  puVar2 = puVar1;
  while (iVar3 = iVar3 + -1, iVar3 != -1) {
    *puVar2 = 0xffffffff;
    puVar2[1] = 0;
    puVar2 = puVar2 + 2;
  }
  param_1[3] = puVar1;
  dword_F012F0B8 = dword_F012F0B8 + 1;
  dword_F012F0BC = dword_F012F0BC + param_1[1];
  piVar5 = piVar6;
  while (iVar4 = iVar4 + -1, iVar4 != -1) {
    if (*piVar5 != -1) {
      _NXMapInsert(param_1,*piVar5,piVar5[1]);
    }
    piVar5 = piVar5 + 2;
  }
  if (iVar7 != param_1[1]) {
    __NXLogError(aMaptableCountD);
  }
  _free(piVar6);
  return CONCAT44(param_2,param_1);
}
