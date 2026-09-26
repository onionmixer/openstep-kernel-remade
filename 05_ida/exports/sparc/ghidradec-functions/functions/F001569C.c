
/* WARNING: Removing unreachable block (ram,0xf00158bc) */
/* WARNING: Removing unreachable block (ram,0xf00157b4) */

undefined8 _rwuio(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined uVar4;
  undefined4 uVar3;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
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
  puVar5 = *(uint **)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_1;
  uVar8 = *puVar5;
  *(int *)((int)register0x00000038 + 0x48) = param_2;
  uVar1 = _active_u[0x56];
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  if (uVar8 < uVar1) {
    iVar6 = *(int *)(_active_u[0x53] + uVar8 * 4);
    *(int *)((int)register0x00000038 + -0x24) = iVar6;
    if ((iVar6 != 0) && (iVar6 != -0x10000)) {
      if (param_2 == 0) {
        uVar1 = *(uint *)(*(int *)((int)register0x00000038 + -0x24) + 8) & 1;
      }
      else {
        uVar1 = *(uint *)(*(int *)((int)register0x00000038 + -0x24) + 8) & 2;
      }
      piVar9 = *(int **)((int)register0x00000038 + -0x1c);
      if (uVar1 != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
        piVar9[5] = 0;
        iVar6 = piVar9[1];
        piVar9[3] = 0;
        iVar7 = *piVar9;
        if (0 < iVar6) {
          do {
            if ((*(int *)(iVar7 + 4) < 0) ||
               (iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0x1c) + 0x14) +
                        *(int *)(iVar7 + 4),
               *(int *)(*(int *)((int)register0x00000038 + -0x1c) + 0x14) = iVar2, iVar2 < 0)) {
              *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
              goto locret_F00158D0;
            }
            iVar2 = *(int *)((int)register0x00000038 + -0x10);
            iVar7 = iVar7 + 8;
            *(int *)((int)register0x00000038 + -0x10) = iVar2 + 1;
          } while (iVar2 + 1 < iVar6);
        }
        *(undefined4 *)((int)register0x00000038 + -0x14) =
             *(undefined4 *)(*(int *)((int)register0x00000038 + -0x1c) + 0x14);
        iVar6 = *(int *)((int)register0x00000038 + -0x24);
        do {
          iVar7 = *(int *)((int)register0x00000038 + -0x1c);
          *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar6 + 0x1c);
          *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(iVar7 + 0x14);
          iVar6 = dword_F0133DDC + 0x28;
          _setjmp();
          iVar7 = *(int *)((int)register0x00000038 + -0x1c);
          if (iVar6 == 0) {
            *(int *)((int)register0x00000038 + -0xc) = *(int *)((int)register0x00000038 + -0xc) + 1;
            uVar3 = *(undefined4 *)((int)register0x00000038 + -0x24);
            (*(code *)**(undefined4 **)(*(int *)((int)register0x00000038 + -0x24) + 0x14))
                      (uVar3,*(undefined4 *)((int)register0x00000038 + 0x48),
                       *(undefined4 *)((int)register0x00000038 + -0x1c));
            uVar4 = (undefined)uVar3;
loc_F0015868:
            *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
loc_F001586C:
            iVar7 = *(int *)((int)register0x00000038 + -0x1c);
            iVar6 = *(int *)((int)register0x00000038 + -0x14);
            iVar2 = *(int *)(iVar7 + 0x14);
          }
          else {
            iVar6 = *(int *)((int)register0x00000038 + -0x14);
            if (*(int *)(iVar7 + 0x14) == iVar6) {
              if ((_active_u[0x4f] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) != 0) {
                uVar4 = 4;
                goto loc_F0015868;
              }
              *(undefined *)(dword_F0133DDC + 0x39) = 2;
              goto loc_F001586C;
            }
            iVar2 = *(int *)(iVar7 + 0x14);
          }
          *(int *)(dword_F0133DDC + 0x30) = iVar6 - iVar2;
          iVar6 = *(int *)((int)register0x00000038 + -0x24);
          *(int *)(iVar6 + 0x1c) =
               *(int *)(iVar6 + 0x1c) +
               (*(int *)((int)register0x00000038 + -0x18) - *(int *)(iVar7 + 0x14));
          if (*(char *)(dword_F0133DDC + 0x38) == '\0') break;
          uVar1 = *(uint *)(iVar6 + 8) & 0x1000;
          _fspause();
          iVar6 = *(int *)((int)register0x00000038 + -0x24);
        } while (uVar1 != 0);
        goto locret_F00158D0;
      }
    }
  }
  *(undefined *)(dword_F0133DDC + 0x38) = 9;
locret_F00158D0:
  return CONCAT44(param_2,param_1);
}
