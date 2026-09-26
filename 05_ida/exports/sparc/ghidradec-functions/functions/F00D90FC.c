
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
          (undefined4 param_1,undefined4 param_2,int param_3,uint *param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar2 = paInputchannel;
  uVar6 = paIsequal;
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
  puVar5 = (undefined *)0x0;
  *param_4 = 0;
  uVar1 = param_1;
  _objc_msgSend(param_1,uVar2);
  uVar4 = param_5;
  _objc_msgSend(param_5,uVar6,uVar1);
  if ((uVar4 & 0xff) == 0) {
    uVar2 = param_1;
    _objc_msgSend(param_1,paOutputchannel);
    uVar4 = param_5;
    _objc_msgSend(param_5,uVar6,uVar2);
    uVar2 = paIskindof;
    uVar6 = paClass;
    if ((uVar4 & 0xff) == 0) {
      uVar1 = paInputstream;
      _objc_msgSend(paInputstream,paClass);
      uVar4 = param_5;
      _objc_msgSend(param_5,uVar2,uVar1);
      if ((uVar4 & 0xff) == 0) {
        uVar1 = paOutputstream;
        _objc_msgSend(paOutputstream,uVar6);
        _objc_msgSend(param_5,uVar2,uVar1);
        if ((param_5 & 0xff) == 0) {
          _IOLog(aAudioUnknownPa);
        }
        else {
          puVar5 = unk_F00F9724;
          *param_4 = 10;
        }
      }
      else {
        puVar5 = unk_F00F974C;
        *param_4 = 6;
      }
    }
    else {
      puVar5 = unk_F00F96D0;
      *param_4 = 0xe;
      uVar6 = param_1;
    }
  }
  else {
    puVar5 = unk_F00F9708;
    *param_4 = 7;
    uVar6 = param_1;
  }
  uVar4 = 0;
  iVar3 = 0;
  if (*param_4 != 0) {
    do {
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar3 + param_3) = *(undefined4 *)(puVar5 + iVar3);
      iVar3 = iVar3 + 4;
    } while (uVar4 < *param_4);
  }
  return CONCAT44(param_2,uVar6);
}
