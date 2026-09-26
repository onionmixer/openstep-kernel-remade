
/* WARNING: Removing unreachable block (ram,0xf00c8188) */
/* WARNING: Removing unreachable block (ram,0xf00c8154) */
/* WARNING: Removing unreachable block (ram,0xf00c8134) */
/* WARNING: Removing unreachable block (ram,0xf00c8168) */
/* WARNING: Removing unreachable block (ram,0xf00c8194) */
/* WARNING: Removing unreachable block (ram,0xf00c80ec) */

undefined8 -[IODiskPartition _freePartitions](uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  uVar1 = param_1;
  _objc_msgSend(param_1,paNextlogicaldis_0);
  if (*(int *)(param_1 + 0x1a4) == 0) {
    if (uVar1 == 0) {
      uVar4 = 0;
      goto locret_F00C819C;
    }
    uVar2 = uVar1;
    _objc_msgSend(uVar1,paIsopen);
    if ((uVar2 & 0xff) == 0) {
      _objc_msgSend(uVar1,paFree);
      _objc_msgSend(param_1,paSetlogicaldisk,0);
      uVar4 = 0;
      goto locret_F00C819C;
    }
    puVar3 = aSFreepartition_0;
  }
  else {
    puVar3 = aSFreepartition;
  }
  uVar4 = 0xfffffd2b;
  _objc_msgSend(param_1,paName);
  _IOLog(puVar3,param_1);
locret_F00C819C:
  return CONCAT44(param_2,uVar4);
}
