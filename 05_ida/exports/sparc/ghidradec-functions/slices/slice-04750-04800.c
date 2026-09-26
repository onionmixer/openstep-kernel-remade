/* GHIDRADEC_FUNCTION index=4750 start=0xf00dab50 */

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
/* GHIDRADEC_FUNCTION index=4751 start=0xf00dac9c */

/* WARNING: Removing unreachable block (ram,0xf00dacfc) */
/* WARNING: Removing unreachable block (ram,0xf00dacb8) */
/* WARNING: Removing unreachable block (ram,0xf00dacf0) */
/* WARNING: Removing unreachable block (ram,0xf00dad18) */
/* WARNING: Removing unreachable block (ram,0xf00daca8) */

undefined8 -[AudioChannel controlStreams:](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paLock);
  iVar1 = *(int *)(param_1 + 0xc);
  _objc_msgSend(iVar1,paCount_0);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  else if (iVar1 < 1) {
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
    iVar3 = 0;
    while( true ) {
      _objc_msgSend(uVar2,paObjectat,iVar3);
      _objc_msgSend();
      if (iVar1 <= iVar3 + 1) break;
      uVar2 = *(undefined4 *)(param_1 + 0xc);
      iVar3 = iVar3 + 1;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4752 start=0xf00dad28 */

undefined8 -[AudioChannel isDetectingPeaks](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x53));
}
/* GHIDRADEC_FUNCTION index=4753 start=0xf00dad38 */

/* WARNING: Removing unreachable block (ram,0xf00dad7c) */
/* WARNING: Removing unreachable block (ram,0xf00dad6c) */
/* WARNING: Removing unreachable block (ram,0xf00dad88) */
/* WARNING: Removing unreachable block (ram,0xf00dad60) */

undefined8 -[AudioChannel setDetectPeaks:](int param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
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
  *(int *)(param_1 + 0x50) = (int)param_3;
  if ((param_3 != 0) && (*(int *)(param_1 + 0x58) == 0)) {
    uVar1 = 0x40;
    _IOMalloc();
    *(undefined4 *)(param_1 + 0x58) = uVar1;
    uVar1 = 0x40;
    _IOMalloc();
    *(undefined4 *)(param_1 + 0x5c) = uVar1;
    _audio_clear_peaks(*(undefined4 *)(param_1 + 0x58),0x10);
    _audio_clear_peaks(*(undefined4 *)(param_1 + 0x5c),0x10);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4754 start=0xf00dad98 */

/* WARNING: Removing unreachable block (ram,0xf00dadc0) */
/* WARNING: Removing unreachable block (ram,0xf00dadb0) */

undefined8
-[AudioChannel getPeakLeft:right:]
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
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
  if (*(int *)(param_1 + 0x50) == 0) {
    *param_4 = 0;
    *param_3 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x58);
    _audio_max_peak(uVar1,*(undefined4 *)(param_1 + 0x54));
    *param_3 = uVar1;
    uVar1 = *(undefined4 *)(param_1 + 0x5c);
    _audio_max_peak(uVar1,*(undefined4 *)(param_1 + 0x54));
    *param_4 = uVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4755 start=0xf00daddc */

undefined8 -[AudioChannel clipCount](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 100));
}
/* GHIDRADEC_FUNCTION index=4756 start=0xf00dadec */

undefined8 -[AudioChannel incrementClipCount:](int param_1,undefined4 param_2,int param_3)

{
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
  *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4757 start=0xf00dae04 */

undefined8 -[AudioChannel audioDevice](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 4));
}
/* GHIDRADEC_FUNCTION index=4758 start=0xf00dae14 */

/* WARNING: Removing unreachable block (ram,0xf00daef4) */
/* WARNING: Removing unreachable block (ram,0xf00daea4) */
/* WARNING: Removing unreachable block (ram,0xf00dae94) */
/* WARNING: Removing unreachable block (ram,0xf00dae4c) */
/* WARNING: Removing unreachable block (ram,0xf00dae8c) */
/* WARNING: Removing unreachable block (ram,0xf00dae9c) */
/* WARNING: Removing unreachable block (ram,0xf00daee4) */
/* WARNING: Removing unreachable block (ram,0xf00daec4) */
/* WARNING: Removing unreachable block (ram,0xf00dae38) */

undefined8
-[AudioStream initChannel:tag:user:owner:type:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
          undefined4 param_6)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [12];
  undefined7 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422a8;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  pauVar2 = paAudiodevice;
  *(undefined4 *)(param_1 + 4) = param_3;
  _objc_msgSend(param_3,pauVar2);
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  *(undefined4 *)(param_1 + 100) = 0x5622;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 2;
  *(int *)(param_1 + 0x30) = param_1 + 0x2c;
  puVar3 = paNxlock;
  puVar1 = paAlloc;
  *(int *)(param_1 + 0x2c) = param_1 + 0x2c;
  _objc_msgSend(puVar3,puVar1);
  _objc_msgSend();
  *(undefined7 **)(param_1 + 0x28) = puVar3;
  _task_self();
  _port_allocate_EXTERNAL();
  if (puVar3 == (undefined7 *)0x0) {
    uVar4 = *param_5;
    *(undefined4 *)(param_1 + 0xc) = uVar4;
    _IOConvertPort(uVar4,2,0);
    *(undefined4 *)(param_1 + 0x10) = uVar4;
    *(undefined4 *)(param_1 + 0x14) = param_6;
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
  }
  else {
    _IOLog(aAudioInitchann,aMachErr);
    _objc_msgSend(param_1,paFree);
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4759 start=0xf00daf08 */

undefined8 -[AudioStream userPort](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0xc));
}
/* GHIDRADEC_FUNCTION index=4760 start=0xf00daf18 */

undefined8 -[AudioStream ownerPort](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x14));
}
/* GHIDRADEC_FUNCTION index=4761 start=0xf00daf28 */

undefined8 -[AudioStream channel](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 4));
}
/* GHIDRADEC_FUNCTION index=4762 start=0xf00daf38 */

undefined8 -[AudioStream type](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x1c));
}
/* GHIDRADEC_FUNCTION index=4763 start=0xf00daf48 */

/* WARNING: Removing unreachable block (ram,0xf00daf5c) */

undefined8 -[AudioStream createSndReplyMsg](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
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
  if (*(int *)(param_1 + 0x34) == 0) {
    uVar1 = 0x2000;
    _IOMalloc();
    *(undefined4 *)(param_1 + 0x34) = uVar1;
    iVar2 = *(int *)(param_1 + 0x34);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x34);
  }
  *(undefined *)(iVar2 + 3) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 0x18;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x14) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4764 start=0xf00dafa8 */

