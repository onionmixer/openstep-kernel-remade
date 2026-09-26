
/* WARNING: Removing unreachable block (ram,0xf00d91f8) */
/* WARNING: Removing unreachable block (ram,0xf00d91b8) */
/* WARNING: Removing unreachable block (ram,0xf00d9168) */
/* WARNING: Removing unreachable block (ram,0xf00d9128) */
/* WARNING: Removing unreachable block (ram,0xf00d9158) */
/* WARNING: Removing unreachable block (ram,0xf00d91a8) */
/* WARNING: Removing unreachable block (ram,0xf00d91e8) */
/* WARNING: Removing unreachable block (ram,0xf00d9224) */
/* WARNING: Removing unreachable block (ram,0xf00d9118) */

undefined8
-[IOAudio _getSupportedParameters:count:forObject:]
          (undefined6 *param_1,undefined4 param_2,int param_3,uint *param_4,uint param_5)

{
  undefined (*pauVar1) [10];
  undefined (*pauVar2) [9];
  undefined (*pauVar3) [14];
  undefined6 *puVar4;
  undefined (*pauVar5) [12];
  undefined (*pauVar6) [13];
  int iVar7;
  uint uVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar9;
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
  
  pauVar3 = paInputchannel;
  pauVar2 = paIsequal;
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
  puVar9 = (undefined *)0x0;
  *param_4 = 0;
  puVar4 = param_1;
  _objc_msgSend(param_1,pauVar3);
  uVar8 = param_5;
  _objc_msgSend(param_5,pauVar2,puVar4);
  if ((uVar8 & 0xff) == 0) {
    puVar4 = param_1;
    _objc_msgSend(param_1,paOutputchannel);
    uVar8 = param_5;
    _objc_msgSend(param_5,pauVar2,puVar4);
    pauVar1 = paIskindof;
    puVar4 = paClass;
    if ((uVar8 & 0xff) == 0) {
      pauVar5 = paInputstream;
      _objc_msgSend(paInputstream,paClass);
      uVar8 = param_5;
      _objc_msgSend(param_5,pauVar1,pauVar5);
      if ((uVar8 & 0xff) == 0) {
        pauVar6 = paOutputstream;
        _objc_msgSend(paOutputstream,puVar4);
        _objc_msgSend(param_5,pauVar1,pauVar6);
        if ((param_5 & 0xff) == 0) {
          _IOLog(aAudioUnknownPa);
        }
        else {
          puVar9 = unk_F00F9724;
          *param_4 = 10;
        }
      }
      else {
        puVar9 = unk_F00F974C;
        *param_4 = 6;
      }
    }
    else {
      puVar9 = unk_F00F96D0;
      *param_4 = 0xe;
      puVar4 = param_1;
    }
  }
  else {
    puVar9 = unk_F00F9708;
    *param_4 = 7;
    puVar4 = param_1;
  }
  uVar8 = 0;
  iVar7 = 0;
  if (*param_4 != 0) {
    do {
      uVar8 = uVar8 + 1;
      *(undefined4 *)(iVar7 + param_3) = *(undefined4 *)(puVar9 + iVar7);
      iVar7 = iVar7 + 4;
    } while (uVar8 < *param_4);
  }
  return CONCAT44(param_2,puVar4);
}

