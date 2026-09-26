
/* WARNING: Removing unreachable block (ram,0xf00c8a6c) */
/* WARNING: Removing unreachable block (ram,0xf00c88d0) */
/* WARNING: Removing unreachable block (ram,0xf00c88a8) */
/* WARNING: Removing unreachable block (ram,0xf00c8878) */
/* WARNING: Removing unreachable block (ram,0xf00c89d0) */
/* WARNING: Removing unreachable block (ram,0xf00c8980) */
/* WARNING: Removing unreachable block (ram,0xf00c8a14) */
/* WARNING: Removing unreachable block (ram,0xf00c8830) */
/* WARNING: Removing unreachable block (ram,0xf00c87b8) */
/* WARNING: Removing unreachable block (ram,0xf00c881c) */
/* WARNING: Removing unreachable block (ram,0xf00c8a4c) */
/* WARNING: Removing unreachable block (ram,0xf00c89ec) */
/* WARNING: Removing unreachable block (ram,0xf00c89a0) */
/* WARNING: Removing unreachable block (ram,0xf00c8968) */
/* WARNING: Removing unreachable block (ram,0xf00c888c) */
/* WARNING: Removing unreachable block (ram,0xf00c88b8) */
/* WARNING: Removing unreachable block (ram,0xf00c8a58) */
/* WARNING: Removing unreachable block (ram,0xf00c8a94) */
/* WARNING: Removing unreachable block (ram,0xf00c8738) */

undefined8 sub_F00C8724(undefined4 param_1,undefined4 *param_2)

{
  uint *puVar1;
  int *piVar2;
  undefined (*pauVar3) [13];
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar10;
  uint uVar11;
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
  puVar10 = (uint *)0x0;
  _objc_msgSend(dword_F01330B0,paLock);
  if ((int **)dword_F01330A8 != &dword_F01330A8) {
    param_2 = &DAT_f0133000;
    param_1 = 0xf00c8858;
    do {
      piVar2 = dword_F01330A8;
      puVar9 = (undefined4 *)dword_F01330A8[4];
      puVar7 = (undefined4 *)dword_F01330A8[5];
      puVar8 = &dword_F01330A8;
      if ((int **)puVar9 != &dword_F01330A8) {
        puVar8 = puVar9 + 4;
      }
      puVar8[1] = puVar7;
      puVar8 = &dword_F01330A8;
      if ((int **)puVar7 != &dword_F01330A8) {
        puVar8 = puVar7 + 4;
      }
      *puVar8 = puVar9;
      _objc_msgSend(dword_F01330B0,paUnlock);
      pauVar3 = paAbortrequest;
      uVar11 = piVar2[1];
      iVar5 = 0;
      if (*piVar2 == 0) {
loc_F00C8840:
        switch(iVar5) {
        case :
          uVar4 = uVar11;
          _objc_msgSend(uVar11,paUpdatereadysta);
          _objc_msgSend(uVar11,paSetlastreadyst,uVar4);
          if (uVar4 == 0) {
            sub_F00C8AA4(uVar11,(int)*(sword *)(piVar2 + 3),(int)*(sword *)((int)piVar2 + 0xe));
            uVar4 = uVar11;
            _objc_msgSend(uVar11,paIsremovable);
            if ((uVar4 & 0xff) == 0) break;
          }
          puVar10 = (uint *)0x20;
          _IOMalloc();
          *puVar10 = uVar11;
          *(undefined2 *)(puVar10 + 1) = *(undefined2 *)(piVar2 + 3);
          *(undefined2 *)((int)puVar10 + 6) = *(undefined2 *)((int)piVar2 + 0xe);
          puVar10[2] = 0;
          *(undefined *)(puVar10 + 3) = 0;
          *(undefined *)((int)puVar10 + 0xd) = 0;
          puVar10[5] = piVar2[2];
          if ((uint **)dword_F01330A0 == &dword_F01330A0) {
            dword_F01330A0 = puVar10;
            DAT_f01330a4 = puVar10;
            puVar10[6] = (uint)&dword_F01330A0;
            puVar10[7] = (uint)&dword_F01330A0;
          }
          else {
            puVar10[7] = (uint)DAT_f01330a4;
            puVar10[6] = (uint)&dword_F01330A0;
            puVar1 = DAT_f01330a4 + 6;
            DAT_f01330a4 = puVar10;
            *puVar1 = (uint)puVar10;
          }
          break;
        case :
          puVar7 = (undefined4 *)puVar10[6];
          puVar8 = (undefined4 *)puVar10[7];
          if ((uint **)puVar7 == &dword_F01330A0) {
            puVar9 = &dword_F01330A0;
          }
          else {
            puVar9 = puVar7 + 6;
          }
          puVar9[1] = puVar8;
          if ((uint **)puVar8 == &dword_F01330A0) {
            puVar8 = &dword_F01330A0;
          }
          else {
            puVar8 = puVar8 + 6;
          }
          *puVar8 = puVar7;
          _IOFree(puVar10,0x20);
          break;
        case :
          uVar4 = uVar11;
          _objc_msgSend(uVar11,paUnit_0);
          if ((*(char *)((int)puVar10 + 0xd) == '\0') &&
             (uVar6 = uVar11, _objc_msgSend(uVar11,paLastreadystate_0), uVar6 != 0)) {
            _vol_panel_disk_num(sub_F00C8BC4,0,piVar2[2],uVar4,uVar11,0,puVar10 + 4);
            *(undefined *)((int)puVar10 + 0xd) = 1;
          }
          break;
        case :
          _objc_msgSend(uVar11,paSetlastreadyst,3);
          puVar10[2] = 5;
          *(undefined *)(puVar10 + 3) = 0;
          puVar10[5] = piVar2[2];
          break;
        case :
          _objc_msgSend(uVar11,paSetlastreadyst,1);
          break;
        case :
          if (*(char *)((int)puVar10 + 0xd) != '\0') {
            *(undefined *)((int)puVar10 + 0xd) = 0;
            _objc_msgSend(uVar11,pauVar3);
          }
        }
      }
      else {
        if ((uint **)dword_F01330A0 == &dword_F01330A0) {
loc_F00C8804:
          puVar10 = (uint *)0x0;
        }
        else {
          uVar4 = *dword_F01330A0;
          puVar10 = dword_F01330A0;
          while (uVar4 != uVar11) {
            puVar10 = (uint *)puVar10[6];
            if ((uint **)puVar10 == &dword_F01330A0) goto loc_F00C8804;
            uVar4 = *puVar10;
          }
        }
        if (puVar10 != (uint *)0x0) {
          iVar5 = *piVar2;
          goto loc_F00C8840;
        }
        _objc_msgSend(uVar11,paName);
        _IOLog(aVolcheckDiskSN,uVar11,*piVar2);
      }
      _IOFree(piVar2,0x18);
      _objc_msgSend(dword_F01330B0,paLock);
    } while ((int **)dword_F01330A8 != &dword_F01330A8);
  }
  _objc_msgSend(dword_F01330B0,paUnlock);
  return CONCAT44(param_2,param_1);
}

