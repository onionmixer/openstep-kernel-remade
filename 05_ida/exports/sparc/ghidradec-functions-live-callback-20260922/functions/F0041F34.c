
/* WARNING: Removing unreachable block (ram,0xf0042088) */
/* WARNING: Removing unreachable block (ram,0xf0042024) */
/* WARNING: Removing unreachable block (ram,0xf0041ff4) */
/* WARNING: Removing unreachable block (ram,0xf0042008) */
/* WARNING: Removing unreachable block (ram,0xf0042038) */
/* WARNING: Removing unreachable block (ram,0xf00420a4) */
/* WARNING: Removing unreachable block (ram,0xf0041f54) */

undefined8 _xdr_putrddirres(int *param_1,uint *param_2)

{
  word *pwVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar7;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 1;
  iVar2 = *param_1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  if (iVar2 == 0) {
    piVar6 = param_1;
    _xdr_enum(param_1,param_2 + 1);
    if (piVar6 == (int *)0x0) {
      uVar7 = 0;
      goto locret_F00420B4;
    }
    if (param_2[1] != 0) {
      uVar7 = 1;
      goto locret_F00420B4;
    }
    piVar3 = param_1;
    (**(code **)(param_1[1] + 0x10))();
    uVar7 = param_2[3];
    piVar6 = (int *)param_2[5];
    *(uint *)((int)register0x00000038 + -0x18) = param_2[2];
    for (; 0 < (int)uVar7; uVar7 = uVar7 - *pwVar1) {
      uVar5 = (uint)*(word *)(piVar6 + 1);
      if (uVar5 == 0) {
        uVar7 = 0;
        goto locret_F00420B4;
      }
      if (uVar5 < *(word *)((int)piVar6 + 6) + 9) goto loc_F004209C;
      iVar2 = *piVar6;
      *(uint *)((int)register0x00000038 + -0x18) = *(int *)((int)register0x00000038 + -0x18) + uVar5
      ;
      if (iVar2 != 0) {
        *(int **)((int)register0x00000038 + -0x10) = piVar6 + 2;
        *(uint *)((int)register0x00000038 + -0x14) = (uint)*(word *)((int)piVar6 + 6);
        piVar4 = param_1;
        _xdr_bool(param_1,(undefined *)((int)register0x00000038 + -0xc));
        if (((piVar4 == (int *)0x0) ||
            (piVar4 = param_1, _xdr_u_long(param_1,piVar6), piVar4 == (int *)0x0)) ||
           (piVar4 = param_1,
           _xdr_bytes(param_1,(undefined *)((int)register0x00000038 + -0x10),
                      (undefined *)((int)register0x00000038 + -0x14),0xff), piVar4 == (int *)0x0))
        goto loc_F004209C;
        piVar4 = param_1;
        _xdr_u_long(param_1,(undefined *)((int)register0x00000038 + -0x18));
        if (piVar4 == (int *)0x0) {
          uVar7 = 0;
          goto locret_F00420B4;
        }
        piVar4 = param_1;
        (**(code **)(param_1[1] + 0x10))();
        if (*param_2 <= (uint)((int)piVar4 - (int)piVar3)) {
          param_2[4] = 0;
          break;
        }
      }
      pwVar1 = (word *)(piVar6 + 1);
      piVar6 = (int *)((int)piVar6 + (uint)*pwVar1);
    }
    piVar6 = param_1;
    _xdr_bool(param_1,(undefined *)((int)register0x00000038 + -0x1c));
    if (piVar6 != (int *)0x0) {
      _xdr_bool(param_1,param_2 + 4);
      uVar7 = (uint)(param_1 != (int *)0x0);
      goto locret_F00420B4;
    }
  }
loc_F004209C:
  uVar7 = 0;
locret_F00420B4:
  return CONCAT44(param_2,uVar7);
}

