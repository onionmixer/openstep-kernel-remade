
/* WARNING: Removing unreachable block (ram,0xf00c5c98) */
/* WARNING: Removing unreachable block (ram,0xf00c5c5c) */
/* WARNING: Removing unreachable block (ram,0xf00c5c44) */
/* WARNING: Removing unreachable block (ram,0xf00c5c7c) */
/* WARNING: Removing unreachable block (ram,0xf00c5cbc) */
/* WARNING: Removing unreachable block (ram,0xf00c5c38) */

undefined8 +[IODevice objectsForClass:](undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined5 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
  
  piVar3 = dword_F0133034;
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
  puVar1 = paList;
  _objc_msgSend(paList,paAlloc);
  _objc_msgSend();
  _objc_msgSend(dword_F013303C,paLock);
  if ((int **)piVar3 != &dword_F0133034) {
    iVar2 = *piVar3;
    while( true ) {
      _objc_msgSend(iVar2,paClass);
      if (iVar2 == param_3) {
        _objc_msgSend(puVar1,paAddobject,*piVar3);
        piVar3 = (int *)piVar3[2];
      }
      else {
        piVar3 = (int *)piVar3[2];
      }
      if ((int **)piVar3 == &dword_F0133034) break;
      iVar2 = *piVar3;
    }
  }
  _objc_msgSend(dword_F013303C,paUnlock);
  return CONCAT44(param_2,puVar1);
}

