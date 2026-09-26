
/* WARNING: Removing unreachable block (ram,0xf00d2b80) */
/* WARNING: Removing unreachable block (ram,0xf00d2b64) */
/* WARNING: Removing unreachable block (ram,0xf00d2b44) */
/* WARNING: Removing unreachable block (ram,0xf00d2b04) */
/* WARNING: Removing unreachable block (ram,0xf00d2ba8) */
/* WARNING: Removing unreachable block (ram,0xf00d2bb8) */
/* WARNING: Removing unreachable block (ram,0xf00d2b30) */
/* WARNING: Removing unreachable block (ram,0xf00d2b54) */
/* WARNING: Removing unreachable block (ram,0xf00d2b70) */
/* WARNING: Removing unreachable block (ram,0xf00d2b8c) */
/* WARNING: Removing unreachable block (ram,0xf00d2ae4) */

undefined8
-[EventDriver mapEventShmem:task:size:at:]
          (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,undefined4 *param_6)

{
  undefined5 *puVar1;
  undefined7 *puVar2;
  undefined (*pauVar3) [10];
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  if (param_3 == *(int *)(param_1 + 0x114)) {
    if (*(char *)(param_1 + 0x1d0) == '\0') {
      iVar5 = -0x2c1;
    }
    else {
      if (param_4 != 0) {
        if (param_5 == 0) {
          iVar5 = -0x2c2;
          goto locret_F00D2BC4;
        }
        if (*(int *)(param_1 + 0x150) != 0) {
          iVar5 = -0x2c2;
          goto locret_F00D2BC4;
        }
        if (*(int *)(param_1 + 0x154) == 0) {
          iVar5 = param_4;
          _createEventShmem(param_4,param_5,(undefined *)((int)register0x00000038 + -0x14),
                            (undefined *)((int)register0x00000038 + -0x18),param_1 + 0x15c);
          puVar1 = paLock;
          if (iVar5 == 0) {
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
            *(int *)(param_1 + 0x160) = param_5;
            *(int *)(param_1 + 0x150) = param_4;
            uVar4 = *(undefined4 *)((int)register0x00000038 + -0x18);
            *(undefined4 *)(param_1 + 0x158) = uVar4;
            *param_6 = uVar4;
            pauVar3 = paInitshmem;
            *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)((int)register0x00000038 + -0x14);
            _objc_msgSend(param_1,pauVar3);
            puVar2 = paUnlock;
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
            _objc_msgSend(param_1,paResetmousepara);
            _objc_msgSend(param_1,paResetkeyboardp);
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),puVar1);
            _objc_msgSend(param_1,paSchedulenextpe);
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),puVar2);
            iVar5 = 0;
          }
          else {
            _objc_msgSend(param_1,paName);
            _IOLog(aSCreateeventsh,param_1,iVar5);
          }
          goto locret_F00D2BC4;
        }
      }
      iVar5 = -0x2c2;
    }
  }
  else {
    iVar5 = -0x2c1;
  }
locret_F00D2BC4:
  return CONCAT44(param_2,iVar5);
}

