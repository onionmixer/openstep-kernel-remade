/* GHIDRADEC_FUNCTION index=2500 start=0xf00a7620 */

/* WARNING: Removing unreachable block (ram,0xf00a7738) */
/* WARNING: Removing unreachable block (ram,0xf00a7714) */
/* WARNING: Removing unreachable block (ram,0xf00a76d0) */
/* WARNING: Removing unreachable block (ram,0xf00a7698) */
/* WARNING: Removing unreachable block (ram,0xf00a7664) */
/* WARNING: Removing unreachable block (ram,0xf00a764c) */
/* WARNING: Removing unreachable block (ram,0xf00a7654) */
/* WARNING: Removing unreachable block (ram,0xf00a767c) */
/* WARNING: Removing unreachable block (ram,0xf00a76b4) */
/* WARNING: Removing unreachable block (ram,0xf00a76ec) */
/* WARNING: Removing unreachable block (ram,0xf00a771c) */
/* WARNING: Removing unreachable block (ram,0xf00a7744) */
/* WARNING: Removing unreachable block (ram,0xf00a7624) */

undefined8
_badtrap(uint param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
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
  _splaudio();
  _printf(aBadTrapCpuDTyp,_cpuid,param_1,param_2,param_3,param_4,param_5);
  _mmu_print_sfsr(param_4);
  _printf(aRegsAtX,param_2);
  _printf(aPsrXPcXNpcX,*param_2,param_2[1],param_2[2]);
  _printf(aYXG1XG2XG3X,param_2[3],param_2[4],param_2[5],param_2[6]);
  _printf(aG4XG5XG6XG7X,param_2[7],param_2[8],param_2[9],param_2[10]);
  _printf(aO0XO1XO2XO3X,param_2[0xb],param_2[0xc],param_2[0xd],param_2[0xe]);
  _printf(aO4XO5XSpXRaX,param_2[0xf],param_2[0x10],param_2[0x11],param_2[0x12]);
  if (_active_threads != 0) {
    _showregs(param_1,param_2,param_3,param_4,param_5);
  }
  _traceback(param_2[0x11]);
  if (param_1 < 0x2c) {
    _panic(*(undefined4 *)(_trap_type + param_1 * 4));
  }
  _panic(&aTrap);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2501 start=0xf00a7754 */

/* WARNING: Removing unreachable block (ram,0xf00a77c4) */
/* WARNING: Removing unreachable block (ram,0xf00a77ac) */

undefined8
_get_faulttype(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
              undefined4 param_5)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  switch(param_4 >> 2 & 7) {
  case :
  case :
    uVar1 = 1;
    break;
  :
    _printf(aUnexpectedTrap,param_1,param_4 >> 2 & 7);
    _badtrap(param_1,param_2,param_3,param_4,param_5);
  case :
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2502 start=0xf00a77e0 */

/* WARNING: Removing unreachable block (ram,0xf00a78e4) */
/* WARNING: Removing unreachable block (ram,0xf00a78a4) */
/* WARNING: Removing unreachable block (ram,0xf00a7884) */
/* WARNING: Removing unreachable block (ram,0xf00a7830) */
/* WARNING: Removing unreachable block (ram,0xf00a780c) */
/* WARNING: Removing unreachable block (ram,0xf00a7850) */
/* WARNING: Removing unreachable block (ram,0xf00a7898) */
/* WARNING: Removing unreachable block (ram,0xf00a78d4) */
/* WARNING: Removing unreachable block (ram,0xf00a78f0) */
/* WARNING: Removing unreachable block (ram,0xf00a7800) */

undefined8 _check_fsr(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  undefined *puVar2;
  undefined6 *puVar3;
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
  if (((param_4 & 0x3c00) != 0) && ((param_4 & 0x3000) != 0)) {
    _splaudio();
    uVar1 = param_4;
    _vac_parity_chk_dis(param_4,0);
    if (uVar1 == 0) {
      puVar2 = aFatalSystemFau_0;
    }
    else {
      puVar2 = aModuleParityEr;
    }
    _printf(puVar2);
    _pmap_getpte(*(undefined4 *)(*(int *)(*(int *)(_active_threads + 0xc) + 0xc) + 0x24),param_3,
                 (undefined *)((int)register0x00000038 + -0xc));
    if ((*(uint *)((int)register0x00000038 + -0xc) & 3) == 2) {
      _log_mem_err(param_4,0,
                   (*(uint *)((int)register0x00000038 + -0xc) >> 8) << 0xc | param_3 & 0xfff,1);
    }
    else {
      _printf(aAddrXIsNotVali,param_3);
    }
    _printf(aControlRegiste_0);
    if (param_5 == 2) {
      puVar3 = &aWrite_0;
    }
    else {
      puVar3 = (undefined6 *)&aRead_0;
    }
    _printf(aSfsr0xXSFault,param_4,puVar3);
    _printf(aAtVaddr0xX,param_3);
    _panic(aMemoryError_0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2503 start=0xf00a7900 */

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
/* GHIDRADEC_FUNCTION index=2504 start=0xf00a8554 */

/* WARNING: Removing unreachable block (ram,0xf00a8708) */
/* WARNING: Removing unreachable block (ram,0xf00a8650) */
/* WARNING: Removing unreachable block (ram,0xf00a8834) */
/* WARNING: Removing unreachable block (ram,0xf00a87a4) */
/* WARNING: Removing unreachable block (ram,0xf00a875c) */
/* WARNING: Removing unreachable block (ram,0xf00a8588) */
/* WARNING: Removing unreachable block (ram,0xf00a8698) */
/* WARNING: Removing unreachable block (ram,0xf00a877c) */
/* WARNING: Removing unreachable block (ram,0xf00a87bc) */
/* WARNING: Removing unreachable block (ram,0xf00a88b0) */
/* WARNING: Removing unreachable block (ram,0xf00a86d0) */
/* WARNING: Removing unreachable block (ram,0xf00a8900) */
/* WARNING: Removing unreachable block (ram,0xf00a8570) */

undefined8 _kernel_trap(uint param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined uVar5;
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
  uint auStackX_4c [4];
  
  iVar1 = _active_threads;
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
  auStackX_4c[0] = param_3;
  if (_active_threads == 0) {
    _printf(aKernelTrapCall);
    _badtrap(param_1,param_2,auStackX_4c[0],param_4,param_5);
  }
  if (param_1 == 9) {
loc_F00A8730:
    if (((_cpu == 0x80) && (iVar3 = 0, (param_4 >> 10 & 0xff) != 0)) &&
       (_ebe_handler(0,param_4,auStackX_4c[0],param_1,param_2), iVar3 != -1)) goto locret_F00A8908;
    _module_wkaround(auStackX_4c,param_2,param_5,param_4);
    if (_small_4m == 0) {
      _check_fsr(param_1,param_2,auStackX_4c[0],param_4,param_5);
    }
    _get_faulttype(param_1,param_2,auStackX_4c[0],param_4,param_5);
    if (iVar1 != 0) {
      uVar5 = *(undefined *)(dword_F0133DDC + 0x38);
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
    }
    iVar3 = _kernel_map;
    if (auStackX_4c[0] < 0xf0000000) {
      iVar3 = *(int *)(*(int *)(iVar1 + 0xc) + 0xc);
    }
    uVar4 = 1;
    if (param_5 == 2) {
      uVar4 = 3;
    }
    _vm_fault(iVar3,auStackX_4c[0] & ~_page_mask,uVar4,0,0);
    if (iVar1 != 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = uVar5;
    }
    if (iVar3 == 0) goto locret_F00A8908;
    uVar4 = 1;
    uVar2 = auStackX_4c[0];
    if (*(int *)(iVar1 + 0x74) != 0) {
                    /* WARNING: Subroutine does not return */
      *(undefined4 *)(iVar1 + 0x74) = 0;
      _longjmp();
    }
  }
  else if (param_1 < 10) {
    if (param_1 == 2) {
loc_F00A865C:
      uVar4 = 2;
      iVar3 = 2;
      uVar2 = *(uint *)(param_2 + 4);
    }
    else if (param_1 < 3) {
      if (param_1 != 1) goto loc_F00A8644;
loc_F00A86B0:
      if (_small_4m == 0) {
        _check_fsr(param_1,param_2,auStackX_4c[0],param_4,param_5);
      }
      if (((_cpu == 0x80) && (iVar1 = 0, (param_4 >> 10 & 0xff) != 0)) &&
         (_ebe_handler(0,param_4,auStackX_4c[0],param_1,param_2), iVar1 != -1))
      goto locret_F00A8908;
      uVar4 = 1;
      iVar3 = 0x301;
      uVar2 = auStackX_4c[0];
    }
    else if (param_1 == 7) {
      uVar4 = 1;
      iVar3 = 0x304;
      uVar2 = *(uint *)(param_2 + 4);
    }
    else {
      if (param_1 != 8) goto loc_F00A8644;
      if ((_tudebug != 0) && (_tudebugfpe != 0)) {
        _showregs(8,param_2,auStackX_4c[0],0,0);
      }
      uVar4 = 3;
      iVar3 = 8;
      uVar2 = auStackX_4c[0];
    }
  }
  else if (param_1 == 0x2b) {
    if (_small_4m == 0) {
      _check_fsr(0x2b,param_2,auStackX_4c[0],param_4,param_5);
    }
    uVar4 = 1;
    iVar3 = 0x306;
    uVar2 = auStackX_4c[0];
  }
  else {
    if (param_1 < 0x2c) {
      if (param_1 == 0x21) goto loc_F00A86B0;
      if (param_1 == 0x29) goto loc_F00A8730;
loc_F00A8644:
      _badtrap(param_1,param_2,auStackX_4c[0],param_4,param_5);
      goto loc_F00A865C;
    }
    if (param_1 == 0x81) {
      uVar4 = 6;
      iVar3 = 0x81;
      uVar2 = *(uint *)(param_2 + 4);
    }
    else {
      if (param_1 != 0x88) goto loc_F00A8644;
      uVar2 = *(uint *)(param_2 + 4);
      uVar4 = 6;
      iVar3 = 0x81;
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 8);
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 4;
    }
  }
  _kdp_raise_exception(uVar4,iVar3,uVar2,param_2);
locret_F00A8908:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2505 start=0xf00a8910 */

/* WARNING: Removing unreachable block (ram,0xf00a8940) */
/* WARNING: Removing unreachable block (ram,0xf00a8950) */

undefined8
_trap(uint param_1,uint *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
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
  if ((*param_2 & 0x40) == 0) {
    *dword_F0133DDC = param_2;
    _user_trap(param_1 | 0x10000);
  }
  else {
    _kernel_trap(param_1,param_2,param_3,param_4,param_5);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2506 start=0xf00a8960 */

/* WARNING: Removing unreachable block (ram,0xf00a8b44) */
/* WARNING: Removing unreachable block (ram,0xf00a8aac) */
/* WARNING: Removing unreachable block (ram,0xf00a89e0) */
/* WARNING: Removing unreachable block (ram,0xf00a8a90) */
/* WARNING: Removing unreachable block (ram,0xf00a8adc) */
/* WARNING: Removing unreachable block (ram,0xf00a89d4) */
/* WARNING: Removing unreachable block (ram,0xf00a8980) */

undefined8 _syscall(uint *param_1,undefined4 param_2)

{
  sword sVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  sword *psVar7;
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
  bool bVar8;
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
  uVar3 = *param_1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = _active_threads;
  if ((uVar3 & 0x40) != 0) {
    _panic(&aSyscall);
  }
  uVar6 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0x28) + 0x84);
  *(uint *)((int)register0x00000038 + -0x20) = param_1[4];
  iVar4 = *_active_u;
  *(undefined4 *)((int)register0x00000038 + -0x14) = uVar6;
  *(int *)((int)register0x00000038 + -0x1c) = iVar4;
  if (iVar4 == 0) {
    _exception(5,0x700,0);
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = _active_u[0x5d];
    *(int *)((int)register0x00000038 + -0xc) = _active_u[0x5e];
    _syncfpu(param_1);
    uVar3 = *(uint *)((int)register0x00000038 + -0x20);
    bVar8 = uVar3 < _nsysent;
    **(int **)((int)register0x00000038 + -0x14) = (int)param_1;
    if (bVar8) {
      *(undefined **)((int)register0x00000038 + -0x24) = _sysent + uVar3 * 8;
    }
    else {
      *(undefined **)((int)register0x00000038 + -0x24) = unk_F010AA00;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = 0;
    psVar7 = *(sword **)((int)register0x00000038 + -0x24);
    sVar1 = *psVar7;
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    if (sVar1 < 7) {
      iVar4 = *(int *)((int)register0x00000038 + -0x14);
      puVar2 = param_1 + 0xb;
    }
    else {
      iVar5 = *(int *)((int)register0x00000038 + -0x14);
      *(uint *)(iVar5 + 4) = param_1[0xb];
      *(uint *)(iVar5 + 8) = param_1[0xc];
      *(uint *)(iVar5 + 0xc) = param_1[0xd];
      *(uint *)(iVar5 + 0x10) = param_1[0xe];
      *(uint *)(iVar5 + 0x14) = param_1[0xf];
      *(uint *)(iVar5 + 0x18) = param_1[0x10];
      iVar4 = param_1[0x11] + 0x5c;
      _copyin(iVar4,iVar5 + 0x1c,(*psVar7 + -6) * 4);
      if (iVar4 != 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
        _unix_syscall_return(*(undefined4 *)((int)register0x00000038 + -0x18));
      }
      iVar4 = *(int *)((int)register0x00000038 + -0x14);
      puVar2 = (uint *)(iVar4 + 4);
    }
    *(uint **)(iVar4 + 0x24) = puVar2;
    iVar5 = *(int *)((int)register0x00000038 + -0x14);
    *(undefined4 *)(iVar5 + 0x30) = 0;
    iVar4 = iVar5 + 0x28;
    *(uint *)(iVar5 + 0x34) = param_1[0xc];
    _setjmp();
    if (iVar4 == 0) {
      *(undefined *)(*(int *)((int)register0x00000038 + -0x14) + 0x39) = 3;
      (**(code **)(*(int *)((int)register0x00000038 + -0x24) + 4))
                (*(undefined4 *)(dword_F0133DDC + 0x24));
      *(int *)((int)register0x00000038 + -0x18) =
           (int)*(char *)(*(int *)((int)register0x00000038 + -0x14) + 0x38);
    }
    else if ((*(int *)((int)register0x00000038 + -0x18) == 0) &&
            (*(char *)(*(int *)((int)register0x00000038 + -0x14) + 0x39) != '\x02')) {
      *(undefined4 *)((int)register0x00000038 + -0x18) = 4;
    }
    _unix_syscall_return(*(undefined4 *)((int)register0x00000038 + -0x18));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2507 start=0xf00a8b54 */

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
/* GHIDRADEC_FUNCTION index=2508 start=0xf00a8e10 */

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
/* GHIDRADEC_FUNCTION index=2509 start=0xf00a9178 */

/* WARNING: Removing unreachable block (ram,0xf00a9240) */

undefined8 _indir(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
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
  uVar2 = *(uint *)dword_F0133DDC[9];
  if ((uVar2 == 0) || (_nsysent <= uVar2)) {
    puVar6 = unk_F010AA00;
  }
  else {
    puVar6 = _sysent + uVar2 * 8;
  }
  *(undefined *)(dword_F0133DDC + 0xe) = 0;
  iVar5 = (int)*(sword *)puVar6;
  if (5 < iVar5) {
    iVar5 = 5;
  }
  piVar1 = (int *)dword_F0133DDC[9];
  piVar3 = dword_F0133DDC;
  piVar4 = piVar1;
  while( true ) {
    piVar4 = piVar4 + 1;
    piVar3 = piVar3 + 1;
    if (piVar1 + iVar5 < piVar4) break;
    *piVar3 = *piVar4;
    piVar1 = (int *)dword_F0133DDC[9];
  }
  if (5 < *(sword *)puVar6) {
    iVar5 = *(int *)(*dword_F0133DDC + 0x44) + 0x5c;
    _copyin(iVar5,dword_F0133DDC + 6,(*(sword *)puVar6 + -5) * 4);
    if (iVar5 != 0) {
      *(undefined *)(dword_F0133DDC + 0xe) = 0xe;
      goto locret_F00A9280;
    }
  }
  dword_F0133DDC[9] = (int)(dword_F0133DDC + 1);
  (**(code **)((int)puVar6 + 4))(dword_F0133DDC[9]);
locret_F00A9280:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2510 start=0xf00a9288 */

/* WARNING: Removing unreachable block (ram,0xf00a93cc) */
/* WARNING: Removing unreachable block (ram,0xf00a93b0) */
/* WARNING: Removing unreachable block (ram,0xf00a9378) */
/* WARNING: Removing unreachable block (ram,0xf00a9310) */
/* WARNING: Removing unreachable block (ram,0xf00a92d8) */
/* WARNING: Removing unreachable block (ram,0xf00a93c0) */
/* WARNING: Removing unreachable block (ram,0xf00a92c8) */
/* WARNING: Removing unreachable block (ram,0xf00a92e8) */

undefined8 _traceback(uint param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar4;
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
  if ((_panicstr == 0) ||
     (iVar3 = dword_F011BC7C + 1, bVar1 = dword_F011BC7C < 1, dword_F011BC7C = iVar3, bVar1)) {
    if ((param_1 & 7) == 0) {
      _flush_windows();
      uVar4 = (param_1 - 1) + _page_size >> ((byte)_page_shift & 0x1f);
      _printf(aBeginTraceback,param_1);
      if ((param_1 - 1) + _page_size >> ((byte)_page_shift & 0x1f) == uVar4) {
        uVar2 = *(uint *)(param_1 + 0x38);
        while (param_1 != uVar2) {
          _printf(aCalledFromXFpX,*(undefined4 *)(param_1 + 0x3c),uVar2,
                  *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                  *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
                  *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34));
          param_1 = *(uint *)(param_1 + 0x38);
          if ((param_1 == 0) || ((param_1 - 1) + _page_size >> ((byte)_page_shift & 0x1f) != uVar4))
          goto loc_F00A93B0;
          uVar2 = *(uint *)(param_1 + 0x38);
        }
        _printf(aFpLoopAtX,param_1);
      }
loc_F00A93B0:
      _printf(aEndTraceback);
      _vac_flush(_pmsgbuf,0x1000);
      _us_spin(2000000);
    }
    else {
      _printf(aTracebackMisal,param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2511 start=0xf00a93dc */

/* WARNING: Removing unreachable block (ram,0xf00a93e8) */
/* WARNING: Removing unreachable block (ram,0xf00a93e0) */

undefined8 _tracedump(undefined4 param_1,undefined4 param_2)

{
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
  _setjmp((undefined *)((int)register0x00000038 + -0x10));
  _traceback(*(undefined4 *)((int)register0x00000038 + -0xc));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2512 start=0xf00a93f8 */

/* WARNING: Removing unreachable block (ram,0xf00a96d8) */
/* WARNING: Removing unreachable block (ram,0xf00a9698) */
/* WARNING: Removing unreachable block (ram,0xf00a9634) */
/* WARNING: Removing unreachable block (ram,0xf00a9600) */
/* WARNING: Removing unreachable block (ram,0xf00a95a4) */
/* WARNING: Removing unreachable block (ram,0xf00a9500) */
/* WARNING: Removing unreachable block (ram,0xf00a9520) */
/* WARNING: Removing unreachable block (ram,0xf00a9530) */
/* WARNING: Removing unreachable block (ram,0xf00a9438) */
/* WARNING: Removing unreachable block (ram,0xf00a945c) */
/* WARNING: Removing unreachable block (ram,0xf00a9510) */
/* WARNING: Removing unreachable block (ram,0xf00a9540) */
/* WARNING: Removing unreachable block (ram,0xf00a94f0) */
/* WARNING: Removing unreachable block (ram,0xf00a9570) */
/* WARNING: Removing unreachable block (ram,0xf00a95f8) */
/* WARNING: Removing unreachable block (ram,0xf00a961c) */
/* WARNING: Removing unreachable block (ram,0xf00a9650) */
/* WARNING: Removing unreachable block (ram,0xf00a96c8) */
/* WARNING: Removing unreachable block (ram,0xf00a96e0) */
/* WARNING: Removing unreachable block (ram,0xf00a9418) */

qword _showregs(uint param_1,uint *param_2,int param_3,undefined *param_4,int param_5)

{
  int iVar1;
  undefined *puVar2;
  undefined7 *puVar3;
  undefined6 *puVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
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
  iVar1 = *_active_u;
  iVar5 = -1;
  if (iVar1 != 0) {
    iVar5 = (int)*(sword *)(iVar1 + 0x30);
  }
  _splaudio();
  uVar8 = param_1 & 0xfffeffff;
  if (iVar5 == -1) {
    _printf(aUnknown_1);
  }
  else {
    _printf(aPidDS,iVar5,_active_u + 2);
  }
  if (uVar8 < 0x2c) {
    puVar2 = (undefined *)&aS_4;
    uVar6 = *(uint *)(_trap_type + uVar8 * 4);
  }
  else {
    if (uVar8 == 0x82) {
      _printf(aZeroDivideTrap);
      goto loc_F00A957C;
    }
    if (uVar8 < 0x83) {
      if (uVar8 == 0x80) {
        _printf(aSyscallTrap);
        goto loc_F00A957C;
      }
      if (uVar8 == 0x81) {
        _printf(aBreakpointTrap);
        goto loc_F00A957C;
      }
    }
    else {
      if (uVar8 == 0x110) {
        _printf(aSpuriousInterr);
        goto loc_F00A957C;
      }
      if (uVar8 < 0x111) {
        if (uVar8 == 0x83) {
          _printf(aFlushWindowsTr);
          goto loc_F00A957C;
        }
      }
      else if (uVar8 == 0x400) {
        _printf(&aAst);
        goto loc_F00A957C;
      }
    }
    if (uVar8 - 0x80 < 0x80) {
      puVar2 = aSoftwareTrap0x;
      uVar6 = uVar8 - 0x80;
    }
    else {
      puVar2 = aBadTrapD;
      uVar6 = uVar8;
    }
  }
  _printf(puVar2,uVar6);
loc_F00A957C:
  if ((uVar8 == 9) || (uVar8 == 1)) {
    _pmap_getpte(*(undefined4 *)(*(int *)(*(int *)(_active_threads + 0xc) + 0xc) + 0x24),param_3,
                 (undefined *)((int)register0x00000038 + -0xc));
    if ((*param_2 & 0x40) == 0) {
      puVar3 = (undefined7 *)&aUser_5;
    }
    else {
      puVar3 = &aKernel;
    }
    if (param_5 == 2) {
      puVar4 = &aWrite_1;
    }
    else {
      puVar4 = (undefined6 *)&aRead_2;
    }
    _printf(aSSFaultAtAddr0,puVar3,puVar4,param_3,*(undefined4 *)((int)register0x00000038 + -0xc));
    _mmu_print_sfsr(param_4);
    uVar8 = param_2[1];
  }
  else {
    param_4 = aTDataStoreMmuF_0;
    if (param_3 != 0) {
      param_4 = aAddr0xX;
      _printf(aAddr0xX,param_3);
    }
    uVar8 = param_2[1];
  }
  uVar7 = param_2[0x11];
  uVar6 = *param_2;
  _mmu_getctx();
  _printf(aRp0xXPc0xXSp0x,param_2,uVar8,uVar7,uVar6,param_4);
  if ((*param_2 & 0x40) == 0) {
    _printf(aO0O7XXXXXXXX,param_2[0xb],param_2[0xc],param_2[0xd],param_2[0xe],param_2[0xf],
            param_2[0x10],param_2[0x11],param_2[0x12]);
    uVar8 = param_2[4];
  }
  else {
    uVar8 = param_2[4];
  }
  _printf(aG1G7XXXXXXX,uVar8,param_2[5],param_2[6],param_2[7],param_2[8],param_2[9],param_2[10]);
  _vac_flush(_pmsgbuf,0x1000);
  _splx(iVar1);
  return CONCAT44(param_2,param_1) & 0xfffffffffffeffff;
}
/* GHIDRADEC_FUNCTION index=2513 start=0xf00a97a4 */

undefined8 _getregaddr(int param_1,int param_2,uint param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar1;
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
  if (param_3 == 0) {
    puVar1 = &_dev_null;
  }
  else if (param_3 < 0x10) {
    puVar1 = (undefined4 *)(param_1 + param_3 * 4);
  }
  else {
    puVar1 = (undefined4 *)(param_2 + param_3 * 4 + -0x40);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2514 start=0xf00a97e4 */

/* WARNING: Removing unreachable block (ram,0xf00a9af4) */
/* WARNING: Removing unreachable block (ram,0xf00a9a18) */
/* WARNING: Removing unreachable block (ram,0xf00a9a68) */
/* WARNING: Removing unreachable block (ram,0xf00a9c1c) */
/* WARNING: Removing unreachable block (ram,0xf00a9bd8) */
/* WARNING: Removing unreachable block (ram,0xf00a9bac) */
/* WARNING: Removing unreachable block (ram,0xf00a9b58) */
/* WARNING: Removing unreachable block (ram,0xf00a9998) */
/* WARNING: Removing unreachable block (ram,0xf00a9944) */
/* WARNING: Removing unreachable block (ram,0xf00a98f4) */
/* WARNING: Removing unreachable block (ram,0xf00a985c) */
/* WARNING: Removing unreachable block (ram,0xf00a988c) */
/* WARNING: Removing unreachable block (ram,0xf00a9914) */
/* WARNING: Removing unreachable block (ram,0xf00a9960) */
/* WARNING: Removing unreachable block (ram,0xf00a99cc) */
/* WARNING: Removing unreachable block (ram,0xf00a9b14) */
/* WARNING: Removing unreachable block (ram,0xf00a9bc0) */
/* WARNING: Removing unreachable block (ram,0xf00a9bf4) */
/* WARNING: Removing unreachable block (ram,0xf00a9a38) */
/* WARNING: Removing unreachable block (ram,0xf00a9a00) */
/* WARNING: Removing unreachable block (ram,0xf00a9ac4) */
/* WARNING: Removing unreachable block (ram,0xf00a9ae0) */
/* WARNING: Removing unreachable block (ram,0xf00a97ec) */

qword _do_unaligned(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined3 *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  int iVar10;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
  undefined4 unaff_i1;
  uint uVar13;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  iVar9 = 0;
  uVar1 = *(uint *)(param_1 + 4);
  _fuword();
  uVar3 = uVar1 >> 0x13 & 3;
  uVar8 = uVar1 >> 0x19 & 0x1f;
  uVar6 = uVar1 >> 0xe & 0x1f;
  uVar13 = uVar1 >> 0x18 & 1;
  uVar11 = uVar1 >> 0xd & 1;
  if (uVar3 == 1) {
    _printf(aAlignmentBotch);
    uVar12 = 0;
    goto locret_F00A9C3C;
  }
  if (uVar3 < 2) {
    iVar9 = 4;
  }
  else if (uVar3 == 2) {
    iVar9 = 2;
  }
  else if (uVar3 == 3) {
    iVar9 = 8;
  }
  if (_aligndebug != 0) {
    _printf(aUnalignedAcces,*(undefined4 *)(param_1 + 4),uVar1);
    if ((uVar1 >> 0x15 & 1) == 0) {
      puVar4 = &aLd;
    }
    else {
      puVar4 = &aSt;
    }
    if ((uVar1 >> 0x16 & 1) == 0) {
      puVar5 = aUnsigned;
    }
    else {
      puVar5 = (undefined *)&aSigned;
    }
    _printf(aTypeSSS,puVar4,puVar5,*(undefined4 *)(_sizestr + (uVar1 >> 0x11 & 0xc)));
    _printf(aRdDRs1DRs2DImm,uVar8,uVar6,uVar1 & 0x1f,uVar1 & 0x1fff);
  }
  if (uVar1 >> 0x1e != 3) {
    uVar12 = 0;
    goto locret_F00A9C3C;
  }
  if ((uVar11 == 0) && ((uVar1 >> 5 & 0xff) != 0)) {
    uVar12 = 0;
    goto locret_F00A9C3C;
  }
  iVar10 = param_1 + 0xc;
  _flush_user_windows_to_stack();
  uVar12 = *(undefined4 *)(param_1 + 0x44);
  iVar7 = iVar10;
  sub_F00A96F0(iVar10,uVar12,uVar6,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar7 != 0) {
    uVar12 = 0xffffffff;
    goto locret_F00A9C3C;
  }
  iVar7 = *(int *)((int)register0x00000038 + -0xc);
  if (uVar11 == 0) {
    iVar2 = iVar10;
    sub_F00A96F0(iVar10,uVar12,uVar1 & 0x1f,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar2 != 0) {
      uVar12 = 0xffffffff;
      goto locret_F00A9C3C;
    }
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
    iVar2 = (int)(uVar1 << 0x13) >> 0x13;
  }
  iVar7 = iVar7 + iVar2;
  if (_aligndebug != 0) {
    _printf(aAddr0xX_0,iVar7);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar7;
  }
  if (param_2 == 0) {
    uVar12 = 1;
    goto locret_F00A9C3C;
  }
  if ((uVar1 >> 0x15 & 1) == 0) {
    if (iVar9 == 2) {
      _copyin(iVar7,(undefined *)((int)register0x00000038 + -0x16),2);
      if (iVar7 != -1) {
        if (((uVar1 >> 0x16 & 1) == 0) || (-1 < *(sword *)((int)register0x00000038 + -0x16))) {
          *(undefined2 *)((int)register0x00000038 + -0x18) = 0;
        }
        else {
          *(undefined2 *)((int)register0x00000038 + -0x18) = 0xffff;
        }
        goto loc_F00A9B6C;
      }
    }
    else {
      _copyin(iVar7,(undefined *)((int)register0x00000038 + -0x18),iVar9);
      if (iVar7 == -1) {
        uVar12 = 0xffffffff;
        goto locret_F00A9C3C;
      }
loc_F00A9B6C:
      if (_aligndebug != 0) {
        _printf(aDataXXXXXXXX_0,*(undefined *)((int)register0x00000038 + -0x18),
                *(undefined *)((int)register0x00000038 + -0x17),
                *(undefined *)((int)register0x00000038 + -0x16),
                *(undefined *)((int)register0x00000038 + -0x15),
                *(undefined *)((int)register0x00000038 + -0x14),
                *(undefined *)((int)register0x00000038 + -0x13),
                *(undefined *)((int)register0x00000038 + -0x12),
                *(undefined *)((int)register0x00000038 + -0x11));
      }
      if (uVar13 != 0) {
        __fp_write_pfreg((undefined *)((int)register0x00000038 + -0x18),uVar8);
        uVar12 = 1;
        if (iVar9 == 8) {
          __fp_write_pfreg((undefined *)((int)register0x00000038 + -0x14),uVar8 + 1);
          uVar12 = 1;
        }
        goto locret_F00A9C3C;
      }
      iVar7 = *(int *)((int)register0x00000038 + -0x18);
      sub_F00A975C(iVar7,iVar10,uVar12,uVar8);
      if (iVar7 != -1) {
        if (iVar9 != 8) {
          uVar12 = 1;
          goto locret_F00A9C3C;
        }
        iVar9 = *(int *)((int)register0x00000038 + -0x14);
        sub_F00A975C(iVar9,iVar10,uVar12,uVar8 + 1);
        bVar14 = iVar9 == -1;
        goto loc_F00A9C28;
      }
    }
  }
  else {
    if (uVar13 == 0) {
      iVar2 = iVar10;
      sub_F00A96F0(iVar10,uVar12,uVar8,(undefined *)((int)register0x00000038 + -0xc));
      if (iVar2 != 0) {
        uVar12 = 0xffffffff;
        goto locret_F00A9C3C;
      }
      *(undefined4 *)((int)register0x00000038 + -0x18) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      if (iVar9 == 8) {
        sub_F00A96F0(iVar10,uVar12,uVar8 + 1,(undefined *)((int)register0x00000038 + -0xc));
        uVar12 = 0xffffffff;
        if (iVar10 != 0) goto locret_F00A9C3C;
        *(undefined4 *)((int)register0x00000038 + -0x14) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
      }
    }
    else {
      __fp_read_pfreg((undefined *)((int)register0x00000038 + -0x18),uVar8);
      if (iVar9 == 8) {
        __fp_read_pfreg((undefined *)((int)register0x00000038 + -0x14),uVar8 + 1);
      }
    }
    if (_aligndebug != 0) {
      _printf(aDataXXXXXXXX,*(undefined *)((int)register0x00000038 + -0x18),
              *(undefined *)((int)register0x00000038 + -0x17),
              *(undefined *)((int)register0x00000038 + -0x16),
              *(undefined *)((int)register0x00000038 + -0x15),
              *(undefined *)((int)register0x00000038 + -0x14),
              *(undefined *)((int)register0x00000038 + -0x13),
              *(undefined *)((int)register0x00000038 + -0x12),
              *(undefined *)((int)register0x00000038 + -0x11));
    }
    puVar5 = (undefined *)((int)register0x00000038 + -0x18);
    if (iVar9 == 2) {
      puVar5 = (undefined *)((int)register0x00000038 + -0x16);
      _copyout(puVar5,iVar7,2);
      bVar14 = puVar5 == (undefined *)0xffffffff;
    }
    else {
      _copyout(puVar5,iVar7,iVar9);
      bVar14 = puVar5 == (undefined *)0xffffffff;
    }
loc_F00A9C28:
    uVar12 = 1;
    if (!bVar14) goto locret_F00A9C3C;
  }
  uVar12 = 0xffffffff;
locret_F00A9C3C:
  return CONCAT44(uVar1 >> 0x18,uVar12) & 0x1ffffffff;
}
/* GHIDRADEC_FUNCTION index=2515 start=0xf00a9c44 */

/* WARNING: Removing unreachable block (ram,0xf00a9da4) */
/* WARNING: Removing unreachable block (ram,0xf00a9de4) */
/* WARNING: Removing unreachable block (ram,0xf00a9e24) */
/* WARNING: Removing unreachable block (ram,0xf00a9e64) */
/* WARNING: Removing unreachable block (ram,0xf00a9cf8) */
/* WARNING: Removing unreachable block (ram,0xf00a9c64) */
/* WARNING: Removing unreachable block (ram,0xf00a9cbc) */
/* WARNING: Removing unreachable block (ram,0xf00a9e84) */
/* WARNING: Removing unreachable block (ram,0xf00a9e44) */
/* WARNING: Removing unreachable block (ram,0xf00a9e04) */
/* WARNING: Removing unreachable block (ram,0xf00a9dc4) */
/* WARNING: Removing unreachable block (ram,0xf00a9eac) */
/* WARNING: Removing unreachable block (ram,0xf00a9c4c) */

undefined8 _simulate_unimp(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 uVar4;
  undefined4 unaff_l5;
  int iVar5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar2 = *(uint *)(param_1 + 4);
  bVar1 = true;
  _fuword();
  if (uVar2 == 0xffffffff) {
    iVar6 = 0;
    goto locret_F00A9EDC;
  }
  _flush_user_windows_to_stack();
  if ((uVar2 & 0xc1f80000) == 0x81d80000) goto loc_F00A9C84;
  if (uVar2 >> 0x1e != 2) {
    iVar6 = 0;
    goto locret_F00A9EDC;
  }
  iVar5 = param_1 + 0xc;
  uVar4 = *(undefined4 *)(param_1 + 0x44);
  iVar6 = iVar5;
  sub_F00A96F0(iVar5,uVar4,uVar2 >> 0xe & 0x1f,(undefined *)((int)register0x00000038 + -0x14));
  if (iVar6 != 0) {
    iVar6 = -1;
    goto locret_F00A9EDC;
  }
  iVar6 = *(int *)((int)register0x00000038 + -0x14);
  if ((uVar2 >> 0xd & 1) == 0) {
    iVar3 = iVar5;
    sub_F00A96F0(iVar5,uVar4,uVar2 & 0x1f,(undefined *)((int)register0x00000038 + -0x14));
    if (iVar3 != 0) {
      iVar6 = -1;
      goto locret_F00A9EDC;
    }
    iVar3 = *(int *)((int)register0x00000038 + -0x14);
  }
  else {
    iVar3 = (int)(uVar2 << 0x13) >> 0x13;
  }
  switch(uVar2 >> 0x13 & 0x3f) {
  case :
    __ip_umul(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    bVar7 = iVar6 == 1;
    break;
  case :
    __ip_mul(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    bVar7 = iVar6 == 1;
    break;
  :
    iVar6 = 0;
    goto locret_F00A9EDC;
  case :
    __ip_udiv(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    goto loc_F00A9E90;
  case :
    __ip_div(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    goto loc_F00A9E90;
  case :
    __ip_umulcc(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    bVar7 = iVar6 == 1;
    break;
  case :
    __ip_mulcc(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    bVar7 = iVar6 == 1;
    break;
  case :
    __ip_udivcc(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    goto loc_F00A9E90;
  case :
    __ip_divcc(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
loc_F00A9E90:
    bVar1 = false;
    bVar7 = iVar6 == 1;
  }
  if (bVar7) {
    iVar6 = *(int *)((int)register0x00000038 + -0x10);
    sub_F00A975C(iVar6,iVar5,uVar4,uVar2 >> 0x19 & 0x1f);
    if (iVar6 == 0) {
      if (bVar1) {
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0xc);
      }
loc_F00A9C84:
      iVar6 = 1;
    }
    else {
      iVar6 = -1;
    }
  }
locret_F00A9EDC:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=2516 start=0xf00a9ee4 */

/* WARNING: Removing unreachable block (ram,0xf00a9f70) */
/* WARNING: Removing unreachable block (ram,0xf00a9f2c) */
/* WARNING: Removing unreachable block (ram,0xf00a9f04) */
/* WARNING: Removing unreachable block (ram,0xf00a9fb0) */
/* WARNING: Removing unreachable block (ram,0xf00a9f14) */

undefined8 _fix_addr(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  puVar1 = *(undefined4 **)(param_1 + 4);
  bVar5 = &dword_F0000000 < puVar1;
  if (bVar5) {
    puVar1 = (undefined4 *)*puVar1;
    _flush_windows();
  }
  else {
    _fuword();
    if (puVar1 == (undefined4 *)0xffffffff) {
      iVar3 = -1;
      goto locret_F00A9FD4;
    }
    _flush_user_windows_to_stack();
  }
  if ((uint)puVar1 >> 0x1e != 3) {
    iVar3 = -1;
    goto locret_F00A9FD4;
  }
  iVar2 = param_1 + 0xc;
  if (((uint)puVar1 >> 0x17 & 3) == 3) {
loc_F00A9FC4:
    iVar3 = -1;
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + 0x44);
    iVar3 = iVar2;
    sub_F00A9FDC(iVar2,uVar4,(uint)puVar1 >> 0xe & 0x1f,
                 (undefined *)((int)register0x00000038 + -0xc),bVar5);
    if (iVar3 != 0) {
      iVar3 = -1;
      goto locret_F00A9FD4;
    }
    if (((uint)puVar1 >> 0xd & 1) == 0) {
      sub_F00A9FDC(iVar2,uVar4,(uint)puVar1 & 0x1f,(undefined *)((int)register0x00000038 + -0x10),
                   bVar5);
      iVar3 = *(int *)((int)register0x00000038 + -0xc);
      if (iVar2 != 0) goto loc_F00A9FC4;
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
    }
    else {
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      iVar3 = ((int)puVar1 << 0x13) >> 0x13;
    }
    iVar3 = iVar3 + iVar2;
  }
locret_F00A9FD4:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2517 start=0xf00aa060 */

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
/* GHIDRADEC_FUNCTION index=2518 start=0xf00aa288 */

/* WARNING: Removing unreachable block (ram,0xf00aa294) */

undefined8 _pagemove(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
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
  _pmap_move_page(param_1,param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2519 start=0xf00aa2a4 */

/* WARNING: Removing unreachable block (ram,0xf00aa340) */
/* WARNING: Removing unreachable block (ram,0xf00aa300) */
/* WARNING: Removing unreachable block (ram,0xf00aa3c4) */
/* WARNING: Removing unreachable block (ram,0xf00aa2c0) */
/* WARNING: Removing unreachable block (ram,0xf00aa390) */
/* WARNING: Removing unreachable block (ram,0xf00aa450) */
/* WARNING: Removing unreachable block (ram,0xf00aa328) */
/* WARNING: Removing unreachable block (ram,0xf00aa36c) */
/* WARNING: Removing unreachable block (ram,0xf00aa2b8) */

undefined8 _allocbuf(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
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
  iVar2 = param_2 + -1 + _page_size;
  .udiv(iVar2,_page_size);
  .umul();
  uVar1 = unk_F0133EB8._0_4_;
  iVar5 = *(int *)(param_1 + 0x18);
  if (iVar2 == iVar5) {
    *(int *)(param_1 + 0x14) = param_2;
  }
  else if (iVar2 < iVar5) {
    if ((undefined *)unk_F0133EB8._0_4_ == unk_F0133EAC) {
      *(int *)(param_1 + 0x14) = param_2;
    }
    else {
      _spltty();
      *(undefined4 *)(*(int *)(uVar1 + 0x10) + 0xc) = *(undefined4 *)(uVar1 + 0xc);
      *(undefined4 *)(*(int *)(uVar1 + 0xc) + 0x10) = *(undefined4 *)(uVar1 + 0x10);
      *(uint *)uVar1 = *(uint *)uVar1 | 8;
      _splx();
      _pagemove(*(int *)(param_1 + 0x20) + iVar2,*(undefined4 *)(uVar1 + 0x20),
                *(int *)(param_1 + 0x18) - iVar2);
      *(int *)(uVar1 + 0x18) = *(int *)(param_1 + 0x18) - iVar2;
      *(int *)(param_1 + 0x18) = iVar2;
      *(undefined4 *)(uVar1 + 0x14) = 0;
      *(uint *)uVar1 = *(uint *)uVar1 | 0x10000;
      _brelse();
      *(int *)(param_1 + 0x14) = param_2;
    }
  }
  else if (iVar5 < iVar2) {
    do {
      puVar3 = *(uint **)(param_1 + 0x18);
      uVar6 = iVar2 - (int)puVar3;
      _getnewbuf();
      uVar4 = puVar3[6];
      if ((int)uVar4 <= (int)uVar6) {
        uVar6 = uVar4;
      }
      _pagemove(puVar3[8] + (uVar4 - uVar6),*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x18),
                uVar6);
      *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar6;
      uVar6 = puVar3[6] - uVar6;
      puVar3[6] = uVar6;
      if ((int)uVar6 < (int)puVar3[5]) {
        puVar3[5] = uVar6;
      }
      if ((int)puVar3[6] < 1) {
        *(uint *)(puVar3[2] + 4) = puVar3[1];
        *(uint *)(puVar3[1] + 8) = puVar3[2];
        puVar3[1] = (uint)DAT_f0133eb0._0_4_;
        puVar3[2] = (uint)unk_F0133EAC;
        DAT_f0133eb0._0_4_[2] = (uint)puVar3;
        DAT_f0133eb0._0_4_ = puVar3;
        *(undefined2 *)((int)puVar3 + 0x1e) = 0xffff;
        *(undefined2 *)(puVar3 + 7) = 0;
        *puVar3 = *puVar3 | 0x10000;
      }
      _brelse(puVar3);
    } while (*(int *)(param_1 + 0x18) < iVar2);
    *(int *)(param_1 + 0x14) = param_2;
  }
  else {
    *(int *)(param_1 + 0x14) = param_2;
  }
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=2520 start=0xf00aa474 */

undefined8 _bfree(int param_1,undefined4 param_2)

{
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
  *(undefined4 *)(param_1 + 0x14) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2521 start=0xf00aa484 */

/* WARNING: Removing unreachable block (ram,0xf00aa57c) */
/* WARNING: Removing unreachable block (ram,0xf00aa6e0) */
/* WARNING: Removing unreachable block (ram,0xf00aa538) */
/* WARNING: Removing unreachable block (ram,0xf00aa694) */
/* WARNING: Removing unreachable block (ram,0xf00aa560) */
/* WARNING: Removing unreachable block (ram,0xf00aa5d8) */
/* WARNING: Removing unreachable block (ram,0xf00aa4a0) */

undefined8 _sendsig(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar10;
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
  *(int *)((int)register0x00000038 + 0x44) = param_1;
  *(int *)((int)register0x00000038 + 0x48) = param_2;
  uVar2 = *(undefined4 *)(_active_threads + 0x28);
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = uVar2;
  _flush_user_windows_to_stack();
  iVar4 = _active_u[0x52];
  *(int *)((int)register0x00000038 + -0x14) = _active_u[0x52];
  *(int *)((int)register0x00000038 + -0x1c) = *(int *)(_active_threads + 0x28) + 0x234;
  if ((iVar4 == 0) &&
     ((_active_u[0x4e] >> ((char)*(undefined4 *)((int)register0x00000038 + 0x48) - 1U & 0x1f) & 1U)
      != 0)) {
    piVar1 = _active_u + 0x51;
    _active_u[0x52] = 1;
    *(int *)((int)register0x00000038 + -0x24) = *piVar1 + -0x8b0;
  }
  else {
    *(int *)((int)register0x00000038 + -0x24) =
         *(int *)(*(int *)((int)register0x00000038 + -0x1c) + 0x44) + -0x8b0;
  }
  if (((*(uint *)((int)register0x00000038 + -0x24) & 7) == 0) &&
     (*(uint *)((int)register0x00000038 + -0x24) < 0xf0000000)) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x10);
    _setjmp();
    if (puVar3 == (undefined *)0x0) {
      uVar6 = *(undefined4 *)((int)register0x00000038 + -0x14);
      iVar4 = *(int *)((int)register0x00000038 + -0x24);
      puVar7 = *(undefined4 **)((int)register0x00000038 + -0x1c);
      *(undefined **)(_active_threads + 0x74) = (undefined *)((int)register0x00000038 + -0x10);
      uVar2 = *(undefined4 *)((int)register0x00000038 + 0x4c);
      *(undefined4 *)(iVar4 + 0x50) = uVar6;
      *(undefined4 *)(iVar4 + 0x54) = uVar2;
      *(undefined4 *)(iVar4 + 0x58) = puVar7[0x11];
      *(undefined4 *)(iVar4 + 0x5c) = puVar7[1];
      *(undefined4 *)(iVar4 + 0x60) = puVar7[2];
      *(undefined4 *)(iVar4 + 100) = *puVar7;
      *(undefined4 *)(iVar4 + 0x68) = puVar7[4];
      *(undefined4 *)(iVar4 + 0x6c) = puVar7[0xb];
      iVar4 = *(int *)((int)register0x00000038 + -0x2c);
      *(undefined4 *)(*(int *)((int)register0x00000038 + -0x24) + 0x70) =
           *(undefined4 *)(iVar4 + 0x230);
      iVar8 = 0;
      uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
      if (0 < *(int *)(iVar4 + 0x230)) {
        iVar9 = 0xf0;
        param_2 = *(int *)((int)register0x00000038 + -0x2c);
        iVar10 = 0x10;
        param_1 = *(int *)((int)register0x00000038 + -0x24);
        iVar4 = *(int *)((int)register0x00000038 + -0x2c);
        do {
          iVar8 = iVar8 + 1;
          iVar4 = iVar4 + iVar10;
          iVar5 = *(int *)((int)register0x00000038 + -0x24) + iVar9;
          iVar9 = iVar9 + 0x40;
          iVar10 = iVar10 + 0x40;
          *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_2 + 0x210);
          _bcopy(iVar4,iVar5,0x40);
          iVar4 = *(int *)((int)register0x00000038 + -0x2c);
          param_2 = param_2 + 4;
          param_1 = param_1 + 4;
        } while (iVar8 < *(int *)(iVar4 + 0x230));
        uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
      }
      iVar4 = *(int *)((int)register0x00000038 + -0x2c);
      *(undefined4 *)(*(int *)((int)register0x00000038 + -0x24) + 0x40) = uVar2;
      uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
      if (*(int *)(iVar4 + 0x230) == 0) {
        _bcopy(*(undefined4 *)(*(int *)((int)register0x00000038 + -0x1c) + 0x44),
               *(undefined4 *)((int)register0x00000038 + -0x24),0x40);
        uVar2 = *(undefined4 *)((int)register0x00000038 + 0x48);
      }
      switch(uVar2) {
      case :
      case :
      case :
      case :
      case :
        *(undefined4 *)(*(int *)((int)register0x00000038 + -0x24) + 0x44) =
             *(undefined4 *)(dword_F0133DDC + 0x44);
        *(undefined4 *)(dword_F0133DDC + 0x44) = 0;
        break;
      :
        *(undefined4 *)(*(int *)((int)register0x00000038 + -0x24) + 0x44) = 0;
      }
      iVar9 = *(int *)((int)register0x00000038 + -0x24);
      *(int *)(iVar9 + 0x48) = iVar9 + 0x50;
      iVar4 = *(int *)((int)register0x00000038 + -0x2c);
      *(undefined4 *)(_active_threads + 0x74) = 0;
      *(undefined4 *)(iVar4 + 0x230) = 0;
      iVar8 = *(int *)((int)register0x00000038 + -0x1c);
      iVar4 = *(int *)((int)register0x00000038 + 0x44);
      *(int *)(iVar8 + 0x44) = iVar9;
      *(int *)(iVar8 + 4) = iVar4;
      *(int *)(iVar8 + 8) = iVar4 + 4;
      goto locret_F00AA790;
    }
  }
  _printf(aSendsigBadSign,(int)*(sword *)(*_active_u + 0x30),
          *(undefined4 *)((int)register0x00000038 + 0x48));
  _printf(aSigsp0xXAction,*(undefined4 *)((int)register0x00000038 + -0x24),
          *(undefined4 *)((int)register0x00000038 + 0x44),
          *(undefined4 *)(*(int *)((int)register0x00000038 + -0x1c) + 4));
  _active_u[0x10] = 0;
  *(uint *)(*_active_u + 0x20) = *(uint *)(*_active_u + 0x20) & 0xfffffff7;
  *(uint *)(*_active_u + 0x24) = *(uint *)(*_active_u + 0x24) & 0xfffffff7;
  *(uint *)(*_active_u + 0x1c) = *(uint *)(*_active_u + 0x1c) & 0xfffffff7;
  *(undefined4 *)((int)register0x00000038 + 0x48) = 8;
  _psignal(*_active_u,4);
locret_F00AA790:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2522 start=0xf00aa798 */

/* WARNING: Removing unreachable block (ram,0xf00aa8c0) */
/* WARNING: Removing unreachable block (ram,0xf00aa7e8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _sigreturn(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint *puVar4;
  int iVar5;
  undefined4 unaff_l3;
  uint *puVar6;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  int iVar8;
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
  iVar5 = *(int *)(_active_threads + 0x28);
  puVar4 = *(uint **)(iVar5 + 0x260);
  if ((((puVar4 < &dword_F0000000) && (((uint)puVar4 & 3) == 0)) && ((puVar4[3] & 3) == 0)) &&
     ((puVar4[4] & 3) == 0)) {
    _flush_user_windows();
    _active_u[0x52] = *puVar4 & 1;
    *(uint *)(*_active_u + 0x1c) = puVar4[1] & 0xfffefeff;
    *(uint *)(iVar5 + 0x278) = puVar4[2];
    *(uint *)(iVar5 + 0x238) = puVar4[3];
    *(uint *)(iVar5 + 0x23c) = puVar4[4];
    *(uint *)(iVar5 + 0x234) = *(uint *)(iVar5 + 0x234) & 0xff0fffff | puVar4[5] & 0xf00000;
    *(uint *)(iVar5 + 0x244) = puVar4[6];
    *(uint *)(iVar5 + 0x260) = puVar4[7];
    iVar3 = 0;
    if (puVar4[8] < __nwindows) {
      iVar8 = *(int *)(iVar5 + 0x230);
      if (0 < (int)puVar4[8]) {
        iVar7 = 0xa0;
        puVar6 = puVar4;
        do {
          iVar1 = (int)puVar4 + iVar7;
          iVar7 = iVar7 + 0x40;
          iVar2 = iVar8 + iVar3;
          iVar3 = iVar3 + 1;
          *(uint *)(iVar2 * 4 + iVar5 + 0x210) = puVar6[9];
          _copyin(iVar1,iVar5 + iVar2 * 0x40 + 0x10,0x40);
          puVar6 = puVar6 + 1;
        } while (iVar3 < (int)puVar4[8]);
      }
      *(uint *)(iVar5 + 0x230) = *(int *)(iVar5 + 0x230) + puVar4[8];
    }
    else {
      *(undefined4 *)(iVar5 + 0x230) = 0;
    }
    *(undefined *)(dword_F0133DDC + 0x39) = 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2523 start=0xf00aa908 */

undefined8
_machine_exception(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  undefined4 uVar1;
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
  if (param_1 == 2) {
    uVar1 = 4;
  }
  else {
    uVar1 = 8;
    if (param_1 != 3) {
      uVar1 = 0;
      goto locret_F00AA938;
    }
  }
  *param_4 = uVar1;
  *param_5 = param_2;
  uVar1 = 1;
locret_F00AA938:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2524 start=0xf00aa940 */

/* WARNING: Removing unreachable block (ram,0xf00aaa74) */
/* WARNING: Removing unreachable block (ram,0xf00aa9f4) */
/* WARNING: Removing unreachable block (ram,0xf00aa9e8) */
/* WARNING: Removing unreachable block (ram,0xf00aaa60) */
/* WARNING: Removing unreachable block (ram,0xf00aaa80) */
/* WARNING: Removing unreachable block (ram,0xf00aa980) */

undefined8 _startup_early(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
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
  iVar3 = _nclist * 0x40;
  iVar1 = _ncsize * 0x48;
  if (_bufpages == 0) {
    uVar4 = _mem_size;
    .udiv(_mem_size,0x32);
    _bufpages = uVar4 >> ((byte)_page_shift & 0x1f);
  }
  if ((_nbuf == 0) && (_nbuf = _bufpages, (int)_bufpages < 0x10)) {
    _nbuf = 0x10;
  }
  if (0xff < (int)_nbuf) {
    _nbuf = 0xff;
  }
  uVar2 = 0x2000;
  .udiv(0x2000,_page_size);
  uVar4 = _nbuf;
  .umul(_nbuf,uVar2);
  if (uVar4 < _bufpages) {
    _bufpages = uVar4;
  }
  if (_nmfsbuf == 0) {
    _nmfsbuf = (int)_nbuf / 2;
  }
  uVar4 = iVar3 + iVar1 + _nbuf * 0x44 + _page_mask & ~_page_mask;
  iVar1 = _kernel_map;
  _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar4);
  if (iVar1 != 0) {
    _panic(aStartupEarlyNo);
  }
  _bzero(*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
  _cfree = *(int *)((int)register0x00000038 + -0xc);
  _ncache = *(int *)((int)register0x00000038 + -0xc) + _nclist * 0x40;
  *(int *)((int)register0x00000038 + -0xc) = _ncache;
  _buf = _ncache + _ncsize * 0x48;
  *(int *)((int)register0x00000038 + -0xc) = _buf;
  *(uint *)((int)register0x00000038 + -0xc) = _buf + _nbuf * 0x44;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2525 start=0xf00aaaf4 */

/* WARNING: Removing unreachable block (ram,0xf00aaef4) */
/* WARNING: Removing unreachable block (ram,0xf00aaec0) */
/* WARNING: Removing unreachable block (ram,0xf00aae8c) */
/* WARNING: Removing unreachable block (ram,0xf00aae40) */
/* WARNING: Removing unreachable block (ram,0xf00aad94) */
/* WARNING: Removing unreachable block (ram,0xf00aace8) */
/* WARNING: Removing unreachable block (ram,0xf00aac8c) */
/* WARNING: Removing unreachable block (ram,0xf00aac4c) */
/* WARNING: Removing unreachable block (ram,0xf00aac08) */
/* WARNING: Removing unreachable block (ram,0xf00aabd8) */
/* WARNING: Removing unreachable block (ram,0xf00aab84) */
/* WARNING: Removing unreachable block (ram,0xf00aab44) */
/* WARNING: Removing unreachable block (ram,0xf00aab2c) */
/* WARNING: Removing unreachable block (ram,0xf00aab34) */
/* WARNING: Removing unreachable block (ram,0xf00aab50) */
/* WARNING: Removing unreachable block (ram,0xf00aabb0) */
/* WARNING: Removing unreachable block (ram,0xf00aabf4) */
/* WARNING: Removing unreachable block (ram,0xf00aac3c) */
/* WARNING: Removing unreachable block (ram,0xf00aac78) */
/* WARNING: Removing unreachable block (ram,0xf00aaca8) */
/* WARNING: Removing unreachable block (ram,0xf00aad08) */
/* WARNING: Removing unreachable block (ram,0xf00aadd8) */
/* WARNING: Removing unreachable block (ram,0xf00aae84) */
/* WARNING: Removing unreachable block (ram,0xf00aae94) */
/* WARNING: Removing unreachable block (ram,0xf00aaeec) */
/* WARNING: Removing unreachable block (ram,0xf00aaefc) */
/* WARNING: Removing unreachable block (ram,0xf00aab10) */

undefined8 _startup(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined *puVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar12;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  _cons_tp = _cons;
  DAT_f01351c8._0_2_ = 0xc00;
  _kminit();
  _kmpopup(_mach_title,0,0,0,0);
  _startup_early();
  *(undefined4 *)((int)register0x00000038 + 0x44) = _virtual_avail;
  _panic_init();
  _printf(_version);
  uVar9 = _mem_size >> 0x14;
  uVar7 = _mem_size & 0xfffff;
  uVar1 = _mem_size;
  .urem(_mem_size,0x19999);
  _printf(aPhysicalMemory,uVar9,uVar7 * 10 >> 0x14,(uVar1 * 0x19 & 0x3fffffff) >> 0x12);
  uVar3 = _kernel_map;
  uVar2 = 0;
  *(uint *)((int)register0x00000038 + 0x44) =
       *(int *)((int)register0x00000038 + 0x44) + _page_mask & ~_page_mask;
  _vm_object_allocate(0);
  _vm_map_find(uVar3,uVar2,0,(undefined *)((int)register0x00000038 + 0x44),0x800000,1);
  _vm_map_remove(_kernel_map,*(int *)((int)register0x00000038 + 0x44),
                 *(int *)((int)register0x00000038 + 0x44) + 0x800000);
  uVar1 = _bufpages;
  iVar4 = _nbuf;
  iVar10 = *(int *)((int)register0x00000038 + 0x44);
  iVar5 = _nbuf * 0x2000;
  uVar7 = _bufpages;
  _buffers = iVar10;
  .div(_bufpages,_nbuf);
  .rem(uVar1,iVar4);
  puVar11 = (undefined *)(iVar10 + iVar5 + _page_mask & ~_page_mask);
  iVar10 = (int)puVar11 - iVar10;
  uVar3 = _kernel_map;
  _kmem_suballoc(_kernel_map,(undefined *)((int)register0x00000038 + 0x44),
                 (undefined *)((int)register0x00000038 + -0xc),iVar10,1);
  iVar4 = iVar10;
  _buffer_map = uVar3;
  _vm_object_allocate(iVar10);
  _vm_map_find(uVar3,iVar4,0,(undefined *)((int)register0x00000038 + 0x44),iVar10,0);
  uVar9 = 0;
  if (_nbuf != 0) {
    puVar11 = DAT_f013ec00;
    bVar12 = uVar1 != 0;
    do {
      uVar6 = uVar7;
      if (bVar12) {
        uVar6 = uVar7 + 1;
      }
      iVar4 = _page_size;
      .umul(_page_size,uVar6);
      iVar5 = _buffers + uVar9 * 0x2000;
      _vm_map_pageable(_buffer_map,iVar5,iVar5 + iVar4,0);
      uVar9 = uVar9 + 1;
      bVar12 = true;
    } while (uVar9 < uVar1);
  }
  iVar4 = _nbuf;
  iVar10 = _bufpages << ((byte)_page_shift & 0x1f);
  iVar5 = iVar10;
  if (iVar10 < 0) {
    iVar5 = iVar10 + 0xfffff;
  }
  iVar8 = (iVar10 + (iVar5 >> 0x14) * -0x100000) * 10;
  if (iVar8 < 0) {
    iVar8 = iVar8 + 0xfffff;
  }
  .rem(iVar10,0x19999);
  iVar10 = iVar10 * 100;
  if (iVar10 < 0) {
    iVar10 = iVar10 + 0xfffff;
  }
  _printf(aUsingDBuffersC,iVar4,iVar5 >> 0x14,iVar8 >> 0x14,iVar10 >> 0x14);
  iVar4 = _vm_page_free_count;
  iVar10 = _vm_page_free_count << ((byte)_page_shift & 0x1f);
  iVar5 = iVar10;
  if (iVar10 < 0) {
    iVar5 = iVar10 + 0xfffff;
  }
  iVar8 = (iVar10 + (iVar5 >> 0x14) * -0x100000) * 10;
  if (iVar8 < 0) {
    iVar8 = iVar8 + 0xfffff;
  }
  .rem(iVar10,0x19999);
  iVar10 = iVar10 * 100;
  if (iVar10 < 0) {
    iVar10 = iVar10 + 0xfffff;
  }
  _printf(aAvailableMemor,iVar5 >> 0x14,iVar8 >> 0x14,iVar10 >> 0x14,iVar4);
  _callout_init();
  _clock_timer_init();
  uVar3 = _kernel_map;
  _kmem_suballoc(_kernel_map,&_mbutl,_embutl,_nmbclusters << 10,0);
  _debug_init_done = 1;
  _mb_map = uVar3;
  if (_iom != 0) {
    _iom_init();
  }
  _configure();
  _spl0();
  return CONCAT44(param_2,puVar11);
}
/* GHIDRADEC_FUNCTION index=2526 start=0xf00aaf0c */

/* WARNING: Removing unreachable block (ram,0xf00ab018) */
/* WARNING: Removing unreachable block (ram,0xf00aafe4) */
/* WARNING: Removing unreachable block (ram,0xf00aafac) */
/* WARNING: Removing unreachable block (ram,0xf00aaf7c) */
/* WARNING: Removing unreachable block (ram,0xf00aafd8) */
/* WARNING: Removing unreachable block (ram,0xf00ab000) */
/* WARNING: Removing unreachable block (ram,0xf00ab020) */
/* WARNING: Removing unreachable block (ram,0xf00aaf4c) */

undefined8 _map_alloc(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined4 uVar6;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  uVar3 = param_2 - 1;
  uVar5 = param_1 + _page_mask & ~_page_mask;
  if ((param_2 & uVar3) == 0) {
    iVar1 = _kernel_map;
    _vm_map_find(_kernel_map,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar5,1);
    if (iVar1 != 0) {
      uVar6 = 0;
      goto locret_F00AB02C;
    }
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    if ((param_2 != 0) && ((uVar2 & uVar3) != 0)) {
      _vm_map_remove(_kernel_map,uVar2,uVar2 + uVar5);
      *(uint *)((int)register0x00000038 + -0xc) =
           *(int *)((int)register0x00000038 + -0xc) + -1 + param_2 & ~uVar3;
      iVar1 = _kernel_map;
      _vm_map_find(_kernel_map,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar5,0);
      if (iVar1 != 0) goto loc_F00AAFC0;
    }
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    _vm_object_reference(_kernel_object);
    _lock_write(_kernel_map);
    iVar1 = _kernel_map;
    *(int *)(_kernel_map + 0x4c) = *(int *)(_kernel_map + 0x4c) + 1;
    _vm_map_delete(iVar1,*(int *)((int)register0x00000038 + -0xc),
                   *(int *)((int)register0x00000038 + -0xc) + uVar5);
    _vm_map_insert(_kernel_map,_kernel_object,iVar4 + 0x10000000,
                   *(int *)((int)register0x00000038 + -0xc),
                   *(int *)((int)register0x00000038 + -0xc) + uVar5);
    _lock_done(_kernel_map);
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
loc_F00AAFC0:
    uVar6 = 0;
  }
locret_F00AB02C:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=2527 start=0xf00ab034 */

/* WARNING: Removing unreachable block (ram,0xf00ab058) */

undefined8 _map_free(uint param_1,int param_2)

{
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
  _vm_map_remove(_kernel_map,param_1 & ~_page_mask,param_1 + param_2 + _page_mask & ~_page_mask);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2528 start=0xf00ab5ac */

/* WARNING: Removing unreachable block (ram,0xf00ab5cc) */
/* WARNING: Removing unreachable block (ram,0xf00ab5dc) */

undefined8 __fp_add(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4)

{
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
  if (*param_2 == *param_3) {
    sub_F00AB068(param_1,param_2);
  }
  else {
    sub_F00AB218(param_1,param_2,param_3,param_4);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2529 start=0xf00ab5ec */

/* WARNING: Removing unreachable block (ram,0xf00ab628) */
/* WARNING: Removing unreachable block (ram,0xf00ab634) */

undefined8 __fp_sub(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4)

{
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
  if (param_3[1] < 4) {
    *param_3 = 1 - *param_3;
  }
  if (*param_2 == *param_3) {
    sub_F00AB068(param_1,param_2);
  }
  else {
    sub_F00AB218(param_1,param_2,param_3,param_4);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2530 start=0xf00ab644 */

/* WARNING: Removing unreachable block (ram,0xf00ab684) */
/* WARNING: Removing unreachable block (ram,0xf00ab728) */

undefined8 __fp_compare(undefined4 param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
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
  uint uVar4;
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
  iVar3 = param_2[1];
  if (iVar3 != 4) {
    iVar2 = param_3[1];
    if (((iVar2 != 4) && (iVar3 != 5)) && (iVar2 != 5)) {
      if (iVar3 == 0) {
        if (iVar2 == 0) {
          uVar4 = 0;
          goto locret_F00AB760;
        }
        iVar3 = *param_2;
      }
      else {
        iVar3 = *param_2;
      }
      if (*param_3 <= iVar3) {
        uVar4 = 1;
        if (*param_3 < iVar3) goto locret_F00AB760;
        iVar3 = param_2[1];
        uVar4 = 2;
        if (iVar3 <= param_3[1]) {
          if (iVar3 < param_3[1]) {
loc_F00AB71C:
            uVar4 = 1;
          }
          else if (iVar3 == 2) {
            uVar4 = 0;
          }
          else {
            uVar4 = 2;
            if (param_2[2] <= param_3[2]) {
              piVar1 = param_2 + 3;
              if (param_2[2] < param_3[2]) goto loc_F00AB71C;
              _fpu_cmpli(piVar1,param_3 + 3,4);
              uVar4 = 2;
              if ((int)piVar1 < 1) {
                uVar4 = (uint)piVar1 >> 0x1f;
              }
            }
          }
        }
        if (*param_2 == 0) goto locret_F00AB760;
        if (uVar4 != 1) {
          if (uVar4 == 2) {
            uVar4 = 1;
          }
          goto locret_F00AB760;
        }
      }
      uVar4 = 2;
      goto locret_F00AB760;
    }
  }
  uVar4 = 3;
  if (param_4 != 0) {
    _fpu_set_exception(param_1,4);
    uVar4 = 3;
  }
locret_F00AB760:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2531 start=0xf00ab768 */

/* WARNING: Removing unreachable block (ram,0xf00abce8) */
/* WARNING: Removing unreachable block (ram,0xf00abc30) */
/* WARNING: Removing unreachable block (ram,0xf00abc08) */
/* WARNING: Removing unreachable block (ram,0xf00abb64) */
/* WARNING: Removing unreachable block (ram,0xf00abb3c) */
/* WARNING: Removing unreachable block (ram,0xf00abb08) */
/* WARNING: Removing unreachable block (ram,0xf00aba70) */
/* WARNING: Removing unreachable block (ram,0xf00aba48) */
/* WARNING: Removing unreachable block (ram,0xf00ab9a8) */
/* WARNING: Removing unreachable block (ram,0xf00ab980) */
/* WARNING: Removing unreachable block (ram,0xf00ab94c) */
/* WARNING: Removing unreachable block (ram,0xf00ab8fc) */
/* WARNING: Removing unreachable block (ram,0xf00ab96c) */
/* WARNING: Removing unreachable block (ram,0xf00ab994) */
/* WARNING: Removing unreachable block (ram,0xf00aba28) */
/* WARNING: Removing unreachable block (ram,0xf00aba5c) */
/* WARNING: Removing unreachable block (ram,0xf00aba84) */
/* WARNING: Removing unreachable block (ram,0xf00abb28) */
/* WARNING: Removing unreachable block (ram,0xf00abb50) */
/* WARNING: Removing unreachable block (ram,0xf00abbe8) */
/* WARNING: Removing unreachable block (ram,0xf00abc1c) */
/* WARNING: Removing unreachable block (ram,0xf00abc44) */
/* WARNING: Removing unreachable block (ram,0xf00ab884) */
/* WARNING: Removing unreachable block (ram,0xf00ab8bc) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00ab8fc */
/* WARNING: Restarted to delay deadcode elimination for space: register */

uint __fp_div(uint *param_1,uint *param_2)

{
  undefined4 extraout_o0;
  undefined4 extraout_o0_00;
  undefined4 extraout_o0_01;
  undefined4 extraout_o0_02;
  qword in_o0_1;
  uint *puVar3;
  undefined4 uVar4;
  qword qVar1;
  sqword sVar2;
  undefined4 unaff_l0;
  uint *puVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
  undefined4 unaff_i1;
  int iVar7;
  undefined4 unaff_i2;
  undefined *puVar8;
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
  uVar6 = (uint)(in_o0_1 >> 0x20);
  puVar3 = (uint *)in_o0_1;
  *param_2 = *puVar3;
  param_2[1] = puVar3[1];
  param_2[2] = puVar3[2];
  param_2[3] = puVar3[3];
  param_2[4] = puVar3[4];
  param_2[5] = puVar3[5];
  param_2[6] = puVar3[6];
  param_2[7] = puVar3[7];
  param_2[8] = puVar3[8];
  if (((int)param_1[1] < 4) && ((int)puVar3[1] < 4)) {
    *param_2 = *puVar3 ^ *param_1;
    switch(puVar3[1]) {
    case :
    case :
      if (puVar3[1] != param_1[1]) {
        return uVar6;
      }
      _fpu_error_nan();
      param_2[1] = 4;
      return uVar6;
    case :
      if (param_1[1] == 0) {
        _fpu_set_exception(uVar6);
        param_2[1] = 2;
        return uVar6;
      }
      if (param_1[1] == 2) {
        param_2[1] = 0;
        return uVar6;
      }
      break;
    :
    }
    puVar5 = param_1 + 3;
    *(uint *)((int)register0x00000038 + -0x18) = uVar6;
    *(uint *)((int)register0x00000038 + -0x14) = puVar3[4];
    *(uint *)((int)register0x00000038 + -0x10) = puVar3[5];
    *(uint *)((int)register0x00000038 + -0xc) = puVar3[6];
    _fpu_cmpli((undefined *)((int)register0x00000038 + -0x18),puVar3,4);
    param_2[2] = uVar6;
    uVar6 = 0;
    puVar8 = (undefined *)((int)register0x00000038 + -0x18);
    do {
      uVar6 = uVar6 * 2;
      uVar4 = (undefined4)in_o0_1;
      _fpu_cmpli(puVar8,uVar4,4);
      extraout_o0 = (undefined4)(in_o0_1 >> 0x20);
      if (-1 < (sqword)in_o0_1) {
        uVar6 = uVar6 + 1;
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0xc),uVar4,param_1[6],0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x10),uVar4,param_1[5],extraout_o0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x14),uVar4,param_1[4],extraout_o0);
        _fpu_sub3wc(puVar8,uVar4,*puVar5,extraout_o0);
      }
      qVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x14),
                       *(int *)((int)register0x00000038 + -0x18) << 1) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x18) = (uint)qVar1 | (uint)(qVar1 >> 0x3f);
      *(uint *)((int)register0x00000038 + -0x14) =
           *(int *)((int)register0x00000038 + -0x14) << 1 |
           *(uint *)((int)register0x00000038 + -0x10) >> 0x1f;
      in_o0_1 = CONCAT44(*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0xc)) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x10) << 1 | (uint)(in_o0_1 >> 0x3f);
      *(int *)((int)register0x00000038 + -0xc) = (int)in_o0_1 << 1;
    } while (uVar6 < 0x10000);
    param_2[3] = uVar6;
    uVar6 = 0;
    iVar7 = 0x1f;
    do {
      uVar6 = uVar6 * 2;
      uVar4 = (undefined4)in_o0_1;
      _fpu_cmpli(puVar8,uVar4,4);
      extraout_o0_00 = (undefined4)(in_o0_1 >> 0x20);
      if (-1 < (sqword)in_o0_1) {
        uVar6 = uVar6 + 1;
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0xc),uVar4,param_1[6],0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x10),uVar4,param_1[5],extraout_o0_00);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x14),uVar4,param_1[4],extraout_o0_00);
        _fpu_sub3wc(puVar8,uVar4,*puVar5,extraout_o0_00);
      }
      iVar7 = iVar7 + -1;
      qVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x14),
                       *(int *)((int)register0x00000038 + -0x18) << 1) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x18) = (uint)qVar1 | (uint)(qVar1 >> 0x3f);
      *(uint *)((int)register0x00000038 + -0x14) =
           *(int *)((int)register0x00000038 + -0x14) << 1 |
           *(uint *)((int)register0x00000038 + -0x10) >> 0x1f;
      in_o0_1 = CONCAT44(*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0xc)) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x10) << 1 | (uint)(in_o0_1 >> 0x3f);
      *(int *)((int)register0x00000038 + -0xc) = (int)in_o0_1 << 1;
    } while (iVar7 != -1);
    param_2[4] = uVar6;
    uVar6 = 0;
    iVar7 = 0x1f;
    do {
      uVar6 = uVar6 * 2;
      uVar4 = (undefined4)in_o0_1;
      _fpu_cmpli(puVar8,uVar4,4);
      extraout_o0_01 = (undefined4)(in_o0_1 >> 0x20);
      if (-1 < (sqword)in_o0_1) {
        uVar6 = uVar6 + 1;
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0xc),uVar4,param_1[6],0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x10),uVar4,param_1[5],extraout_o0_01);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x14),uVar4,param_1[4],extraout_o0_01);
        _fpu_sub3wc(puVar8,uVar4,*puVar5,extraout_o0_01);
      }
      iVar7 = iVar7 + -1;
      qVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x14),
                       *(int *)((int)register0x00000038 + -0x18) << 1) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x18) = (uint)qVar1 | (uint)(qVar1 >> 0x3f);
      *(uint *)((int)register0x00000038 + -0x14) =
           *(int *)((int)register0x00000038 + -0x14) << 1 |
           *(uint *)((int)register0x00000038 + -0x10) >> 0x1f;
      in_o0_1 = CONCAT44(*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0xc)) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x10) << 1 | (uint)(in_o0_1 >> 0x3f);
      *(int *)((int)register0x00000038 + -0xc) = (int)in_o0_1 << 1;
    } while (iVar7 != -1);
    param_2[5] = uVar6;
    uVar6 = 0;
    iVar7 = 0x1f;
    do {
      uVar6 = uVar6 * 2;
      uVar4 = (undefined4)in_o0_1;
      _fpu_cmpli(puVar8,uVar4,4);
      extraout_o0_02 = (undefined4)(in_o0_1 >> 0x20);
      if (-1 < (sqword)in_o0_1) {
        uVar6 = uVar6 + 1;
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0xc),uVar4,param_1[6],0);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x10),uVar4,param_1[5],extraout_o0_02);
        _fpu_sub3wc((undefined *)((int)register0x00000038 + -0x14),uVar4,param_1[4],extraout_o0_02);
        _fpu_sub3wc(puVar8,uVar4,*puVar5,extraout_o0_02);
      }
      iVar7 = iVar7 + -1;
      qVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x14),
                       *(int *)((int)register0x00000038 + -0x18) << 1) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x18) = (uint)qVar1 | (uint)(qVar1 >> 0x3f);
      *(uint *)((int)register0x00000038 + -0x14) =
           *(int *)((int)register0x00000038 + -0x14) << 1 |
           *(uint *)((int)register0x00000038 + -0x10) >> 0x1f;
      in_o0_1 = CONCAT44(*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0xc)) & 0x80000000ffffffff;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x10) << 1 | (uint)(in_o0_1 >> 0x3f);
      *(int *)((int)register0x00000038 + -0xc) = (int)in_o0_1 << 1;
    } while (iVar7 != -1);
    param_2[6] = uVar6;
    sVar2 = *(sqword *)((int)register0x00000038 + -0x18);
    uVar6 = 1;
    if ((((int)((qword)sVar2 >> 0x20) == 0 && (int)sVar2 == 0) &&
        *(int *)((int)register0x00000038 + -0x10) == 0) &&
        *(int *)((int)register0x00000038 + -0xc) == 0) {
      param_2[7] = 0;
      param_2[8] = 0;
    }
    else {
      param_2[8] = 1;
      _fpu_cmpli(puVar8,(int)sVar2,4);
      if (-1 < sVar2) {
        param_2[7] = 1;
      }
    }
  }
  else if ((int)puVar3[1] < (int)param_1[1]) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    param_2[3] = param_1[3];
    param_2[4] = param_1[4];
    param_2[5] = param_1[5];
    param_2[6] = param_1[6];
    param_2[7] = param_1[7];
    param_2[8] = param_1[8];
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2532 start=0xf00abd04 */

