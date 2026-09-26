
/* WARNING: Removing unreachable block (ram,0xf00ddf94) */
/* WARNING: Removing unreachable block (ram,0xf00ddf40) */
/* WARNING: Removing unreachable block (ram,0xf00ddf64) */
/* WARNING: Removing unreachable block (ram,0xf00ddf84) */
/* WARNING: Removing unreachable block (ram,0xf00ddfa8) */
/* WARNING: Removing unreachable block (ram,0xf00ddf10) */

undefined8 _audioMessages(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
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
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = param_1;
    sub_F00DDA44(param_1,param_2);
    if (iVar1 != 0) goto loc_F00DDF90;
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    puVar2 = aAudioUnrecogni_1;
  }
  else if (*(int *)(param_1 + 0x14) < 700) {
    iVar1 = param_1;
    _snd_server(param_1,param_2);
    if (iVar1 != 0) goto loc_F00DDF90;
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    puVar2 = aAudioUnrecogni_2;
  }
  else {
    iVar1 = param_1;
    _audio_server(param_1,param_2);
    if (iVar1 != 0) goto loc_F00DDF90;
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    puVar2 = aAudioUnrecogni_3;
  }
  _IOLog(puVar2,uVar3);
loc_F00DDF90:
  iVar1 = param_2;
  _msg_send(param_2,1,1000);
  if (iVar1 != 0) {
    _IOLog(aMsgSendFailedD,iVar1);
  }
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffecf;
  return CONCAT44(param_2,param_1);
}
