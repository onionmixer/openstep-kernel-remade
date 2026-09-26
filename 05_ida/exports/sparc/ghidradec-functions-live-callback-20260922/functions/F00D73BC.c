
/* WARNING: Removing unreachable block (ram,0xf00d7510) */
/* WARNING: Removing unreachable block (ram,0xf00d74f0) */
/* WARNING: Removing unreachable block (ram,0xf00d74d4) */
/* WARNING: Removing unreachable block (ram,0xf00d749c) */
/* WARNING: Removing unreachable block (ram,0xf00d7470) */
/* WARNING: Removing unreachable block (ram,0xf00d7454) */
/* WARNING: Removing unreachable block (ram,0xf00d7420) */
/* WARNING: Removing unreachable block (ram,0xf00d7408) */
/* WARNING: Removing unreachable block (ram,0xf00d73e0) */
/* WARNING: Removing unreachable block (ram,0xf00d73c8) */
/* WARNING: Removing unreachable block (ram,0xf00d73f0) */
/* WARNING: Removing unreachable block (ram,0xf00d7410) */
/* WARNING: Removing unreachable block (ram,0xf00d7430) */
/* WARNING: Removing unreachable block (ram,0xf00d7468) */
/* WARNING: Removing unreachable block (ram,0xf00d7488) */
/* WARNING: Removing unreachable block (ram,0xf00d74a4) */
/* WARNING: Removing unreachable block (ram,0xf00d74e8) */
/* WARNING: Removing unreachable block (ram,0xf00d7508) */
/* WARNING: Removing unreachable block (ram,0xf00d7528) */
/* WARNING: Removing unreachable block (ram,0xf00d73c0) */

void sub_F00D73BC(int param_1)

{
  undefined (*pauVar1) [37];
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar6;
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
  iVar5 = param_1;
  _task_self();
  _port_allocate_EXTERNAL();
  uVar6 = *(undefined4 *)((int)register0x00000038 + -0x44);
  if (iVar5 != 0) {
    _IOLog(aAudioPortAlloc);
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0x44);
  }
  puVar2 = aEventdriver;
  _objc_lookUpClass();
  if (puVar2 == (undefined *)0x0) {
    _IOLog(aAudioObjcLooku);
    _IOExitThread();
  }
  _objc_msgSend(puVar2,paInstance);
  puVar3 = puVar2;
  _objc_msgSend();
  pauVar1 = paSetspecialkeyp;
  puVar4 = puVar2;
  _objc_msgSend(puVar2,paSetspecialkeyp,puVar3,0,uVar6);
  if (puVar4 != (undefined *)0x0) {
    _IOLog(aAudioSetspecia,puVar4);
    _IOExitThread();
  }
  _objc_msgSend(puVar2,pauVar1,puVar3,1,uVar6);
  if (puVar2 != (undefined *)0x0) {
    _IOLog(aAudioSetspecia,puVar2);
    _IOExitThread();
  }
  *(undefined4 *)((int)register0x00000038 + -0x34) = uVar6;
  do {
    *(undefined4 *)((int)register0x00000038 + -0x3c) = 0x38;
    puVar2 = (undefined *)((int)register0x00000038 + -0x40);
    _msg_receive(puVar2,0,0);
    if (puVar2 == (undefined *)0x0) {
      iVar5 = *(int *)((int)register0x00000038 + -0x2c);
    }
    else {
      _IOLog(aAudioKeythread,puVar2);
      _IOExitThread();
      iVar5 = *(int *)((int)register0x00000038 + -0x2c);
    }
    if (iVar5 != 0x536b6579) {
      _IOLog(aAudioUnknownMs);
      _IOExitThread();
    }
    _objc_msgSend(param_1,paKeyoccurredEve,*(undefined4 *)((int)register0x00000038 + -0x24),
                  *(undefined4 *)((int)register0x00000038 + -0x1c),
                  *(undefined4 *)((int)register0x00000038 + -0x14));
    *(undefined4 *)((int)register0x00000038 + -0x34) = uVar6;
  } while( true );
}

