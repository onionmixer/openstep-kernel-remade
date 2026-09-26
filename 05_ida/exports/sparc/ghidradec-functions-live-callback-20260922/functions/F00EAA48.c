
/* WARNING: Removing unreachable block (ram,0xf00eaafc) */
/* WARNING: Removing unreachable block (ram,0xf00eaabc) */
/* WARNING: Removing unreachable block (ram,0xf00eaa94) */
/* WARNING: Removing unreachable block (ram,0xf00eaaa4) */
/* WARNING: Removing unreachable block (ram,0xf00eaaf0) */
/* WARNING: Removing unreachable block (ram,0xf00eab1c) */
/* WARNING: Removing unreachable block (ram,0xf00eaa5c) */

undefined8
-[HashTable insertKey:value:](int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined (*pauVar2) [10];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = param_1;
  _objc_msgSend(param_1,paInsertkeynoreh,param_3,param_4);
  if (iVar3 == 0) {
    if (*(uint *)(param_1 + 0x10) < *(uint *)(param_1 + 4)) {
      iVar3 = param_1;
      _objc_msgSend(param_1,paZone);
      pauVar2 = paHashtable;
      _objc_msgSend(paHashtable,paAllocfromzone,iVar3);
      _objc_msgSend();
      *(undefined4 *)(*pauVar2 + 4) = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)pauVar2[2] = *(undefined4 *)(param_1 + 0x14);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) * 2 + 1;
      *(undefined4 *)(param_1 + 4) = 0;
      iVar3 = param_1;
      _objc_msgSend(param_1,paZone);
      _NXZoneCalloc();
      *(int *)(param_1 + 0x14) = iVar3;
      _objc_msgSend((undefined *)((int)register0x00000038 + -0x18),pauVar2,paInitstate);
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
    iVar3 = 0;
  }
  return CONCAT44(param_2,iVar3);
}

