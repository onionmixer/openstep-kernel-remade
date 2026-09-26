
/* WARNING: Removing unreachable block (ram,0xf00dbfcc) */
/* WARNING: Removing unreachable block (ram,0xf00dc000) */
/* WARNING: Removing unreachable block (ram,0xf00dbee8) */
/* WARNING: Removing unreachable block (ram,0xf00dbf28) */
/* WARNING: Removing unreachable block (ram,0xf00dbf70) */
/* WARNING: Removing unreachable block (ram,0xf00dbff0) */
/* WARNING: Removing unreachable block (ram,0xf00dbeb8) */

undefined8 sub_F00DBEB4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 uVar8;
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
  iVar2 = 0x28;
  _IOMalloc();
  uVar1 = dword_F012EF38;
  iVar6 = 0;
  uVar8 = 0;
  uVar7 = 0;
  _objc_msgSend(dword_F012EF3C,paUnlock);
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  do {
    while( true ) {
      *(undefined4 *)(iVar2 + 4) = 0x28;
      if (iVar6 < 1) {
        uVar3 = 0;
        iVar6 = 0;
      }
      else {
        uVar3 = 0x100;
      }
      iVar5 = iVar2;
      _msg_receive(iVar2,uVar3,iVar6);
      if (iVar5 != -0xcb) break;
loc_F00DBFE4:
      iVar6 = 0;
      _objc_msgSend(uVar8,paControl,uVar7);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
    }
    if ((iVar5 != 0) || (*(int *)(iVar2 + 0x14) != 0)) {
      _IOExitThread();
      return CONCAT44(param_2,param_1);
    }
    uVar8 = *(undefined4 *)(iVar2 + 0x1c);
    puVar4 = *(undefined4 **)(iVar2 + 0x24);
    uVar7 = *(undefined4 *)(iVar2 + 0x20);
    *(undefined4 *)((int)register0x00000038 + -0x18) = *puVar4;
    *(undefined4 *)((int)register0x00000038 + -0x14) = puVar4[1];
    _microtime((undefined *)((int)register0x00000038 + -0x10));
    iVar6 = *(int *)((int)register0x00000038 + -0x18);
    *(int *)((int)register0x00000038 + -0x18) = iVar6 - *(int *)((int)register0x00000038 + -0x10);
    iVar5 = *(int *)((int)register0x00000038 + -0x14) - *(int *)((int)register0x00000038 + -0xc);
    *(int *)((int)register0x00000038 + -0x14) = iVar5;
    if (iVar5 < 0) {
      *(int *)((int)register0x00000038 + -0x18) =
           (iVar6 - *(int *)((int)register0x00000038 + -0x10)) + -1;
      *(int *)((int)register0x00000038 + -0x14) = iVar5 + 1000000;
    }
    iVar5 = *(int *)((int)register0x00000038 + -0x18);
    iVar6 = *(int *)((int)register0x00000038 + -0x14);
    .div(iVar6,1000);
    iVar6 = iVar5 * 1000 + iVar6;
    if (iVar6 < 1) goto loc_F00DBFE4;
    *(undefined4 *)(iVar2 + 0xc) = uVar1;
  } while( true );
}
