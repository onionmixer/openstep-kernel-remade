
/* WARNING: Removing unreachable block (ram,0xf00db660) */
/* WARNING: Removing unreachable block (ram,0xf00db5bc) */
/* WARNING: Removing unreachable block (ram,0xf00db558) */
/* WARNING: Removing unreachable block (ram,0xf00db630) */
/* WARNING: Removing unreachable block (ram,0xf00db4b8) */
/* WARNING: Removing unreachable block (ram,0xf00db494) */

undefined8
-[AudioStream mixBuffer:maxCount:rate:format:channelCount:descriptor:virgin:streamCount:]
          (uint param_1,undefined4 param_2,int param_3,uint param_4,int *param_5,int *param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l3;
  int *piVar7;
  undefined4 unaff_l4;
  undefined4 uVar8;
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
  piVar7 = *(int **)((int)register0x00000038 + 0x5c);
  uVar6 = *(uint *)((int)register0x00000038 + 100);
  uVar5 = 0;
  uVar8 = *(undefined4 *)((int)register0x00000038 + 0x60);
  if (*(char *)(param_1 + 0x24) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
    iVar4 = *(int *)(param_1 + 0x2c);
    if (param_1 + 0x2c == iVar4) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paUnlock);
      uVar5 = 0;
    }
    else {
      uVar3 = *(uint *)(iVar4 + 8);
      while( true ) {
        if (uVar3 < *(uint *)(iVar4 + 4)) {
          if (*(int *)(iVar4 + 0x34) == 0) {
            if (*param_5 == 0) {
              *param_5 = *(int *)(param_1 + 100);
              iVar1 = *param_6;
            }
            else {
              iVar1 = *param_6;
            }
            if (iVar1 == -1) {
              *param_6 = *(int *)(param_1 + 0x68);
              iVar1 = *piVar7;
            }
            else {
              iVar1 = *piVar7;
            }
            if (iVar1 == 0) {
              *piVar7 = *(int *)(param_1 + 0x6c);
            }
            uVar3 = param_1;
            _objc_msgSend(param_1,paCanconvertregi,iVar4,*param_5,*param_6,*piVar7);
            if ((uVar3 & 0xff) == 0) {
              iVar4 = *(int *)(iVar4 + 0x3c);
            }
            else {
              uVar3 = param_3 + uVar5;
              if ((*(int *)(param_1 + 0x68) == 0) && ((uVar3 & 1) != 0)) {
                uVar3 = uVar3 & 0xfffffffe;
              }
              uVar2 = param_1;
              _objc_msgSend(param_1,paMixregionDescr,iVar4,uVar8,uVar3,param_4 - uVar5,
                            (int)(char)uVar6,*param_5,*param_6,*piVar7);
              if (*(int *)(iVar4 + 0x28) == 0) {
                *(undefined4 *)(iVar4 + 0x20) = uVar8;
                *(undefined4 *)(iVar4 + 0x28) = 1;
              }
              uVar5 = uVar5 + uVar2;
              if ((*(uint *)(iVar4 + 4) <= *(uint *)(iVar4 + 8)) && (*(int *)(iVar4 + 0x2c) == 0)) {
                *(undefined4 *)(iVar4 + 0x24) = uVar8;
                *(undefined4 *)(iVar4 + 0x2c) = 1;
              }
              if (param_4 <= uVar5) {
                uVar8 = *(undefined4 *)(param_1 + 0x28);
                goto loc_F00DB62C;
              }
              iVar4 = *(int *)(iVar4 + 0x3c);
            }
          }
          else {
            iVar4 = *(int *)(iVar4 + 0x3c);
          }
        }
        else {
          iVar4 = *(int *)(iVar4 + 0x3c);
        }
        if (param_1 + 0x2c == iVar4) break;
        uVar3 = *(uint *)(iVar4 + 8);
      }
      uVar8 = *(undefined4 *)(param_1 + 0x28);
loc_F00DB62C:
      _objc_msgSend(uVar8,paUnlock);
      if (((uVar6 & 0xff) != 0) && (uVar5 < param_4)) {
        _objc_msgSend(param_1,paClearformixSiz,param_3 + uVar5,param_4 - uVar5,*param_6);
      }
    }
  }
  else {
    uVar5 = 0;
  }
  return CONCAT44(param_2,uVar5);
}

