
/* WARNING: Removing unreachable block (ram,0xf0013838) */
/* WARNING: Removing unreachable block (ram,0xf00137f4) */
/* WARNING: Removing unreachable block (ram,0xf00137ac) */
/* WARNING: Removing unreachable block (ram,0xf00137dc) */
/* WARNING: Removing unreachable block (ram,0xf0013820) */
/* WARNING: Removing unreachable block (ram,0xf001386c) */
/* WARNING: Removing unreachable block (ram,0xf0013778) */

undefined8 _uname(undefined4 param_1,undefined4 param_2)

{
  undefined uVar2;
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined *puVar4;
  undefined4 unaff_l3;
  int *piVar5;
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
  uVar2 = 0x18;
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  puVar4 = (undefined *)((int)register0x00000038 + -0x2c);
  _copyoutstr(aNextstep,*piVar5,0x20,puVar4);
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    uVar2 = 0x30;
    _copyoutstr(_hostname,*piVar5 + 0x20,0x20,puVar4);
    *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
    puVar3 = (undefined *)((int)register0x00000038 + -0x28);
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      _sprintf(puVar3,&aD_0,0);
      puVar1 = puVar3;
      _copyoutstr(puVar3,*piVar5 + 0x40,0x20,puVar4);
      *(char *)(dword_F0133DDC + 0x38) = (char)puVar1;
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        _sprintf(puVar3,&aD_1,4);
        _copyoutstr(puVar3,*piVar5 + 0x60,0x20,puVar4);
        *(char *)(dword_F0133DDC + 0x38) = (char)puVar3;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          uVar2 = 0x38;
          _copyoutstr(&aUnknown,*piVar5 + 0x80,0x20,puVar4);
          *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

