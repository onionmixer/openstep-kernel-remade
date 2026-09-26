
/* WARNING: Removing unreachable block (ram,0xf00e9744) */
/* WARNING: Removing unreachable block (ram,0xf00e985c) */
/* WARNING: Removing unreachable block (ram,0xf00e96b4) */
/* WARNING: Removing unreachable block (ram,0xf00e9810) */
/* WARNING: Removing unreachable block (ram,0xf00e96f8) */
/* WARNING: Removing unreachable block (ram,0xf00e9900) */
/* WARNING: Removing unreachable block (ram,0xf00e967c) */

undefined8 -[IOFrameBufferDisplay hideCursor:](int param_1,undefined4 param_2)

{
  char cVar1;
  sword sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  undefined4 unaff_l0;
  int iVar10;
  undefined4 unaff_l1;
  int iVar11;
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
  iVar3 = *(int *)(param_1 + 0x1fc) + 4;
  _ev_try_lock();
  if (iVar3 == 0) goto locret_F00E9908;
  cVar1 = *(char *)(*(int *)(param_1 + 0x1fc) + 8);
  *(char *)(*(int *)(param_1 + 0x1fc) + 8) = cVar1 + '\x01';
  if (cVar1 == '\0') {
    iVar3 = param_1;
    _objc_msgSend(param_1,paDisplayinfo);
    uVar4 = *(uint *)(iVar3 + 0x18);
    if (uVar4 < 4) {
      if (uVar4 < 2) {
        if (uVar4 == 1) {
          iVar3 = param_1;
          _objc_msgSend(param_1,paDisplayinfo);
          iVar10 = *(int *)(param_1 + 0x1fc);
          *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar10 + 0xc);
          *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar10 + 0xe);
          sVar2 = *(sword *)(iVar10 + 0x10);
          *(sword *)((int)register0x00000038 + -0x14) = sVar2;
          *(undefined2 *)((int)register0x00000038 + -0x12) = *(undefined2 *)(iVar10 + 0x12);
          iVar11 = *(int *)(iVar3 + 8);
          iVar5 = iVar11;
          umul(iVar11,(int)sVar2 - (int)*(sword *)(iVar10 + 0x34));
          puVar9 = (undefined *)(iVar10 + 0x848);
          puVar7 = (undefined *)
                   (*(int *)(iVar3 + 0x14) + iVar5 +
                   ((int)*(sword *)((int)register0x00000038 + -0x18) -
                   (int)*(sword *)(iVar10 + 0x30)));
          iVar10 = (uint)*(word *)((int)register0x00000038 + -0x16) -
                   (int)*(sword *)((int)register0x00000038 + -0x18);
          iVar5 = ((uint)*(word *)((int)register0x00000038 + -0x12) -
                  (uint)*(word *)((int)register0x00000038 + -0x14)) + -1;
          iVar3 = iVar10;
          if (iVar5 * 0x10000 >> 0x10 == -1) goto loc_F00E98FC;
          do {
            while ((iVar3 + -1) * 0x10000 >> 0x10 != -1) {
              *puVar7 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar7 = puVar7 + 1;
              iVar3 = iVar3 + -1;
            }
            iVar5 = iVar5 + -1;
            puVar7 = puVar7 + (iVar11 - (iVar10 * 0x10000 >> 0x10));
            iVar3 = iVar10;
          } while (iVar5 * 0x10000 >> 0x10 != -1);
          iVar3 = *(int *)(param_1 + 0x1fc);
        }
        else {
          iVar3 = *(int *)(param_1 + 0x1fc);
        }
      }
      else {
loc_F00E98FC:
        iVar3 = *(int *)(param_1 + 0x1fc);
      }
    }
    else {
      if (uVar4 == 4) {
        iVar3 = param_1;
        _objc_msgSend(param_1,paDisplayinfo);
        iVar10 = *(int *)(param_1 + 0x1fc);
        *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar10 + 0xc);
        *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar10 + 0xe);
        sVar2 = *(sword *)(iVar10 + 0x10);
        *(sword *)((int)register0x00000038 + -0x14) = sVar2;
        *(undefined2 *)((int)register0x00000038 + -0x12) = *(undefined2 *)(iVar10 + 0x12);
        iVar11 = *(int *)(iVar3 + 8);
        iVar5 = iVar11;
        umul(iVar11,(int)sVar2 - (int)*(sword *)(iVar10 + 0x34));
        puVar8 = (undefined4 *)(iVar10 + 0x1048);
        puVar6 = (undefined4 *)
                 (*(int *)(iVar3 + 0x14) + iVar5 * 4 +
                 ((int)*(sword *)((int)register0x00000038 + -0x18) - (int)*(sword *)(iVar10 + 0x30))
                 * 4);
        iVar5 = (int)*(sword *)((int)register0x00000038 + -0x16) -
                (int)*(sword *)((int)register0x00000038 + -0x18);
        iVar3 = (int)*(sword *)((int)register0x00000038 + -0x12) -
                (int)*(sword *)((int)register0x00000038 + -0x14);
        while (iVar3 = iVar3 + -1, iVar10 = iVar5, iVar3 != -1) {
          while (iVar10 + -1 != -1) {
            *puVar6 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar6 = puVar6 + 1;
            iVar10 = iVar10 + -1;
          }
          puVar6 = puVar6 + (iVar11 - iVar5);
        }
        goto loc_F00E98FC;
      }
      iVar3 = *(int *)(param_1 + 0x1fc);
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1fc);
  }
  _ev_unlock(iVar3 + 4);
locret_F00E9908:
  return CONCAT44(param_2,param_1);
}

