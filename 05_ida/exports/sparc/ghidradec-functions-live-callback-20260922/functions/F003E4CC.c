
/* WARNING: Removing unreachable block (ram,0xf003e848) */
/* WARNING: Removing unreachable block (ram,0xf003e7e8) */
/* WARNING: Removing unreachable block (ram,0xf003e798) */
/* WARNING: Removing unreachable block (ram,0xf003e738) */
/* WARNING: Removing unreachable block (ram,0xf003e5e0) */
/* WARNING: Removing unreachable block (ram,0xf003e560) */
/* WARNING: Removing unreachable block (ram,0xf003e538) */
/* WARNING: Removing unreachable block (ram,0xf003e510) */
/* WARNING: Removing unreachable block (ram,0xf003e580) */
/* WARNING: Removing unreachable block (ram,0xf003e5a4) */
/* WARNING: Removing unreachable block (ram,0xf003e728) */
/* WARNING: Removing unreachable block (ram,0xf003e780) */
/* WARNING: Removing unreachable block (ram,0xf003e7d8) */
/* WARNING: Removing unreachable block (ram,0xf003e830) */
/* WARNING: Removing unreachable block (ram,0xf003e86c) */
/* WARNING: Removing unreachable block (ram,0xf003e4f4) */

undefined8 sub_F003E4CC(int param_1,undefined4 param_2,undefined *param_3)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
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
  int iVar6;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar1 = *(uint *)(param_1 + 0xc);
  *(undefined4 *)((int)register0x00000038 + -0x19c) = 0;
  if ((uVar1 & 0x40) != 0) {
    param_3 = (undefined *)0x0;
    goto locret_F003E874;
  }
  _copyin(param_3,(undefined *)((int)register0x00000038 + -400),0x34);
  puVar2 = *(undefined **)((int)register0x00000038 + -400);
  bVar7 = false;
  if (param_3 == (undefined *)0x0) {
    _copyin(puVar2,(undefined *)((int)register0x00000038 + -0x38),0x10);
    bVar7 = false;
    param_3 = puVar2;
    if (puVar2 == (undefined *)0x0) {
      param_3 = (undefined *)0x2e;
      if (*(sword *)((int)register0x00000038 + -0x38) != 2) goto loc_F003E854;
      param_3 = *(undefined **)((int)register0x00000038 + -0x18c);
      _copyin(param_3,(undefined *)((int)register0x00000038 + -0x28),0x20);
      bVar7 = false;
      if (param_3 == (undefined *)0x0) {
        param_3 = *(undefined **)((int)register0x00000038 + -0x174);
        if ((*(uint *)((int)register0x00000038 + -0x188) & 0x20) == 0) {
          sub_F003ED40((undefined *)((int)register0x00000038 + -0x38),
                       (undefined *)((int)register0x00000038 + -0x58));
          uVar1 = *(uint *)((int)register0x00000038 + -0x188);
        }
        else {
          _copyinstr(param_3,(undefined *)((int)register0x00000038 + -0x58),0x20,
                     (undefined *)((int)register0x00000038 + -0x194));
          bVar7 = param_3 == (undefined *)0x0;
          if (!bVar7) goto loc_F003E858;
          uVar1 = *(uint *)((int)register0x00000038 + -0x188);
        }
        if ((uVar1 & 0x1000) == 0) {
          *(undefined4 *)((int)register0x00000038 + -0x198) = 0xffffffff;
        }
        else {
          _copyinstr(*(undefined4 *)((int)register0x00000038 + -0x160),
                     (undefined *)((int)register0x00000038 + -0x158),0x100,
                     (undefined *)((int)register0x00000038 + -0x198));
        }
        param_3 = (undefined *)((int)register0x00000038 + -0x19c);
        sub_F003E87C(param_3,param_1,(undefined *)((int)register0x00000038 + -0x38),
                     (undefined *)((int)register0x00000038 + -0x28),
                     (undefined *)((int)register0x00000038 + -0x58),
                     (undefined *)((int)register0x00000038 + -0x158),
                     *(undefined4 *)((int)register0x00000038 + -0x198),
                     *(undefined4 *)((int)register0x00000038 + -0x188));
        if (param_3 != (undefined *)0x0) goto locret_F003E874;
        iVar6 = *(int *)(*(int *)(*(int *)((int)register0x00000038 + -0x19c) + 0x24) + 0x128);
        uVar4 = *(uint *)(iVar6 + 0x14);
        uVar1 = (*(uint *)((int)register0x00000038 + -0x188) >> 7 & 1) << 0x1b;
        *(uint *)(iVar6 + 0x14) = uVar4 & 0xf7ffffff | uVar1;
        *(uint *)(iVar6 + 0x14) =
             uVar4 & 0xf3ffffff | uVar1 |
             (*(uint *)((int)register0x00000038 + -0x188) >> 0xd & 1) << 0x1a;
        if (((*(uint *)((int)register0x00000038 + -0x188) & 0x10) == 0) ||
           (*(undefined4 *)(iVar6 + 0x30) = *(undefined4 *)((int)register0x00000038 + -0x178),
           -1 < *(int *)((int)register0x00000038 + -0x178))) {
          if (((*(uint *)((int)register0x00000038 + -0x188) & 8) == 0) ||
             (*(undefined4 *)(iVar6 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0x17c),
             0 < *(int *)((int)register0x00000038 + -0x17c))) {
            uVar1 = *(uint *)((int)register0x00000038 + -0x188);
            if ((uVar1 & 4) != 0) {
              iVar5 = *(int *)((int)register0x00000038 + -0x180);
              if (iVar5 < 1) {
                param_3 = (undefined *)0x16;
                goto loc_F003E854;
              }
              iVar3 = *(int *)(iVar6 + 0x1c);
              if (iVar5 < *(int *)(iVar6 + 0x1c)) {
                iVar3 = iVar5;
              }
              *(int *)(iVar6 + 0x1c) = iVar3;
              uVar1 = *(uint *)((int)register0x00000038 + -0x188);
            }
            uVar4 = *(uint *)((int)register0x00000038 + -0x188);
            if ((uVar1 & 2) != 0) {
              iVar5 = *(int *)((int)register0x00000038 + -0x184);
              if (iVar5 < 1) {
                param_3 = (undefined *)0x16;
                goto loc_F003E854;
              }
              iVar3 = *(int *)(iVar6 + 0x20);
              if (iVar5 < *(int *)(iVar6 + 0x20)) {
                iVar3 = iVar5;
              }
              *(int *)(iVar6 + 0x20) = iVar3;
              uVar4 = *(uint *)((int)register0x00000038 + -0x188);
            }
            iVar5 = *(int *)((int)register0x00000038 + -0x170);
            if ((uVar4 & 0x100) != 0) {
              if (iVar5 < 0) {
                iVar5 = 0xe10;
              }
              else {
                if (iVar5 == 0) {
                  param_3 = (undefined *)0x16;
                  _printf(aNfsMountAcregm);
                  bVar7 = false;
                  goto loc_F003E858;
                }
                _min(iVar5,0xe10);
              }
              *(int *)(iVar6 + 0x60) = iVar5;
            }
            uVar1 = *(uint *)((int)register0x00000038 + -0x188);
            if ((uVar1 & 0x200) != 0) {
              uVar1 = *(uint *)((int)register0x00000038 + -0x16c);
              if ((int)uVar1 < 0) {
                uVar1 = 36000;
              }
              else {
                if (uVar1 < *(uint *)(iVar6 + 0x60)) {
                  param_3 = (undefined *)0x16;
                  _printf(aNfsMountAcregm_0);
                  bVar7 = false;
                  goto loc_F003E858;
                }
                _min(uVar1,36000);
              }
              *(uint *)(iVar6 + 100) = uVar1;
              uVar1 = *(uint *)((int)register0x00000038 + -0x188);
            }
            iVar5 = *(int *)((int)register0x00000038 + -0x168);
            if ((uVar1 & 0x400) != 0) {
              if (iVar5 < 0) {
                iVar5 = 0xe10;
              }
              else {
                if (iVar5 == 0) {
                  param_3 = (undefined *)0x16;
                  _printf(aNfsMountAcdirm);
                  bVar7 = false;
                  goto loc_F003E858;
                }
                _min(iVar5,0xe10);
              }
              *(int *)(iVar6 + 0x68) = iVar5;
            }
            bVar7 = true;
            if ((*(uint *)((int)register0x00000038 + -0x188) & 0x800) == 0) goto loc_F003E858;
            uVar1 = *(uint *)((int)register0x00000038 + -0x164);
            if ((int)uVar1 < 0) {
              uVar1 = 36000;
            }
            else {
              if (uVar1 < *(uint *)(iVar6 + 0x68)) {
                param_3 = (undefined *)0x16;
                _printf(aNfsMountAcdirm_0);
                bVar7 = false;
                goto loc_F003E858;
              }
              _min(uVar1,36000);
            }
            *(uint *)(iVar6 + 0x6c) = uVar1;
          }
          else {
            param_3 = (undefined *)0x16;
          }
        }
        else {
          param_3 = (undefined *)0x16;
        }
loc_F003E854:
        bVar7 = param_3 == (undefined *)0x0;
      }
    }
  }
loc_F003E858:
  if ((!bVar7) && (*(int *)((int)register0x00000038 + -0x19c) != 0)) {
    _vn_rele();
  }
locret_F003E874:
  return CONCAT44(param_2,param_3);
}

