
/* WARNING: Removing unreachable block (ram,0xf0013d00) */
/* WARNING: Removing unreachable block (ram,0xf0013bb8) */
/* WARNING: Removing unreachable block (ram,0xf0013d08) */
/* WARNING: Removing unreachable block (ram,0xf0013b24) */

undefined8 _ptrace(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  piVar6 = *(int **)(dword_F0133DDC + 0x24);
  if (*piVar6 < 1) {
    *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x10;
    *(undefined4 *)(*_active_u + 0x7c) = *(undefined4 *)(*_active_u + 0x44);
    *(int *)(*(int *)(*_active_u + 0x44) + 0x80) = *_active_u;
    goto locret_F0013D24;
  }
  iVar1 = piVar6[1];
  _pfind();
  if (iVar1 == 0) {
loc_F0013B3C:
    uVar2 = 3;
  }
  else {
    iVar3 = *piVar6;
    iVar7 = *(int *)(iVar1 + 0x68);
    if (iVar3 == 10) {
      iVar3 = *_active_u;
      if (*(sword *)(iVar3 + 0x2c) == 0) {
        uVar4 = *(uint *)(iVar1 + 0x28);
      }
      else {
        if (*(sword *)(iVar1 + 0x2c) != *(sword *)(iVar3 + 0x2c)) goto loc_F0013B3C;
        uVar4 = *(uint *)(iVar1 + 0x28);
      }
      if (((uVar4 & 0x10) == 0) && (*(int *)(iVar3 + 0x80) == 0)) {
        *(uint *)(iVar1 + 0x28) = uVar4 | 0x10;
        *(int *)(iVar1 + 0x7c) = *_active_u;
        *(int *)(iVar3 + 0x80) = iVar1;
        _psignal(iVar1,0x11);
        goto locret_F0013D24;
      }
      goto loc_F0013B3C;
    }
    if ((((*(int *)(iVar7 + 0x44) == 0) || (*(char *)(iVar1 + 0x13) != '\x06')) ||
        (iVar5 = *(int *)(iVar1 + 0x7c), iVar5 != *_active_u)) ||
       ((*(uint *)(iVar1 + 0x28) & 0x10) == 0)) goto loc_F0013B3C;
    if (iVar3 == 8) {
      *(char *)(iVar1 + 0x17) = *(char *)(iVar1 + 0x17) + ' ';
loc_F0013CDC:
      *(undefined *)(iVar1 + 0x13) = 3;
      if ((*(int *)(iVar1 + 0x6c) != 0) && (*(char *)(iVar1 + 0x17) != '\0')) {
        _clear_wait(*(int *)(iVar1 + 0x6c),2,1);
      }
      _task_resume(iVar7);
      goto locret_F0013D24;
    }
    if (iVar3 < 9) {
      if (iVar3 == 7) {
        iVar3 = *(int *)(iVar7 + 0x1c);
loc_F0013C80:
        if ((uint)piVar6[3] < 0x21) {
          if ((0x1ef8 >> (*(char *)(iVar1 + 0x17) - 1U & 0x1f) & 1U) != 0) {
            *(undefined *)(*(int *)(iVar3 + 0x84) + 0x48) = 0;
          }
          *(char *)(iVar1 + 0x17) = (char)piVar6[3];
          if ((0x1ef8 >> ((char)piVar6[3] - 1U & 0x1f) & 1U) != 0) {
            *(char *)(*(int *)(iVar3 + 0x84) + 0x48) = (char)piVar6[3];
          }
          goto loc_F0013CDC;
        }
      }
loc_F0013D18:
      uVar2 = 5;
    }
    else {
      if (iVar3 == 9) {
        iVar3 = *(int *)(iVar7 + 0x1c);
        goto loc_F0013C80;
      }
      if (iVar3 != 0xb) goto loc_F0013D18;
      iVar3 = *(int *)(iVar5 + 0x80);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 0x7c) = 0;
        *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & 0xffffffef;
        *(undefined4 *)(iVar5 + 0x80) = 0;
        goto loc_F0013CDC;
      }
      uVar2 = 0x16;
    }
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
locret_F0013D24:
  return CONCAT44(param_2,param_1);
}
