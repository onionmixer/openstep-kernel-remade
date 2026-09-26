
/* WARNING: Removing unreachable block (ram,0xf003e398) */
/* WARNING: Removing unreachable block (ram,0xf003e314) */
/* WARNING: Removing unreachable block (ram,0xf003e2dc) */
/* WARNING: Removing unreachable block (ram,0xf003e2c4) */
/* WARNING: Removing unreachable block (ram,0xf003e22c) */
/* WARNING: Removing unreachable block (ram,0xf003e204) */
/* WARNING: Removing unreachable block (ram,0xf003e220) */
/* WARNING: Removing unreachable block (ram,0xf003e28c) */
/* WARNING: Removing unreachable block (ram,0xf003e2d0) */
/* WARNING: Removing unreachable block (ram,0xf003e2e8) */
/* WARNING: Removing unreachable block (ram,0xf003e370) */
/* WARNING: Removing unreachable block (ram,0xf003e35c) */
/* WARNING: Removing unreachable block (ram,0xf003e1fc) */

undefined8 sub_F003E1D4(undefined4 param_1,char *param_2,undefined2 *param_3,char *param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar5;
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
  *(undefined4 *)((int)register0x00000038 + -0x28) = 5;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  *(undefined **)((int)register0x00000038 + -0x10) = _hostname;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x20);
  puVar5 = puVar3;
  _bzero(puVar3,0x10);
  sub_F003DE24();
  if (puVar5 == (undefined *)0x0) {
    uVar1 = 0x100;
    _kalloc();
    *(undefined4 *)((int)register0x00000038 + -0x20) = uVar1;
    uVar1 = 0x100;
    _kalloc();
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar1;
    iVar4 = 0;
    do {
      puVar2 = unk_F012F514;
      *(undefined4 *)((int)register0x00000038 + -0x30) =
           *(undefined4 *)((int)register0x00000038 + -0x28);
      *(undefined4 *)((int)register0x00000038 + -0x2c) =
           *(undefined4 *)((int)register0x00000038 + -0x24);
      sub_F003DD3C(unk_F012F514,0x186ba,1,2,_xdr_bp_getfile_arg,
                   (undefined *)((int)register0x00000038 + -0x10),_xdr_bp_getfile_res,puVar3,
                   (undefined *)((int)register0x00000038 + -0x30),0);
      if (puVar2 != (undefined *)0x5) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    uVar1 = *(undefined4 *)((int)register0x00000038 + -0x20);
    if (puVar2 == (undefined *)0x0) {
      _strcpy(param_2,*(undefined4 *)((int)register0x00000038 + -0x20));
      _strcpy(param_4,*(undefined4 *)((int)register0x00000038 + -0x14));
      uVar1 = *(undefined4 *)((int)register0x00000038 + -0x20);
    }
    _kfree(uVar1,0x100);
    _kfree(*(undefined4 *)((int)register0x00000038 + -0x14),0x100);
    if (puVar2 == (undefined *)0x0) {
      _bcopy((undefined *)((int)register0x00000038 + -0x18),
             (undefined *)((int)register0x00000038 + -0x34),4);
      if (*param_2 == '\0') {
        puVar5 = (undefined *)0x16;
      }
      else if ((*param_4 == '\0') || (*(int *)((int)register0x00000038 + -0x34) == 0)) {
        puVar5 = (undefined *)0x16;
      }
      else if (*(int *)((int)register0x00000038 + -0x1c) == 1) {
        _bzero(param_3,0x10);
        *param_3 = 2;
        *(undefined4 *)(param_3 + 2) = *(undefined4 *)((int)register0x00000038 + -0x34);
        _printf(aNfsMountingSFr,param_1,param_2,param_4);
        puVar5 = (undefined *)0x0;
      }
      else {
        _printf(aGetfileUnknown);
        puVar5 = (undefined *)0x2b;
      }
    }
    else {
      puVar5 = (undefined *)0x3c;
      if (puVar2 != (undefined *)0x5) {
        puVar5 = puVar2;
      }
    }
  }
  return CONCAT44(param_2,puVar5);
}
