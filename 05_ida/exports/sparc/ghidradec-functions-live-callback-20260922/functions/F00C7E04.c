
/* WARNING: Removing unreachable block (ram,0xf00c7e3c) */
/* WARNING: Removing unreachable block (ram,0xf00c7f08) */
/* WARNING: Removing unreachable block (ram,0xf00c7ee4) */
/* WARNING: Removing unreachable block (ram,0xf00c7ec4) */
/* WARNING: Removing unreachable block (ram,0xf00c7e98) */
/* WARNING: Removing unreachable block (ram,0xf00c7e6c) */
/* WARNING: Removing unreachable block (ram,0xf00c7eac) */
/* WARNING: Removing unreachable block (ram,0xf00c7ed4) */
/* WARNING: Removing unreachable block (ram,0xf00c7ef4) */
/* WARNING: Removing unreachable block (ram,0xf00c7f14) */
/* WARNING: Removing unreachable block (ram,0xf00c7e48) */
/* WARNING: Removing unreachable block (ram,0xf00c7e14) */

undefined8 -[IODiskPartition _probeLabel:](undefined (*param_1) [16],undefined4 param_2,int param_3)

{
  undefined (*pauVar1) [16];
  undefined (*pauVar2) [16];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined (*pauVar3) [16];
  int iVar4;
  undefined4 unaff_l3;
  int iVar5;
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
  _objc_msgSend(param_1,paPhysicaldisk_0);
  if (*(int *)(param_1[0x1a] + 4) == 0) {
    iVar4 = 1;
    iVar5 = 0xf0;
    _objc_msgSend(param_1,paInitpartitionD,0,param_3 + 0x2c);
    pauVar1 = paSetlogicaldisk;
    pauVar3 = param_1;
    do {
      pauVar2 = pauVar3;
      if (0 < *(int *)(param_3 + iVar5 + 4)) {
        pauVar2 = paIodiskpartitio_1;
        _objc_msgSend(paIodiskpartitio_1,paNew);
        _objc_msgSend();
        _objc_msgSend(pauVar2,paInitpartitionD,iVar4,param_3 + 0x2c);
        _objc_msgSend(pauVar2,paInit);
        _objc_msgSend(pauVar2,paRegisterdevice);
        _objc_msgSend(pauVar3,pauVar1,pauVar2);
        _objc_msgSend(param_1,paPhysicaldisk_0);
        _objc_msgSend();
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x30;
      pauVar3 = pauVar2;
    } while (iVar4 < 7);
  }
  else {
    pauVar1 = param_1;
    _objc_msgSend(param_1,paName);
    _IOLog(aSProbelabelOnP,pauVar1);
  }
  return CONCAT44(param_2,param_1);
}

