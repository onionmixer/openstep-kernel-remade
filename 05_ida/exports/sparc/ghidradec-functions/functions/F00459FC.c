
/* WARNING: Removing unreachable block (ram,0xf0045ac8) */
/* WARNING: Removing unreachable block (ram,0xf0045aa8) */
/* WARNING: Removing unreachable block (ram,0xf0045a40) */
/* WARNING: Removing unreachable block (ram,0xf0045ad8) */
/* WARNING: Removing unreachable block (ram,0xf0045af0) */
/* WARNING: Removing unreachable block (ram,0xf0045a30) */

undefined8 _xdr_string(uint *param_1,int *param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
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
  iVar6 = *param_2;
  if (*param_1 == 0) {
loc_F0045A30:
    iVar4 = iVar6;
    _strlen();
    *(int *)((int)register0x00000038 + -0xc) = iVar4;
  }
  else if (*param_1 == 2) {
    if (iVar6 == 0) {
      param_1 = (uint *)0x1;
      goto locret_F0045AF8;
    }
    goto loc_F0045A30;
  }
  puVar1 = param_1;
  _xdr_u_int(param_1,(undefined *)((int)register0x00000038 + -0xc));
  if (puVar1 == (uint *)0x0) {
    puVar3 = aXdrStringSizeF;
  }
  else {
    if (*(uint *)((int)register0x00000038 + -0xc) <= param_3) {
      uVar5 = *param_1;
      iVar4 = *(uint *)((int)register0x00000038 + -0xc) + 1;
      if (uVar5 == 1) {
        iVar2 = *(int *)((int)register0x00000038 + -0xc);
        if (iVar6 == 0) {
          _kalloc();
          *param_2 = iVar4;
          iVar2 = *(int *)((int)register0x00000038 + -0xc);
          iVar6 = iVar4;
        }
        *(undefined *)(iVar6 + iVar2) = 0;
      }
      else if (1 < uVar5) {
        if (uVar5 == 2) {
          _kfree(iVar6);
          *param_2 = 0;
          param_1 = (uint *)0x1;
          goto locret_F0045AF8;
        }
        puVar3 = aXdrStringBadOp;
        goto loc_F0045AF0;
      }
      _xdr_opaque(param_1,iVar6,*(undefined4 *)((int)register0x00000038 + -0xc));
      goto locret_F0045AF8;
    }
    puVar3 = aXdrStringBadSi;
  }
loc_F0045AF0:
  param_1 = (uint *)0x0;
  _printf(puVar3);
locret_F0045AF8:
  return CONCAT44(param_2,param_1);
}

