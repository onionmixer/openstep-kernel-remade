
/* WARNING: Removing unreachable block (ram,0xf00c8ba4) */
/* WARNING: Removing unreachable block (ram,0xf00c8b50) */
/* WARNING: Removing unreachable block (ram,0xf00c8af4) */
/* WARNING: Removing unreachable block (ram,0xf00c8adc) */
/* WARNING: Removing unreachable block (ram,0xf00c8ac0) */
/* WARNING: Removing unreachable block (ram,0xf00c8b08) */
/* WARNING: Removing unreachable block (ram,0xf00c8b30) */
/* WARNING: Removing unreachable block (ram,0xf00c8b88) */
/* WARNING: Removing unreachable block (ram,0xf00c8bb4) */
/* WARNING: Removing unreachable block (ram,0xf00c8aac) */

undefined8 sub_F00C8AA4(uint param_1,undefined4 param_2,sword param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar3;
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
  byte bVar4;
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
  uVar1 = 0x1c5c;
  _IOMalloc(0x1c5c);
  uVar2 = param_1;
  _objc_msgSend(param_1,paIsremovable);
  bVar4 = (uVar2 & 0xff) != 0;
  uVar2 = param_1;
  _objc_msgSend(param_1,paNextlogicaldis_0);
  if (uVar2 == 0) {
    _IOLog(aVolcheckPhysde);
    uVar2 = 0xfffffbb4;
  }
  else {
    _objc_msgSend();
  }
  if (uVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
    uVar2 = param_1;
    _objc_msgSend(param_1,paIsformatted);
    if ((uVar2 & 0xff) != 0) {
      uVar3 = 1;
    }
  }
  uVar2 = param_1;
  _objc_msgSend(param_1,paIswriteprotect);
  if ((uVar2 & 0xff) != 0) {
    bVar4 = bVar4 | 2;
  }
  uVar2 = param_1;
  _objc_msgSend(param_1,paName);
  _vol_notify_dev((int)(sword)param_2,(int)param_3,&asc_F00FA528,uVar3,uVar2,bVar4);
  _IOFree(uVar1,0x1c5c);
  return CONCAT44(param_2,param_1);
}
