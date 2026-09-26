
/* WARNING: Removing unreachable block (ram,0xf00aa158) */
/* WARNING: Removing unreachable block (ram,0xf00aa16c) */
/* WARNING: Removing unreachable block (ram,0xf00aa274) */
/* WARNING: Removing unreachable block (ram,0xf00aa0c4) */

undefined8 _check_for_ast(int param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 unaff_l0;
  int iVar10;
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
  bool bVar11;
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
  iVar10 = *_active_u;
  piVar6 = param_2;
  do {
    uVar2 = _need_ast;
    if (iVar10 != 0) {
      piVar6 = _active_u;
      if (((*(uint *)(iVar10 + 0x28) & 0x200000) != 0) &&
         (piVar6 = _active_u + 0x91, _active_u[0x96] != 0)) {
        _addupc(*(undefined4 *)(param_1 + 4),piVar6,1);
        *(uint *)(iVar10 + 0x28) = *(uint *)(iVar10 + 0x28) & 0xffdfffff;
      }
      _need_ast = _need_ast & 0xffffffdf;
      if ((*(uint *)(iVar3 + 0x18c) & 3) == 0) {
        bVar11 = false;
        if (*(char *)(iVar10 + 0x17) == '\0') {
          piVar6 = *(int **)(iVar10 + 0x18);
          uVar5 = (uint)piVar6 | *(uint *)(*(int *)(iVar3 + 0x84) + 0x4c);
          if (uVar5 == 0) goto loc_F00AA174;
          if ((*(uint *)(iVar10 + 0x28) & 0x10) == 0) {
            piVar6 = *(int **)(iVar10 + 0x1c);
            if ((uVar5 & ~(*(uint *)(iVar10 + 0x20) | (uint)piVar6)) == 0) goto loc_F00AA174;
            cVar1 = *(char *)(iVar10 + 0x17);
          }
          else {
            cVar1 = *(char *)(iVar10 + 0x17);
          }
          bVar11 = cVar1 == '\0';
        }
        if (bVar11) {
          iVar4 = 0;
          _issig();
          if (iVar4 == 0) goto loc_F00AA174;
        }
        _psig();
      }
    }
loc_F00AA174:
    _need_ast = _need_ast & ~uVar2;
    uVar5 = *(uint *)(iVar3 + 0x18c);
    if ((uVar5 & 3) != 0) {
      _thread_halt_self();
      return CONCAT44(piVar6,uVar5);
    }
    if ((uVar2 & 4) == 0) {
      iVar9 = *(int *)(*(int *)(_processor_ptr + 300) + 0x108);
      iVar8 = *(int *)(*(int *)(_processor_ptr + 300) + 0x104);
      iVar4 = *(int *)(iVar3 + 0x60);
      iVar7 = *(int *)(iVar3 + 0x58);
      if ((*(uint *)(iVar3 + 0x4c) & 2) == 0) {
        if (*(int *)(_processor_ptr + 0x108) < 1) {
          if (((iVar4 == 2) || (2 < iVar4)) || (iVar4 != 1)) {
            if (iVar9 == 0) {
              bVar11 = false;
            }
            else {
              bVar11 = false;
              if (((iVar7 <= iVar8) && (bVar11 = true, iVar8 <= iVar7)) &&
                 (bVar11 = false, *(int *)(_processor_ptr + 0x124) == 0)) {
                bVar11 = true;
              }
            }
          }
          else {
            bVar11 = false;
            if (((*(int *)(_processor_ptr + 0x124) == 0) && (0 < iVar9)) &&
               (bVar11 = false, iVar7 <= iVar8)) goto loc_F00AA24C;
          }
        }
        else {
          bVar11 = true;
        }
      }
      else {
loc_F00AA24C:
        bVar11 = true;
      }
      if (!bVar11) {
        return CONCAT44(param_2,param_1);
      }
    }
    piVar6 = (int *)(_active_u[0x6c] + 1);
    _active_u[0x6c] = (int)piVar6;
    _thread_block_with_continuation(_thread_exception_return);
  } while( true );
}
