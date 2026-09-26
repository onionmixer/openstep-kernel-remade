
/* WARNING: Removing unreachable block (ram,0xf00dac7c) */
/* WARNING: Removing unreachable block (ram,0xf00dac54) */
/* WARNING: Removing unreachable block (ram,0xf00dac24) */
/* WARNING: Removing unreachable block (ram,0xf00dabfc) */
/* WARNING: Removing unreachable block (ram,0xf00dabe8) */
/* WARNING: Removing unreachable block (ram,0xf00daba0) */
/* WARNING: Removing unreachable block (ram,0xf00dab74) */
/* WARNING: Removing unreachable block (ram,0xf00dab64) */
/* WARNING: Removing unreachable block (ram,0xf00dab84) */
/* WARNING: Removing unreachable block (ram,0xf00dabb0) */
/* WARNING: Removing unreachable block (ram,0xf00dabcc) */
/* WARNING: Removing unreachable block (ram,0xf00dac0c) */
/* WARNING: Removing unreachable block (ram,0xf00dac3c) */
/* WARNING: Removing unreachable block (ram,0xf00dac6c) */
/* WARNING: Removing unreachable block (ram,0xf00dac8c) */
/* WARNING: Removing unreachable block (ram,0xf00dab5c) */

undefined8 -[AudioChannel removeStream:](uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
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
  _objc_msgSend(param_3,paUserport);
  _audio_enroll_stream_port();
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paLock);
  iVar1 = *(int *)(param_1 + 0xc);
  _objc_msgSend(iVar1,paCount_0);
  if (iVar1 == 1) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paUnlock);
    uVar3 = param_1;
    _objc_msgSend(param_1,paIsread);
    if ((uVar3 & 0xff) == 0) {
      _objc_msgSend(*(undefined4 *)(param_1 + 4),paAudiocommand_0);
    }
    else {
      _objc_msgSend(*(undefined4 *)(param_1 + 4),paAudiocommand_0);
    }
    _objc_msgSend();
    _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paLock);
    if (*(int *)(param_1 + 0x58) == 0) {
      iVar1 = *(int *)(param_1 + 0x5c);
    }
    else {
      _audio_clear_peaks(*(int *)(param_1 + 0x58),0x10);
      iVar1 = *(int *)(param_1 + 0x5c);
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 100) = 0;
    }
    else {
      _audio_clear_peaks(iVar1,0x10);
      *(undefined4 *)(param_1 + 100) = 0;
    }
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  _objc_msgSend(uVar2,paRemoveobject,param_3);
  _objc_msgSend(paAudiochannel,paRemovestream,param_3);
  _objc_msgSend(param_3,paFree);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paUnlock);
  return CONCAT44(param_2,param_1);
}

