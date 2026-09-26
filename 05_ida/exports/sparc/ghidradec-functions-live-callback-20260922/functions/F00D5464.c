
/* WARNING: Removing unreachable block (ram,0xf00d54b4) */
/* WARNING: Removing unreachable block (ram,0xf00d5498) */
/* WARNING: Removing unreachable block (ram,0xf00d54dc) */
/* WARNING: Removing unreachable block (ram,0xf00d5474) */

undefined8
_EvSetParameterChar(undefined (*param_1) [12],undefined4 param_2,int param_3,undefined4 param_4,
                   undefined4 param_5)

{
  undefined (*pauVar1) [12];
  int iVar2;
  undefined (*pauVar3) [12];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined (*pauVar4) [12];
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
  pauVar1 = paEventdriver_0;
  _objc_msgSend(paEventdriver_0,paInstance);
  if (pauVar1 == (undefined (*) [12])0x0) {
    pauVar4 = (undefined (*) [12])0xfffffd27;
  }
  else {
    iVar2 = param_3;
    _strncmp(param_3,&aEv,3);
    if (iVar2 == 0) {
      pauVar3 = pauVar1;
      _objc_msgSend(pauVar1,paEvPort);
      pauVar4 = (undefined (*) [12])0xfffffd3f;
      if (pauVar3 != param_1) goto locret_F00D54E8;
    }
    _objc_msgSend(pauVar1,paSetcharvaluesF_0,param_4,param_3,param_5);
    pauVar4 = pauVar1;
  }
locret_F00D54E8:
  return CONCAT44(param_2,pauVar4);
}

