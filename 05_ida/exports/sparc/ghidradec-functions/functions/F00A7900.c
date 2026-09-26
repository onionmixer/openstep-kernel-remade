
/* WARNING: Removing unreachable block (ram,0xf00a8544) */
/* WARNING: Removing unreachable block (ram,0xf00a8450) */
/* WARNING: Removing unreachable block (ram,0xf00a8428) */
/* WARNING: Removing unreachable block (ram,0xf00a83a8) */
/* WARNING: Removing unreachable block (ram,0xf00a8038) */
/* WARNING: Removing unreachable block (ram,0xf00a7e78) */
/* WARNING: Removing unreachable block (ram,0xf00a7cd0) */
/* WARNING: Removing unreachable block (ram,0xf00a7c6c) */
/* WARNING: Removing unreachable block (ram,0xf00a7c08) */
/* WARNING: Removing unreachable block (ram,0xf00a7bc4) */
/* WARNING: Removing unreachable block (ram,0xf00a7b4c) */
/* WARNING: Removing unreachable block (ram,0xf00a7b20) */
/* WARNING: Removing unreachable block (ram,0xf00a7aa8) */
/* WARNING: Removing unreachable block (ram,0xf00a7fc0) */
/* WARNING: Removing unreachable block (ram,0xf00a7df4) */
/* WARNING: Removing unreachable block (ram,0xf00a7d98) */
/* WARNING: Removing unreachable block (ram,0xf00a8100) */
/* WARNING: Removing unreachable block (ram,0xf00a806c) */
/* WARNING: Removing unreachable block (ram,0xf00a7f64) */
/* WARNING: Removing unreachable block (ram,0xf00a81f0) */
/* WARNING: Removing unreachable block (ram,0xf00a8008) */
/* WARNING: Removing unreachable block (ram,0xf00a815c) */
/* WARNING: Removing unreachable block (ram,0xf00a8204) */
/* WARNING: Removing unreachable block (ram,0xf00a830c) */
/* WARNING: Removing unreachable block (ram,0xf00a7f1c) */
/* WARNING: Removing unreachable block (ram,0xf00a80a4) */
/* WARNING: Removing unreachable block (ram,0xf00a7d44) */
/* WARNING: Removing unreachable block (ram,0xf00a7de4) */
/* WARNING: Removing unreachable block (ram,0xf00a7e14) */
/* WARNING: Removing unreachable block (ram,0xf00a7e40) */
/* WARNING: Removing unreachable block (ram,0xf00a7af8) */
/* WARNING: Removing unreachable block (ram,0xf00a7b38) */
/* WARNING: Removing unreachable block (ram,0xf00a7b84) */
/* WARNING: Removing unreachable block (ram,0xf00a7bfc) */
/* WARNING: Removing unreachable block (ram,0xf00a7c18) */
/* WARNING: Removing unreachable block (ram,0xf00a7c84) */
/* WARNING: Removing unreachable block (ram,0xf00a7d0c) */
/* WARNING: Removing unreachable block (ram,0xf00a7e80) */
/* WARNING: Removing unreachable block (ram,0xf00a8328) */
/* WARNING: Removing unreachable block (ram,0xf00a83bc) */
/* WARNING: Removing unreachable block (ram,0xf00a8444) */
/* WARNING: Removing unreachable block (ram,0xf00a8468) */
/* WARNING: Removing unreachable block (ram,0xf00a83d4) */
/* WARNING: Removing unreachable block (ram,0xf00a7940) */

undefined8 _user_trap(int *param_1,uint param_2,undefined4 param_3,uint param_4,int param_5)

