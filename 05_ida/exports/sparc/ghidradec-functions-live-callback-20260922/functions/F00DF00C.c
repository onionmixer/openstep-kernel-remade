
/* WARNING: Removing unreachable block (ram,0xf00df06c) */
/* WARNING: Removing unreachable block (ram,0xf00df04c) */
/* WARNING: Removing unreachable block (ram,0xf00df034) */
/* WARNING: Removing unreachable block (ram,0xf00df060) */
/* WARNING: Removing unreachable block (ram,0xf00df080) */
/* WARNING: Removing unreachable block (ram,0xf00df028) */

undefined8 __NXAudioGetSamplingRates(int param_1,int *param_2)

{
  undefined (*pauVar1) [12];
  int iVar2;
  undefined4 *in_o5;
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
  char cVar3;
  
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
  *in_o5 = 0;
  pauVar1 = paAudiodevice;
  if (param_1 == 0) {
    uVar4 = 0xca;
  }
  else {
    iVar2 = param_1;
    _objc_msgSend(param_1,paAudiodevice);
    cVar3 = (char)iVar2;
    _objc_msgSend();
    *param_2 = (int)cVar3;
    _objc_msgSend(param_1,pauVar1);
    _objc_msgSend();
    _objc_msgSend(param_1,pauVar1);
    _objc_msgSend();
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}

