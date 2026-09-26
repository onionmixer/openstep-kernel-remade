/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a7970 */

void FUN_001a7970(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  
  piVar10 = (int *)0x0;
  _objc_msgSend(DAT_001e86e8,PTR_s_lock_001f9220);
  piVar4 = DAT_001e86e0;
  do {
    DAT_001e86e0 = piVar4;
    if ((int **)piVar4 == &DAT_001e86e0) {
      _objc_msgSend(DAT_001e86e8,PTR_s_unlock_001f9474);
      return;
    }
    puVar1 = (undefined4 *)piVar4[4];
    puVar2 = (undefined4 *)piVar4[5];
    puVar7 = &DAT_001e86e0;
    if ((int **)puVar1 != &DAT_001e86e0) {
      puVar7 = puVar1 + 4;
    }
    puVar7[1] = puVar2;
    puVar7 = &DAT_001e86e0;
    if ((int **)puVar2 != &DAT_001e86e0) {
      puVar7 = puVar2 + 4;
    }
    *puVar7 = puVar1;
    _objc_msgSend(DAT_001e86e8,PTR_s_unlock_001f9474);
    iVar3 = piVar4[1];
    piVar5 = DAT_001e86d8;
    if (*piVar4 == 0) {
LAB_001a7a40:
      switch(*piVar4) {
      case 0:
        iVar9 = _objc_msgSend(iVar3,PTR_s_updateReadyState_001f9cbc);
        _objc_msgSend(iVar3,PTR_s_setLastReadyState__001f9c6c,iVar9);
        if (iVar9 == 0) {
          FUN_001a7c70(iVar3,(int)(short)piVar4[3],(int)*(short *)((int)piVar4 + 0xe));
          cVar6 = _objc_msgSend(iVar3,PTR_s_isRemovable_001f93c8);
          if (cVar6 == '\0') break;
        }
        piVar10 = (int *)_IOMalloc(0x20);
        *piVar10 = iVar3;
        *(short *)(piVar10 + 1) = (short)piVar4[3];
        *(undefined2 *)((int)piVar10 + 6) = *(undefined2 *)((int)piVar4 + 0xe);
        piVar10[2] = 0;
        *(undefined1 *)(piVar10 + 3) = 0;
        *(undefined1 *)((int)piVar10 + 0xd) = 0;
        piVar10[5] = piVar4[2];
        if ((int **)DAT_001e86d8 == &DAT_001e86d8) {
          DAT_001e86d8 = piVar10;
          DAT_001e86dc = piVar10;
          piVar10[6] = (int)&DAT_001e86d8;
          piVar10[7] = (int)&DAT_001e86d8;
        }
        else {
          piVar10[7] = (int)DAT_001e86dc;
          piVar10[6] = (int)&DAT_001e86d8;
          piVar5 = DAT_001e86dc + 6;
          DAT_001e86dc = piVar10;
          *piVar5 = (int)piVar10;
        }
        break;
      case 1:
        puVar1 = (undefined4 *)piVar10[6];
        puVar2 = (undefined4 *)piVar10[7];
        puVar7 = &DAT_001e86d8;
        if ((int **)puVar1 != &DAT_001e86d8) {
          puVar7 = puVar1 + 6;
        }
        puVar7[1] = puVar2;
        puVar7 = &DAT_001e86d8;
        if ((int **)puVar2 != &DAT_001e86d8) {
          puVar7 = puVar2 + 6;
        }
        *puVar7 = puVar1;
        _IOFree(piVar10,0x20);
        break;
      case 2:
        uVar8 = _objc_msgSend(iVar3,PTR_s_unit_001f9c28);
        if ((*(char *)((int)piVar10 + 0xd) == '\0') &&
           (iVar9 = _objc_msgSend(iVar3,PTR_s_lastReadyState_001f9c70), iVar9 != 0)) {
          _vol_panel_disk_num(FUN_001a7d6c,0,piVar4[2],uVar8,iVar3,0,piVar10 + 4);
          *(undefined1 *)((int)piVar10 + 0xd) = 1;
        }
        break;
      case 3:
        _objc_msgSend(iVar3,PTR_s_setLastReadyState__001f9c6c,3);
        piVar10[2] = 1;
        *(undefined1 *)(piVar10 + 3) = 0;
        piVar10[5] = piVar4[2];
        break;
      case 4:
        _objc_msgSend(iVar3,PTR_s_setLastReadyState__001f9c6c,1);
        break;
      case 5:
        if (*(char *)((int)piVar10 + 0xd) != '\0') {
          *(undefined1 *)((int)piVar10 + 0xd) = 0;
          _objc_msgSend(iVar3,PTR_s_abortRequest_001f9c10);
        }
      }
    }
    else {
      while (piVar10 = piVar5, (int **)piVar10 != &DAT_001e86d8) {
        if (*piVar10 == iVar3) goto LAB_001a7a10;
        piVar5 = (int *)piVar10[6];
      }
      piVar10 = (int *)0x0;
LAB_001a7a10:
      if (piVar10 != (int *)0x0) goto LAB_001a7a40;
      uVar8 = _objc_msgSend(iVar3,PTR_s_name_001f9228,*piVar4);
      _IOLog("volCheck: disk %s not registered, cmd = %d\n",uVar8);
    }
    _IOFree(piVar4,0x18);
    _objc_msgSend(DAT_001e86e8,PTR_s_lock_001f9220);
    piVar4 = DAT_001e86e0;
  } while( true );
}

