
/* WARNING: Removing unreachable block (ram,0xf006faf8) */
/* WARNING: Removing unreachable block (ram,0xf006fa88) */
/* WARNING: Removing unreachable block (ram,0xf006fb18) */
/* WARNING: Removing unreachable block (ram,0xf006fab0) */
/* WARNING: Removing unreachable block (ram,0xf006fa44) */

undefined8 _kdp_packet(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined *puVar4;
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
  puVar2 = (undefined *)((int)register0x00000038 + -0x610);
  uVar3 = *param_2;
  _bcopy(param_1,puVar2,0x604);
  uVar1 = *(uint *)((int)register0x00000038 + -0x610);
  if ((uVar3 < 8) || ((uVar1 & 0xffff) != uVar3)) {
    _safe_prf(aKdpPacketBadLe,uVar3,*(uint *)((int)register0x00000038 + -0x610) & 0xffff);
    puVar4 = (undefined *)0x0;
  }
  else if ((uVar1 & 0x1000000) == 0) {
    uVar3 = uVar1 >> 0x19;
    if (uVar3 < 0xf) {
      puVar4 = puVar2;
      (**(code **)(unk_F01100B8 + uVar3 * 4))(puVar2,param_2,param_3);
      _bcopy(puVar2,param_1,*param_2);
    }
    else {
      _safe_prf(aKdpPacketBadRe,uVar3,uVar1 & 0xffff,uVar1 >> 0x10 & 0xff,
                *(undefined4 *)((int)register0x00000038 + -0x60c));
      puVar4 = (undefined *)0x0;
    }
  }
  else {
    _safe_prf(aKdpPacketReply,uVar1 >> 0x19,uVar1 >> 0x10 & 0xff);
    puVar4 = (undefined *)0x0;
  }
  return CONCAT44(param_2,puVar4);
}
