
/* WARNING: Removing unreachable block (ram,0xf00da670) */
/* WARNING: Removing unreachable block (ram,0xf00da640) */
/* WARNING: Removing unreachable block (ram,0xf00da604) */
/* WARNING: Removing unreachable block (ram,0xf00da5a0) */
/* WARNING: Removing unreachable block (ram,0xf00da574) */
/* WARNING: Removing unreachable block (ram,0xf00da5d8) */
/* WARNING: Removing unreachable block (ram,0xf00da508) */
/* WARNING: Removing unreachable block (ram,0xf00da530) */
/* WARNING: Removing unreachable block (ram,0xf00da5ec) */
/* WARNING: Removing unreachable block (ram,0xf00da58c) */
/* WARNING: Removing unreachable block (ram,0xf00da5b4) */
/* WARNING: Removing unreachable block (ram,0xf00da618) */
/* WARNING: Removing unreachable block (ram,0xf00da654) */
/* WARNING: Removing unreachable block (ram,0xf00da67c) */
/* WARNING: Removing unreachable block (ram,0xf00da4f8) */

undefined8 -[AudioChannel dequeueDescriptor](int param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
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
  iVar8 = *(int *)(param_1 + 0x24);
  iVar7 = *(int *)(iVar8 + 8);
  piVar5 = *(int **)(iVar8 + 0xc);
  iVar6 = iVar7;
  if (param_1 + 0x24 != iVar7) {
    iVar6 = iVar7 + 8;
  }
  *(int **)(iVar6 + 4) = piVar5;
  piVar1 = piVar5 + 2;
  if ((int *)(param_1 + 0x24) == piVar5) {
    piVar1 = piVar5;
  }
  *piVar1 = iVar7;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paLock);
  uVar2 = *(uint *)(param_1 + 0xc);
  _objc_msgSend(uVar2,paCount_0);
  if (uVar2 == 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    if (*(int *)(param_1 + 0x50) != 0) {
      uVar4 = *(uint *)(param_1 + 4);
      _objc_msgSend(uVar4,paDataencoding_0);
      if (uVar4 == 0x259) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),paChannelcount_0);
        _audio_linear8_peak();
        uVar3 = *(undefined4 *)(param_1 + 0x58);
      }
      else if (uVar4 < 0x25a) {
        if (uVar4 == 600) {
          _objc_msgSend(*(undefined4 *)(param_1 + 4),paChannelcount_0);
          _audio_linear16_peak();
          uVar3 = *(undefined4 *)(param_1 + 0x58);
        }
        else {
          uVar3 = *(undefined4 *)(param_1 + 0x58);
        }
      }
      else if (uVar4 == 0x25a) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),paChannelcount_0);
        _audio_mulaw8_peak();
        uVar3 = *(undefined4 *)(param_1 + 0x58);
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 0x58);
      }
      _audio_add_peak(uVar3,*(undefined4 *)((int)register0x00000038 + -0x14),param_1 + 0x60,
                      *(undefined4 *)(param_1 + 0x54));
      _audio_add_peak(*(undefined4 *)(param_1 + 0x5c),
                      *(undefined4 *)((int)register0x00000038 + -0x18),param_1 + 0x60,
                      *(undefined4 *)(param_1 + 0x54));
    }
    uVar4 = 0;
    if (uVar2 == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x10);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0xc);
      while( true ) {
        _objc_msgSend(uVar3,paObjectat,uVar4);
        uVar4 = uVar4 + 1;
        _objc_msgSend();
        if (uVar2 <= uVar4) break;
        uVar3 = *(undefined4 *)(param_1 + 0xc);
      }
      uVar3 = *(undefined4 *)(param_1 + 0x10);
    }
  }
  _objc_msgSend(uVar3,paUnlock);
  _bzero(*(undefined4 *)(iVar8 + 4),*(undefined4 *)(param_1 + 0x40));
  iVar6 = param_1 + 0x2c;
  if (iVar6 == *(int *)(param_1 + 0x2c)) {
    *(int *)(param_1 + 0x2c) = iVar8;
    *(int *)(param_1 + 0x30) = iVar8;
    *(int *)(iVar8 + 8) = iVar6;
    *(int *)(iVar8 + 0xc) = iVar6;
  }
  else {
    iVar7 = *(int *)(param_1 + 0x30);
    *(int *)(iVar8 + 0xc) = iVar7;
    *(int *)(iVar8 + 8) = iVar6;
    *(int *)(param_1 + 0x30) = iVar8;
    *(int *)(iVar7 + 8) = iVar8;
  }
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + -1;
  return CONCAT44(param_2,param_1);
}

