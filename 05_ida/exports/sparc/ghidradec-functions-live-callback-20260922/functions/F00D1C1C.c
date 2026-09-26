
/* WARNING: Removing unreachable block (ram,0xf00d1cc8) */
/* WARNING: Removing unreachable block (ram,0xf00d1ca4) */
/* WARNING: Removing unreachable block (ram,0xf00d1e64) */
/* WARNING: Removing unreachable block (ram,0xf00d1e30) */
/* WARNING: Removing unreachable block (ram,0xf00d1e04) */
/* WARNING: Removing unreachable block (ram,0xf00d1ddc) */
/* WARNING: Removing unreachable block (ram,0xf00d1d50) */
/* WARNING: Removing unreachable block (ram,0xf00d1d70) */
/* WARNING: Removing unreachable block (ram,0xf00d1d18) */
/* WARNING: Removing unreachable block (ram,0xf00d1d80) */
/* WARNING: Removing unreachable block (ram,0xf00d1d9c) */
/* WARNING: Removing unreachable block (ram,0xf00d1df4) */
/* WARNING: Removing unreachable block (ram,0xf00d1e18) */
/* WARNING: Removing unreachable block (ram,0xf00d1e44) */
/* WARNING: Removing unreachable block (ram,0xf00d1c98) */
/* WARNING: Removing unreachable block (ram,0xf00d1cb4) */
/* WARNING: Removing unreachable block (ram,0xf00d1e80) */
/* WARNING: Removing unreachable block (ram,0xf00d1c4c) */

undefined8 sub_F00D1C1C(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
  undefined4 unaff_l4;
  uint uVar8;
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
  bool bVar9;
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
  bVar1 = true;
  puVar7 = (undefined *)0x200;
  puVar5 = (undefined *)((int)register0x00000038 + -0x208);
  uVar8 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)(param_1 + 0x148);
    *(undefined **)(puVar5 + 4) = puVar7;
    puVar3 = puVar5;
    _msg_receive(puVar5,0x1000,0);
    if (puVar3 == (undefined *)0xffffff36) {
      bVar1 = false;
loc_F00D1E74:
      bVar9 = !bVar1;
    }
    else if ((int)puVar3 < -0xc9) {
      if (puVar3 == (undefined *)0xffffff34) {
        if ((undefined *)0x200 < puVar7) {
          _IOFree(puVar5,puVar7);
        }
        puVar7 = *(undefined **)(puVar5 + 4);
        puVar5 = puVar7;
        _IOMalloc();
        goto loc_F00D1E74;
      }
loc_F00D1CB4:
      iVar2 = param_1;
      _objc_msgSend(param_1,paName);
      _IOLog(aSErrorOnMsgRec,iVar2,puVar3);
      bVar9 = !bVar1;
    }
    else {
      if (puVar3 != (undefined *)0x0) goto loc_F00D1CB4;
      if (*(int *)(puVar5 + 0xc) == *(int *)(param_1 + 0x13c)) {
        bVar9 = !bVar1;
        if ((*(int *)(puVar5 + 0x1c) == *(int *)(param_1 + 0x144)) &&
           (bVar9 = !bVar1, *(int *)(puVar5 + 0x1c) != 0)) {
          _objc_msgSend(param_1,paEvcloseToken,*(undefined4 *)(param_1 + 0x134),
                        *(undefined4 *)(param_1 + 0x114));
          bVar9 = !bVar1;
        }
        goto loc_F00D1E78;
      }
      puVar3 = (undefined *)0x0;
      if (*(int *)(puVar5 + 0x14) == 1) {
        if (*(int *)(puVar5 + 0xc) == *(int *)(param_1 + 0x134)) {
          _objc_msgSend(param_1,paIoophandler,puVar5 + 0x1c);
          puVar3 = (undefined *)0x1;
        }
      }
      else {
        if (iVar6 == 0) {
          uVar8 = 0x1400;
          iVar6 = 0x1400;
          _IOMalloc();
        }
        puVar3 = puVar5;
        _Event_server(puVar5,iVar6);
      }
      iVar2 = param_1;
      if (puVar3 == (undefined *)0x0) {
        _objc_msgSend(param_1,paName);
        puVar3 = aSInvalidMessag;
        iVar4 = *(int *)(puVar5 + 0x14);
loc_F00D1E30:
        _IOLog(puVar3,iVar2,iVar4);
loc_F00D1E38:
        if (iVar6 != 0) {
          _IOFree(iVar6,uVar8);
          iVar6 = 0;
          uVar8 = 0;
        }
      }
      else {
        if (*(int *)(puVar5 + 0x10) == 0) goto loc_F00D1E38;
        if (iVar6 != 0) {
          if (uVar8 < *(uint *)(iVar6 + 4)) {
            iVar4 = param_1;
            _objc_msgSend(param_1,paName);
            _IOLog(aSReplyMsgOverf,iVar4,*(undefined4 *)(iVar6 + 4),uVar8);
          }
          iVar4 = iVar6;
          _msg_send(iVar6,0,0);
          if (iVar4 != 0) {
            _objc_msgSend(param_1,paName);
            puVar3 = aSErrorOnMsgSen;
            goto loc_F00D1E30;
          }
          goto loc_F00D1E38;
        }
      }
      bVar9 = !bVar1;
      if ((undefined *)0x200 < puVar7) {
        _IOFree(puVar5,puVar7);
        puVar7 = (undefined *)0x200;
        puVar5 = (undefined *)((int)register0x00000038 + -0x208);
        goto loc_F00D1E74;
      }
    }
loc_F00D1E78:
    if (bVar9) {
      _IOExitThread();
      return CONCAT44(param_2,param_1);
    }
  } while( true );
}