/* WARNING: Removing unreachable block (ram,0xf00ac244) */
/* WARNING: Removing unreachable block (ram,0xf00ac21c) */
/* WARNING: Removing unreachable block (ram,0xf00ac1f4) */
/* WARNING: Removing unreachable block (ram,0xf00ac1cc) */
/* WARNING: Removing unreachable block (ram,0xf00ac194) */
/* WARNING: Removing unreachable block (ram,0xf00ac0cc) */
/* WARNING: Removing unreachable block (ram,0xf00ac0a4) */
/* WARNING: Removing unreachable block (ram,0xf00ac07c) */
/* WARNING: Removing unreachable block (ram,0xf00abfac) */
/* WARNING: Removing unreachable block (ram,0xf00abf84) */
/* WARNING: Removing unreachable block (ram,0xf00abf4c) */
/* WARNING: Removing unreachable block (ram,0xf00abf70) */
/* WARNING: Removing unreachable block (ram,0xf00abf98) */
/* WARNING: Removing unreachable block (ram,0xf00ac058) */
/* WARNING: Removing unreachable block (ram,0xf00ac090) */
/* WARNING: Removing unreachable block (ram,0xf00ac0b8) */
/* WARNING: Removing unreachable block (ram,0xf00ac0e0) */
/* WARNING: Removing unreachable block (ram,0xf00ac1b8) */
/* WARNING: Removing unreachable block (ram,0xf00ac1e0) */
/* WARNING: Removing unreachable block (ram,0xf00ac208) */
/* WARNING: Removing unreachable block (ram,0xf00ac230) */
/* WARNING: Removing unreachable block (ram,0xf00ac2f8) */
/* WARNING: Removing unreachable block (ram,0xf00abdb4) */