{
  undefined uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar13;
  int iVar14;
  undefined4 unaff_l3;
  int iVar15;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar16;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar17;
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
  iVar14 = 0;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  uVar13 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  iVar15 = *_active_u;
  if (iVar15 != 0) {
    *(int *)((int)register0x00000038 + -0x10) = _active_u[0x5d];
    *(int *)((int)register0x00000038 + -0xc) = _active_u[0x5e];
  }
  piVar4 = _active_u;
  _syncfpu(param_2);
  if (param_1 == (int *)0x1000a) {
    if (_tudebug != 0) {
      _showregs(0x1000a,param_2,0,0,0);
    }
    iVar14 = 3;
    uVar13 = 10;
    *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_2 + 4);
  }
  else if (param_1 < (int *)0x1000b) {
    if (param_1 == (int *)0x10005) {
      iVar12 = 0;
      _flush_user_windows();
      iVar10 = *(int *)(iVar3 + 0x28);
      bVar17 = false;
      if (0 < *(int *)(iVar10 + 0x230)) {
        iVar16 = 0x10;
        do {
          uVar7 = *(uint *)(iVar12 * 4 + iVar10 + 0x210);
          iVar10 = iVar10 + iVar16;
          if ((uVar7 & 7) != 0) {
loc_F00A8054:
            iVar14 = 2;
            uVar13 = 0x501;
            bVar17 = true;
            *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_2 + 4);
            break;
          }
          _copyout(iVar10,uVar7,0x40);
          iVar12 = iVar12 + 1;
          if (iVar10 != 0) goto loc_F00A8054;
          iVar10 = *(int *)(iVar3 + 0x28);
          iVar16 = iVar16 + 0x40;
          bVar17 = false;
        } while (iVar12 < *(int *)(iVar10 + 0x230));
      }
      if (!bVar17) {
        *(undefined4 *)(*(int *)(iVar3 + 0x28) + 0x230) = 0;
        goto locret_F00A854C;
      }
      if (_tudebug != 0) {
        _showregs(0x10005,param_2,0,0,0);
        bVar17 = iVar14 == 0;
        goto loc_F00A831C;
      }
    }
    else if (param_1 < (int *)0x10006) {
      if (param_1 == (int *)0x10002) {
        if (_tudebug != 0) {
          _showregs(0x10002,param_2,0,0,0);
        }
        uVar7 = param_2;
        _simulate_unimp();
        uVar13 = 0x502;
        if (uVar7 != 0xffffffff) {
          if (uVar7 < 0x80000000) {
            if (uVar7 == 0) {
              uVar13 = 0x502;
            }
            else {
              uVar13 = 0x502;
              if (uVar7 == 1) {
loc_F00A7EC0:
                *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 8);
                *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 4;
                goto locret_F00A854C;
              }
            }
          }
          else {
            uVar13 = 0x606;
            if (uVar7 != 0xfffffffe) {
              uVar13 = 0x502;
            }
          }
        }
        iVar14 = 2;
        *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_2 + 4);
      }
      else {
        if (param_1 < (int *)0x10003) {
          piVar4 = (int *)0x10001;
loc_F00A7A24:
          if (param_1 != piVar4) goto loc_F00A7A90;
          goto loc_F00A7B58;
        }
        if (param_1 != (int *)0x10003) goto loc_F00A7A90;
        if (_tudebug != 0) {
          _showregs(0x10003,param_2,0,0,0);
        }
        iVar14 = 2;
        uVar13 = 3;
        *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_2 + 4);
      }
    }
    else {
      if (param_1 != (int *)0x10008) {
        if ((int *)0x10008 < param_1) goto loc_F00A7B44;
        if (param_1 == (int *)0x10007) {
          if (_tudebug != 0) {
            _showregs(0x10007,param_2,0,0,0);
          }
          piVar4 = _active_u;
          _alignfaults = _alignfaults + 1;
          if (((*(uint *)(*(int *)(iVar3 + 0x28) + 0x294) & 2) != 0) || (_fix_user_alignment != 0))
          {
            if (_log_user_alignment_traps != 0) {
              _printf(aUserTrapCorrec);
              if (piVar4 == (int *)0x0) {
                piVar6 = (int *)&aUnknown_0;
              }
              else {
                piVar6 = piVar4 + 2;
              }
              iVar14 = -1;
              if (piVar4 != (int *)0x0) {
                if (*piVar4 == 0) {
                  iVar14 = -1;
                }
                else {
                  iVar14 = (int)*(sword *)(*piVar4 + 0x30);
                }
              }
              _printf(aProgramSPidDPc,piVar6,iVar14,*(undefined4 *)(param_2 + 4));
            }
            uVar13 = param_2;
            _do_unaligned(param_2,1,0);
            if (uVar13 == 1) goto loc_F00A7EC0;
          }
          iVar14 = 1;
          uVar13 = 0x304;
          _do_unaligned(param_2,0,(undefined *)((int)register0x00000038 + -0x14));
          bVar17 = false;
          goto loc_F00A831C;
        }
        goto loc_F00A7A90;
      }
      if ((_tudebug != 0) && (_tudebugfpe != 0)) {
        _showregs(0x10008,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c),0,0);
      }
      iVar14 = 3;
      uVar13 = 8;
      *(undefined4 *)((int)register0x00000038 + -0x14) =
           *(undefined4 *)((int)register0x00000038 + 0x4c);
    }
  }
  else if (param_1 == (int *)0x1002b) {
loc_F00A7B04:
    if (_small_4m == 0) {
      _check_fsr(param_1,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c),param_4,param_5);
    }
    _badtrap(param_1,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c),param_4,param_5);