/* WARNING: Removing unreachable block (ram,0xf00db0cc) */
/* WARNING: Removing unreachable block (ram,0xf00db0a0) */
/* WARNING: Removing unreachable block (ram,0xf00db060) */
/* WARNING: Removing unreachable block (ram,0xf00db010) */
/* WARNING: Removing unreachable block (ram,0xf00dafe4) */
/* WARNING: Removing unreachable block (ram,0xf00db000) */
/* WARNING: Removing unreachable block (ram,0xf00db030) */
/* WARNING: Removing unreachable block (ram,0xf00db0bc) */
/* WARNING: Removing unreachable block (ram,0xf00db07c) */
/* WARNING: Removing unreachable block (ram,0xf00db0ec) */
/* WARNING: Removing unreachable block (ram,0xf00dafd0) */

undefined8
-[AudioStream sendControlMessage:mask:](int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  if (*(int *)(param_1 + 0x1c) == 0) {
    if ((*(uint *)(param_1 + 0x60) & param_4) != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x5c);
      _IOConvertPort(uVar1,0,1);
      uVar3 = *(undefined4 *)(param_1 + 0x10);
      _IOConvertPort(uVar3,0,1);
      __NXAudioReplyStreamStatus(uVar1,uVar3,uVar1,*(undefined4 *)(param_1 + 0x18),0,param_3);
    }
    goto locret_F00DB0F4;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
  iVar5 = param_1 + 0x2c;
  if (iVar5 == *(int *)(param_1 + 0x2c)) {
loc_F00DB0E4:
    uVar1 = *(undefined4 *)(param_1 + 0x28);
  }
  else {
    _objc_msgSend(param_1,paCreatesndreply);
    iVar4 = *(int *)(param_1 + 0x2c);
    if (iVar5 != iVar4) {
      uVar2 = *(uint *)(iVar4 + 0x18);
      while( true ) {
        if ((uVar2 & param_4) != 0) {
          uVar1 = *(undefined4 *)(iVar4 + 0x1c);
          _IOConvertPort(uVar1,0,1);
          if (param_3 == 2) {
            _audio_snd_reply_paused
                      (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(iVar4 + 0x14));
            uVar3 = *(undefined4 *)(param_1 + 0x34);
          }
          else if (param_3 == 3) {
            _audio_snd_reply_resumed
                      (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(iVar4 + 0x14));
            uVar3 = *(undefined4 *)(param_1 + 0x34);
          }
          else {
            uVar3 = *(undefined4 *)(param_1 + 0x34);
            if (param_3 == 4) {
              _audio_snd_reply_aborted(uVar3,uVar1,*(undefined4 *)(iVar4 + 0x14));
              uVar3 = *(undefined4 *)(param_1 + 0x34);
            }
          }
          _msg_send(uVar3,0x21,1000);
        }
        iVar4 = *(int *)(iVar4 + 0x3c);
        if (iVar5 == iVar4) break;
        uVar2 = *(uint *)(iVar4 + 0x18);
      }
      goto loc_F00DB0E4;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x28);
  }
  _objc_msgSend(uVar1,paUnlock);
locret_F00DB0F4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4765 start=0xf00db0fc */

/* WARNING: Removing unreachable block (ram,0xf00db160) */
/* WARNING: Removing unreachable block (ram,0xf00db1a4) */
/* WARNING: Removing unreachable block (ram,0xf00db1e0) */
/* WARNING: Removing unreachable block (ram,0xf00db11c) */
/* WARNING: Removing unreachable block (ram,0xf00db188) */
/* WARNING: Removing unreachable block (ram,0xf00db1c4) */
/* WARNING: Removing unreachable block (ram,0xf00db1f0) */
/* WARNING: Removing unreachable block (ram,0xf00db174) */
/* WARNING: Removing unreachable block (ram,0xf00db108) */

undefined8
-[AudioStream sendStatusMessage:forRegion:](int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = *(int *)(param_4 + 0x1c);
  _IOConvertPort(iVar1,0,1);
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  _IOConvertPort(uVar2,0,1);
  if (*(int *)(param_1 + 0x1c) == 0) {
    if ((param_3 == 4) && (*(int *)(param_4 + 0x38) != 0)) {
      param_3 = 6;
    }
    __NXAudioReplyStreamStatus
              (iVar1,uVar2,iVar1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_4 + 0x14),
               param_3);
    if (iVar1 != 0) {
      _IOLog(aAsReplystreams,iVar1);
    }
  }
  else {
    _objc_msgSend(param_1,paCreatesndreply);
    if (param_3 == 0) {
      _audio_snd_reply_started
                (*(undefined4 *)(param_1 + 0x34),iVar1,*(undefined4 *)(param_4 + 0x14));
      uVar2 = *(undefined4 *)(param_1 + 0x34);
    }
    else if (param_3 == 1) {
      _audio_snd_reply_completed
                (*(undefined4 *)(param_1 + 0x34),iVar1,*(undefined4 *)(param_4 + 0x14));
      uVar2 = *(undefined4 *)(param_1 + 0x34);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x34);
      if (param_3 == 5) {
        _audio_snd_reply_overflow(uVar2,iVar1,*(undefined4 *)(param_4 + 0x14));
        uVar2 = *(undefined4 *)(param_1 + 0x34);
      }
    }
    _msg_send(uVar2,0x21,1000);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4766 start=0xf00db200 */

/* WARNING: Removing unreachable block (ram,0xf00db208) */

undefined8 -[AudioStream freeRegion:](undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
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
  _IOFree(param_3,0x44);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4767 start=0xf00db218 */

undefined8
-[AudioStream completeRegion:descriptor:size:used:](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4768 start=0xf00db224 */

/* WARNING: Removing unreachable block (ram,0xf00db3b8) */
/* WARNING: Removing unreachable block (ram,0xf00db328) */
/* WARNING: Removing unreachable block (ram,0xf00db288) */
/* WARNING: Removing unreachable block (ram,0xf00db2ac) */
/* WARNING: Removing unreachable block (ram,0xf00db368) */
/* WARNING: Removing unreachable block (ram,0xf00db3ec) */
/* WARNING: Removing unreachable block (ram,0xf00db238) */

undefined8
-[AudioStream dmaCompleteDescriptor:transfered:]
          (int param_1,undefined4 param_2,int param_3,uint param_4)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
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
  bool bVar9;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  bVar1 = false;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
  piVar7 = *(int **)(param_1 + 0x2c);
  piVar2 = (int *)(param_1 + 0x2c);
  if (piVar2 != piVar7) {
    iVar4 = piVar7[8];
    do {
      if (iVar4 == param_3) {
        if ((piVar7[6] & 1U) != 0) {
          _objc_msgSend(param_1,paSendstatusmess,0,piVar7);
        }
        piVar7[8] = 0;
      }
      _objc_msgSend(param_1,paCompleteregion,piVar7,param_3,param_4,
                    (undefined *)((int)register0x00000038 + -0x14));
      iVar4 = piVar7[0xd];
      if (piVar7[9] == param_3) {
loc_F00DB2E4:
        bVar9 = iVar4 == 0;
loc_F00DB2E8:
        if (bVar9) {
          iVar4 = piVar7[0xd];
        }
        else {
          if ((piVar7[6] & 0x10U) != 0) {
            if ((bVar1) && (*(int *)(param_1 + 0x1c) != 1)) {
              iVar4 = piVar7[0xd];
              goto loc_F00DB334;
            }
            bVar1 = true;
            _objc_msgSend(param_1,paSendstatusmess,4,piVar7);
          }
          iVar4 = piVar7[0xd];
        }
loc_F00DB334:
        if (iVar4 == 0) {
          if (piVar7[0xc] == 0) {
            if ((piVar7[6] & 2U) != 0) {
              _objc_msgSend(param_1,paSendstatusmess,1,piVar7);
            }
            goto loc_F00DB374;
          }
          piVar8 = (int *)piVar7[0xf];
        }
        else {
loc_F00DB374:
          piVar8 = (int *)piVar7[0xf];
        }
        piVar6 = (int *)piVar7[0x10];
        piVar5 = piVar2;
        if (piVar2 != piVar8) {
          piVar5 = piVar8 + 0xf;
        }
        piVar5[1] = (int)piVar6;
        piVar5 = piVar2;
        if (piVar2 != piVar6) {
          piVar5 = piVar6 + 0xf;
        }
        *piVar5 = (int)piVar8;
        _objc_msgSend(param_1,paFreeregion,piVar7);
        piVar7 = (int *)piVar7[0xf];
      }
      else {
        bVar9 = iVar4 == 0;
        if (!bVar9) goto loc_F00DB2E8;
        if (piVar7[0xc] != 0) {
          iVar4 = piVar7[0xd];
          goto loc_F00DB2E4;
        }
        if (param_4 <= *(uint *)((int)register0x00000038 + -0x14)) {
          uVar3 = *(undefined4 *)(param_1 + 0x28);
          goto loc_F00DB3E8;
        }
        piVar7 = (int *)piVar7[0xf];
      }
      if (piVar2 == piVar7) goto loc_f00db3e4;
      iVar4 = piVar7[8];
    } while( true );
  }
  uVar3 = *(undefined4 *)(param_1 + 0x28);
loc_F00DB3E8:
  _objc_msgSend(uVar3,paUnlock);
  return CONCAT44(param_2,param_1);
loc_f00db3e4:
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  goto loc_F00DB3E8;
}
/* GHIDRADEC_FUNCTION index=4769 start=0xf00db3fc */

/* WARNING: Removing unreachable block (ram,0xf00db404) */

sqword -[AudioStream mixRegion:descriptor:buffer:maxCount:virgin:rate:format:channelCount:]
                 (undefined4 param_1,uint param_2)

{
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
  _IOLog(aAudioSubclassD);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4770 start=0xf00db414 */

undefined8 -[AudioStream clearForMix:size:format:](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4771 start=0xf00db420 */

undefined8
-[AudioStream canConvertRegion:rate:format:channelCount:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  uVar1 = 0;
  if ((param_4 == *(int *)(param_1 + 100)) && (param_5 == *(int *)(param_1 + 0x68))) {
    uVar1 = (uint)(param_6 == *(int *)(param_1 + 0x6c));
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4772 start=0xf00db460 */

/* WARNING: Removing unreachable block (ram,0xf00db660) */
/* WARNING: Removing unreachable block (ram,0xf00db5bc) */
/* WARNING: Removing unreachable block (ram,0xf00db558) */
/* WARNING: Removing unreachable block (ram,0xf00db630) */
/* WARNING: Removing unreachable block (ram,0xf00db4b8) */
/* WARNING: Removing unreachable block (ram,0xf00db494) */

undefined8
-[AudioStream mixBuffer:maxCount:rate:format:channelCount:descriptor:virgin:streamCount:]
          (uint param_1,undefined4 param_2,int param_3,uint param_4,int *param_5,int *param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l3;
  int *piVar7;
  undefined4 unaff_l4;
  undefined4 uVar8;
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
  piVar7 = *(int **)((int)register0x00000038 + 0x5c);
  uVar6 = *(uint *)((int)register0x00000038 + 100);
  uVar5 = 0;
  uVar8 = *(undefined4 *)((int)register0x00000038 + 0x60);
  if (*(char *)(param_1 + 0x24) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
    iVar4 = *(int *)(param_1 + 0x2c);
    if (param_1 + 0x2c == iVar4) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paUnlock);
      uVar5 = 0;
    }
    else {
      uVar3 = *(uint *)(iVar4 + 8);
      while( true ) {
        if (uVar3 < *(uint *)(iVar4 + 4)) {
          if (*(int *)(iVar4 + 0x34) == 0) {
            if (*param_5 == 0) {
              *param_5 = *(int *)(param_1 + 100);
              iVar1 = *param_6;
            }
            else {
              iVar1 = *param_6;
            }
            if (iVar1 == -1) {
              *param_6 = *(int *)(param_1 + 0x68);
              iVar1 = *piVar7;
            }
            else {
              iVar1 = *piVar7;
            }
            if (iVar1 == 0) {
              *piVar7 = *(int *)(param_1 + 0x6c);
            }
            uVar3 = param_1;
            _objc_msgSend(param_1,paCanconvertregi,iVar4,*param_5,*param_6,*piVar7);
            if ((uVar3 & 0xff) == 0) {
              iVar4 = *(int *)(iVar4 + 0x3c);
            }
            else {
              uVar3 = param_3 + uVar5;
              if ((*(int *)(param_1 + 0x68) == 0) && ((uVar3 & 1) != 0)) {
                uVar3 = uVar3 & 0xfffffffe;
              }
              uVar2 = param_1;
              _objc_msgSend(param_1,paMixregionDescr,iVar4,uVar8,uVar3,param_4 - uVar5,
                            (int)(char)uVar6,*param_5,*param_6,*piVar7);
              if (*(int *)(iVar4 + 0x28) == 0) {
                *(undefined4 *)(iVar4 + 0x20) = uVar8;
                *(undefined4 *)(iVar4 + 0x28) = 1;
              }
              uVar5 = uVar5 + uVar2;
              if ((*(uint *)(iVar4 + 4) <= *(uint *)(iVar4 + 8)) && (*(int *)(iVar4 + 0x2c) == 0)) {
                *(undefined4 *)(iVar4 + 0x24) = uVar8;
                *(undefined4 *)(iVar4 + 0x2c) = 1;
              }
              if (param_4 <= uVar5) {
                uVar8 = *(undefined4 *)(param_1 + 0x28);
                goto loc_F00DB62C;
              }
              iVar4 = *(int *)(iVar4 + 0x3c);
            }
          }
          else {
            iVar4 = *(int *)(iVar4 + 0x3c);
          }
        }
        else {
          iVar4 = *(int *)(iVar4 + 0x3c);
        }
        if (param_1 + 0x2c == iVar4) break;
        uVar3 = *(uint *)(iVar4 + 8);
      }
      uVar8 = *(undefined4 *)(param_1 + 0x28);
loc_F00DB62C:
      _objc_msgSend(uVar8,paUnlock);
      if (((uVar6 & 0xff) != 0) && (uVar5 < param_4)) {
        _objc_msgSend(param_1,paClearformixSiz,param_3 + uVar5,param_4 - uVar5,*param_6);
      }
    }
  }
  else {
    uVar5 = 0;
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=4773 start=0xf00db674 */

/* WARNING: Removing unreachable block (ram,0xf00db6e4) */
/* WARNING: Removing unreachable block (ram,0xf00db6a4) */
/* WARNING: Removing unreachable block (ram,0xf00db680) */

undefined8 -[AudioStream markAbortionsExclude:](int param_1,undefined4 param_2,char param_3)

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
  undefined4 uVar2;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
  iVar1 = *(int *)(param_1 + 0x2c);
  if (param_1 + 0x2c == iVar1) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paUnlock);
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x34) = 1;
    while( true ) {
      *(int *)(iVar1 + 0x38) = (int)param_3;
      iVar1 = *(int *)(iVar1 + 0x3c);
      if (param_1 + 0x2c == iVar1) break;
      *(undefined4 *)(iVar1 + 0x34) = 1;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paUnlock);
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4774 start=0xf00db6f8 */

/* WARNING: Removing unreachable block (ram,0xf00dba14) */
/* WARNING: Removing unreachable block (ram,0xf00db8dc) */
/* WARNING: Removing unreachable block (ram,0xf00db8bc) */
/* WARNING: Removing unreachable block (ram,0xf00db888) */
/* WARNING: Removing unreachable block (ram,0xf00db864) */
/* WARNING: Removing unreachable block (ram,0xf00db928) */
/* WARNING: Removing unreachable block (ram,0xf00db8fc) */
/* WARNING: Removing unreachable block (ram,0xf00db9e4) */
/* WARNING: Removing unreachable block (ram,0xf00db9b0) */
/* WARNING: Removing unreachable block (ram,0xf00db988) */
/* WARNING: Removing unreachable block (ram,0xf00db960) */
/* WARNING: Removing unreachable block (ram,0xf00dbaa4) */
/* WARNING: Removing unreachable block (ram,0xf00dbadc) */
/* WARNING: Removing unreachable block (ram,0xf00db7d8) */
/* WARNING: Removing unreachable block (ram,0xf00db7a4) */
/* WARNING: Removing unreachable block (ram,0xf00db77c) */
/* WARNING: Removing unreachable block (ram,0xf00db754) */
/* WARNING: Removing unreachable block (ram,0xf00db774) */
/* WARNING: Removing unreachable block (ram,0xf00db798) */
/* WARNING: Removing unreachable block (ram,0xf00db7cc) */
/* WARNING: Removing unreachable block (ram,0xf00db7ec) */
/* WARNING: Removing unreachable block (ram,0xf00dbaec) */
/* WARNING: Removing unreachable block (ram,0xf00dbac8) */
/* WARNING: Removing unreachable block (ram,0xf00db980) */
/* WARNING: Removing unreachable block (ram,0xf00db9a4) */
/* WARNING: Removing unreachable block (ram,0xf00db9d8) */
/* WARNING: Removing unreachable block (ram,0xf00db9f8) */
/* WARNING: Removing unreachable block (ram,0xf00db918) */
/* WARNING: Removing unreachable block (ram,0xf00db844) */
/* WARNING: Removing unreachable block (ram,0xf00db86c) */
/* WARNING: Removing unreachable block (ram,0xf00db894) */
/* WARNING: Removing unreachable block (ram,0xf00db8c8) */
/* WARNING: Removing unreachable block (ram,0xf00dba08) */
/* WARNING: Removing unreachable block (ram,0xf00dba90) */
/* WARNING: Removing unreachable block (ram,0xf00db810) */

undefined8 -[AudioStream control:atTime:](uint param_1,undefined4 param_2,uint param_3,int *param_4)

{
  undefined (*pauVar1) [24];
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 *puVar8;
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
  if (param_3 == 1) {
    if (*param_4 == 0) {
      if (param_4[1] == 0) {
        *(undefined *)(param_1 + 0x24) = 0;
        _objc_msgSend(param_1,paSendcontrolmes,3,8);
        pauVar1 = paDatapendingfor;
        uVar6 = *(undefined4 *)(param_1 + 8);
        uVar5 = param_1;
        _objc_msgSend(param_1,paChannel);
        _objc_msgSend(uVar6,pauVar1,uVar5);
        goto locret_F00DBAF4;
      }
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    else {
      *(int *)(param_1 + 0x4c) = *param_4;
    }
    puVar4 = (undefined4 *)0x28;
    *(int *)(param_1 + 0x50) = param_4[1];
    _IOMalloc();
    puVar8 = (undefined4 *)(param_1 + 0x3c);
    iVar7 = param_1 + 0x4c;
    if (*(int *)(param_1 + 0x3c) == 0) {
      puVar2 = puVar4;
      _task_self();
      _port_allocate_EXTERNAL();
      if (puVar2 != (undefined4 *)0x0) {
        _IOLog(aAudioStreamCon,aMachErr);
        _IOLog(aAudioDriverErr);
      }
      if (dword_F012EF3C == 0) {
        iVar3 = paNxlock;
        _objc_msgSend(paNxlock,paAlloc);
        _objc_msgSend();
        dword_F012EF3C = iVar3;
      }
      _objc_msgSend(dword_F012EF3C,paLock);
      dword_F012EF38 = *(undefined4 *)(param_1 + 0x3c);
loc_F00DBA04:
      _current_task_EXTERNAL();
      _kernel_thread();
    }
  }
  else if (param_3 < 2) {
    if (*param_4 == 0) {
      if (param_4[1] == 0) {
        *(undefined *)(param_1 + 0x24) = 1;
        _objc_msgSend(param_1,paSendcontrolmes,2,4);
        goto locret_F00DBAF4;
      }
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    else {
      *(int *)(param_1 + 0x44) = *param_4;
    }
    puVar4 = (undefined4 *)0x28;
    *(int *)(param_1 + 0x48) = param_4[1];
    _IOMalloc();
    puVar8 = (undefined4 *)(param_1 + 0x38);
    iVar7 = param_1 + 0x44;
    if (*(int *)(param_1 + 0x38) == 0) {
      puVar2 = puVar4;
      _task_self();
      _port_allocate_EXTERNAL();
      if (puVar2 != (undefined4 *)0x0) {
        _IOLog(aAudioStreamCon,aMachErr);
        _IOLog(aAudioDriverErr);
      }
      if (dword_F012EF3C == 0) {
        iVar3 = paNxlock;
        _objc_msgSend(paNxlock,paAlloc);
        _objc_msgSend();
        dword_F012EF3C = iVar3;
      }
      _objc_msgSend(dword_F012EF3C,paLock);
      dword_F012EF38 = *(undefined4 *)(param_1 + 0x38);
      goto loc_F00DBA04;
    }
  }
  else {
    if (param_3 != 2) {
      if (param_3 == 4) {
        _objc_msgSend(param_1,paMarkabortionse,1);
      }
      else {
        _IOLog(aAudioUnrecogni,param_3);
      }
      goto locret_F00DBAF4;
    }
    if (*param_4 == 0) {
      if (param_4[1] == 0) {
        uVar5 = param_1;
        _objc_msgSend(param_1,paMarkabortionse,0);
        if ((uVar5 & 0xff) == 0) {
          _objc_msgSend(param_1,paSendcontrolmes,4,0x10);
        }
        goto locret_F00DBAF4;
      }
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    else {
      *(int *)(param_1 + 0x54) = *param_4;
    }
    puVar4 = (undefined4 *)0x28;
    *(int *)(param_1 + 0x58) = param_4[1];
    _IOMalloc();
    puVar8 = (undefined4 *)(param_1 + 0x40);
    iVar7 = param_1 + 0x54;
    if (*(int *)(param_1 + 0x40) == 0) {
      puVar2 = puVar4;
      _task_self();
      _port_allocate_EXTERNAL();
      if (puVar2 != (undefined4 *)0x0) {
        _IOLog(aAudioStreamCon,aMachErr);
        _IOLog(aAudioDriverErr);
      }
      if (dword_F012EF3C == 0) {
        iVar3 = paNxlock;
        _objc_msgSend(paNxlock,paAlloc);
        _objc_msgSend();
        dword_F012EF3C = iVar3;
      }
      _objc_msgSend(dword_F012EF3C,paLock);
      dword_F012EF38 = *(undefined4 *)(param_1 + 0x40);
      goto loc_F00DBA04;
    }
  }
  *puVar4 = 1;
  puVar4[1] = 0x28;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[6] = 0x2200030;
  puVar4[7] = 0;
  puVar4[8] = 0;
  puVar4[9] = 0;
  puVar4[4] = *puVar8;
  puVar4[7] = param_1;
  puVar4[8] = param_3;
  puVar4[9] = iVar7;
  _msg_send(puVar4,1,1000);
locret_F00DBAF4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4775 start=0xf00dbafc */

/* WARNING: Removing unreachable block (ram,0xf00dbb20) */

undefined8 -[AudioStream control:](undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  _objc_msgSend(param_1,paControlAttime,param_3,(undefined *)((int)register0x00000038 + -0x20));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4776 start=0xf00dbb30 */

undefined8 -[AudioStream returnRecordedData](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4777 start=0xf00dbb3c */

/* WARNING: Removing unreachable block (ram,0xf00dbb98) */

undefined8 -[AudioStream freeRegions](int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
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
  piVar2 = (int *)(param_1 + 0x2c);
  if (piVar2 != *(int **)(param_1 + 0x2c)) {
    iVar4 = *(int *)(param_1 + 0x2c);
    while( true ) {
      piVar5 = *(int **)(iVar4 + 0x3c);
      piVar3 = *(int **)(iVar4 + 0x40);
      piVar1 = piVar2;
      if (piVar2 != piVar5) {
        piVar1 = piVar5 + 0xf;
      }
      piVar1[1] = (int)piVar3;
      piVar1 = piVar2;
      if (piVar2 != piVar3) {
        piVar1 = piVar3 + 0xf;
      }
      *piVar1 = (int)piVar5;
      _objc_msgSend(param_1,paFreeregion);
      if (piVar2 == *(int **)(param_1 + 0x2c)) break;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4778 start=0xf00dbbb8 */

/* WARNING: Removing unreachable block (ram,0xf00dbbc8) */
/* WARNING: Removing unreachable block (ram,0xf00dbbbc) */

undefined8 -[AudioStream newRegion](undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = 0x44;
  _IOMalloc(0x44);
  _bzero();
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4779 start=0xf00dbbd8 */

/* WARNING: Removing unreachable block (ram,0xf00dbc9c) */
/* WARNING: Removing unreachable block (ram,0xf00dbc70) */
/* WARNING: Removing unreachable block (ram,0xf00dbc4c) */
/* WARNING: Removing unreachable block (ram,0xf00dbc34) */
/* WARNING: Removing unreachable block (ram,0xf00dbc14) */
/* WARNING: Removing unreachable block (ram,0xf00dbbf4) */
/* WARNING: Removing unreachable block (ram,0xf00dbc0c) */
/* WARNING: Removing unreachable block (ram,0xf00dbc2c) */
/* WARNING: Removing unreachable block (ram,0xf00dbc44) */
/* WARNING: Removing unreachable block (ram,0xf00dbc54) */
/* WARNING: Removing unreachable block (ram,0xf00dbc84) */
/* WARNING: Removing unreachable block (ram,0xf00dbcb8) */
/* WARNING: Removing unreachable block (ram,0xf00dbbec) */

undefined8 -[AudioStream free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
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
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar2 = *(int *)(param_1 + 0x3c);
  }
  else {
    _task_self();
    _port_deallocate_EXTERNAL();
    iVar2 = *(int *)(param_1 + 0x3c);
  }
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x40);
  }
  else {
    _task_self();
    _port_deallocate_EXTERNAL();
    iVar2 = *(int *)(param_1 + 0x40);
  }
  if (iVar2 != 0) {
    _task_self();
    _port_deallocate_EXTERNAL();
  }
  iVar2 = param_1;
  _objc_msgSend(param_1,paFreeregions);
  _task_self();
  _port_deallocate_EXTERNAL();
  if (iVar2 != 0) {
    _IOLog(aAudioStreamPor,aMachErr);
  }
  uVar1 = paFree;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paFree);
  if (*(int *)(param_1 + 0x34) == 0) {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  else {
    _IOFree(*(int *)(param_1 + 0x34),0x2000);
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422a8;
  _objc_msgSendSuper(puVar3,uVar1);
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4780 start=0xf00dbcc8 */

undefined8 -[AudioStream setOwner:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4781 start=0xf00dbcd8 */

/* WARNING: Removing unreachable block (ram,0xf00dbcf4) */
/* WARNING: Removing unreachable block (ram,0xf00dbd28) */
/* WARNING: Removing unreachable block (ram,0xf00dbce4) */

undefined8
-[AudioStream bytesProcessed:atTime:]
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined (*pauVar2) [24];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paOutputstarttim);
  iVar1 = *(int *)(param_1 + 8);
  pauVar2 = paLastinterruptt;
  _objc_msgSend();
  if ((iVar1 == 0) && (pauVar2 == (undefined (*) [24])0x0)) {
    *param_4 = 0;
    *param_3 = 0;
    uVar3 = 0;
  }
  else {
    __udivdi3();
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = pauVar2;
    }
    uVar3 = 1;
    *param_3 = *(undefined4 *)(param_1 + 0x20);
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4782 start=0xf00dbd50 */

/* WARNING: Removing unreachable block (ram,0xf00dbda4) */

undefined8 -[AudioStream dataEncoding](int param_1,undefined4 param_2)

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
  undefined4 uVar2;
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
  iVar1 = *(int *)(param_1 + 0x68);
  if (iVar1 == 1) {
    uVar2 = 0x25a;
    goto locret_F00DBDB0;
  }
  if (iVar1 < 2) {
    if (iVar1 == 0) {
      uVar2 = 600;
      goto locret_F00DBDB0;
    }
  }
  else {
    if (iVar1 == 2) {
      uVar2 = 0x25b;
      goto locret_F00DBDB0;
    }
    if (iVar1 == 3) {
      uVar2 = 0x259;
      goto locret_F00DBDB0;
    }
  }
  _IOLog(aAudioUnrecogni_0,*(undefined4 *)(param_1 + 0x68));
  uVar2 = 0xffffffff;
locret_F00DBDB0:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4783 start=0xf00dbdb8 */

/* WARNING: Removing unreachable block (ram,0xf00dbe34) */

undefined8 -[AudioStream setDataEncoding:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  switch(param_3) {
  case :
    *(undefined4 *)(param_1 + 0x68) = 0;
    break;
  case :
    *(undefined4 *)(param_1 + 0x68) = 3;
    break;
  case :
    *(undefined4 *)(param_1 + 0x68) = 1;
    break;
  case :
    *(undefined4 *)(param_1 + 0x68) = 2;
    break;
  case :
    *(undefined4 *)(param_1 + 0x68) = 4;
    break;
  :
    _IOLog(aAudioSupported);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4784 start=0xf00dbe44 */

undefined8 -[AudioStream samplingRate](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 100));
}
/* GHIDRADEC_FUNCTION index=4785 start=0xf00dbe54 */

undefined8 -[AudioStream setSamplingRate:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 100) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4786 start=0xf00dbe64 */

undefined8 -[AudioStream channelCount](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x6c));
}
/* GHIDRADEC_FUNCTION index=4787 start=0xf00dbe74 */

undefined8 -[AudioStream setChannelCount:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x6c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4788 start=0xf00dbe84 */

sqword -[AudioStream lowWaterMark](undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4789 start=0xf00dbe90 */

undefined8 -[AudioStream setLowWaterMark:](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4790 start=0xf00dbe9c */

sqword -[AudioStream highWaterMark](undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4791 start=0xf00dbea8 */

undefined8 -[AudioStream setHighWaterMark:](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4792 start=0xf00dbeb4 */

/* WARNING: Removing unreachable block (ram,0xf00dbfcc) */
/* WARNING: Removing unreachable block (ram,0xf00dc000) */
/* WARNING: Removing unreachable block (ram,0xf00dbee8) */
/* WARNING: Removing unreachable block (ram,0xf00dbf28) */
/* WARNING: Removing unreachable block (ram,0xf00dbf70) */
/* WARNING: Removing unreachable block (ram,0xf00dbff0) */
/* WARNING: Removing unreachable block (ram,0xf00dbeb8) */

undefined8 sub_F00DBEB4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 uVar8;
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
  iVar2 = 0x28;
  _IOMalloc();
  uVar1 = dword_F012EF38;
  iVar6 = 0;
  uVar8 = 0;
  uVar7 = 0;
  _objc_msgSend(dword_F012EF3C,paUnlock);
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  do {
    while( true ) {
      *(undefined4 *)(iVar2 + 4) = 0x28;
      if (iVar6 < 1) {
        uVar3 = 0;
        iVar6 = 0;
      }
      else {
        uVar3 = 0x100;
      }
      iVar5 = iVar2;
      _msg_receive(iVar2,uVar3,iVar6);
      if (iVar5 != -0xcb) break;
loc_F00DBFE4:
      iVar6 = 0;
      _objc_msgSend(uVar8,paControl,uVar7);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
    }
    if ((iVar5 != 0) || (*(int *)(iVar2 + 0x14) != 0)) {
      _IOExitThread();
      return CONCAT44(param_2,param_1);
    }
    uVar8 = *(undefined4 *)(iVar2 + 0x1c);
    puVar4 = *(undefined4 **)(iVar2 + 0x24);
    uVar7 = *(undefined4 *)(iVar2 + 0x20);
    *(undefined4 *)((int)register0x00000038 + -0x18) = *puVar4;
    *(undefined4 *)((int)register0x00000038 + -0x14) = puVar4[1];
    _microtime((undefined *)((int)register0x00000038 + -0x10));
    iVar6 = *(int *)((int)register0x00000038 + -0x18);
    *(int *)((int)register0x00000038 + -0x18) = iVar6 - *(int *)((int)register0x00000038 + -0x10);
    iVar5 = *(int *)((int)register0x00000038 + -0x14) - *(int *)((int)register0x00000038 + -0xc);
    *(int *)((int)register0x00000038 + -0x14) = iVar5;
    if (iVar5 < 0) {
      *(int *)((int)register0x00000038 + -0x18) =
           (iVar6 - *(int *)((int)register0x00000038 + -0x10)) + -1;
      *(int *)((int)register0x00000038 + -0x14) = iVar5 + 1000000;
    }
    iVar5 = *(int *)((int)register0x00000038 + -0x18);
    iVar6 = *(int *)((int)register0x00000038 + -0x14);
    .div(iVar6,1000);
    iVar6 = iVar5 * 1000 + iVar6;
    if (iVar6 < 1) goto loc_F00DBFE4;
    *(undefined4 *)(iVar2 + 0xc) = uVar1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4793 start=0xf00dc010 */

/* WARNING: Removing unreachable block (ram,0xf00dc14c) */
/* WARNING: Removing unreachable block (ram,0xf00dc120) */
/* WARNING: Removing unreachable block (ram,0xf00dc0a0) */
/* WARNING: Removing unreachable block (ram,0xf00dc028) */
/* WARNING: Removing unreachable block (ram,0xf00dc060) */
/* WARNING: Removing unreachable block (ram,0xf00dc0e8) */
/* WARNING: Removing unreachable block (ram,0xf00dc13c) */
/* WARNING: Removing unreachable block (ram,0xf00dc07c) */
/* WARNING: Removing unreachable block (ram,0xf00dc014) */

undefined8
-[InputStream recordSize:tag:replyTo:replyMsgs:]
          (int *param_1,undefined4 param_2,uint param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  piVar1 = param_1;
  _kern_serv_kernel_task_port();
  _IOConvertPort(param_5,2,0);
  if (param_1[0x1a] == 0) {
    if (param_1[0x1b] == 1) {
      param_3 = param_3 & 0xfffffffe;
    }
    else {
      param_3 = param_3 & 0xfffffffc;
    }
  }
  _vm_allocate_EXTERNAL(piVar1,(undefined *)((int)register0x00000038 + -0x14),param_3,1);
  if (piVar1 == (int *)0x0) {
    piVar1 = param_1;
    _objc_msgSend(param_1,paNewregion);
    piVar1[4] = param_3;
    piVar1[5] = param_4;
    piVar1[7] = param_5;
    piVar1[6] = param_6;
    uVar4 = paLock;
    iVar3 = *(int *)((int)register0x00000038 + -0x14);
    *piVar1 = iVar3;
    piVar1[3] = iVar3;
    piVar1[2] = iVar3;
    piVar1[1] = *piVar1 + param_3;
    param_1[0x18] = param_6;
    param_1[0x17] = param_5;
    _objc_msgSend(param_1[10],uVar4);
    piVar2 = param_1 + 0xb;
    if (piVar2 == (int *)param_1[0xb]) {
      param_1[0xb] = (int)piVar1;
      param_1[0xc] = (int)piVar1;
      piVar1[0xf] = (int)piVar2;
      piVar1[0x10] = (int)piVar2;
    }
    else {
      iVar3 = param_1[0xc];
      piVar1[0x10] = iVar3;
      piVar1[0xf] = (int)piVar2;
      param_1[0xc] = (int)piVar1;
      *(int **)(iVar3 + 0x3c) = piVar1;
    }
    _objc_msgSend(param_1[10],paUnlock);
    uVar4 = paDatapendingfor;
    iVar3 = param_1[2];
    _objc_msgSend(param_1,paChannel);
    _objc_msgSend(iVar3,uVar4,param_1);
    uVar4 = 1;
  }
  else {
    _IOLog(aAudioRecordReq,param_3);
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=4794 start=0xf00dc160 */

undefined8
-[InputStream mixRegion:descriptor:buffer:maxCount:virgin:rate:format:channelCount:]
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          uint param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  uVar1 = *(int *)(param_3 + 4) - *(int *)(param_3 + 8);
  if (param_6 < uVar1) {
    uVar1 = param_6;
  }
  *(uint *)(param_3 + 8) = *(int *)(param_3 + 8) + uVar1;
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4795 start=0xf00dc18c */

/* WARNING: Removing unreachable block (ram,0xf00dc2b8) */
/* WARNING: Removing unreachable block (ram,0xf00dc258) */
/* WARNING: Removing unreachable block (ram,0xf00dc1fc) */
/* WARNING: Removing unreachable block (ram,0xf00dc1c8) */
/* WARNING: Removing unreachable block (ram,0xf00dc1dc) */
/* WARNING: Removing unreachable block (ram,0xf00dc210) */
/* WARNING: Removing unreachable block (ram,0xf00dc2a8) */
/* WARNING: Removing unreachable block (ram,0xf00dc23c) */
/* WARNING: Removing unreachable block (ram,0xf00dc1a8) */

undefined8 -[InputStream sendRecordedDataForRegion:](int param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  int iVar5;
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
  uVar1 = *param_3;
  iVar4 = param_3[3] - uVar1;
  iVar5 = uVar1 - (uVar1 & ~_page_mask);
  _kern_serv_kernel_task_port();
  _vm_read_EXTERNAL();
  if (uVar1 != 0) {
    _IOLog(aAudioVmReadRet,uVar1);
  }
  iVar5 = *(int *)((int)register0x00000038 + -0x14) + iVar5;
  if (iVar4 != 0) {
    uVar1 = param_3[7];
    _IOConvertPort(uVar1,0,1);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    _IOConvertPort(uVar2,0,1);
    if (*(int *)(param_1 + 0x1c) == 0) {
      __NXAudioReplyRecordedData
                (uVar1,uVar2,uVar1,*(undefined4 *)(param_1 + 0x18),param_3[5],iVar5,iVar4);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x34);
      if (iVar3 == 0) {
        iVar3 = 0x2000;
        _IOMalloc(0x2000,uVar1);
        *(int *)(param_1 + 0x34) = iVar3;
        *(undefined *)(iVar3 + 3) = 1;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 0x18;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 8) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0xc) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x14) = 0;
        iVar3 = *(int *)(param_1 + 0x34);
      }
      _audio_snd_reply_recorded_data(iVar3,uVar1,param_3[5],iVar5,iVar4);
      _msg_send(*(undefined4 *)(param_1 + 0x34),0x21,1000);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4796 start=0xf00dc2c8 */

/* WARNING: Removing unreachable block (ram,0xf00dc400) */
/* WARNING: Removing unreachable block (ram,0xf00dc3ac) */

undefined8
-[InputStream completeRegion:descriptor:size:used:]
          (int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int *param_6)

{
  undefined2 uVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 unaff_l0;
  uint uVar7;
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
  pbVar6 = *(byte **)(param_3 + 0xc);
  uVar7 = *(int *)(param_3 + 8) - (int)pbVar6;
  if (param_5 != 0) {
    if (uVar7 == 0) {
      iVar2 = *(int *)(param_3 + 0x24);
      goto loc_F00DC3DC;
    }
    iVar2 = *param_6;
    if (param_5 < iVar2 + uVar7) {
      uVar7 = param_5 - iVar2;
    }
    iVar5 = *(int *)(param_1 + 0x68);
    pbVar3 = (byte *)(*(int *)(param_4 + 4) + iVar2);
    if (iVar5 == 0) {
      uVar4 = 0;
      if (uVar7 >> 1 == 0) goto loc_F00DC3B4;
      do {
        uVar4 = uVar4 + 1;
        uVar1 = *(undefined2 *)pbVar3;
        pbVar3 = pbVar3 + 2;
        *(undefined2 *)pbVar6 = uVar1;
        pbVar6 = pbVar6 + 2;
      } while (uVar4 < uVar7 >> 1);
      iVar2 = *param_6;
    }
    else if (iVar5 == 3) {
      uVar4 = 0;
      if (uVar7 == 0) {
loc_F00DC3B4:
        iVar2 = *param_6;
      }
      else {
        do {
          uVar4 = uVar4 + 1;
          *pbVar6 = *pbVar3 ^ 0x80 | *pbVar3 & 0x7f;
          pbVar6 = pbVar6 + 1;
          pbVar3 = pbVar3 + 1;
        } while (uVar4 < uVar7);
        iVar2 = *param_6;
      }
    }
    else {
      if (iVar5 == 1) {
        _bcopy(pbVar3,pbVar6,uVar7);
        goto loc_F00DC3B4;
      }
      iVar2 = *param_6;
    }
    *param_6 = iVar2 + uVar7;
    *(uint *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + uVar7;
    *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar7;
  }
  iVar2 = *(int *)(param_3 + 0x24);
loc_F00DC3DC:
  if ((iVar2 == param_4) || (*(int *)(param_3 + 0x30) != 0)) {
    _objc_msgSend(param_1,paSendrecordedda,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4797 start=0xf00dc410 */

/* WARNING: Removing unreachable block (ram,0xf00dc4fc) */
/* WARNING: Removing unreachable block (ram,0xf00dc614) */
/* WARNING: Removing unreachable block (ram,0xf00dc57c) */
/* WARNING: Removing unreachable block (ram,0xf00dc54c) */
/* WARNING: Removing unreachable block (ram,0xf00dc4d8) */
/* WARNING: Removing unreachable block (ram,0xf00dc498) */
/* WARNING: Removing unreachable block (ram,0xf00dc42c) */
/* WARNING: Removing unreachable block (ram,0xf00dc4a8) */
/* WARNING: Removing unreachable block (ram,0xf00dc53c) */
/* WARNING: Removing unreachable block (ram,0xf00dc568) */
/* WARNING: Removing unreachable block (ram,0xf00dc590) */
/* WARNING: Removing unreachable block (ram,0xf00dc4f0) */
/* WARNING: Removing unreachable block (ram,0xf00dc50c) */
/* WARNING: Removing unreachable block (ram,0xf00dc414) */

undefined8 -[InputStream returnRecordedData](int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  uint *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar10;
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
  iVar5 = param_1;
  _kern_serv_kernel_task_port();
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
  puVar6 = *(uint **)(param_1 + 0x2c);
  puVar8 = (uint *)0x0;
  bVar1 = false;
  if ((uint *)(param_1 + 0x2c) != puVar6) {
    uVar7 = puVar6[3];
    do {
      if (*puVar6 < uVar7) {
        if (uVar7 < puVar6[1]) {
          bVar1 = true;
          puVar8 = puVar6;
          break;
        }
        puVar6 = (uint *)puVar6[0xf];
      }
      else {
        puVar6 = (uint *)puVar6[0xf];
      }
      puVar8 = puVar6;
      bVar1 = false;
      if ((uint *)(param_1 + 0x2c) == puVar6) break;
      uVar7 = puVar6[3];
    } while( true );
  }
  if (bVar1) {
    piVar3 = (int *)0x44;
    _IOMalloc();
    _memcpy();
    iVar9 = puVar8[3] - *puVar8;
    uVar7 = puVar8[4] - iVar9;
    iVar10 = puVar8[2] - puVar8[3];
    iVar4 = iVar5;
    _vm_allocate_EXTERNAL(iVar5,piVar3,iVar9,1);
    if (iVar4 == 0) {
      puVar8[8] = 0;
      puVar8[10] = 0;
      _bcopy(*puVar8,*piVar3,iVar9);
      iVar4 = iVar5;
      _vm_deallocate_EXTERNAL(iVar5,*puVar8,puVar8[4]);
      if (iVar4 != 0) {
        _IOLog(aAudioVmDealloc,aMachErr);
      }
      _vm_allocate_EXTERNAL(iVar5,puVar8,uVar7,1);
      if (iVar5 != 0) {
        _IOLog(aAudioCannotAll);
        iVar10 = 0;
        uVar7 = 0;
      }
      puVar8[4] = uVar7;
      puVar8[1] = *puVar8 + uVar7;
      puVar8[3] = *puVar8;
      puVar8[2] = *puVar8 + iVar10;
      piVar3[4] = iVar9;
      piVar3[0xc] = 1;
      piVar3[0xb] = 1;
      iVar9 = *piVar3 + iVar9;
      piVar3[1] = iVar9;
      piVar3[2] = iVar9;
      piVar3[3] = iVar9;
      iVar5 = *(int *)(param_1 + 0x2c);
      if (param_1 + 0x2c == iVar5) {
        *(int **)(param_1 + 0x2c) = piVar3;
        *(int **)(param_1 + 0x30) = piVar3;
        piVar3[0xf] = iVar5;
        piVar3[0x10] = iVar5;
      }
      else {
        piVar3[0x10] = param_1 + 0x2c;
        piVar3[0xf] = iVar5;
        *(int **)(param_1 + 0x2c) = piVar3;
        *(int **)(iVar5 + 0x40) = piVar3;
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paUnlock);
      *(undefined *)(param_1 + 0x78) = 0;
      goto locret_F00DC620;
    }
    _IOLog(aAudioCannotAll);
    _IOFree(piVar3,0x44);
    uVar2 = *(undefined4 *)(param_1 + 0x28);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x28);
  }
  _objc_msgSend(uVar2,paUnlock);
  *(undefined *)(param_1 + 0x78) = 1;
locret_F00DC620:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4798 start=0xf00dc628 */

/* WARNING: Removing unreachable block (ram,0xf00dc668) */
/* WARNING: Removing unreachable block (ram,0xf00dc64c) */

undefined8
-[InputStream dmaCompleteDescriptor:transfered:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422d0;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paDmacompletedes,param_3,param_4
                    );
  if (*(char *)(param_1 + 0x78) != '\0') {
    _objc_msgSend(param_1,paReturnrecorded);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4799 start=0xf00dc678 */

/* WARNING: Removing unreachable block (ram,0xf00dc6a4) */
/* WARNING: Removing unreachable block (ram,0xf00dc688) */
/* WARNING: Removing unreachable block (ram,0xf00dc6c8) */
/* WARNING: Removing unreachable block (ram,0xf00dc67c) */

undefined8 -[InputStream freeRegion:](int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
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
  iVar1 = param_1;
  _kern_serv_kernel_task_port();
  _vm_deallocate_EXTERNAL();
  if (iVar1 != 0) {
    _IOLog(aAudioStreamVmD,aMachErr);
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422d0;
  _objc_msgSendSuper(puVar2,paFreeregion,param_3);
  return CONCAT44(param_2,puVar2);
}

