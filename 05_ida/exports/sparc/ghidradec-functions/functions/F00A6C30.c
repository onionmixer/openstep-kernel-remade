
/* WARNING: Removing unreachable block (ram,0xf00a6d74) */
/* WARNING: Removing unreachable block (ram,0xf00a6d4c) */
/* WARNING: Removing unreachable block (ram,0xf00a6d20) */
/* WARNING: Removing unreachable block (ram,0xf00a6cfc) */
/* WARNING: Removing unreachable block (ram,0xf00a6cd0) */
/* WARNING: Removing unreachable block (ram,0xf00a6ca4) */
/* WARNING: Removing unreachable block (ram,0xf00a6c8c) */
/* WARNING: Removing unreachable block (ram,0xf00a6c94) */
/* WARNING: Removing unreachable block (ram,0xf00a6cb0) */
/* WARNING: Removing unreachable block (ram,0xf00a6ce0) */
/* WARNING: Removing unreachable block (ram,0xf00a6d08) */
/* WARNING: Removing unreachable block (ram,0xf00a6d30) */
/* WARNING: Removing unreachable block (ram,0xf00a6d60) */
/* WARNING: Removing unreachable block (ram,0xf00a6d84) */
/* WARNING: Removing unreachable block (ram,0xf00a6d14) */
/* WARNING: Removing unreachable block (ram,0xf00a6c64) */

undefined8 _p4m35_ebe_handler(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
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
  bool bVar4;
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
  if (param_1 == 0) {
    uVar1 = 0x6000;
    if ((param_2 & 0x6000) != 0) {
      _printf(aSynchronousPar);
      if ((param_2 >> 2 & 7) == 4) {
        puVar3 = aParityErrorDur;
loc_F00A6CFC:
        _panic(puVar3);
      }
      else {
        _printf(aAttemptingReco);
        param_1 = param_3;
        _p4m35_parerr_reset(param_3);
        param_1 = ~param_1;
        bVar4 = param_1 != 0;
        _mmu_getctx();
        uVar1 = param_3;
        _mmu_probe();
        *(uint *)((int)register0x00000038 + -0xc) = uVar1;
        _printf(aCtx0xXVaddr0xX,param_1,param_3,uVar1,bVar4);
        _p4m35_parerr_recover(param_3,(undefined *)((int)register0x00000038 + -0xc),bVar4);
        if (param_3 == 0xffffffff) {
          puVar3 = aUnrecoverableP;
          goto loc_F00A6CFC;
        }
      }
      _printf(aSystemOperatio);
      goto locret_F00A6D8C;
    }
    _mmu_getctx();
    uVar2 = param_3;
    _mmu_probe();
    *(uint *)((int)register0x00000038 + -0xc) = uVar2;
    _printf(aNonParitySynch);
    _printf(aCtx0xXVaddr0xX_0,uVar1,param_3,*(undefined4 *)((int)register0x00000038 + -0xc),param_2)
    ;
    puVar3 = aSyncMemoryErro;
    param_1 = uVar1;
  }
  else {
    if (param_1 != 1) goto locret_F00A6D8C;
    _printf(aAsynchronousMe);
    _printf(aAddr0xXReg0xX,param_3,param_2);
    puVar3 = aAsyncMemoryErr;
  }
  _panic(puVar3);
locret_F00A6D8C:
  return CONCAT44(param_2,param_1);
}
