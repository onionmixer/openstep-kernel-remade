
/* WARNING: Removing unreachable block (ram,0xf00c96fc) */
/* WARNING: Removing unreachable block (ram,0xf00c96d4) */
/* WARNING: Removing unreachable block (ram,0xf00c96e8) */
/* WARNING: Removing unreachable block (ram,0xf00c9768) */
/* WARNING: Removing unreachable block (ram,0xf00c9724) */

undefined8 -[IODirectDevice waitForInterrupt:](int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  uint uVar3;
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
  uVar3 = 0x1100;
  if (*(int *)(param_1 + 0x10c) == 0) {
    uVar4 = 0xfffffd21;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0x18;
    while( true ) {
      puVar2 = (undefined *)((int)register0x00000038 + -0x28);
      *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x10c);
      _msg_receive(puVar2,uVar3,0);
      if (puVar2 == (undefined *)0xffffff34) break;
      if ((puVar2 != (undefined *)0x0) && (puVar2 != (undefined *)0xffffff35)) {
        iVar1 = param_1;
        _objc_msgSend(param_1,paName);
        _objc_msgSend(param_1,paDevicekind_0);
        _IOLog(aSSWaitforinter,iVar1,param_1,puVar2);
        uVar4 = 0xfffffd41;
        goto locret_F00C9788;
      }
      if ((uVar3 & 0x100) != 0) {
        if (puVar2 == (undefined *)0xffffff35) {
          uVar3 = 0x1000;
        }
        else {
          _thread_block();
        }
      }
      if (puVar2 == (undefined *)0x0) {
        uVar4 = 0;
        *param_3 = *(undefined4 *)((int)register0x00000038 + -0x14);
        goto locret_F00C9788;
      }
      *(undefined4 *)((int)register0x00000038 + -0x24) = 0x18;
    }
    uVar4 = 0xfffffd1f;
  }
locret_F00C9788:
  return CONCAT44(param_2,uVar4);
}

