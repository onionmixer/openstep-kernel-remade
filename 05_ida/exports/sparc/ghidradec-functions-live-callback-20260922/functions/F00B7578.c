
/* WARNING: Removing unreachable block (ram,0xf00b762c) */
/* WARNING: Removing unreachable block (ram,0xf00b7610) */
/* WARNING: Removing unreachable block (ram,0xf00b7638) */

undefined8 _esp_watchsubr(int param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
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
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar2 = *(int *)((iVar2 >> 0xe) + param_1 + 0xb8);
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 0x29) == '\0') {
        if ((*(sword *)(param_1 + 0xb2) != -1) &&
           (iVar2 != *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8))) goto loc_F00B7648;
        wVar1 = *(word *)(iVar2 + 0x5c);
      }
      else {
        wVar1 = *(word *)(iVar2 + 0x5c);
      }
      if ((wVar1 & 0x20) != 0) {
        if (*(int *)(iVar2 + 0x58) == 0) {
          if ((**(uint **)(param_1 + 0xa0) & 3) == 0) {
            if ((wVar1 & 0x10) == 0) {
              _esp_curcmd_timeout(param_1);
            }
            else {
              _esp_disccmd_timeout(param_1,(int)(sword)iVar3);
            }
          }
          else {
            *(undefined4 *)(iVar2 + 0x58) = 1;
            _espsvc(param_1);
          }
          break;
        }
        *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + -1;
      }
    }
loc_F00B7648:
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 0x10000;
  } while (iVar3 * 0x10000 >> 0x10 < 0x40);
  return CONCAT44(param_2,param_1);
}

