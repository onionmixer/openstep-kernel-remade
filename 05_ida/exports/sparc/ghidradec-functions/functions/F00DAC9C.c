
/* WARNING: Removing unreachable block (ram,0xf00dacfc) */
/* WARNING: Removing unreachable block (ram,0xf00dacb8) */
/* WARNING: Removing unreachable block (ram,0xf00dacf0) */
/* WARNING: Removing unreachable block (ram,0xf00dad18) */
/* WARNING: Removing unreachable block (ram,0xf00daca8) */

undefined8 -[AudioChannel controlStreams:](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paLock);
  iVar1 = *(int *)(param_1 + 0xc);
  _objc_msgSend(iVar1,paCount_0);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  else if (iVar1 < 1) {
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
    iVar3 = 0;
    while( true ) {
      _objc_msgSend(uVar2,paObjectat,iVar3);
      _objc_msgSend();
      if (iVar1 <= iVar3 + 1) break;
      uVar2 = *(undefined4 *)(param_1 + 0xc);
      iVar3 = iVar3 + 1;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}
