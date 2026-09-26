
/* WARNING: Removing unreachable block (ram,0xf00dbc9c) */
/* WARNING: Removing unreachable block (ram,0xf00dbc70) */
/* WARNING: Removing unreachable block (ram,0xf00dbc4c) */
/* WARNING: Removing unreachable block (ram,0xf00dbc34) */
/* WARNING: Removing unreachable block (ram,0xf00dbc14) */
/* WARNING: Removing unreachable block (ram,0xf00dbbf4) */
/* WARNING: Removing unreachable block (ram,0xf00dbc0c) */
/* WARNING: Removing unreachable block (ram,0xf00dbc2c) */
/* WARNING: Removing unreachable block (ram,0xf00dbc44) */
/* WARNING: Removing unreachable block (ram,0xf00dbc54) */
/* WARNING: Removing unreachable block (ram,0xf00dbc84) */
/* WARNING: Removing unreachable block (ram,0xf00dbcb8) */
/* WARNING: Removing unreachable block (ram,0xf00dbbec) */

undefined8 -[AudioStream free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
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
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar2 = *(int *)(param_1 + 0x3c);
  }
  else {
    _task_self();
    _port_deallocate_EXTERNAL();
    iVar2 = *(int *)(param_1 + 0x3c);
  }
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x40);
  }
  else {
    _task_self();
    _port_deallocate_EXTERNAL();
    iVar2 = *(int *)(param_1 + 0x40);
  }
  if (iVar2 != 0) {
    _task_self();
    _port_deallocate_EXTERNAL();
  }
  iVar2 = param_1;
  _objc_msgSend(param_1,paFreeregions);
  _task_self();
  _port_deallocate_EXTERNAL();
  if (iVar2 != 0) {
    _IOLog(aAudioStreamPor,aMachErr);
  }
  uVar1 = paFree;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paFree);
  if (*(int *)(param_1 + 0x34) == 0) {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  else {
    _IOFree(*(int *)(param_1 + 0x34),0x2000);
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422a8;
  _objc_msgSendSuper(puVar3,uVar1);
  return CONCAT44(param_2,puVar3);
}
