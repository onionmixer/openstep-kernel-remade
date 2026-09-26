
/* WARNING: Removing unreachable block (ram,0xf00d217c) */
/* WARNING: Removing unreachable block (ram,0xf00d215c) */
/* WARNING: Removing unreachable block (ram,0xf00d214c) */
/* WARNING: Removing unreachable block (ram,0xf00d213c) */
/* WARNING: Removing unreachable block (ram,0xf00d212c) */
/* WARNING: Removing unreachable block (ram,0xf00d2124) */
/* WARNING: Removing unreachable block (ram,0xf00d2134) */
/* WARNING: Removing unreachable block (ram,0xf00d2144) */
/* WARNING: Removing unreachable block (ram,0xf00d2154) */
/* WARNING: Removing unreachable block (ram,0xf00d2170) */
/* WARNING: Removing unreachable block (ram,0xf00d2198) */
/* WARNING: Removing unreachable block (ram,0xf00d211c) */

undefined8 -[EventDriver free](int param_1,undefined4 param_2)

{
  undefined5 *puVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
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
  _objc_msgSend(param_1,paEvcloseToken,*(undefined4 *)(param_1 + 0x134),
                *(undefined4 *)(param_1 + 0x114));
  _task_self();
  _port_deallocate_EXTERNAL();
  _task_self();
  _port_deallocate_EXTERNAL();
  _task_self();
  _port_deallocate_EXTERNAL();
  _task_self();
  _port_set_deallocate_EXTERNAL();
  puVar1 = paFree;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paFree);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),puVar1);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
  _objc_msgSendSuper(puVar2,puVar1);
  return CONCAT44(param_2,puVar2);
}