undefined8 __fp_sqrt(uint *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_l0;
  int iVar8;
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
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  param_3[3] = param_2[3];
  param_3[4] = param_2[4];
  param_3[5] = param_2[5];
  param_3[6] = param_2[6];
  param_3[7] = param_2[7];
  param_3[8] = param_2[8];
  switch(param_2[1]) {
  case :
  case :
  case :
    goto locret_F00AC310;
  case :
    if (*param_2 == 1) goto loc_F00ABDB4;
    uVar6 = param_2[2];
    break;
  case :
    if (*param_2 != 1) goto locret_F00AC310;
loc_F00ABDB4:
    _fpu_error_nan(param_1,param_3);
    param_3[1] = 4;
    goto locret_F00AC310;
  :
    uVar6 = param_2[2];
  }
  param_1 = (uint *)(param_2 + 3);
  if ((uVar6 & 1) == 0) {
    param_3[2] = (int)uVar6 / 2;
  }
  else {
    param_3[2] = (int)(uVar6 - 1) / 2;
    param_2[3] = param_2[3] << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  }
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
  iVar8 = 0;
  uVar6 = 0x10000;
  do {
    uVar7 = *(int *)((int)register0x00000038 + -0x28) + uVar6;
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    if (uVar7 <= *param_1) {
      *(uint *)((int)register0x00000038 + -0x28) = uVar7 + uVar6;
      iVar8 = iVar8 + uVar6;
      *param_1 = *param_1 - uVar7;
    }
    uVar6 = uVar6 >> 1;
    *param_1 = *param_1 << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  } while (uVar6 != 0);
  param_3[3] = iVar8;
  iVar8 = 0;
  uVar6 = 0x80000000;
  do {
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    *(uint *)((int)register0x00000038 + -0x14) = *(int *)((int)register0x00000038 + -0x24) + uVar6;
    *(undefined4 *)((int)register0x00000038 + -0x18) =
         *(undefined4 *)((int)register0x00000038 + -0x28);
    _fpu_cmpli(puVar2,param_1,2);
    if ((int)puVar2 < 1) {
      puVar2 = (undefined *)((int)register0x00000038 + -0x24);
      iVar8 = iVar8 + uVar6;
      _fpu_add3wc(puVar2,*(undefined4 *)((int)register0x00000038 + -0x14),uVar6,0);
      _fpu_add3wc((undefined *)((int)register0x00000038 + -0x28),
                  *(undefined4 *)((int)register0x00000038 + -0x18),0,puVar2);
      piVar3 = param_2 + 4;
      _fpu_sub3wc(piVar3,param_2[4],*(undefined4 *)((int)register0x00000038 + -0x14),0);
      _fpu_sub3wc(param_1,*param_1,*(undefined4 *)((int)register0x00000038 + -0x18),piVar3);
      uVar7 = *param_1;
    }
    else {
      uVar7 = *param_1;
    }
    uVar6 = uVar6 >> 1;
    *param_1 = uVar7 << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  } while (uVar6 != 0);
  param_3[4] = iVar8;
  iVar8 = 0;
  uVar6 = 0x80000000;
  do {
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    *(uint *)((int)register0x00000038 + -0x10) = *(int *)((int)register0x00000038 + -0x20) + uVar6;
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0x24);
    *(undefined4 *)((int)register0x00000038 + -0x18) =
         *(undefined4 *)((int)register0x00000038 + -0x28);
    _fpu_cmpli(puVar2,param_1,3);
    if ((int)puVar2 < 1) {
      puVar2 = (undefined *)((int)register0x00000038 + -0x20);
      iVar8 = iVar8 + uVar6;
      _fpu_add3wc(puVar2,*(undefined4 *)((int)register0x00000038 + -0x10),uVar6,0);
      puVar5 = (undefined *)((int)register0x00000038 + -0x24);
      _fpu_add3wc(puVar5,*(undefined4 *)((int)register0x00000038 + -0x14),0,puVar2);
      _fpu_add3wc((undefined *)((int)register0x00000038 + -0x28),
                  *(undefined4 *)((int)register0x00000038 + -0x18),0,puVar5);
      piVar3 = param_2 + 5;
      _fpu_sub3wc(piVar3,param_2[5],*(undefined4 *)((int)register0x00000038 + -0x10),0);
      piVar4 = param_2 + 4;
      _fpu_sub3wc(piVar4,param_2[4],*(undefined4 *)((int)register0x00000038 + -0x14),piVar3);
      _fpu_sub3wc(param_1,*param_1,*(undefined4 *)((int)register0x00000038 + -0x18),piVar4);
      uVar7 = *param_1;
    }
    else {
      uVar7 = *param_1;
    }
    uVar6 = uVar6 >> 1;
    *param_1 = uVar7 << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  } while (uVar6 != 0);
  param_3[5] = iVar8;
  iVar8 = 0;
  uVar6 = 0x80000000;
  do {
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    *(uint *)((int)register0x00000038 + -0xc) = *(int *)((int)register0x00000038 + -0x1c) + uVar6;
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0x20);
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0x24);
    *(undefined4 *)((int)register0x00000038 + -0x18) =
         *(undefined4 *)((int)register0x00000038 + -0x28);
    _fpu_cmpli(puVar2,param_1,4);
    if ((int)puVar2 < 1) {
      puVar2 = (undefined *)((int)register0x00000038 + -0x1c);
      iVar8 = iVar8 + uVar6;
      _fpu_add3wc(puVar2,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6,0);
      puVar5 = (undefined *)((int)register0x00000038 + -0x20);
      _fpu_add3wc(puVar5,*(undefined4 *)((int)register0x00000038 + -0x10),0,puVar2);
      puVar2 = (undefined *)((int)register0x00000038 + -0x24);
      _fpu_add3wc(puVar2,*(undefined4 *)((int)register0x00000038 + -0x14),0,puVar5);
      _fpu_add3wc((undefined *)((int)register0x00000038 + -0x28),
                  *(undefined4 *)((int)register0x00000038 + -0x18),0,puVar2);
      piVar3 = param_2 + 6;
      _fpu_sub3wc(piVar3,param_2[6],*(undefined4 *)((int)register0x00000038 + -0xc),0);
      piVar4 = param_2 + 5;
      _fpu_sub3wc(piVar4,param_2[5],*(undefined4 *)((int)register0x00000038 + -0x10),piVar3);
      piVar3 = param_2 + 4;
      _fpu_sub3wc(piVar3,param_2[4],*(undefined4 *)((int)register0x00000038 + -0x14),piVar4);
      _fpu_sub3wc(param_1,*param_1,*(undefined4 *)((int)register0x00000038 + -0x18),piVar3);
      uVar7 = *param_1;
    }
    else {
      uVar7 = *param_1;
    }
    uVar6 = uVar6 >> 1;
    *param_1 = uVar7 << 1 | (uint)param_2[4] >> 0x1f;
    param_2[4] = param_2[4] << 1 | (uint)param_2[5] >> 0x1f;
    param_2[5] = param_2[5] << 1 | (uint)param_2[6] >> 0x1f;
    param_2[6] = param_2[6] << 1;
  } while (uVar6 != 0);
  param_3[6] = iVar8;
  piVar3 = param_2 + 4;
  piVar4 = param_2 + 5;
  piVar1 = param_2 + 6;
  param_2 = (int *)0x0;
  if (((*param_1 == 0 && *piVar3 == 0) && *piVar4 == 0) && *piVar1 == 0) {
    param_3[7] = 0;
    param_3[8] = 0;
  }
  else {
    param_3[8] = 1;
    puVar2 = (undefined *)((int)register0x00000038 + -0x28);
    _fpu_cmpli(puVar2,param_1,4);
    if ((int)puVar2 < 0) {
      param_3[7] = 1;
    }
    else {
      param_3[7] = 0;
    }
  }
