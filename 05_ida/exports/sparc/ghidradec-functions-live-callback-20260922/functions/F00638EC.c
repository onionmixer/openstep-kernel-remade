
/* WARNING: Removing unreachable block (ram,0xf0063b38) */
/* WARNING: Removing unreachable block (ram,0xf0063bc4) */
/* WARNING: Removing unreachable block (ram,0xf0063bcc) */
/* WARNING: Removing unreachable block (ram,0xf00638f4) */

undefined8 _ast_check(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
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
  
  iVar3 = _active_threads;
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
  puVar4 = DAT_f0134000;
  _splusclock();
  iVar6 = *(int *)(_processor_ptr + 0x114);
  if (iVar6 != 1) {
    if (iVar6 < 2) {
      if (iVar6 == 0) goto loc_F0063BCC;
    }
    else if (iVar6 < 4) goto loc_F0063BCC;
    _panic(aAstCheckBadPro);
    goto loc_F0063BCC;
  }
  iVar6 = *_active_u;
  if ((iVar6 != 0) &&
     ((*(char *)(iVar6 + 0x17) != '\0' ||
      (((iVar3 != 0 &&
        (uVar1 = *(uint *)(iVar6 + 0x18) | *(uint *)(*(int *)(iVar3 + 0x84) + 0x4c), uVar1 != 0)) &&
       (((*(uint *)(iVar6 + 0x28) & 0x10) != 0 ||
        ((uVar1 & ~(*(uint *)(iVar6 + 0x20) | *(uint *)(iVar6 + 0x1c))) != 0)))))))) {
    _need_ast = _need_ast | 0x20;
  }
  _need_ast = _need_ast | *(uint *)(iVar3 + 0x18c);
  if (_need_ast != 0) goto loc_F0063BCC;
  if (((*(uint *)(iVar3 + 0x4c) & 2) != 0) || (0 < *(int *)(_processor_ptr + 0x108))) {
    _need_ast = 4;
    goto loc_F0063BCC;
  }
  iVar6 = *(int *)(_processor_ptr + 300);
  if ((*(uint *)(iVar6 + 0x168) & 2) == 0) {
    if ((*(int *)(_processor_ptr + 0x124) != 0) || (*(int *)(iVar6 + 0x108) < 1)) goto loc_F0063BCC;
    iVar5 = *(int *)(iVar6 + 0x104) * 8;
    if (iVar6 + iVar5 == *(int *)(iVar6 + iVar5)) {
      do {
        do {
        } while (*(int *)(iVar6 + 0x100) != 0);
        piVar9 = (int *)(iVar6 + 0x100);
        _simple_lock_try();
      } while (piVar9 == (int *)0x0);
      iVar5 = *(int *)(iVar6 + 0x104);
      piVar9 = (int *)(iVar6 + iVar5 * 8);
      if (0 < *(int *)(iVar6 + 0x108)) {
        if (iVar5 < 0) {
          *(int *)(iVar6 + 0x104) = iVar5;
        }
        else {
          do {
            if (piVar9 != (int *)*piVar9) {
              *(int *)(iVar6 + 0x104) = iVar5;
              goto loc_F0063B90;
            }
            iVar5 = iVar5 + -1;
            piVar9 = piVar9 + -2;
          } while (-1 < iVar5);
          *(int *)(iVar6 + 0x104) = iVar5;
        }
      }
loc_F0063B90:
      *(undefined4 *)(iVar6 + 0x100) = 0;
      iVar6 = *(int *)(iVar6 + 0x104);
    }
    else {
      iVar6 = *(int *)(iVar6 + 0x104);
    }
    uVar1 = _need_ast;
    if (iVar6 < *(int *)(iVar3 + 0x58)) goto loc_F0063BCC;
  }
  else {
    iVar8 = *(int *)(iVar6 + 0x104);
    iVar5 = *(int *)(iVar3 + 0x60);
    iVar7 = *(int *)(iVar3 + 0x58);
    if (((iVar5 == 2) || (2 < iVar5)) || (iVar5 != 1)) {
      if (*(int *)(iVar6 + 0x108) == 0) goto loc_F0063AC4;
      bVar2 = false;
      if (((iVar7 <= iVar8) && (bVar2 = true, iVar8 <= iVar7)) &&
         (bVar2 = false, *(int *)(_processor_ptr + 0x124) == 0)) {
        bVar2 = true;
      }
    }
    else {
      bVar2 = false;
      if (((*(int *)(_processor_ptr + 0x124) == 0) && (0 < *(int *)(iVar6 + 0x108))) &&
         (bVar2 = true, iVar8 < iVar7)) {
loc_F0063AC4:
        bVar2 = false;
      }
    }
    uVar1 = 0;
    if (!bVar2) {
      if (*(int *)(iVar3 + 0x60) == 2) {
        *(undefined4 *)(_processor_ptr + 0x124) = 1;
      }
      goto loc_F0063BCC;
    }
  }
  _need_ast = uVar1;
  _need_ast = _need_ast | 4;
loc_F0063BCC:
  _splx(puVar4);
  return CONCAT44(param_2,param_1);
}

