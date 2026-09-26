
/* WARNING: Removing unreachable block (ram,0xf002c588) */
/* WARNING: Removing unreachable block (ram,0xf002c554) */
/* WARNING: Removing unreachable block (ram,0xf002c524) */
/* WARNING: Removing unreachable block (ram,0xf002c570) */
/* WARNING: Removing unreachable block (ram,0xf002c590) */
/* WARNING: Removing unreachable block (ram,0xf002c518) */

undefined8 _raw_detach(int *param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = param_1[2];
  if (param_1[0xe] != 0) {
    _rtfree();
  }
  *(undefined4 *)(iVar2 + 8) = 0;
  _sofree(iVar2);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  if (param_1[0xd] != 0) {
    _m_freem(param_1[0xd] & 0xffffff80);
  }
  if (iVar2 == _ip_mrouter) {
    _ip_mrouter_done();
    sVar1 = *(sword *)(param_1 + 0xb);
  }
  else {
    sVar1 = *(sword *)(param_1 + 0xb);
  }
  if (sVar1 == 2) {
    _ip_freemoptions(param_1[0x14]);
  }
  _m_freem((uint)param_1 & 0xffffff80);
  return CONCAT44(param_2,param_1);
}