locret_F00AC310:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2533 start=0xf00ac968 */

/* WARNING: Removing unreachable block (ram,0xf00ac994) */

undefined8 _fpu_simulator(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
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
  *(undefined4 *)(param_1 + 0x20) = param_2;
  *(code **)(param_1 + 0x14) = __fp_read_pfreg;
  *(code **)(param_1 + 0x18) = __fp_write_pfreg;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_4;
  sub_F00AC318(param_1,(undefined *)((int)register0x00000038 + -0xc),param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2534 start=0xf00ac9a4 */

/* WARNING: Removing unreachable block (ram,0xf00aca50) */
/* WARNING: Removing unreachable block (ram,0xf00acb20) */
/* WARNING: Removing unreachable block (ram,0xf00acaac) */
/* WARNING: Removing unreachable block (ram,0xf00ac9dc) */

undefined8 _fp_emulator(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
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
  *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_5 + 0x80);
  *(int *)(param_1 + 0x10) = param_5;
  *(code **)(param_1 + 0x14) = __fp_read_vfreg;
  *(code **)(param_1 + 0x18) = __fp_write_vfreg;
  *(int *)(param_1 + 0x20) = param_2;
  iVar1 = param_2;
  __fp_read_word(param_2,(undefined *)((int)register0x00000038 + -0xc),param_1);
  uVar2 = *(uint *)((int)register0x00000038 + -0xc);
  if (iVar1 == 0) {
    if ((uVar2 & 0xc0000000) == 0x80000000) {
      if ((uVar2 & 0x1f80000) == 0x1a00000) goto loc_F00ACAA0;
      if ((uVar2 & 0x1f80000) == 0x1a80000) goto loc_F00ACAA0;
    }
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    while( true ) {
      iVar1 = param_1;
      __fp_iu_simulator(param_1,(undefined *)((int)register0x00000038 + -0x14),param_3,param_4,
                        param_5);
      while( true ) {
        if (iVar1 != 0) goto locret_F00ACB38;
        iVar1 = *(int *)(param_3 + 4);
        *(int *)(param_1 + 0x20) = iVar1;
        __fp_read_word(iVar1,(undefined *)((int)register0x00000038 + -0xc),param_1);
        uVar2 = *(uint *)((int)register0x00000038 + -0xc);
        if (iVar1 != 0) goto locret_F00ACB38;
        if (((uVar2 & 0xc0000000) != 0x80000000) ||
           (((uVar2 & 0x1f80000) != 0x1a00000 && ((uVar2 & 0x1f80000) != 0x1a80000)))) break;
loc_F00ACAA0:
        *(uint *)((int)register0x00000038 + -0x14) = uVar2;
        iVar1 = param_1;
        sub_F00AC318(param_1,(undefined *)((int)register0x00000038 + -0x14),
                     (undefined *)((int)register0x00000038 + -0x10));
        *(undefined4 *)(param_5 + 0x80) = *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_3 + 8);
        *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 4;
      }
      if (((uVar2 & 0xc1c00000) != 0xc1000000) &&
         (((uVar2 & 0xc0000000) != 0 || (((int)uVar2 >> 0x15 & 7U) != 6)))) break;
      *(uint *)((int)register0x00000038 + -0x14) = uVar2;
    }
  }
locret_F00ACB38:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2535 start=0xf00acfcc */

/* WARNING: Removing unreachable block (ram,0xf00ad020) */
/* WARNING: Removing unreachable block (ram,0xf00ad010) */

undefined8
__fp_iu_simulator(undefined *param_1,uint *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar1;
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
  uVar1 = *param_2;
  if (uVar1 >> 0x1e == 0) {
    *(uint *)((int)register0x00000038 + -0xc) = uVar1;
    param_1 = (undefined *)((int)register0x00000038 + -0xc);
    sub_F00ACB40(param_1,param_3,param_5,param_4);
  }
  else if (uVar1 >> 0x1e == 3) {
    *(uint *)((int)register0x00000038 + -0xc) = uVar1;
    sub_F00ACD30(param_1,(undefined *)((int)register0x00000038 + -0xc));
  }
  else {
    param_1 = (undefined *)0x3;
  }
  return CONCAT44(uVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=2536 start=0xf00ad034 */

/* WARNING: Removing unreachable block (ram,0xf00ad4b8) */
/* WARNING: Removing unreachable block (ram,0xf00ad490) */
/* WARNING: Removing unreachable block (ram,0xf00ad3bc) */
/* WARNING: Removing unreachable block (ram,0xf00ad394) */
/* WARNING: Removing unreachable block (ram,0xf00ad2b8) */
/* WARNING: Removing unreachable block (ram,0xf00ad290) */
/* WARNING: Removing unreachable block (ram,0xf00ad1f0) */
/* WARNING: Removing unreachable block (ram,0xf00ad1c8) */
/* WARNING: Removing unreachable block (ram,0xf00ad1dc) */
/* WARNING: Removing unreachable block (ram,0xf00ad204) */
/* WARNING: Removing unreachable block (ram,0xf00ad2a4) */
/* WARNING: Removing unreachable block (ram,0xf00ad2cc) */
/* WARNING: Removing unreachable block (ram,0xf00ad3a8) */
/* WARNING: Removing unreachable block (ram,0xf00ad3d0) */
/* WARNING: Removing unreachable block (ram,0xf00ad4a4) */
/* WARNING: Removing unreachable block (ram,0xf00ad4cc) */
/* WARNING: Removing unreachable block (ram,0xf00ad108) */

undefined8 __fp_mul(uint param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  uint *puVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
  undefined4 unaff_i1;
  uint *puVar9;
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
  if ((int)param_2[1] < (int)param_3[1]) {
    uVar1 = *param_3;
    puVar9 = param_3;
  }
  else {
    uVar1 = *param_2;
    puVar9 = param_2;
    param_2 = param_3;
  }
  *param_4 = uVar1;
  param_4[1] = puVar9[1];
  param_4[2] = puVar9[2];
  param_4[3] = puVar9[3];
  param_4[4] = puVar9[4];
  param_4[5] = puVar9[5];
  param_4[6] = puVar9[6];
  param_4[7] = puVar9[7];
  param_4[8] = puVar9[8];
  if ((int)param_4[1] < 4) {
    *param_4 = *puVar9 ^ *param_2;
  }
  switch(puVar9[1]) {
  case :
  case :
  case :
    goto locret_F00AD5A8;
  case :
    if (param_2[1] == 0) {
      param_4[1] = 0;
      goto locret_F00AD5A8;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    break;
  case :
    if (param_2[1] == 0) {
      _fpu_error_nan(param_1,param_4);
      param_4[1] = 4;
    }
    goto locret_F00AD5A8;
  :
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  }
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  uVar1 = 0;
  uVar7 = param_2[6];
  uVar6 = 0;
  puVar5 = puVar9 + 3;
  if (uVar7 != 0) {
    uVar8 = 1;
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    while( true ) {
      uVar6 = uVar6 | uVar1;
      uVar1 = uVar2 & 1;
      uVar2 = *(uint *)((int)register0x00000038 + -0x10) << 0x1f | uVar2 >> 1;
      *(uint *)((int)register0x00000038 + -0xc) = uVar2;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x14) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x10) >> 1;
      *(uint *)((int)register0x00000038 + -0x14) =
           *(uint *)((int)register0x00000038 + -0x18) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x14) >> 1;
      *(uint *)((int)register0x00000038 + -0x18) = *(uint *)((int)register0x00000038 + -0x18) >> 1;
      if ((uVar8 & uVar7) != 0) {
        puVar3 = (undefined *)((int)register0x00000038 + -0xc);
        _fpu_add3wc(puVar3,uVar2,puVar9[6],0);
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        _fpu_add3wc(puVar4,*(undefined4 *)((int)register0x00000038 + -0x10),puVar9[5],puVar3);
        puVar3 = (undefined *)((int)register0x00000038 + -0x14);
        _fpu_add3wc(puVar3,*(undefined4 *)((int)register0x00000038 + -0x14),puVar9[4],puVar4);
        _fpu_add3wc((undefined *)((int)register0x00000038 + -0x18),
                    *(undefined4 *)((int)register0x00000038 + -0x18),*puVar5,puVar3);
      }
      uVar8 = uVar8 * 2;
      if (uVar8 == 0) break;
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    }
  }
  uVar8 = param_2[5];
  uVar7 = 1;
  if (uVar8 == 0) {
    uVar6 = uVar6 | uVar1 | *(uint *)((int)register0x00000038 + -0xc) & 0x7fffffff;
    uVar1 = *(uint *)((int)register0x00000038 + -0xc) >> 0x1f;
    *(undefined4 *)((int)register0x00000038 + -0xc) =
         *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0x14);
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    uVar7 = param_2[4];
  }
  else {
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    do {
      uVar6 = uVar6 | uVar1;
      uVar1 = uVar2 & 1;
      uVar2 = *(uint *)((int)register0x00000038 + -0x10) << 0x1f | uVar2 >> 1;
      *(uint *)((int)register0x00000038 + -0xc) = uVar2;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x14) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x10) >> 1;
      *(uint *)((int)register0x00000038 + -0x14) =
           *(uint *)((int)register0x00000038 + -0x18) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x14) >> 1;
      *(uint *)((int)register0x00000038 + -0x18) = *(uint *)((int)register0x00000038 + -0x18) >> 1;
      if ((uVar7 & uVar8) != 0) {
        puVar3 = (undefined *)((int)register0x00000038 + -0xc);
        _fpu_add3wc(puVar3,uVar2,puVar9[6],0);
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        _fpu_add3wc(puVar4,*(undefined4 *)((int)register0x00000038 + -0x10),puVar9[5],puVar3);
        puVar3 = (undefined *)((int)register0x00000038 + -0x14);
        _fpu_add3wc(puVar3,*(undefined4 *)((int)register0x00000038 + -0x14),puVar9[4],puVar4);
        _fpu_add3wc((undefined *)((int)register0x00000038 + -0x18),
                    *(undefined4 *)((int)register0x00000038 + -0x18),*puVar5,puVar3);
      }
      uVar7 = uVar7 * 2;
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    } while (uVar7 != 0);
    uVar7 = param_2[4];
  }
  uVar8 = 1;
  if (uVar7 == 0) {
    uVar6 = uVar6 | uVar1 | *(uint *)((int)register0x00000038 + -0xc) & 0x7fffffff;
    uVar1 = *(uint *)((int)register0x00000038 + -0xc) >> 0x1f;
    *(undefined4 *)((int)register0x00000038 + -0xc) =
         *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0x14);
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    uVar7 = param_2[3];
  }
  else {
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    do {
      uVar6 = uVar6 | uVar1;
      uVar1 = uVar2 & 1;
      uVar2 = *(uint *)((int)register0x00000038 + -0x10) << 0x1f | uVar2 >> 1;
      *(uint *)((int)register0x00000038 + -0xc) = uVar2;
      *(uint *)((int)register0x00000038 + -0x10) =
           *(uint *)((int)register0x00000038 + -0x14) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x10) >> 1;
      *(uint *)((int)register0x00000038 + -0x14) =
           *(uint *)((int)register0x00000038 + -0x18) << 0x1f |
           *(uint *)((int)register0x00000038 + -0x14) >> 1;
      *(uint *)((int)register0x00000038 + -0x18) = *(uint *)((int)register0x00000038 + -0x18) >> 1;
      if ((uVar8 & uVar7) != 0) {
        puVar3 = (undefined *)((int)register0x00000038 + -0xc);
        _fpu_add3wc(puVar3,uVar2,puVar9[6],0);
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        _fpu_add3wc(puVar4,*(undefined4 *)((int)register0x00000038 + -0x10),puVar9[5],puVar3);
        puVar3 = (undefined *)((int)register0x00000038 + -0x14);
        _fpu_add3wc(puVar3,*(undefined4 *)((int)register0x00000038 + -0x14),puVar9[4],puVar4);
        _fpu_add3wc((undefined *)((int)register0x00000038 + -0x18),
                    *(undefined4 *)((int)register0x00000038 + -0x18),*puVar5,puVar3);
      }
      uVar8 = uVar8 * 2;
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    } while (uVar8 != 0);
    uVar7 = param_2[3];
  }
  param_1 = 1;
  uVar8 = *(uint *)((int)register0x00000038 + -0xc);
  do {
    uVar6 = uVar6 | uVar1;
    uVar1 = uVar8 & 1;
    uVar8 = *(uint *)((int)register0x00000038 + -0x10) << 0x1f | uVar8 >> 1;
    *(uint *)((int)register0x00000038 + -0xc) = uVar8;
    *(uint *)((int)register0x00000038 + -0x10) =
         *(uint *)((int)register0x00000038 + -0x14) << 0x1f |
         *(uint *)((int)register0x00000038 + -0x10) >> 1;
    *(uint *)((int)register0x00000038 + -0x14) =
         *(uint *)((int)register0x00000038 + -0x18) << 0x1f |
         *(uint *)((int)register0x00000038 + -0x14) >> 1;
    *(uint *)((int)register0x00000038 + -0x18) = *(uint *)((int)register0x00000038 + -0x18) >> 1;
    if ((param_1 & uVar7) != 0) {
      puVar3 = (undefined *)((int)register0x00000038 + -0xc);
      _fpu_add3wc(puVar3,uVar8,puVar9[6],0);
      puVar4 = (undefined *)((int)register0x00000038 + -0x10);
      _fpu_add3wc(puVar4,*(undefined4 *)((int)register0x00000038 + -0x10),puVar9[5],puVar3);
      puVar3 = (undefined *)((int)register0x00000038 + -0x14);
      _fpu_add3wc(puVar3,*(undefined4 *)((int)register0x00000038 + -0x14),puVar9[4],puVar4);
      _fpu_add3wc((undefined *)((int)register0x00000038 + -0x18),
                  *(undefined4 *)((int)register0x00000038 + -0x18),*puVar5,puVar3);
    }
    param_1 = param_1 * 2;
    uVar8 = *(uint *)((int)register0x00000038 + -0xc);
  } while (param_1 < uVar7 || param_1 - uVar7 == 0);
  if (*(uint *)((int)register0x00000038 + -0x18) < 0x20000) {
    param_4[2] = puVar9[2] + param_2[2];
    param_4[8] = uVar6;
    param_4[7] = uVar1;
    param_4[6] = *(uint *)((int)register0x00000038 + -0xc);
    param_4[5] = *(uint *)((int)register0x00000038 + -0x10);
    param_4[4] = *(uint *)((int)register0x00000038 + -0x14);
    uVar1 = *(uint *)((int)register0x00000038 + -0x18);
  }
  else {
    param_4[2] = puVar9[2] + param_2[2] + 1;
    param_4[8] = uVar6 | uVar1;
    param_4[7] = *(uint *)((int)register0x00000038 + -0xc) & 1;
    param_4[6] = *(int *)((int)register0x00000038 + -0x10) << 0x1f |
                 *(uint *)((int)register0x00000038 + -0xc) >> 1;
    param_4[5] = *(int *)((int)register0x00000038 + -0x14) << 0x1f |
                 *(uint *)((int)register0x00000038 + -0x10) >> 1;
    param_4[4] = *(int *)((int)register0x00000038 + -0x18) << 0x1f |
                 *(uint *)((int)register0x00000038 + -0x14) >> 1;
    uVar1 = *(uint *)((int)register0x00000038 + -0x18) >> 1;
  }
  param_4[3] = uVar1;
