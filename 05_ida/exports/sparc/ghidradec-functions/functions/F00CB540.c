
/* WARNING: Removing unreachable block (ram,0xf00cb644) */
/* WARNING: Removing unreachable block (ram,0xf00cb614) */
/* WARNING: Removing unreachable block (ram,0xf00cb59c) */
/* WARNING: Removing unreachable block (ram,0xf00cb56c) */
/* WARNING: Removing unreachable block (ram,0xf00cb57c) */
/* WARNING: Removing unreachable block (ram,0xf00cb5b8) */
/* WARNING: Removing unreachable block (ram,0xf00cb634) */
/* WARNING: Removing unreachable block (ram,0xf00cb664) */
/* WARNING: Removing unreachable block (ram,0xf00cb54c) */

undefined8 -[IOEthernet free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
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
  _objc_msgSend(param_1,paCleartimeout);
  if (*(int *)(param_1 + 300) == 0) {
    iVar6 = *(int *)(param_1 + 0x14c);
  }
  else {
    _objc_msgSend(*(int *)(param_1 + 300),paSend,4);
    _objc_msgSend(*(undefined4 *)(param_1 + 300),paFree);
    iVar6 = *(int *)(param_1 + 0x14c);
  }
  if (iVar6 == 0) {
    iVar6 = *(int *)(param_1 + 0x138);
  }
  else {
    _objc_msgSend(iVar6,paFree);
    iVar6 = *(int *)(param_1 + 0x138);
  }
  if (iVar6 != 0) {
    _objc_msgSend(iVar6,paLock);
    piVar4 = (int *)(param_1 + 0x144);
    if (piVar4 == *(int **)(param_1 + 0x144)) {
      uVar1 = *(undefined4 *)(param_1 + 0x138);
    }
    else {
      piVar2 = *(int **)(param_1 + 0x144);
      piVar8 = (int *)piVar2[2];
      while( true ) {
        piVar7 = (int *)piVar2[3];
        piVar5 = piVar4;
        if (piVar4 != piVar8) {
          piVar5 = piVar8 + 2;
        }
        piVar5[1] = (int)piVar7;
        piVar5 = piVar4;
        if (piVar4 != piVar7) {
          piVar5 = piVar7 + 2;
        }
        *piVar5 = (int)piVar8;
        _IOFree(piVar2,0x14);
        piVar2 = *(int **)(param_1 + 0x144);
        if (piVar4 == piVar2) break;
        piVar8 = (int *)piVar2[2];
      }
      uVar1 = *(undefined4 *)(param_1 + 0x138);
    }
    _objc_msgSend(uVar1,paUnlock);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x138),paFree);
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01420a0;
  _objc_msgSendSuper(puVar3,paFree);
  return CONCAT44(param_2,puVar3);
}
