
/* WARNING: Removing unreachable block (ram,0xf00eaf48) */
/* WARNING: Removing unreachable block (ram,0xf00eaf08) */
/* WARNING: Removing unreachable block (ram,0xf00eaeec) */
/* WARNING: Removing unreachable block (ram,0xf00eaecc) */
/* WARNING: Removing unreachable block (ram,0xf00eaee0) */
/* WARNING: Removing unreachable block (ram,0xf00eaefc) */
/* WARNING: Removing unreachable block (ram,0xf00eaf28) */
/* WARNING: Removing unreachable block (ram,0xf00eaf50) */
/* WARNING: Removing unreachable block (ram,0xf00eae90) */

undefined8 -[HashTable printForDebugger:](int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l3;
  int *piVar4;
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
  iVar3 = *(int *)(param_1 + 0x10);
  piVar4 = *(int **)(param_1 + 0x14);
  _NXPrintf(param_3,aTableSSCountDC,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
            *(undefined4 *)(param_1 + 4),iVar3);
  while (iVar3 = iVar3 + -1, iVar3 != -1) {
    iVar1 = *piVar4;
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)piVar4[1];
      _NXPrintf(param_3,&aD);
      while (iVar1 = iVar1 + -1, iVar1 != -1) {
        sub_F00EADC8(param_3,*(undefined4 *)(param_1 + 8),*puVar2);
        _NXPrintf(param_3,&DAT_f00fcd88);
        sub_F00EADC8(param_3,*(undefined4 *)(param_1 + 0xc),puVar2[1]);
        _NXPrintf(param_3,&DAT_f00fcd90);
        puVar2 = puVar2 + 2;
      }
      _NXPrintf(param_3,&asc_F00FAC48);
    }
    piVar4 = piVar4 + 2;
  }
  _NXPrintf(param_3,&asc_F00FAC48);
  _NXFlush(param_3);
  return CONCAT44(param_2,param_1);
}
