
/* WARNING: Removing unreachable block (ram,0xf00c2330) */
/* WARNING: Removing unreachable block (ram,0xf00c2314) */
/* WARNING: Removing unreachable block (ram,0xf00c22ec) */
/* WARNING: Removing unreachable block (ram,0xf00c22bc) */
/* WARNING: Removing unreachable block (ram,0xf00c226c) */
/* WARNING: Removing unreachable block (ram,0xf00c2254) */
/* WARNING: Removing unreachable block (ram,0xf00c2224) */
/* WARNING: Removing unreachable block (ram,0xf00c2218) */
/* WARNING: Removing unreachable block (ram,0xf00c223c) */
/* WARNING: Removing unreachable block (ram,0xf00c227c) */
/* WARNING: Removing unreachable block (ram,0xf00c22a0) */
/* WARNING: Removing unreachable block (ram,0xf00c22c4) */
/* WARNING: Removing unreachable block (ram,0xf00c2304) */
/* WARNING: Removing unreachable block (ram,0xf00c2340) */
/* WARNING: Removing unreachable block (ram,0xf00c22dc) */
/* WARNING: Removing unreachable block (ram,0xf00c2208) */

undefined8 -[SUNMouse mouseInit:](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  _objc_msgSend(param_1,paSetdevicekind,aSunmouse_0);
  iVar1 = param_1;
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  if (iVar1 == 0) {
    _IOLog(aSunmouseMousei);
    uVar3 = 0;
    goto locret_F00C234C;
  }
  _objc_msgSend();
  if (iVar1 == 0) {
    _IOLog(aSunmouseMousei_0);
loc_F00C2294:
    *(undefined4 *)(param_1 + 0x134) = 200;
  }
  else {
    _PCPatoi();
    *(int *)(param_1 + 0x134) = iVar1;
    if (iVar1 < 0) goto loc_F00C2294;
  }
  _objc_msgSend(param_1,paEnableallinter);
  dword_F0133028 = 0;
  puVar2 = unk_F0133018;
  DAT_f0133022._0_1_ = 0;
  byte_F0133021 = 0;
  _task_self();
  _port_set_allocate_EXTERNAL();
  if (puVar2 == (undefined *)0x0) {
    _task_self();
    uVar3 = *(undefined4 *)(param_1 + 0x130);
    iVar1 = param_1;
    _objc_msgSend(param_1,paInterruptport_0);
    _port_set_add_EXTERNAL(puVar2,uVar3,iVar1);
    if (puVar2 == (undefined *)0x0) {
      _IOForkThread(sub_F00C2154,param_1);
      uVar3 = 1;
    }
    else {
      _IOLog(aMouseinitPortS_0,puVar2);
      uVar3 = 0xffffffff;
    }
  }
  else {
    _IOLog(aMouseinitPortS);
    uVar3 = 0;
  }
locret_F00C234C:
  return CONCAT44(param_2,uVar3);
}

