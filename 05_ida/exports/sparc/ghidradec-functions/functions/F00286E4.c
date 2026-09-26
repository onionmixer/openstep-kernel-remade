
/* WARNING: Removing unreachable block (ram,0xf002876c) */
/* WARNING: Removing unreachable block (ram,0xf002870c) */

undefined8 _ftruncate(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 *puVar4;
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
  puVar4 = *(undefined4 **)(dword_F0133DDC + 0x24);
  if ((int)puVar4[1] < 0) {
    uVar2 = 0x16;
  }
  else {
    uVar1 = *puVar4;
    _getvnodefp(uVar1,(undefined *)((int)register0x00000038 + -0xc));
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F00287A0;
    iVar3 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18);
    if ((*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 8) & 2) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F00287A0;
    }
    if ((*(uint *)(*(int *)(iVar3 + 0x24) + 0xc) & 1) != 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x1e;
      goto locret_F00287A0;
    }
    _vattr_null((undefined *)((int)register0x00000038 + -0x50));
    *(undefined4 *)((int)register0x00000038 + -0x38) = puVar4[1];
    (**(code **)(*(int *)(iVar3 + 0x1c) + 0x18))
              (iVar3,(undefined *)((int)register0x00000038 + -0x50),
               *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x20));
    uVar2 = (undefined)iVar3;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
locret_F00287A0:
  return CONCAT44(param_2,param_1);
}
