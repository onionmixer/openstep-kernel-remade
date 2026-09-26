
/* WARNING: Removing unreachable block (ram,0xf00c5d60) */
/* WARNING: Removing unreachable block (ram,0xf00c5d34) */
/* WARNING: Removing unreachable block (ram,0xf00c5d00) */
/* WARNING: Removing unreachable block (ram,0xf00c5d18) */
/* WARNING: Removing unreachable block (ram,0xf00c5d44) */
/* WARNING: Removing unreachable block (ram,0xf00c5d70) */
/* WARNING: Removing unreachable block (ram,0xf00c5cd4) */

undefined8 -[IOConfigTable valueForStringKey:](int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStack_10 [16];
  
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
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = param_3;
  _strlen();
  iVar1 = -(iVar4 + 0x6dU & 0xfffffff8);
  puVar2 = auStack_10 + iVar1;
  *puVar2 = 0x22;
  _strcpy(auStack_10 + iVar1 + 1,param_3);
  puVar2[iVar4 + 1] = 0x22;
  puVar2[iVar4 + 2] = 0;
  _strstr(iVar3,puVar2);
  if (iVar3 != 0) {
    iVar3 = iVar3 + iVar4 + 2;
    _strchr(iVar3,0x22);
    iVar3 = iVar3 + 1;
    iVar1 = iVar3;
    _strchr(iVar3,0x22);
    if (iVar1 != 0) {
      iVar4 = (iVar1 - iVar3) + 1;
      _IOMalloc();
      _strncpy();
      *(undefined *)(iVar4 + (iVar1 - iVar3)) = 0;
      goto locret_F00C5D7C;
    }
  }
  iVar4 = 0;
locret_F00C5D7C:
  return CONCAT44(param_2,iVar4);
}
