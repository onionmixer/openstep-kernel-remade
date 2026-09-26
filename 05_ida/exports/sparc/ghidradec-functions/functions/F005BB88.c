
/* WARNING: Removing unreachable block (ram,0xf005bc70) */
/* WARNING: Removing unreachable block (ram,0xf005bc20) */
/* WARNING: Removing unreachable block (ram,0xf005bbdc) */
/* WARNING: Removing unreachable block (ram,0xf005bd34) */
/* WARNING: Removing unreachable block (ram,0xf005bc50) */
/* WARNING: Removing unreachable block (ram,0xf005bc88) */
/* WARNING: Removing unreachable block (ram,0xf005bba8) */

undefined8
_ipc_right_dnrequest
          (undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 *puVar6;
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
  while (puVar4 = param_1,
        _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc)),
        puVar4 == (undefined4 *)0x0) {
    uVar5 = **(uint **)((int)register0x00000038 + -0xc);
    if ((uVar5 & 0x70000) == 0) {
loc_F005BCDC:
      if ((((uVar5 & 0x100000) == 0) || (param_3 == 0)) || (param_4 == 0)) {
        param_1[2] = 0;
        puVar4 = (undefined4 *)0x11;
        if ((uVar5 & 0x170000) != 0) {
          puVar4 = (undefined4 *)0x4;
        }
      }
      else {
        uVar2 = (uVar5 & 0xffff) + 1;
        if (((uVar5 & 0xffff) < uVar2) && (uVar2 < 0x10000)) {
          **(int **)((int)register0x00000038 + -0xc) = uVar5 + 1;
          param_1[2] = 0;
          _ipc_notify_dead_name(param_4,param_2);
          *param_5 = 0;
loc_F005BD60:
          puVar4 = (undefined4 *)0x0;
        }
        else {
          param_1[2] = 0;
          puVar4 = (undefined4 *)0x13;
        }
      }
      break;
    }
    puVar4 = (undefined4 *)(*(uint **)((int)register0x00000038 + -0xc))[1];
    puVar6 = param_1;
    _ipc_right_check(param_1,puVar4,param_2);
    if (puVar6 != (undefined4 *)0x0) {
      if ((uVar5 & 0x400000) == 0) {
        uVar5 = **(uint **)((int)register0x00000038 + -0xc);
        goto loc_F005BCDC;
      }
      param_1[2] = 0;
      puVar4 = (undefined4 *)0xf;
      break;
    }
    if (param_4 == 0) {
      puVar6 = (undefined4 *)0x0;
      if (((uVar5 & 0x400000) == 0) && (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 8) != 0)
         ) {
        puVar6 = param_1;
        _ipc_right_dncancel(param_1,puVar4,param_2);
      }
      *puVar4 = 0;
      param_1[2] = 0;
      *param_5 = puVar6;
      goto loc_F005BD60;
    }
    if (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 8) == 0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = param_1;
      _ipc_right_dncancel(param_1,puVar4,param_2);
    }
    puVar1 = puVar4;
    _ipc_port_dnrequest(puVar4,param_2,param_4,(undefined *)((int)register0x00000038 + -0x10));
    puVar3 = *(uint **)((int)register0x00000038 + -0xc);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0x10);
      *puVar4 = 0;
      puVar3[2] = uVar2;
      *puVar3 = uVar5 & 0xffbfffff;
      param_1[2] = 0;
      *param_5 = puVar6;
      goto loc_F005BD60;
    }
    param_1[2] = 0;
    _ipc_port_dngrow();
    if (puVar4 != (undefined4 *)0x0) break;
  }
  return CONCAT44(param_2,puVar4);
}
