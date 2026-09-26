
/* WARNING: Removing unreachable block (ram,0xf00c9a90) */
/* WARNING: Removing unreachable block (ram,0xf00c9a64) */
/* WARNING: Removing unreachable block (ram,0xf00c9a30) */
/* WARNING: Removing unreachable block (ram,0xf00c99fc) */
/* WARNING: Removing unreachable block (ram,0xf00c99c4) */
/* WARNING: Removing unreachable block (ram,0xf00c9998) */
/* WARNING: Removing unreachable block (ram,0xf00c99ac) */
/* WARNING: Removing unreachable block (ram,0xf00c99ec) */
/* WARNING: Removing unreachable block (ram,0xf00c9a18) */
/* WARNING: Removing unreachable block (ram,0xf00c9a40) */
/* WARNING: Removing unreachable block (ram,0xf00c9ab8) */
/* WARNING: Removing unreachable block (ram,0xf00c9ae0) */
/* WARNING: Removing unreachable block (ram,0xf00c9964) */

undefined8
-[IODirectDevice _changeInterrupt:to:](uint param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined (*pauVar3) [10];
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
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
  uVar1 = *(uint *)(param_1 + 0x108);
  iVar6 = *(int *)(param_1 + 0x11c);
  _objc_msgSend(uVar1,paNuminterrupts);
  if (param_3 < uVar1) {
    if (*(int *)(iVar6 + 4) == 0) {
      pauVar3 = paHashtable;
      _objc_msgSend(paHashtable,paAlloc);
      _objc_msgSend();
      *(undefined (**) [10])(iVar6 + 4) = pauVar3;
      iVar2 = *(int *)(iVar6 + 4);
    }
    else {
      iVar2 = *(int *)(iVar6 + 4);
    }
    _objc_msgSend(iVar2,paValueforkey,param_3);
    if (iVar2 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x18) = 3;
      iVar2 = *(int *)(param_1 + 0x114);
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
      _objc_msgSend(iVar2,paDevice_0);
      _objc_msgSend();
      _objc_msgSend(*(undefined4 *)(iVar6 + 4),paInsertkeyValue,param_3,iVar2);
      uVar4 = *(undefined4 *)(param_1 + 0x114);
      _objc_msgSend(uVar4,paResourcesforke,aIrqLevels);
      _objc_msgSend();
      _objc_msgSend(param_1,paGethandlerLeve,(undefined *)((int)register0x00000038 + -0x14),
                    (undefined *)((int)register0x00000038 + -0x18),
                    (undefined *)((int)register0x00000038 + -0x1c),param_3);
      if ((param_1 & 0xff) == 0) {
        _objc_msgSend(iVar2,paAttachtobusint_0,uVar4,param_3 + 0x232325);
      }
      else {
        _objc_msgSend(iVar2,paAttachtobusint,uVar4,*(undefined4 *)((int)register0x00000038 + -0x14),
                      *(undefined4 *)((int)register0x00000038 + -0x1c),
                      *(undefined4 *)((int)register0x00000038 + -0x18));
      }
    }
    puVar5 = paSuspend;
    if ((param_4 & 0xff) != 0) {
      puVar5 = (undefined8 *)paResume;
    }
    _objc_msgSend(iVar2,puVar5);
    uVar4 = 0;
  }
  else {
    uVar4 = 0xfffffd3e;
  }
  return CONCAT44(param_2,uVar4);
}
