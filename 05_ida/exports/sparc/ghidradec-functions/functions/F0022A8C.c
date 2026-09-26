
/* WARNING: Removing unreachable block (ram,0xf0022b04) */
/* WARNING: Removing unreachable block (ram,0xf0022ae8) */
/* WARNING: Removing unreachable block (ram,0xf0022ac0) */
/* WARNING: Removing unreachable block (ram,0xf0022ad0) */
/* WARNING: Removing unreachable block (ram,0xf0022af8) */
/* WARNING: Removing unreachable block (ram,0xf0022b20) */
/* WARNING: Removing unreachable block (ram,0xf0022aa4) */

undefined8 _unp_detach(int *param_1,undefined4 param_2)

{
  int iVar1;
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
  if (param_1[1] == 0) {
    iVar1 = param_1[3];
  }
  else {
    *(undefined4 *)(param_1[1] + 0x20) = 0;
    _vn_rele(param_1[1]);
    param_1[1] = 0;
    iVar1 = param_1[3];
  }
  if (iVar1 == 0) {
    iVar1 = param_1[4];
  }
  else {
    _unp_disconnect(param_1);
    iVar1 = param_1[4];
  }
  while (iVar1 != 0) {
    _unp_drop(param_1[4],0x36);
    iVar1 = param_1[4];
  }
  _soisdisconnected(*param_1);
  *(undefined4 *)(*param_1 + 8) = 0;
  _m_freem(param_1[6]);
  _kfree(param_1,0x24);
  if (_unp_rights != 0) {
    _unp_gc();
  }
  return CONCAT44(param_2,param_1);
}
