
/* WARNING: Removing unreachable block (ram,0xf00d8b14) */
/* WARNING: Removing unreachable block (ram,0xf00d8784) */
/* WARNING: Removing unreachable block (ram,0xf00d8900) */
/* WARNING: Removing unreachable block (ram,0xf00d8b88) */
/* WARNING: Removing unreachable block (ram,0xf00d8a50) */
/* WARNING: Removing unreachable block (ram,0xf00d89a4) */
/* WARNING: Removing unreachable block (ram,0xf00d8804) */
/* WARNING: Removing unreachable block (ram,0xf00d8694) */
/* WARNING: Removing unreachable block (ram,0xf00d8814) */
/* WARNING: Removing unreachable block (ram,0xf00d89b4) */
/* WARNING: Removing unreachable block (ram,0xf00d8a60) */
/* WARNING: Removing unreachable block (ram,0xf00d8b30) */
/* WARNING: Removing unreachable block (ram,0xf00d8914) */
/* WARNING: Removing unreachable block (ram,0xf00d8b48) */
/* WARNING: Removing unreachable block (ram,0xf00d8b74) */
/* WARNING: Removing unreachable block (ram,0xf00d8684) */

undefined8
-[IOAudio _intValueForParameter:forObject:]
          (uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [10];
  undefined (*pauVar3) [9];
  uint uVar4;
  uint uVar5;
  undefined (*pauVar6) [12];
  undefined (*pauVar7) [13];
  undefined (*pauVar8) [19];
  undefined (*pauVar9) [15];
  undefined (*pauVar10) [23];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  pauVar3 = paIsequal;
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
  uVar11 = 0;
  uVar4 = param_1;
  _objc_msgSend(param_1,paInputchannel);
  uVar5 = param_4;
  _objc_msgSend(param_4,pauVar3,uVar4);
  if ((uVar5 & 0xff) == 0) {
    uVar4 = param_1;
    _objc_msgSend(param_1,paOutputchannel);
    uVar5 = param_4;
    _objc_msgSend(param_4,pauVar3,uVar4);
    pauVar2 = paIskindof;
    puVar1 = paClass;
    if ((uVar5 & 0xff) == 0) {
      pauVar6 = paInputstream;
      _objc_msgSend(paInputstream,paClass);
      uVar4 = param_4;
      _objc_msgSend(param_4,pauVar2,pauVar6);
      if ((uVar4 & 0xff) == 0) {
        pauVar7 = paOutputstream;
        _objc_msgSend(paOutputstream,puVar1);
        uVar4 = param_4;
        _objc_msgSend(param_4,pauVar2,pauVar7);
        if ((uVar4 & 0xff) == 0) {
          _IOLog(aAudioUnknownPa);
          goto loc_F00D8B90;
        }
        switch(param_3) {
        case :
          pauVar10 = (undefined (*) [23])paDataencoding_0;
          break;
        case :
          pauVar10 = (undefined (*) [23])paSamplingrate;
          break;
        case :
          pauVar10 = (undefined (*) [23])paChannelcount_0;
          break;
        case :
          pauVar10 = (undefined (*) [23])paHighwatermark;
          break;
        case :
          pauVar10 = (undefined (*) [23])paLowwatermark;
          break;
        :
          goto def_F00D86C0;
        case :
          uVar11 = 0x25f;
          goto def_F00D86C0;
        case :
          goto loc_F00D8B08;
        case :
          uVar4 = param_4;
          _objc_msgSend(param_4,paGainleft);
          pauVar9 = (undefined (*) [15])paGainright;
          goto loc_F00D8B48;
        case :
          pauVar10 = (undefined (*) [23])paGainleft;
          break;
        case :
          pauVar10 = (undefined (*) [23])paGainright;
        }
        goto loc_F00D8B74;
      }
      switch(param_3) {
      case :
        pauVar10 = (undefined (*) [23])paDataencoding_0;
        break;
      case :
        pauVar10 = (undefined (*) [23])paSamplingrate;
        break;
      case :
        pauVar10 = (undefined (*) [23])paChannelcount_0;
        break;
      case :
        pauVar10 = (undefined (*) [23])paHighwatermark;
        break;
      case :
        pauVar10 = (undefined (*) [23])paLowwatermark;
        break;
      case :
        uVar11 = 0x25d;
      :
        goto def_F00D86C0;
      }
      goto loc_F00D8B74;
    }
    switch(param_3) {
    case :
      pauVar10 = (undefined (*) [23])paDescriptorsize;
      goto loc_F00D8B74;
    case :
      pauVar10 = (undefined (*) [23])paDmacount;
      goto loc_F00D8B74;
    case :
      goto loc_F00D8B08;
    case :
    case :
    case :
    case :
loc_F00D8B90:
      uVar11 = 0;
      break;
    case :
    case :
    case :
      pauVar8 = (undefined (*) [19])paIsoutputmuted_0;
      goto loc_F00D8B14;
    case :
      pauVar8 = paIsloudnessenha_0;
loc_F00D8B14:
      _objc_msgSend(param_1,pauVar8);
      uVar11 = (uint)(char)param_1;
      break;
    case :
      uVar4 = param_1;
      _objc_msgSend(param_1,paOutputattenuat_2);
      _objc_msgSend(param_1,paOutputattenuat_1);
      uVar11 = (int)(uVar4 + param_1) / 2;
      break;
    case :
      param_4 = param_1;
      pauVar10 = (undefined (*) [23])paOutputattenuat_2;
      goto loc_F00D8B74;
    case :
      param_4 = param_1;
      pauVar10 = paOutputattenuat_1;
      goto loc_F00D8B74;
    case :
      uVar11 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x16);
      break;
    case :
      uVar11 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x15);
      break;
    case :
      uVar11 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x17);
      break;
    case :
      uVar11 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x18);
      break;
    case :
      uVar11 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x19);
    }
    goto def_F00D86C0;
  }
  switch(param_3) {
  case :
    pauVar10 = (undefined (*) [23])paDescriptorsize;
    goto loc_F00D8B74;
  case :
    pauVar10 = (undefined (*) [23])paDmacount;
    goto loc_F00D8B74;
  case :
loc_F00D8B08:
    param_1 = param_4;
    pauVar8 = (undefined (*) [19])paIsdetectingpea;
    goto loc_F00D8B14;
  case :
    param_4 = param_1;
    pauVar10 = (undefined (*) [23])paAnaloginputsou;
    goto loc_F00D8B74;
  case :
    uVar4 = param_1;
    _objc_msgSend(param_1,paInputgainleft_0);
    param_4 = param_1;
    pauVar9 = paInputgainright_0;
loc_F00D8B48:
    _objc_msgSend(param_4,pauVar9);
    uVar11 = uVar4 + param_4 >> 1;
    break;
  case :
    param_4 = param_1;
    pauVar10 = (undefined (*) [23])paInputgainleft_0;
    goto loc_F00D8B74;
  case :
    param_4 = param_1;
    pauVar10 = (undefined (*) [23])paInputgainright_0;
loc_F00D8B74:
    _objc_msgSend(param_4,pauVar10);
    uVar11 = param_4;
    break;
  case :
    uVar11 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x10);
    break;
  case :
    uVar11 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x11);
    break;
  case :
    uVar11 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x12);
    break;
  case :
    uVar11 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x13);
    break;
  case :
    uVar11 = (int)*(char *)(*(int *)(param_1 + 0x174) + 0x14);
  }
def_F00D86C0:
  return CONCAT44(param_2,uVar11);
}

