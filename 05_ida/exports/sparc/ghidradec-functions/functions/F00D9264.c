
/* WARNING: Removing unreachable block (ram,0xf00d9378) */
/* WARNING: Removing unreachable block (ram,0xf00d9324) */
/* WARNING: Removing unreachable block (ram,0xf00d92e4) */
/* WARNING: Removing unreachable block (ram,0xf00d9290) */
/* WARNING: Removing unreachable block (ram,0xf00d92d4) */
/* WARNING: Removing unreachable block (ram,0xf00d9314) */
/* WARNING: Removing unreachable block (ram,0xf00d9368) */
/* WARNING: Removing unreachable block (ram,0xf00d93e8) */
/* WARNING: Removing unreachable block (ram,0xf00d9280) */

undefined8
-[IOAudio _getValues:count:forParameter:forObject:]
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,int param_5
          ,uint param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  char cVar5;
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
  
  uVar2 = paInputchannel;
  uVar1 = paIsequal;
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
  cVar5 = '\x01';
  *param_4 = 0;
  uVar3 = param_1;
  _objc_msgSend(param_1,uVar2);
  uVar4 = param_6;
  _objc_msgSend(param_6,uVar1,uVar3);
  if ((uVar4 & 0xff) == 0) {
    _objc_msgSend(param_1,paOutputchannel);
    uVar4 = param_6;
    _objc_msgSend(param_6,uVar1,param_1);
    uVar2 = paIskindof;
    uVar1 = paClass;
    if ((uVar4 & 0xff) == 0) {
      uVar3 = paInputstream;
      _objc_msgSend(paInputstream,paClass);
      uVar4 = param_6;
      _objc_msgSend(param_6,uVar2,uVar3);
      if ((uVar4 & 0xff) == 0) {
        uVar3 = paOutputstream;
        _objc_msgSend(paOutputstream,uVar1);
        _objc_msgSend(param_6,uVar2,uVar3);
        if ((param_6 & 0xff) == 0) {
          _IOLog(aAudioUnknownPa);
          cVar5 = '\0';
          goto loc_F00D93F4;
        }
        if (param_5 != 400) {
          if (param_5 == 0x196) {
            *param_4 = 1;
            *param_3 = 0x25f;
          }
          else {
            cVar5 = '\0';
          }
          goto loc_F00D93F4;
        }
      }
      else if (param_5 != 400) {
        if (param_5 == 0x195) {
          *param_4 = 1;
          *param_3 = 0x25d;
        }
        else {
          cVar5 = '\0';
        }
        goto loc_F00D93F4;
      }
      *param_4 = 4;
      *param_3 = 600;
      param_3[1] = 0x259;
      param_3[2] = 0x25a;
      param_3[3] = 0x25b;
    }
    else {
      cVar5 = '\0';
    }
  }
  else if (param_5 == 0xe) {
    *param_4 = 2;
    *param_3 = 200;
    param_3[1] = 0xc9;
  }
  else {
    cVar5 = -0x2e;
  }
loc_F00D93F4:
  return CONCAT44(param_2,(int)cVar5);
}
