
/* WARNING: Removing unreachable block (ram,0xf00da87c) */
/* WARNING: Removing unreachable block (ram,0xf00da8f4) */
/* WARNING: Removing unreachable block (ram,0xf00da90c) */
/* WARNING: Removing unreachable block (ram,0xf00da8bc) */
/* WARNING: Removing unreachable block (ram,0xf00da84c) */
/* WARNING: Removing unreachable block (ram,0xf00da834) */
/* WARNING: Removing unreachable block (ram,0xf00da858) */
/* WARNING: Removing unreachable block (ram,0xf00da8c8) */
/* WARNING: Removing unreachable block (ram,0xf00da8e4) */
/* WARNING: Removing unreachable block (ram,0xf00da870) */
/* WARNING: Removing unreachable block (ram,0xf00da894) */
/* WARNING: Removing unreachable block (ram,0xf00da824) */

undefined8 -[AudioChannel removeSndStreams](int param_1,undefined4 param_2)

{
  undefined5 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined5 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  undefined5 *puVar7;
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
  uVar6 = 0;
  puVar1 = paList;
  _objc_msgSend(paList,paAlloc);
  _objc_msgSend();
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paLock);
  while( true ) {
    uVar2 = *(uint *)(param_1 + 0xc);
    _objc_msgSend(uVar2,paCount_0);
    if (uVar2 <= uVar6) break;
    iVar3 = *(int *)(param_1 + 0xc);
    _objc_msgSend(iVar3,paObjectat,uVar6);
    iVar4 = iVar3;
    _objc_msgSend();
    if (iVar4 != 0) {
      _objc_msgSend(puVar1,paAddobject,iVar3);
    }
    uVar6 = uVar6 + 1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paUnlock);
  for (puVar7 = (undefined5 *)0x0; puVar5 = puVar1, _objc_msgSend(puVar1,paCount_0), puVar7 < puVar5
      ; puVar7 = (undefined5 *)((int)puVar7 + 1)) {
    puVar5 = puVar1;
    _objc_msgSend(puVar1,paObjectat,puVar7);
    _objc_msgSend(param_1,paRemovestream,puVar5);
  }
  _objc_msgSend(puVar1,paFree,puVar7);
  return CONCAT44(param_2,param_1);
}

