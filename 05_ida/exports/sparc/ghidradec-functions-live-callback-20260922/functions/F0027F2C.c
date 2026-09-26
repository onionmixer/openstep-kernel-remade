
/* WARNING: Removing unreachable block (ram,0xf0027f40) */

undefined8 _lseek(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
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
  uVar1 = *puVar4;
  _getvnodefp(uVar1,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    iVar3 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18);
    if (*(int *)(iVar3 + 0x28) != 8) {
      iVar2 = puVar4[2];
      if (iVar2 == 1) {
        iVar3 = *(int *)((int)register0x00000038 + -0xc);
        if (((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) &&
           (iVar3 = *(int *)((int)register0x00000038 + -0xc),
           *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) + puVar4[1] < 0)) {
loc_F00280BC:
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
          goto locret_F00280F4;
        }
        *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + puVar4[1];
      }
      else if (iVar2 < 2) {
        if (iVar2 == 0) {
          if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
            *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) = puVar4[1];
          }
          else {
            if ((int)puVar4[1] < 0) goto loc_F00280BC;
            *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) = puVar4[1];
          }
        }
        else {
loc_F00280D4:
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        }
      }
      else {
        if (iVar2 != 2) goto loc_F00280D4;
        (**(code **)(*(int *)(iVar3 + 0x1c) + 0x14))
                  (iVar3,(undefined *)((int)register0x00000038 + -0x50),_active_u[7]);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar3;
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F00280F4;
        if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
          iVar3 = puVar4[1];
        }
        else {
          if (puVar4[1] + *(int *)((int)register0x00000038 + -0x38) < 0) {
            *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
            goto locret_F00280F4;
          }
          iVar3 = puVar4[1];
        }
        *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) =
             iVar3 + *(int *)((int)register0x00000038 + -0x38);
      }
      *(undefined4 *)(dword_F0133DDC + 0x30) =
           *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
      goto locret_F00280F4;
    }
  }
  else if (*(char *)(dword_F0133DDC + 0x38) != '\x16') goto locret_F00280F4;
  *(undefined *)(dword_F0133DDC + 0x38) = 0x1d;
locret_F00280F4:
  return CONCAT44(param_2,param_1);
}

