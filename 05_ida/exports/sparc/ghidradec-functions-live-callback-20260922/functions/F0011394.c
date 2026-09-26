
/* WARNING: Removing unreachable block (ram,0xf00114a8) */
/* WARNING: Removing unreachable block (ram,0xf0011470) */

undefined8 _killpg1(int param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
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
  uVar5 = 0;
  if (((param_3 == 0) && (param_2 == 0)) &&
     (param_2 = (int)*(sword *)(*_active_u + 0x2e), param_2 == 0)) {
    uVar5 = 3;
  }
  else {
    iVar4 = 0;
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2e);
      iVar3 = _allproc;
      do {
        if ((sVar1 == param_2) || (param_3 != 0)) {
          if (*(sword *)(iVar3 + 0x32) == 0) {
            iVar3 = *(int *)(iVar3 + 8);
          }
          else if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
            if ((param_3 == 0) || (iVar3 != *_active_u)) {
              if (((*(sword *)(_active_u[7] + 2) == 0) ||
                  (*(sword *)(_active_u[7] + 2) == *(sword *)(iVar3 + 0x2c))) ||
                 ((param_1 == 0x13 && (iVar2 = iVar3, _inferior(), iVar2 != 0)))) {
                iVar4 = iVar4 + 1;
                if (param_1 != 0) {
                  _psignal(iVar3,param_1);
                }
              }
              else {
                if (param_3 != 0) {
                  iVar3 = *(int *)(iVar3 + 8);
                  goto loc_F00114B4;
                }
                uVar5 = 1;
              }
              iVar3 = *(int *)(iVar3 + 8);
            }
            else {
              iVar3 = *(int *)(iVar3 + 8);
            }
          }
          else {
            iVar3 = *(int *)(iVar3 + 8);
          }
        }
        else {
          iVar3 = *(int *)(iVar3 + 8);
        }
loc_F00114B4:
        if (iVar3 == 0) break;
        sVar1 = *(sword *)(iVar3 + 0x2e);
      } while( true );
    }
    if (uVar5 == 0) {
      uVar5 = (iVar4 != 0) - 1 & 3;
    }
  }
  return CONCAT44(param_2,uVar5);
}

