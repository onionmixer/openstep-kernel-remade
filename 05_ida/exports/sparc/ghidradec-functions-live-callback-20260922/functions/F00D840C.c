
/* WARNING: Removing unreachable block (ram,0xf00d8460) */
/* WARNING: Removing unreachable block (ram,0xf00d8508) */
/* WARNING: Removing unreachable block (ram,0xf00d84d0) */
/* WARNING: Removing unreachable block (ram,0xf00d8498) */
/* WARNING: Removing unreachable block (ram,0xf00d856c) */
/* WARNING: Removing unreachable block (ram,0xf00d8540) */

undefined8
-[IOAudio _setOutputFor:to:](int param_1,undefined4 param_2,undefined4 param_3,undefined param_4)

{
  undefined (*pauVar1) [14];
  undefined6 *puVar2;
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
  
  pauVar1 = paAudiocommand_0;
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
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x16) = param_4;
    _objc_msgSend(param_1,pauVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x15) = param_4;
    _objc_msgSend(param_1,pauVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x17) = param_4;
    _objc_msgSend(param_1,pauVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x18) = param_4;
    _objc_msgSend(param_1,pauVar1);
    break;
  case :
    *(undefined *)(*(int *)(param_1 + 0x174) + 0x19) = param_4;
    _objc_msgSend(param_1,pauVar1);
    break;
  :
    _IOLog(aAudioUnknownOu);
    return CONCAT44(param_2,param_1);
  }
  puVar2 = paSend;
  _objc_msgSend();
  return CONCAT44(puVar2,param_1);
}