loc_F00A7B44:
    _module_wkaround((undefined *)((int)register0x00000038 + 0x4c),param_2,param_5,param_4);
loc_F00A7B58:
    if (((_cpu == 0x80) && (iVar14 = 0, (param_4 >> 10 & 0xff) != 0)) &&
       (_ebe_handler(0,param_4,*(undefined4 *)((int)register0x00000038 + 0x4c),param_1,param_2),
       iVar14 != -1)) {
locret_F00A854C:
      return CONCAT44(param_2,param_1);
    }
    bVar17 = (param_4 & 0xc00) == 0;
    if (((param_4 & 1) != 0) && (bVar17 = (param_4 & 0xc00) == 0, (param_4 >> 2 & 7) == 4)) {
      _printf(aCpuDMultipleFa,_cpuid);
      if (param_1 == (int *)0x10009) {
        puVar8 = aUserData;
      }
      else {
        puVar8 = aUserText;
      }
      _printf(aFirstFaultSAtP,_cpuid,puVar8);
      _printf(aSecondFaultTra);
      _printf(aAtAddrX,*(undefined4 *)((int)register0x00000038 + 0x4c));
      bVar17 = (param_4 & 0xc00) == 0;
    }
    if ((bVar17) || ((param_4 & 0x1000) != 0)) {
      if (_small_4m == 0) {
        _check_fsr(param_1,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c),param_4,param_5);
      }
      _get_faulttype(param_1,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c),param_4,param_5
                    );
      uVar1 = *(undefined *)(dword_F0133DDC + 0x38);
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      uVar9 = 1;
      uVar13 = *(uint *)(*(int *)(iVar3 + 0xc) + 0xc);
      if (param_5 == 2) {
        uVar9 = 3;
      }
      _vm_fault(uVar13,*(uint *)((int)register0x00000038 + 0x4c) & ~_page_mask,uVar9,0,0);
      *(undefined *)(dword_F0133DDC + 0x38) = uVar1;
      if (uVar13 == 0) goto locret_F00A854C;
      if (_tudebug != 0) {
        _showregs(param_1,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c),param_4,param_5);
      }
      iVar14 = 1;
      *(undefined4 *)((int)register0x00000038 + -0x14) =
           *(undefined4 *)((int)register0x00000038 + 0x4c);
    }
    else {
      iVar14 = 1;
      uVar13 = 0x309;
      *(undefined4 *)((int)register0x00000038 + -0x14) =
           *(undefined4 *)((int)register0x00000038 + 0x4c);
    }
  }
  else if (param_1 < (int *)0x1002c) {
    if (param_1 == (int *)0x10029) goto loc_F00A7B44;
    if (param_1 < (int *)0x1002a) {
      piVar4 = (int *)0x10021;
      goto loc_F00A7A24;
    }
loc_F00A7EF0:
    if ((_tudebug != 0) && (_tudebugfpe != 0)) {
      _showregs(param_1,param_2,0,0,0);
    }
    uVar9 = *(undefined4 *)(param_2 + 8);
    uVar13 = 0x606;
loc_F00A7F78:
    iVar14 = 3;
    *(undefined4 *)(param_2 + 4) = uVar9;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 4;
    *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_2 + 4);
  }
  else {
    if (param_1 == (int *)0x10082) goto loc_F00A7EF0;
    if (param_1 < (int *)0x10083) {
      if (param_1 == (int *)0x10081) {
        if ((_tudebug != 0) && (_tudebugbpt != 0)) {
          _showregs(0x10081,param_2,0,0,0);
        }
        iVar14 = 6;
        uVar13 = 0x81;
        goto loc_F00A8318;
      }
    }
    else {
      if (param_1 == (int *)0x10087) {
        if ((_tudebug != 0) && (_tudebugfpe != 0)) {
          _showregs(0x10087,param_2,0,0,0);
        }
        uVar9 = *(undefined4 *)(param_2 + 8);
        uVar13 = 0x604;
        goto loc_F00A7F78;
      }
      if (param_1 == (int *)0x10400) {
        param_1 = (int *)&_need_ast;
        do {
          uVar7 = _need_ast;
          if (iVar15 != 0) {
            piVar4 = _active_u;
            if (((*(uint *)(iVar15 + 0x28) & 0x200000) != 0) &&
               (piVar4 = _active_u + 0x91, _active_u[0x96] != 0)) {
              _addupc(*(undefined4 *)(param_2 + 4),piVar4,1);
              *(uint *)(iVar15 + 0x28) = *(uint *)(iVar15 + 0x28) & 0xffdfffff;
            }
            _need_ast = _need_ast & 0xffffffdf;
            if ((*(uint *)(iVar3 + 0x18c) & 3) == 0) {
              bVar17 = false;
              if (*(char *)(iVar15 + 0x17) == '\0') {
                piVar4 = *(int **)(iVar15 + 0x18);
                uVar5 = (uint)piVar4 | *(uint *)(*(int *)(iVar3 + 0x84) + 0x4c);
                if (uVar5 == 0) goto loc_F00A820C;
                if ((*(uint *)(iVar15 + 0x28) & 0x10) == 0) {
                  piVar4 = *(int **)(iVar15 + 0x1c);
                  if ((uVar5 & ~(*(uint *)(iVar15 + 0x20) | (uint)piVar4)) == 0) goto loc_F00A820C;
                  cVar2 = *(char *)(iVar15 + 0x17);
                }
                else {
                  cVar2 = *(char *)(iVar15 + 0x17);
                }
                bVar17 = cVar2 == '\0';
              }
              if (bVar17) {
                iVar10 = 0;
                _issig();
                if (iVar10 == 0) goto loc_F00A820C;
              }
              _psig();
            }
          }
loc_F00A820C:
          _need_ast = _need_ast & ~uVar7;
          uVar5 = *(uint *)(iVar3 + 0x18c);
          if ((uVar5 & 3) != 0) {
            _thread_halt_self();
            return CONCAT44(piVar4,uVar5);
          }
          if ((uVar7 & 4) == 0) {
            iVar11 = *(int *)(*(int *)(_processor_ptr + 300) + 0x108);
            iVar16 = *(int *)(*(int *)(_processor_ptr + 300) + 0x104);
            iVar10 = *(int *)(iVar3 + 0x60);
            iVar12 = *(int *)(iVar3 + 0x58);
            if ((*(uint *)(iVar3 + 0x4c) & 2) == 0) {
              if (*(int *)(_processor_ptr + 0x108) < 1) {
                if (((iVar10 == 2) || (2 < iVar10)) || (iVar10 != 1)) {
                  if (iVar11 == 0) {
                    bVar17 = false;
                  }
                  else {
                    bVar17 = false;
                    if (((iVar12 <= iVar16) && (bVar17 = true, iVar16 <= iVar12)) &&
                       (bVar17 = false, *(int *)(_processor_ptr + 0x124) == 0)) {
                      bVar17 = true;
                    }
                  }
                }
                else {
                  bVar17 = false;
                  if (((*(int *)(_processor_ptr + 0x124) == 0) && (0 < iVar11)) &&
                     (bVar17 = false, iVar12 <= iVar16)) goto loc_F00A82E4;
                }
              }
              else {
                bVar17 = true;
              }
            }
            else {
loc_F00A82E4:
              bVar17 = true;
            }
            if (!bVar17) goto loc_F00A8318;
          }
          piVar4 = (int *)(_active_u[0x6c] + 1);
          _active_u[0x6c] = (int)piVar4;
          _thread_block_with_continuation(_thread_exception_return);
        } while( true );
      }
    }
loc_F00A7A90:
    if (_tudebug != 0) {
      _showregs(param_1,param_2,0,0,0);
    }
    uVar13 = (uint)param_1 & 0xfffeffff;
    if ((uVar13 < 0x80) && (((uint)param_1 & 0x20) == 0)) {
      _badtrap(param_1,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c),param_4,param_5);
      goto loc_F00A7B04;
    }
    iVar14 = 2;
    if (0x7f < (int)uVar13) {
      iVar14 = 5;
    }
    *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_2 + 4);
  }
