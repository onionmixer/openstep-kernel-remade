
/* WARNING: Removing unreachable block (ram,0xf00c5280) */
/* WARNING: Removing unreachable block (ram,0xf00c5248) */
/* WARNING: Removing unreachable block (ram,0xf00c5234) */
/* WARNING: Removing unreachable block (ram,0xf00c5204) */
/* WARNING: Removing unreachable block (ram,0xf00c51e0) */
/* WARNING: Removing unreachable block (ram,0xf00c51c8) */
/* WARNING: Removing unreachable block (ram,0xf00c51b4) */
/* WARNING: Removing unreachable block (ram,0xf00c51d8) */
/* WARNING: Removing unreachable block (ram,0xf00c51f0) */
/* WARNING: Removing unreachable block (ram,0xf00c5210) */
/* WARNING: Removing unreachable block (ram,0xf00c5240) */
/* WARNING: Removing unreachable block (ram,0xf00c5260) */
/* WARNING: Removing unreachable block (ram,0xf00c5298) */
/* WARNING: Removing unreachable block (ram,0xf00c51a8) */

undefined8
+[IODevice driverKitVersionForDriverNamed:](undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
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
  iVar1 = param_3;
  _strlen();
  uVar2 = iVar1 + 8U;
  _IOMalloc();
  if (uVar2 != 0) {
    _strcpy(uVar2,param_3);
    _strcat(uVar2,&aVersion);
    uVar5 = uVar2;
    _objc_getClass();
    _IOFree(uVar2,iVar1 + 8U);
    if (uVar5 == 0) {
      uVar5 = 0xffffffff;
      goto locret_F00C52A0;
    }
    iVar1 = param_3;
    _strlen();
    iVar3 = iVar1 + 0x14;
    _IOMalloc();
    if (iVar3 != 0) {
      _memcpy(iVar3,aDriverkitversi,0x14);
      _strcat(iVar3,param_3);
      iVar4 = iVar3;
      _sel_getUid(iVar3);
      uVar2 = uVar5;
      _objc_msgSend(uVar5,paRespondsto,iVar4);
      if ((uVar2 & 0xff) == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        _objc_msgSend(uVar5,paPerform,iVar4);
      }
      _IOFree(iVar3,iVar1 + 0x14);
      goto locret_F00C52A0;
    }
  }
  uVar5 = 0xffffffff;
locret_F00C52A0:
  return CONCAT44(param_2,uVar5);
}

