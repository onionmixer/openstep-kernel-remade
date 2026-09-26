
/* WARNING: Removing unreachable block (ram,0xf00e0350) */
/* WARNING: Removing unreachable block (ram,0xf00e03c0) */
/* WARNING: Removing unreachable block (ram,0xf00e0370) */
/* WARNING: Removing unreachable block (ram,0xf00e03e0) */
/* WARNING: Removing unreachable block (ram,0xf00e0390) */

undefined8 _snd_server(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 uVar4;
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
  uVar4 = 1;
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x18;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  uVar2 = *(uint *)(param_1 + 0x14);
  iVar3 = 0;
  if (uVar2 < 2) {
    iVar3 = param_1;
    sub_F00DF338(param_1,param_2);
  }
  else if (uVar2 - 100 < 0x11) {
    iVar3 = param_1;
    sub_F00DF950(param_1,param_2);
  }
  else {
    if (uVar2 - 200 < 8) {
      _IOLog(aAudioReceivedD);
      uVar1 = *(undefined4 *)(param_1 + 0x10);
      uVar2 = *(uint *)(param_1 + 0x14);
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x10);
    }
    uVar4 = 0;
    _audio_snd_reply_illegal_msg(param_2,0,uVar1,uVar2,0x66);
  }
  if (iVar3 != 0) {
    _audio_snd_reply_illegal_msg
              (param_2,0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),iVar3);
  }
  return CONCAT44(param_2,uVar4);
}