loc_F00A8318:
  bVar17 = iVar14 == 0;
loc_F00A831C:
  if (!bVar17) {
    _exception(iVar14,uVar13,*(undefined4 *)((int)register0x00000038 + -0x14));
  }
  do {
    uVar13 = *(uint *)(iVar3 + 0x18c);
    if (iVar15 == 0) goto loc_F00A83C8;
    bVar17 = false;
    if ((uVar13 & 3) == 0) {
      bVar17 = *(char *)(iVar15 + 0x17) == '\0';
      if (bVar17) {
        uVar13 = *(uint *)(iVar15 + 0x18) | *(uint *)(*(int *)(iVar3 + 0x84) + 0x4c);
        if (uVar13 != 0) {
          if ((*(uint *)(iVar15 + 0x28) & 0x10) == 0) {
            if ((uVar13 & ~(*(uint *)(iVar15 + 0x20) | *(uint *)(iVar15 + 0x1c))) == 0) {
              uVar13 = *(uint *)(iVar3 + 0x18c);
              goto loc_F00A83C8;
            }
            cVar2 = *(char *)(iVar15 + 0x17);
          }
          else {
            cVar2 = *(char *)(iVar15 + 0x17);
          }
          bVar17 = cVar2 == '\0';
          goto loc_F00A83A0;
        }
        uVar13 = *(uint *)(iVar3 + 0x18c);
      }
      else {
loc_F00A83A0:
        if (bVar17) {
          iVar14 = 0;
          _issig();
          if (iVar14 == 0) {
            uVar13 = *(uint *)(iVar3 + 0x18c);
            goto loc_F00A83C8;
          }
        }
        _psig();
        uVar13 = *(uint *)(iVar3 + 0x18c);
      }
loc_F00A83C8:
      bVar17 = (uVar13 & 3) == 0;
    }
    piVar4 = _active_u;
    if (bVar17) break;
    _thread_halt_self();
  } while( true );
  if ((iVar15 != 0) && (param_1 = piVar4, _active_u[0x96] != 0)) {
    iVar15 = _active_u[0x5d];
    iVar14 = _active_u[0x5e] - *(int *)((int)register0x00000038 + -0xc);
    iVar10 = *(int *)((int)register0x00000038 + -0x10);
    .div(iVar14,1000);
    iVar14 = (iVar15 - iVar10) * 1000 + iVar14;
    uVar9 = _tick;
    .div(_tick,1000);
    .div(iVar14,uVar9);
    if (iVar14 != 0) {
      _addupc(*(undefined4 *)(param_2 + 4),piVar4 + 0x91,iVar14);
    }
  }
  iVar12 = *(int *)(*(int *)(_processor_ptr + 300) + 0x108);
  iVar10 = *(int *)(*(int *)(_processor_ptr + 300) + 0x104);
  iVar14 = *(int *)(iVar3 + 0x60);
  iVar15 = *(int *)(iVar3 + 0x58);
  if ((*(uint *)(iVar3 + 0x4c) & 2) == 0) {
    if (*(int *)(_processor_ptr + 0x108) < 1) {
      if (((iVar14 == 2) || (2 < iVar14)) || (iVar14 != 1)) {
        if (iVar12 == 0) {
          bVar17 = false;
        }
        else {
          bVar17 = false;
          if (((iVar15 <= iVar10) && (bVar17 = true, iVar10 <= iVar15)) &&
             (bVar17 = false, *(int *)(_processor_ptr + 0x124) == 0)) {
            bVar17 = true;
          }
        }
      }
      else {
        bVar17 = false;
        if (((*(int *)(_processor_ptr + 0x124) == 0) && (0 < iVar12)) &&
           (bVar17 = false, iVar15 <= iVar10)) goto loc_F00A8518;
      }
    }
    else {
      bVar17 = true;
    }
  }
  else {
loc_F00A8518:
    bVar17 = true;
  }
  if (bVar17) {
    _active_u[0x6c] = _active_u[0x6c] + 1;
    _thread_block_with_continuation(_thread_exception_return);
  }
  goto locret_F00A854C;
}