locret_F00AD5A8:
  return CONCAT44(puVar9,param_1);
}
/* GHIDRADEC_FUNCTION index=2537 start=0xf00adff0 */

/* WARNING: Removing unreachable block (ram,0xf00ae158) */
/* WARNING: Removing unreachable block (ram,0xf00ae120) */
/* WARNING: Removing unreachable block (ram,0xf00ae1b4) */
/* WARNING: Removing unreachable block (ram,0xf00ae18c) */
/* WARNING: Removing unreachable block (ram,0xf00ae024) */
/* WARNING: Removing unreachable block (ram,0xf00ae084) */
/* WARNING: Removing unreachable block (ram,0xf00ae198) */
/* WARNING: Removing unreachable block (ram,0xf00ae104) */
/* WARNING: Removing unreachable block (ram,0xf00ae138) */
/* WARNING: Removing unreachable block (ram,0xf00ae1e0) */
/* WARNING: Removing unreachable block (ram,0xf00ae050) */

undefined8 __fp_pack(uint *param_1,undefined *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar4;
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
  if (param_4 == 1) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x10);
    sub_F00AD810(param_1,param_2,puVar3);
    uVar1 = param_1[3] & *param_1;
joined_r0xf00ae064:
    if (uVar1 != 0) goto locret_F00AE254;
  }
  else {
    if (param_4 < 2) {
      puVar3 = (undefined *)((int)register0x00000038 + -0xc);
      sub_F00AD718(param_1,param_2,puVar3);
      uVar1 = param_1[3] & *param_1;
      goto joined_r0xf00ae064;
    }
    if (param_4 == 2) {
      puVar3 = (undefined *)((int)register0x00000038 + -0x18);
      sub_F00ADABC(param_1,param_2,(undefined *)((int)register0x00000038 + -0x14),puVar3);
      param_2 = puVar3;
      if ((param_1[3] & *param_1) != 0) goto locret_F00AE254;
      (*(code *)param_1[6])((undefined *)((int)register0x00000038 + -0x14),param_3 & 0xfffe,param_1)
      ;
      param_3 = (param_3 & 0xfffe) + 1;
    }
    else {
      if (param_4 != 3) goto locret_F00AE254;
      uVar1 = param_1[2];
      if (uVar1 == 2) {
        sub_F00ADABC(param_1,param_2,(undefined *)((int)register0x00000038 + -0x4c),
                     (undefined *)((int)register0x00000038 + -0x50));
        param_2 = (undefined *)((int)register0x00000038 + -0x40);
        *(undefined4 *)((int)register0x00000038 + -0x48) =
             *(undefined4 *)((int)register0x00000038 + -0x4c);
        _unpackdouble(param_1,param_2,(undefined *)((int)register0x00000038 + -0x48),
                      *(undefined4 *)((int)register0x00000038 + -0x50));
      }
      else if (uVar1 < 3) {
        if (uVar1 == 1) {
          sub_F00AD810(param_1,param_2,(undefined *)((int)register0x00000038 + -0x44));
          param_2 = (undefined *)((int)register0x00000038 + -0x40);
          *(undefined4 *)((int)register0x00000038 + -0x48) =
               *(undefined4 *)((int)register0x00000038 + -0x44);
          _unpacksingle(param_1,param_2,(undefined *)((int)register0x00000038 + -0x48));
        }
      }
      else if (uVar1 == 3) {
        if (*(int *)(param_2 + 8) + 0x3fff < 0) {
          iVar2 = 0x31 - (*(int *)(param_2 + 8) + 0x3fff);
        }
        else {
          iVar2 = 0x31;
        }
        _fpu_rightshift(param_2,0x31);
        sub_F00AD5F8(param_1,param_2);
        *(undefined4 *)(param_2 + 0x1c) = 0;
        *(undefined4 *)(param_2 + 0x20) = 0;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + iVar2;
        _fpu_normalize(param_2);
      }
      puVar4 = (undefined *)((int)register0x00000038 + -0x58);
      puVar3 = (undefined *)((int)register0x00000038 + -0x60);
      sub_F00ADD98(param_1,param_2,(undefined *)((int)register0x00000038 + -0x54),puVar4,
                   (undefined *)((int)register0x00000038 + -0x5c),puVar3);
      param_2 = puVar4;
      if ((param_1[3] & *param_1) != 0) goto locret_F00AE254;
      param_3 = param_3 & 0xfffc;
      (*(code *)param_1[6])((undefined *)((int)register0x00000038 + -0x54),param_3,param_1);
      (*(code *)param_1[6])(puVar4,param_3 + 1,param_1);
      (*(code *)param_1[6])((undefined *)((int)register0x00000038 + -0x5c),param_3 + 2,param_1);
      param_3 = param_3 + 3;
    }
  }
  (*(code *)param_1[6])(puVar3,param_3,param_1);
