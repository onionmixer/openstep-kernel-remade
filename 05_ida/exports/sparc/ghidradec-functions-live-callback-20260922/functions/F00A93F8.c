
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

