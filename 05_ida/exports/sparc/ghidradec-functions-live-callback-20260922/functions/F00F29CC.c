
/* WARNING: Removing unreachable block (ram,0xf00f2ae8) */
/* WARNING: Removing unreachable block (ram,0xf00f2ab4) */
/* WARNING: Removing unreachable block (ram,0xf00f2a28) */
/* WARNING: Removing unreachable block (ram,0xf00f2a5c) */
/* WARNING: Removing unreachable block (ram,0xf00f2adc) */
/* WARNING: Removing unreachable block (ram,0xf00f2b44) */
/* WARNING: Removing unreachable block (ram,0xf00f2a20) */

undefined8 __objc_headerVector(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  uint uVar4;
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
  uVar2 = dword_F012F124;
  if (dword_F012F124 == 0) {
    iVar3 = 0;
    iVar1 = *param_1;
    uVar4 = 0;
    while (iVar1 != 0) {
      dword_F012F128 = dword_F012F128 + 1;
      iVar3 = iVar3 + 1;
      uVar4 = dword_F012F128;
      iVar1 = param_1[iVar3];
    }
    __objc_create_zone();
    uVar2 = uVar4;
    __objc_create_zone();
    (**(code **)(uVar4 + 4))();
    if (uVar2 == 0) {
      __objc_fatal(aUnableToAlloca_0);
    }
    uVar4 = 0;
    if (dword_F012F128 != 0) {
      iVar3 = 0;
      do {
        iVar1 = (iVar3 + uVar4) * 8;
        *(int *)(uVar2 + iVar1) = param_1[uVar4];
        iVar1 = uVar2 + iVar1;
        *(undefined4 *)(iVar1 + 0x10) = 0;
        iVar3 = param_1[uVar4];
        _getsectdatafromheader
                  (iVar3,&aObjc,aModuleInfo,(undefined *)((int)register0x00000038 + -0xc));
        *(int *)(iVar1 + 4) = iVar3;
        *(uint *)(iVar1 + 8) = *(uint *)((int)register0x00000038 + -0xc) >> 4;
        iVar3 = param_1[uVar4];
        _getsectdatafromheader
                  (iVar3,&aObjc,aRuntimeSetup,(undefined *)((int)register0x00000038 + -0xc));
        *(int *)(iVar1 + 0xc) = iVar3;
        iVar3 = param_1[uVar4];
        sub_F00F2900();
        if (iVar3 == 0) {
          *(undefined4 *)(uVar2 + uVar4 * 0x18 + 0x14) = 0;
        }
        else {
          *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar3 + 0x24);
        }
        uVar4 = uVar4 + 1;
        iVar3 = uVar4 * 2;
      } while (uVar4 < dword_F012F128);
    }
    _qsort(uVar2,dword_F012F128,0x18,sub_F00F2974);
  }
  return CONCAT44(param_2,uVar2);
}

