
/* WARNING: Removing unreachable block (ram,0xf00db3b8) */
/* WARNING: Removing unreachable block (ram,0xf00db328) */
/* WARNING: Removing unreachable block (ram,0xf00db288) */
/* WARNING: Removing unreachable block (ram,0xf00db2ac) */
/* WARNING: Removing unreachable block (ram,0xf00db368) */
/* WARNING: Removing unreachable block (ram,0xf00db3ec) */
/* WARNING: Removing unreachable block (ram,0xf00db238) */

undefined8
-[AudioStream dmaCompleteDescriptor:transfered:]
          (int param_1,undefined4 param_2,int param_3,uint param_4)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  bVar1 = false;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
  piVar7 = *(int **)(param_1 + 0x2c);
  piVar2 = (int *)(param_1 + 0x2c);
  if (piVar2 != piVar7) {
    iVar4 = piVar7[8];
    do {
      if (iVar4 == param_3) {
        if ((piVar7[6] & 1U) != 0) {
          _objc_msgSend(param_1,paSendstatusmess,0,piVar7);
        }
        piVar7[8] = 0;
      }
      _objc_msgSend(param_1,paCompleteregion,piVar7,param_3,param_4,
                    (undefined *)((int)register0x00000038 + -0x14));
      iVar4 = piVar7[0xd];
      if (piVar7[9] == param_3) {
loc_F00DB2E4:
        bVar9 = iVar4 == 0;
loc_F00DB2E8:
        if (bVar9) {
          iVar4 = piVar7[0xd];
        }
        else {
          if ((piVar7[6] & 0x10U) != 0) {
            if ((bVar1) && (*(int *)(param_1 + 0x1c) != 1)) {
              iVar4 = piVar7[0xd];
              goto loc_F00DB334;
            }
            bVar1 = true;
            _objc_msgSend(param_1,paSendstatusmess,4,piVar7);
          }
          iVar4 = piVar7[0xd];
        }
loc_F00DB334:
        if (iVar4 == 0) {
          if (piVar7[0xc] == 0) {
            if ((piVar7[6] & 2U) != 0) {
              _objc_msgSend(param_1,paSendstatusmess,1,piVar7);
            }
            goto loc_F00DB374;
          }
          piVar8 = (int *)piVar7[0xf];
        }
        else {
loc_F00DB374:
          piVar8 = (int *)piVar7[0xf];
        }
        piVar6 = (int *)piVar7[0x10];
        piVar5 = piVar2;
        if (piVar2 != piVar8) {
          piVar5 = piVar8 + 0xf;
        }
        piVar5[1] = (int)piVar6;
        piVar5 = piVar2;
        if (piVar2 != piVar6) {
          piVar5 = piVar6 + 0xf;
        }
        *piVar5 = (int)piVar8;
        _objc_msgSend(param_1,paFreeregion,piVar7);
        piVar7 = (int *)piVar7[0xf];
      }
      else {
        bVar9 = iVar4 == 0;
        if (!bVar9) goto loc_F00DB2E8;
        if (piVar7[0xc] != 0) {
          iVar4 = piVar7[0xd];
          goto loc_F00DB2E4;
        }
        if (param_4 <= *(uint *)((int)register0x00000038 + -0x14)) {
          uVar3 = *(undefined4 *)(param_1 + 0x28);
          goto loc_F00DB3E8;
        }
        piVar7 = (int *)piVar7[0xf];
      }
      if (piVar2 == piVar7) goto loc_f00db3e4;
      iVar4 = piVar7[8];
    } while( true );
  }
  uVar3 = *(undefined4 *)(param_1 + 0x28);
loc_F00DB3E8:
  _objc_msgSend(uVar3,paUnlock);
  return CONCAT44(param_2,param_1);
loc_f00db3e4:
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  goto loc_F00DB3E8;
}
