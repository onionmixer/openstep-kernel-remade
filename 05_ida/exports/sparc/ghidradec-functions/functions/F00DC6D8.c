
/* WARNING: Removing unreachable block (ram,0xf00dc7d8) */
/* WARNING: Removing unreachable block (ram,0xf00dc754) */
/* WARNING: Removing unreachable block (ram,0xf00dc7c8) */
/* WARNING: Removing unreachable block (ram,0xf00dc768) */
/* WARNING: Removing unreachable block (ram,0xf00dc70c) */

undefined8
-[OutputStream initChannel:tag:user:owner:type:]
          (int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
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
  uint uVar6;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422f8;
  _objc_msgSendSuper(puVar1,paInitchannelTag,param_3,param_4,param_5,param_6,
                     *(undefined4 *)((int)register0x00000038 + 0x5c));
  if (puVar1 == (undefined *)0x0) {
    param_1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x7c) = 0x8000;
    *(undefined4 *)(param_1 + 0x78) = 0x8000;
    *(undefined4 *)(param_1 + 0x98) = 1;
    iVar2 = param_1 + 0x8c;
    *(int *)(param_1 + 0x90) = iVar2;
    *(int *)(param_1 + 0x8c) = iVar2;
    for (uVar6 = 0; uVar3 = param_3, _objc_msgSend(param_3,paDmacount), uVar6 < uVar3;
        uVar6 = uVar6 + 1) {
      puVar4 = (undefined4 *)0x1c;
      _IOMalloc();
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[3] = 0;
      puVar4[2] = 0;
      puVar4[4] = 0;
      if (iVar2 == *(int *)(param_1 + 0x8c)) {
        *(undefined4 **)(param_1 + 0x8c) = puVar4;
        *(undefined4 **)(param_1 + 0x90) = puVar4;
        puVar4[5] = iVar2;
        puVar4[6] = iVar2;
      }
      else {
        iVar5 = *(int *)(param_1 + 0x90);
        puVar4[6] = iVar5;
        puVar4[5] = iVar2;
        *(undefined4 **)(param_1 + 0x90) = puVar4;
        *(undefined4 **)(iVar5 + 0x14) = puVar4;
      }
    }
    iVar5 = _page_size << 3;
    _IOMalloc();
    iVar2 = _page_size;
    *(int *)(param_1 + 0x70) = iVar5;
    iVar2 = iVar2 << 2;
    _IOMalloc();
    *(int *)(param_1 + 0x74) = iVar2;
  }
  return CONCAT44(param_2,param_1);
}
