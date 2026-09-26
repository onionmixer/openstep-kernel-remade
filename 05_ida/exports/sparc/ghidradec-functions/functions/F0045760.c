
/* WARNING: Removing unreachable block (ram,0xf0045840) */

undefined8 _xdr_opaque(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  code *pcVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  if (param_3 != 0) {
    iVar5 = 0;
    if ((param_3 & 3) != 0) {
      iVar5 = 4 - (param_3 & 3);
    }
    iVar1 = *param_1;
    if (iVar1 == 1) {
      piVar3 = param_1;
      (**(code **)(param_1[1] + 8))(param_1,param_2,param_3);
      if (piVar3 == (int *)0x0) {
        puVar2 = aXdrOpaqueDecod;
        goto loc_F0045840;
      }
      if (iVar5 != 0) {
        pcVar4 = *(code **)(param_1[1] + 8);
        puVar2 = unk_F012F55C;
loc_F0045824:
        (*pcVar4)(param_1,puVar2,iVar5);
        goto locret_F0045850;
      }
    }
    else if (iVar1 == 0) {
      piVar3 = param_1;
      (**(code **)(param_1[1] + 0xc))(param_1,param_2,param_3);
      if (piVar3 == (int *)0x0) {
        puVar2 = aXdrOpaqueEncod;
loc_F0045840:
        param_1 = (int *)0x0;
        _printf(puVar2);
        goto locret_F0045850;
      }
      if (iVar5 != 0) {
        pcVar4 = *(code **)(param_1[1] + 0xc);
        puVar2 = (undefined *)&unk_F010DE90;
        goto loc_F0045824;
      }
    }
    else if (iVar1 != 2) {
      puVar2 = aXdrOpaqueBadOp;
      goto loc_F0045840;
    }
  }
  param_1 = (int *)0x1;
locret_F0045850:
  return CONCAT44(param_2,param_1);
}
