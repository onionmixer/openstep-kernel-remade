
/* WARNING: Removing unreachable block (ram,0xf00e9650) */
/* WARNING: Removing unreachable block (ram,0xf00e9630) */
/* WARNING: Removing unreachable block (ram,0xf00e95d8) */
/* WARNING: Removing unreachable block (ram,0xf00e95a4) */
/* WARNING: Removing unreachable block (ram,0xf00e9618) */
/* WARNING: Removing unreachable block (ram,0xf00e9644) */
/* WARNING: Removing unreachable block (ram,0xf00e9660) */
/* WARNING: Removing unreachable block (ram,0xf00e9588) */

undefined8 -[IOFrameBufferDisplay _registerWithED](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [10];
  undefined (*pauVar2) [9];
  undefined (*pauVar3) [12];
  undefined (*pauVar4) [12];
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
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
  undefined auStackX_0 [92];
  
  pauVar3 = paEventdriver_0;
  pauVar2 = paInstance;
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
  pauVar4 = paEventdriver_0;
  _objc_msgSend(paEventdriver_0,paInstance);
  _objc_msgSend();
  if (pauVar4 != (undefined (*) [12])0xffffffff) {
    if (*(uint *)((int)register0x00000038 + -0x1c) < 0x1449) {
      iVar5 = *(int *)(param_1 + 0x1fc);
      _memset(iVar5,0);
      *(undefined *)(iVar5 + 8) = 1;
      *(undefined2 *)(iVar5 + 0x30) = *(undefined2 *)((int)register0x00000038 + -0x18);
      *(undefined2 *)(iVar5 + 0x32) = *(undefined2 *)((int)register0x00000038 + -0x16);
      *(undefined2 *)(iVar5 + 0x34) = *(undefined2 *)((int)register0x00000038 + -0x14);
      pauVar1 = paSettoken;
      *(undefined2 *)(iVar5 + 0x36) = *(undefined2 *)((int)register0x00000038 + -0x12);
      uVar6 = 0;
      _objc_msgSend(param_1,pauVar1,pauVar4);
      goto locret_F00E966C;
    }
    _objc_msgSend(param_1,paName);
    _IOLog(aSShmemSizeSize,param_1,*(undefined4 *)((int)register0x00000038 + -0x1c),0x1448);
    _objc_msgSend(pauVar3,pauVar2);
    _objc_msgSend();
  }
  uVar6 = 0xfffffd3e;
locret_F00E966C:
  return CONCAT44(param_2,uVar6);
}

