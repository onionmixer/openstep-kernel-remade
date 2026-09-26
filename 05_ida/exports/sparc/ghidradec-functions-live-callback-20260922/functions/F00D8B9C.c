
/* WARNING: Removing unreachable block (ram,0xf00d9030) */
/* WARNING: Removing unreachable block (ram,0xf00d8e14) */
/* WARNING: Removing unreachable block (ram,0xf00d9040) */
/* WARNING: Removing unreachable block (ram,0xf00d8f04) */
/* WARNING: Removing unreachable block (ram,0xf00d8e38) */
/* WARNING: Removing unreachable block (ram,0xf00d8ce0) */
/* WARNING: Removing unreachable block (ram,0xf00d8bc4) */
/* WARNING: Removing unreachable block (ram,0xf00d8c90) */
/* WARNING: Removing unreachable block (ram,0xf00d8cf0) */
/* WARNING: Removing unreachable block (ram,0xf00d8e48) */
/* WARNING: Removing unreachable block (ram,0xf00d8f14) */
/* WARNING: Removing unreachable block (ram,0xf00d9004) */
/* WARNING: Removing unreachable block (ram,0xf00d8dc8) */
/* WARNING: Removing unreachable block (ram,0xf00d8fec) */
/* WARNING: Removing unreachable block (ram,0xf00d8bb4) */

undefined8
-[IOAudio _setParameter:toInt:forObject:]
          (uint param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [10];
  undefined (*pauVar3) [9];
  uint uVar4;
  uint uVar5;
  undefined (*pauVar6) [12];
  undefined (*pauVar7) [13];
  undefined (*pauVar8) [18];
  undefined (*pauVar9) [22];
  undefined (*pauVar10) [28];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar11;
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
  uVar11 = 1;
  uVar4 = param_1;
  _objc_msgSend(param_1,paInputchannel);
  uVar5 = param_5;
  _objc_msgSend(param_5,pauVar3,uVar4);
  if ((uVar5 & 0xff) != 0) {
    switch(param_3) {
    case :
    case :
      goto locret_F00D904C;
    case :
loc_F00D8FDC:
      param_1 = param_5;
      pauVar9 = (undefined (*) [22])paSetdetectpeaks;
      goto loc_F00D8FE8;
    :
      goto def_F00D8BF0;
    case :
      param_5 = param_1;
      pauVar10 = (undefined (*) [28])paSetanaloginput;
      break;
    case :
      _objc_msgSend(param_1,paSetinputgainle,param_4);
      param_5 = param_1;
      pauVar10 = (undefined (*) [28])paSetinputgainri;
      break;
    case :
      param_5 = param_1;
      pauVar10 = (undefined (*) [28])paSetinputgainle;
      break;
    case :
    case :
    case :
    case :
    case :
      pauVar8 = (undefined (*) [18])paSetinputforTo;
loc_F00D8E0C:
      _objc_msgSend(param_1,pauVar8,param_3,(int)(char)param_4);
      goto locret_F00D904C;
    }
    goto loc_F00D9030;
  }
  uVar4 = param_1;
  _objc_msgSend(param_1,paOutputchannel);
  uVar5 = param_5;
  _objc_msgSend(param_5,pauVar3,uVar4);
  pauVar2 = paIskindof;
  puVar1 = paClass;
  if ((uVar5 & 0xff) == 0) {
    pauVar6 = paInputstream;
    _objc_msgSend(paInputstream,paClass);
    uVar4 = param_5;
    _objc_msgSend(param_5,pauVar2,pauVar6);
    if ((uVar4 & 0xff) != 0) {
      switch(param_3) {
      case :
        pauVar10 = (undefined (*) [28])paSetdataencodin_0;
        break;
      case :
        pauVar10 = (undefined (*) [28])paSetsamplingrat;
        break;
      case :
        pauVar10 = (undefined (*) [28])paSetchannelcoun_0;
        break;
      case :
        pauVar10 = (undefined (*) [28])paSethighwaterma;
        break;
      case :
        pauVar10 = (undefined (*) [28])paSetlowwatermar;
        break;
      case :
        if (param_4 != 0x25d) {
          uVar11 = 0;
        }
        goto locret_F00D904C;
      :
        goto def_F00D8BF0;
      }
      goto loc_F00D9030;
    }
    pauVar7 = paOutputstream;
    _objc_msgSend(paOutputstream,puVar1);
    uVar4 = param_5;
    _objc_msgSend(param_5,pauVar2,pauVar7);
    if ((uVar4 & 0xff) == 0) {
      _IOLog(aAudioUnknownPa);
def_F00D8BF0:
      uVar11 = 0;
      goto locret_F00D904C;
    }
    switch(param_3) {
    case :
      pauVar10 = (undefined (*) [28])paSetdataencodin_0;
      break;
    case :
      pauVar10 = (undefined (*) [28])paSetsamplingrat;
      break;
    case :
      pauVar10 = (undefined (*) [28])paSetchannelcoun_0;
      break;
    case :
      pauVar10 = (undefined (*) [28])paSethighwaterma;
      break;
    case :
      pauVar10 = (undefined (*) [28])paSetlowwatermar;
      break;
    :
      goto def_F00D8BF0;
    case :
      if (param_4 != 0x25f) {
        uVar11 = 0;
      }
      goto locret_F00D904C;
    case :
      goto loc_F00D8FDC;
    case :
      _objc_msgSend(param_5,paSetgainleft,param_4);
      pauVar10 = (undefined (*) [28])paSetgainright;
      break;
    case :
      pauVar10 = (undefined (*) [28])paSetgainleft;
      break;
    case :
      pauVar10 = (undefined (*) [28])paSetgainright;
    }
    goto loc_F00D9030;
  }
  switch(param_3) {
  case :
  case :
  case :
  case :
  case :
  case :
    goto locret_F00D904C;
  case :
    goto loc_F00D8FDC;
  case :
  case :
  case :
    pauVar9 = (undefined (*) [22])paSetoutputmute;
    goto loc_F00D8FE8;
  case :
    pauVar9 = paSetloudnessenh;
loc_F00D8FE8:
    _objc_msgSend(param_1,pauVar9,(int)(char)param_4);
    goto locret_F00D904C;
  case :
    _objc_msgSend(param_1,paSetoutputatten_0,param_4);
    param_5 = param_1;
    pauVar10 = paSetoutputatten;
    break;
  case :
    param_5 = param_1;
    pauVar10 = (undefined (*) [28])paSetoutputatten_0;
    break;
  case :
    param_5 = param_1;
    pauVar10 = paSetoutputatten;
    break;
  :
    goto def_F00D8BF0;
  case :
  case :
  case :
  case :
  case :
    pauVar8 = paSetoutputforTo;
    goto loc_F00D8E0C;
  }
loc_F00D9030:
  _objc_msgSend(param_5,pauVar10,param_4);
locret_F00D904C:
  return CONCAT44(param_2,uVar11);
}

