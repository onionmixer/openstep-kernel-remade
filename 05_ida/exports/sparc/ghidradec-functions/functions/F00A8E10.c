
/* WARNING: Removing unreachable block (ram,0xf00a9168) */
/* WARNING: Removing unreachable block (ram,0xf00a9064) */
/* WARNING: Removing unreachable block (ram,0xf00a903c) */
/* WARNING: Removing unreachable block (ram,0xf00a8fd8) */
/* WARNING: Removing unreachable block (ram,0xf00a8f08) */
/* WARNING: Removing unreachable block (ram,0xf00a8ed8) */
/* WARNING: Removing unreachable block (ram,0xf00a8ea0) */
/* WARNING: Removing unreachable block (ram,0xf00a8fec) */
/* WARNING: Removing unreachable block (ram,0xf00a9058) */
/* WARNING: Removing unreachable block (ram,0xf00a907c) */
/* WARNING: Removing unreachable block (ram,0xf00a9158) */
/* WARNING: Removing unreachable block (ram,0xf00a8e2c) */

undefined8 _machcall(uint *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar14;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar15;
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
  bool bVar16;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  if ((*param_1 & 0x40) != 0) {
    _panic(aMachcallNotUse);
  }
  iVar15 = *(int *)(iVar3 + 0x84);
  *dword_F0133DDC = (int)param_1;
  iVar14 = *_active_u;
  if (iVar14 == 0) {
    uVar4 = param_1[2];
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = _active_u[0x5d];
    *(int *)((int)register0x00000038 + -0xc) = _active_u[0x5e];
    uVar4 = param_1[2];
  }
  param_1[1] = uVar4;
  param_1[2] = param_1[2] + 4;
  iVar9 = -param_1[4];
  uVar4 = 0xf0110800;
  if ((iVar9 < 0) ||
     (iVar6 = param_1[4] * -0x10, uVar4 = _mach_trap_count, (int)_mach_trap_count <= iVar9)) {
    _kern_invalid();
    param_1[0xb] = uVar4;
  }
  else {
    iVar9 = *(int *)(_mach_trap_table + iVar6);
    if (iVar9 < 7) {
      uVar4 = param_1[0xb];
      uVar7 = param_1[0xc];
      uVar8 = param_1[0xd];
      uVar10 = param_1[0xe];
      uVar11 = param_1[0xf];
      uVar12 = param_1[0x10];
    }
    else {
      iVar13 = param_1[0x11] + 0x5c;
      _copyin(iVar13,iVar15 + 4,(iVar9 + -6) * 4);
      if (iVar13 != 0) {
        *(undefined *)(dword_F0133DDC + 0xe) = 0xe;
        goto loc_F00A8F60;
      }
      if (7 < iVar9) {
        _panic(aMachKernelTrap,iVar9);
      }
      uVar4 = param_1[0xb];
      uVar7 = param_1[0xc];
      uVar8 = param_1[0xd];
      uVar10 = param_1[0xe];
      uVar11 = param_1[0xf];
      uVar12 = param_1[0x10];
    }
    (**(code **)(_mach_trap_table + iVar6 + 4))(uVar4,uVar7,uVar8,uVar10,uVar11,uVar12);
    param_1[0xb] = uVar4;
  }
loc_F00A8F60:
  do {
    if (iVar14 != 0) {
      if ((*(uint *)(iVar3 + 0x18c) & 3) == 0) {
        bVar16 = false;
        if (*(char *)(iVar14 + 0x17) == '\0') {
          uVar4 = *(uint *)(iVar14 + 0x18) | *(uint *)(*(int *)(iVar3 + 0x84) + 0x4c);
          if (uVar4 == 0) goto loc_F00A8FF8;
          if ((*(uint *)(iVar14 + 0x28) & 0x10) == 0) {
            if ((uVar4 & ~(*(uint *)(iVar14 + 0x20) | *(uint *)(iVar14 + 0x1c))) == 0)
            goto loc_F00A8FF8;
            cVar1 = *(char *)(iVar14 + 0x17);
          }
          else {
            cVar1 = *(char *)(iVar14 + 0x17);
          }
          bVar16 = cVar1 == '\0';
        }
        if (bVar16) {
          iVar15 = 0;
          _issig();
          if (iVar15 == 0) goto loc_F00A8FF8;
        }
        _psig();
      }
loc_F00A8FF8:
      piVar2 = _active_u;
      if ((iVar14 != 0) && (_active_u[0x96] != 0)) {
        iVar9 = _active_u[0x5d];
        iVar15 = _active_u[0x5e] - *(int *)((int)register0x00000038 + -0xc);
        iVar6 = *(int *)((int)register0x00000038 + -0x10);
        .div(iVar15,1000);
        iVar15 = (iVar9 - iVar6) * 1000 + iVar15;
        uVar5 = _tick;
        .div(_tick,1000);
        .div(iVar15,uVar5);
        if (iVar15 != 0) {
          _addupc(param_1[1],piVar2 + 0x91,iVar15);
        }
      }
    }
    iVar13 = *(int *)(*(int *)(_processor_ptr + 300) + 0x108);
    iVar6 = *(int *)(*(int *)(_processor_ptr + 300) + 0x104);
    iVar15 = *(int *)(iVar3 + 0x60);
    iVar9 = *(int *)(iVar3 + 0x58);
    if ((*(uint *)(iVar3 + 0x4c) & 2) == 0) {
      if (*(int *)(_processor_ptr + 0x108) < 1) {
        if (((iVar15 == 2) || (2 < iVar15)) || (iVar15 != 1)) {
          if (iVar13 == 0) {
            bVar16 = false;
          }
          else {
            bVar16 = false;
            if (((iVar9 <= iVar6) && (bVar16 = true, iVar6 <= iVar9)) &&
               (bVar16 = false, *(int *)(_processor_ptr + 0x124) == 0)) {
              bVar16 = true;
            }
          }
        }
        else {
          bVar16 = false;
          if (((*(int *)(_processor_ptr + 0x124) == 0) && (0 < iVar13)) &&
             (bVar16 = false, iVar9 <= iVar6)) goto loc_F00A912C;
        }
      }
      else {
        bVar16 = true;
      }
    }
    else {
loc_F00A912C:
      bVar16 = true;
    }
    if (!bVar16) {
      _thread_exception_return();
      return CONCAT44(param_2,param_1);
    }
    _active_u[0x6c] = _active_u[0x6c] + 1;
    _thread_block_with_continuation(_thread_exception_return);
  } while( true );
}
