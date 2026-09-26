
undefined4 sub_4062AD4(int param_1,uint param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  
  uVar7 = param_2 >> (_page_shift & 0x3f);
  iVar1 = sub_4062A70(param_1,param_2,param_4);
  if (param_3 == 1) {
    if (iVar1 != 0) {
      return 0;
    }
    goto loc_4062B16;
  }
  if (iVar1 == 0) {
loc_4062B4A:
    uVar5 = uVar7 + 1;
    uVar6 = *(uint *)(param_1 + 0x10);
    if (uVar6 < uVar5) {
      if (uVar5 * 4 < 0x41) {
        piVar3 = (int *)_kalloc_noblock(uVar5 * 4);
        if (piVar3 != (int *)0x0) {
          iVar1 = 0;
          piVar8 = piVar3;
          if (0 < *(int *)(param_1 + 0x10)) {
            do {
              *piVar8 = *(int *)(*(int *)(param_1 + 8) + iVar1 * 4);
              iVar1 = iVar1 + 1;
              piVar8 = piVar8 + 1;
            } while (iVar1 < *(int *)(param_1 + 0x10));
          }
          iVar1 = *(int *)(param_1 + 0x10);
          if (iVar1 < (int)uVar5) {
            piVar8 = piVar3 + iVar1;
            do {
              *(undefined *)piVar8 = 0;
              piVar8 = piVar8 + 1;
              iVar1 = iVar1 + 1;
            } while (iVar1 < (int)uVar5);
          }
          iVar1 = *(int *)(param_1 + 0x10);
          if (0 < iVar1) {
loc_4062CD6:
            iVar1 = iVar1 << 2;
loc_4062CDA:
            _kfree(*(undefined4 *)(param_1 + 8),iVar1);
          }
loc_4062CE6:
          *(int **)(param_1 + 8) = piVar3;
loc_4062CEA:
          *(uint *)(param_1 + 0x10) = uVar5;
          goto loc_4062CEE;
        }
      }
      else if (uVar6 == 0) {
        iVar1 = ((uVar7 >> 4) + 1) * 4;
        piVar3 = (int *)_kalloc_noblock(iVar1);
        if (piVar3 != (int *)0x0) {
          _bzero(piVar3,iVar1);
          goto loc_4062CE6;
        }
      }
      else if (uVar6 << 2 < 0x41) {
        iVar1 = ((uVar7 >> 4) + 1) * 4;
        piVar3 = (int *)_kalloc_noblock(iVar1);
        if (piVar3 != (int *)0x0) {
          _bzero(piVar3,iVar1);
          iVar4 = _kalloc_noblock(0x40);
          *piVar3 = iVar4;
          if (iVar4 != 0) {
            iVar1 = 0;
            if (0 < *(int *)(param_1 + 0x10)) {
              do {
                *(undefined4 *)(*piVar3 + iVar1 * 4) =
                     *(undefined4 *)(*(int *)(param_1 + 8) + iVar1 * 4);
                iVar1 = iVar1 + 1;
              } while (iVar1 < *(int *)(param_1 + 0x10));
            }
            for (uVar6 = *(uint *)(param_1 + 0x10); uVar6 < 0x10; uVar6 = uVar6 + 1) {
              *(undefined *)(*piVar3 + uVar6 * 4) = 0;
            }
            iVar1 = *(int *)(param_1 + 0x10);
            goto loc_4062CD6;
          }
          _kfree(piVar3,iVar1);
        }
      }
      else {
        iVar1 = ((uVar7 >> 4) + 1) * 4;
        if (((uVar6 - 1 >> 4) + 1) * 4 == iVar1) goto loc_4062CEA;
        piVar3 = (int *)_kalloc_noblock(iVar1);
        if (piVar3 != (int *)0x0) {
          _bzero(piVar3,iVar1);
          uVar6 = 0;
          piVar8 = piVar3;
          if (*(int *)(param_1 + 0x10) - 1U >> 4 != 0xffffffff) {
            do {
              *piVar8 = *(int *)(*(int *)(param_1 + 8) + uVar6 * 4);
              uVar6 = uVar6 + 1;
              piVar8 = piVar8 + 1;
            } while (uVar6 < (*(int *)(param_1 + 0x10) - 1U >> 4) + 1);
          }
          iVar1 = (*(int *)(param_1 + 0x10) - 1U >> 4) * 4 + 4;
          goto loc_4062CDA;
        }
      }
    }
    else {
loc_4062CEE:
      if ((uint)(*(int *)(param_1 + 0x10) << 2) < 0x41) {
        iVar1 = _vnode_pager_findpage(*(undefined4 *)(param_1 + 4),param_4);
        if (iVar1 != 5) {
          iVar1 = *(int *)(param_1 + 8);
          goto loc_4062D78;
        }
      }
      else {
        uVar6 = uVar7 >> 4;
        uVar7 = uVar7 & 0xf;
        if (*(int *)(*(int *)(param_1 + 8) + uVar6 * 4) == 0) {
          uVar2 = _kalloc_noblock(0x40);
          *(undefined4 *)(*(int *)(param_1 + 8) + uVar6 * 4) = uVar2;
          if (*(int *)(*(int *)(param_1 + 8) + uVar6 * 4) == 0) goto loc_4062B16;
          uVar5 = 0;
          do {
            *(undefined *)(*(int *)(*(int *)(param_1 + 8) + uVar6 * 4) + uVar5 * 4) = 0;
            uVar5 = uVar5 + 1;
          } while (uVar5 < 0x10);
        }
        iVar1 = _vnode_pager_findpage(*(undefined4 *)(param_1 + 4),param_4);
        if (iVar1 != 5) {
          iVar1 = *(int *)(*(int *)(param_1 + 8) + uVar6 * 4);
loc_4062D78:
          *(uint *)(iVar1 + uVar7 * 4) = *param_4;
          goto loc_4062D7C;
        }
      }
    }
loc_4062B16:
    uVar2 = 5;
  }
  else {
    if (*(int *)((&unk_40B4E00)[*(byte *)param_4] + 0x24) < (int)(*param_4 & 0xffffff)) {
      sub_40628FA(*param_4);
      goto loc_4062B4A;
    }
loc_4062D7C:
    uVar2 = 0;
  }
  return uVar2;
}