locret_F00AE254:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2538 start=0xf00ae25c */

undefined8 __fp_pack_word(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  (**(code **)(param_1 + 0x18))(param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2539 start=0xf00ae2e8 */

/* WARNING: Removing unreachable block (ram,0xf00ae344) */
/* WARNING: Removing unreachable block (ram,0xf00ae394) */

undefined8 _unpacksingle(undefined4 param_1,uint *param_2,uint *param_3)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar2;
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
  uVar2 = *param_3;
  param_2[7] = 0;
  param_2[8] = 0;
  *param_2 = uVar2 >> 0x1f;
  param_2[4] = 0;
  param_2[5] = 0;
  uVar1 = uVar2 & 0x7fffff;
  param_2[6] = 0;
  if ((uVar2 & 0x7f800000) == 0) {
    if (uVar1 == 0) {
      param_2[1] = 0;
    }
    else {
      param_2[1] = 1;
      param_2[2] = 0xffffff7b;
      param_2[3] = uVar1;
      _fpu_normalize(param_2);
    }
  }
  else {
    if ((uVar2 & 0x7f800000) == 0x7f800000) {
      if (uVar1 == 0) {
        param_2[1] = 2;
        goto locret_F00AE3E0;
      }
      if ((uVar2 & 0x400000) == 0) {
        param_2[1] = 5;
        _fpu_set_exception(param_1,4);
      }
      else {
        param_2[1] = 4;
      }
      param_2[3] = uVar1 >> 7 | 0x18000;
    }
    else {
      param_2[2] = (uVar2 >> 0x17 & 0xff) - 0x7f;
      param_2[1] = 1;
      param_2[3] = uVar1 >> 7 | 0x10000;
      uVar1 = uVar2;
    }
    param_2[4] = uVar1 << 0x19;
  }
locret_F00AE3E0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2540 start=0xf00ae3e8 */

/* WARNING: Removing unreachable block (ram,0xf00ae450) */
/* WARNING: Removing unreachable block (ram,0xf00ae4a0) */

undefined8 _unpackdouble(undefined4 param_1,uint *param_2,uint *param_3,uint param_4)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar2;
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
  uVar2 = *param_3;
  param_2[7] = 0;
  param_2[8] = 0;
  *param_2 = uVar2 >> 0x1f;
  param_2[4] = param_4;
  param_2[5] = 0;
  uVar1 = uVar2 & 0xfffff;
  param_2[6] = 0;
  if ((uVar2 & 0x7ff00000) == 0) {
    if (uVar1 == 0) {
      if (param_4 == 0) {
        param_2[1] = 0;
        goto locret_F00AE4FC;
      }
      param_2[1] = 1;
    }
    else {
      param_2[1] = 1;
    }
    param_2[2] = 0xfffffbfe;
    param_2[3] = uVar1;
    _fpu_normalize(param_2);
  }
  else {
    if ((uVar2 & 0x7ff00000) == 0x7ff00000) {
      if (uVar1 == 0 && param_4 == 0) {
        param_2[1] = 2;
        goto locret_F00AE4FC;
      }
      if ((uVar2 & 0x80000) == 0) {
        param_2[1] = 5;
        _fpu_set_exception(param_1,4);
      }
      else {
        param_2[1] = 4;
      }
      param_2[3] = uVar1 >> 4 | 0x18000;
    }
    else {
      param_2[2] = (uVar2 >> 0x14 & 0x7ff) - 0x3ff;
      param_2[1] = 1;
      param_2[3] = uVar1 >> 4 | 0x10000;
      uVar1 = uVar2;
    }
    param_2[4] = uVar1 << 0x1c | param_4 >> 4;
    param_2[5] = param_4 << 0x1c;
  }
locret_F00AE4FC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2541 start=0xf00ae620 */

/* WARNING: Removing unreachable block (ram,0xf00ae770) */
/* WARNING: Removing unreachable block (ram,0xf00ae6f0) */
/* WARNING: Removing unreachable block (ram,0xf00ae670) */
/* WARNING: Removing unreachable block (ram,0xf00ae69c) */

undefined8 __fp_unpack(int param_1,undefined4 param_2,uint param_3,int param_4)

{
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
  if (param_4 == 1) {
    (**(code **)(param_1 + 0x14))((undefined *)((int)register0x00000038 + -0xc),param_3,param_1);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    _unpacksingle(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10));
  }
  else if (param_4 < 2) {
    if (param_4 == 0) {
      (**(code **)(param_1 + 0x14))((undefined *)((int)register0x00000038 + -0xc),param_3,param_1);
      sub_F00AE27C(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
    }
  }
  else if (param_4 == 2) {
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0xc),param_3 & 0xfffe,param_1);
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0x14),(param_3 & 0xfffe) + 1,param_1);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    _unpackdouble(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10),
                  *(undefined4 *)((int)register0x00000038 + -0x14));
  }
  else if (param_4 == 3) {
    param_3 = param_3 & 0xfffc;
    (**(code **)(param_1 + 0x14))((undefined *)((int)register0x00000038 + -0xc),param_3,param_1);
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0x14),param_3 + 1,param_1);
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0x18),param_3 + 2,param_1);
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0x1c),param_3 + 3,param_1);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    sub_F00AE504(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10),
                 *(undefined4 *)((int)register0x00000038 + -0x14),
                 *(undefined4 *)((int)register0x00000038 + -0x18),
                 *(undefined4 *)((int)register0x00000038 + -0x1c));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2542 start=0xf00ae780 */

