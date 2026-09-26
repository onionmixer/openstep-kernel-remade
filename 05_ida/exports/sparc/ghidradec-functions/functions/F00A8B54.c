
/* WARNING: Removing unreachable block (ram,0xf00a8e00) */
/* WARNING: Removing unreachable block (ram,0xf00a8cf8) */
/* WARNING: Removing unreachable block (ram,0xf00a8ce4) */
/* WARNING: Removing unreachable block (ram,0xf00a8d10) */
/* WARNING: Removing unreachable block (ram,0xf00a8df0) */
/* WARNING: Removing unreachable block (ram,0xf00a8be8) */

undefined8 _unix_syscall_return(uint param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l0;
  uint *puVar8;
  undefined4 unaff_l1;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 *puVar10;
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
  bool bVar11;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar2 = _active_threads;
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
  puVar10 = *(undefined4 **)(_active_threads + 0x84);
  puVar8 = (uint *)*puVar10;
  iVar9 = *_active_u;
  if (param_1 == 0) goto def_F00A8B98;
  switch(param_1) {
  case :
    goto loc_F00A8C24;
  case :
    iVar4 = 0;
    _fspause();
    if (iVar4 != 0) {
      *(undefined *)(dword_F0133DDC + 0x39) = 2;
    }
  }
def_F00A8B98:
  if (*(char *)((int)puVar10 + 0x39) == '\x03') {
    if (param_1 == 0) {
      *puVar8 = *puVar8 & 0xffefffff;
      puVar8[0xb] = *(uint *)(dword_F0133DDC + 0x30);
      puVar8[0xc] = *(uint *)(dword_F0133DDC + 0x34);
    }
    else {
loc_F00A8C24:
      puVar8[0xb] = param_1;
      *puVar8 = *puVar8 | 0x100000;
    }
    puVar8[1] = puVar8[2];
    puVar8[2] = puVar8[2] + 4;
    uVar3 = *(uint *)(iVar2 + 0x18c);
  }
  else {
    uVar3 = *(uint *)(iVar2 + 0x18c);
  }
loc_F00A8C7C:
  do {
    if ((uVar3 & 3) == 0) {
      bVar11 = false;
      if (*(char *)(iVar9 + 0x17) == '\0') {
        uVar3 = *(uint *)(iVar9 + 0x18) | puVar10[0x13];
        if (uVar3 == 0) {
          uVar3 = *(uint *)(iVar2 + 0x18c);
          goto loc_F00A8D04;
        }
        if ((*(uint *)(iVar9 + 0x28) & 0x10) == 0) {
          if ((uVar3 & ~(*(uint *)(iVar9 + 0x20) | *(uint *)(iVar9 + 0x1c))) == 0) {
            uVar3 = *(uint *)(iVar2 + 0x18c);
            goto loc_F00A8D04;
          }
          cVar1 = *(char *)(iVar9 + 0x17);
        }
        else {
          cVar1 = *(char *)(iVar9 + 0x17);
        }
        bVar11 = cVar1 == '\0';
      }
      if (bVar11) {
        iVar4 = 0;
        _issig();
        if (iVar4 == 0) {
          uVar3 = *(uint *)(iVar2 + 0x18c);
          goto loc_F00A8D04;
        }
      }
      _psig();
      uVar3 = *(uint *)(iVar2 + 0x18c);
    }
    else {
      uVar3 = *(uint *)(iVar2 + 0x18c);
    }
loc_F00A8D04:
    if ((uVar3 & 3) == 0) {
      iVar7 = *(int *)(*(int *)(_processor_ptr + 300) + 0x108);
      iVar6 = *(int *)(*(int *)(_processor_ptr + 300) + 0x104);
      iVar4 = *(int *)(iVar2 + 0x60);
      iVar5 = *(int *)(iVar2 + 0x58);
      if ((*(uint *)(iVar2 + 0x4c) & 2) == 0) {
        if (*(int *)(_processor_ptr + 0x108) < 1) {
          if (((iVar4 == 2) || (2 < iVar4)) || (iVar4 != 1)) {
            if (iVar7 == 0) {
              bVar11 = false;
            }
            else {
              bVar11 = false;
              if (((iVar5 <= iVar6) && (bVar11 = true, iVar6 <= iVar5)) &&
                 (bVar11 = false, *(int *)(_processor_ptr + 0x124) == 0)) {
                bVar11 = true;
              }
            }
          }
          else {
            bVar11 = false;
            if (((*(int *)(_processor_ptr + 0x124) == 0) && (0 < iVar7)) &&
               (bVar11 = false, iVar5 <= iVar6)) goto loc_F00A8DC4;
          }
        }
        else {
          bVar11 = true;
        }
      }
      else {
loc_F00A8DC4:
        bVar11 = true;
      }
      if (!bVar11) {
        _thread_exception_return();
        return CONCAT44(param_2,param_1);
      }
      _active_u[0x6c] = _active_u[0x6c] + 1;
      _thread_block_with_continuation(_thread_exception_return);
      uVar3 = *(uint *)(iVar2 + 0x18c);
      goto loc_F00A8C7C;
    }
    _thread_halt_self();
    uVar3 = *(uint *)(iVar2 + 0x18c);
  } while( true );
}