undefined8 __fp_unpack_word(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  (**(code **)(param_1 + 0x14))(param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2543 start=0xf00ae7a0 */

undefined8 __fp_read_vfreg(undefined4 *param_1,int param_2,int param_3)

{
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
  *param_1 = *(undefined4 *)(*(int *)(param_3 + 0x10) + param_2 * 4);
  return CONCAT44(param_2 * 4,param_1);
}
/* GHIDRADEC_FUNCTION index=2544 start=0xf00ae7bc */

undefined8 __fp_write_vfreg(undefined4 *param_1,int param_2,int param_3)

{
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
  *(undefined4 *)(*(int *)(param_3 + 0x10) + param_2 * 4) = *param_1;
  return CONCAT44(param_2 * 4,param_1);
}
/* GHIDRADEC_FUNCTION index=2545 start=0xf00ae7d8 */

undefined8 _fpu_normalize(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
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
  int iVar4;
  byte bVar5;
  undefined4 unaff_i3;
  byte bVar6;
  undefined4 unaff_i4;
  uint uVar7;
  undefined4 unaff_i5;
  uint uVar8;
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
  uVar8 = *(uint *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar3 = *(uint *)(param_1 + 0x18);
  if (*(int *)(param_1 + 4) != 1) goto locret_F00AE958;
  uVar7 = *(uint *)(param_1 + 0x10);
  if (((uVar8 == 0 && *(uint *)(param_1 + 0x10) == 0) && uVar2 == 0) && uVar3 == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
    goto locret_F00AE958;
  }
  while (uVar1 = uVar7, uVar8 == 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
    uVar7 = uVar2;
    uVar2 = uVar3;
    uVar3 = 0;
    uVar8 = uVar1;
  }
  param_2 = uVar8 >> 1;
  if (uVar8 < 0x20000) {
    if (uVar8 < 0x10000) {
      iVar4 = 1;
      param_2 = uVar8;
      while (param_2 = param_2 * 2, param_2 < 0x10000) {
        iVar4 = iVar4 + 1;
      }
      bVar5 = (byte)iVar4;
      bVar6 = 0x20 - bVar5;
      uVar7 = -1 << (bVar6 & 0x1f);
      uVar8 = uVar8 << (bVar5 & 0x1f) | (uVar1 & uVar7) >> (bVar6 & 0x1f);
      uVar1 = uVar1 << (bVar5 & 0x1f) | (uVar2 & uVar7) >> (bVar6 & 0x1f);
      uVar2 = uVar2 << (bVar5 & 0x1f) | (uVar3 & uVar7) >> (bVar6 & 0x1f);
      uVar3 = uVar3 << (bVar5 & 0x1f);
      iVar4 = *(int *)(param_1 + 8) - iVar4;
      goto loc_F00AE944;
    }
    *(uint *)(param_1 + 0xc) = uVar8;
  }
  else {
    iVar4 = 1;
    for (; 0x1ffff < param_2; param_2 = param_2 >> 1) {
      iVar4 = iVar4 + 1;
    }
    bVar5 = (byte)iVar4;
    uVar7 = (1 << (bVar5 & 0x1f)) - 1;
    bVar6 = 0x20 - bVar5;
    uVar3 = (uVar2 & uVar7) << (bVar6 & 0x1f) | uVar3 >> (bVar5 & 0x1f);
    uVar2 = (uVar1 & uVar7) << (bVar6 & 0x1f) | uVar2 >> (bVar5 & 0x1f);
    uVar1 = (uVar8 & uVar7) << (bVar6 & 0x1f) | uVar1 >> (bVar5 & 0x1f);
    iVar4 = *(int *)(param_1 + 8) + iVar4;
    uVar8 = param_2;
loc_F00AE944:
    *(int *)(param_1 + 8) = iVar4;
    *(uint *)(param_1 + 0xc) = uVar8;
  }
  *(uint *)(param_1 + 0x10) = uVar1;
  *(uint *)(param_1 + 0x14) = uVar2;
  *(uint *)(param_1 + 0x18) = uVar3;
locret_F00AE958:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2546 start=0xf00ae960 */

undefined8 _fpu_rightshift(uint param_1,uint param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  undefined4 unaff_i1;
  uint uVar3;
  undefined4 unaff_i2;
  byte bVar4;
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
  uVar2 = param_1;
  uVar3 = param_2;
  if ((int)param_2 < 0x72) {
    for (; 0x1f < (int)uVar3; uVar3 = uVar3 - 0x20) {
      *(uint *)(param_1 + 0x20) =
           *(uint *)(param_1 + 0x20) |
           *(uint *)(param_1 + 0x1c) | *(uint *)(param_1 + 0x18) & 0x7fffffff;
      uVar2 = *(uint *)(param_1 + 0x10);
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x18) >> 0x1f;
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
      *(uint *)(param_1 + 0x14) = uVar2;
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    param_2 = 1;
    if (0 < (int)uVar3) {
      bVar1 = (byte)uVar3;
      uVar2 = *(uint *)(param_1 + 0x18);
      uVar3 = (1 << (bVar1 & 0x1f)) - 1;
      *(uint *)(param_1 + 0x20) =
           *(uint *)(param_1 + 0x20) |
           *(uint *)(param_1 + 0x1c) | uVar2 & (1 << (bVar1 - 1 & 0x1f)) - 1U;
      *(uint *)(param_1 + 0x1c) = (uVar2 & uVar3) >> (bVar1 - 1 & 0x1f);
      bVar4 = 0x20 - bVar1;
      *(uint *)(param_1 + 0x18) =
           (*(uint *)(param_1 + 0x14) & uVar3) << (bVar4 & 0x1f) | uVar2 >> (bVar1 & 0x1f);
      *(uint *)(param_1 + 0x14) =
           (*(uint *)(param_1 + 0x10) & uVar3) << (bVar4 & 0x1f) |
           *(uint *)(param_1 + 0x14) >> (bVar1 & 0x1f);
      uVar2 = *(uint *)(param_1 + 0x10) >> (bVar1 & 0x1f);
      param_2 = (*(uint *)(param_1 + 0xc) & uVar3) << (bVar4 & 0x1f) | uVar2;
      *(uint *)(param_1 + 0x10) = param_2;
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) >> (bVar1 & 0x1f);
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x14);
    if (((*(int *)(param_1 + 0xc) == 0 && *(int *)(param_1 + 0x10) == 0) && uVar2 == 0) &&
        *(int *)(param_1 + 0x18) == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x20) = 1;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2547 start=0xf00aeac4 */

undefined8 _fpu_set_exception(int param_1,undefined4 param_2)

{
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
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1 << ((byte)param_2 & 0x1f);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2548 start=0xf00aeae4 */

/* WARNING: Removing unreachable block (ram,0xf00aeaec) */

undefined8 _fpu_error_nan(undefined4 param_1,undefined4 *param_2)

{
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
  _fpu_set_exception(param_1,4);
  *param_2 = 0;
  param_2[3] = 0x7fffffff;
  param_2[4] = 0xffffffff;
  param_2[5] = 0xffffffff;
  param_2[6] = 0xffffffff;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2549 start=0xf00aeb1c */

undefined8 _fpu_add3wc(uint *param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
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
  bool bVar2;
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
  uVar1 = param_2 + param_3;
  if (param_4 == 0) {
    *param_1 = uVar1;
    bVar2 = uVar1 < param_3;
  }
  else {
    *param_1 = uVar1 + 1;
    bVar2 = uVar1 + 1 <= param_3;
  }
  return CONCAT44(param_2,(uint)bVar2);
}

