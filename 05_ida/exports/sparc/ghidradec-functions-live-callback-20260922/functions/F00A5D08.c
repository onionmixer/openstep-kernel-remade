
/* WARNING: Removing unreachable block (ram,0xf00a5e6c) */
/* WARNING: Removing unreachable block (ram,0xf00a5e48) */
/* WARNING: Removing unreachable block (ram,0xf00a5e30) */
/* WARNING: Removing unreachable block (ram,0xf00a5e14) */
/* WARNING: Removing unreachable block (ram,0xf00a5de4) */
/* WARNING: Removing unreachable block (ram,0xf00a5e00) */
/* WARNING: Removing unreachable block (ram,0xf00a5e20) */
/* WARNING: Removing unreachable block (ram,0xf00a5e3c) */
/* WARNING: Removing unreachable block (ram,0xf00a5e5c) */
/* WARNING: Removing unreachable block (ram,0xf00a5ea4) */
/* WARNING: Removing unreachable block (ram,0xf00a5dcc) */

undefined8 _process_aflt(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 uVar5;
  undefined4 unaff_l1;
  undefined4 uVar6;
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
  bool bVar7;
  bool bVar8;
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
  if (*(int *)((int)&_a_head + _cpuid * 4) != *(int *)((int)&_a_tail + _cpuid * 4)) {
    do {
      iVar4 = _cpuid;
      bVar8 = false;
      uVar1 = *(int *)((int)&_a_tail + _cpuid * 4) + 1U & 0x3f;
      *(uint *)((int)&_a_tail + _cpuid * 4) = uVar1;
      iVar4 = uVar1 * 0x18 + iVar4 * 0x600;
      uVar1 = *(uint *)(_a_flts + iVar4 + 4);
      uVar5 = *(undefined4 *)(_a_flts + iVar4 + 8);
      uVar6 = *(undefined4 *)(_a_flts + iVar4 + 0xc);
      if (*(sword *)(_a_flts + iVar4) == 2) {
        bVar8 = (uVar1 & 1) != 0;
        _log_mem_err(uVar1,uVar5,uVar6,0);
        if ((uVar1 & 8) == 0) goto loc_F00A5E74;
        uVar2 = uVar1;
        _fix_nc_ecc(uVar1,uVar5,uVar6);
        bVar7 = !bVar8;
        if (uVar2 == 0xffffffff) {
          _printf(aAfsr0xX,uVar1);
          _printf(aAfar00xXAfar10,uVar5,uVar6);
          _panic(aAsynchronousFa);
          bVar7 = !bVar8;
        }
      }
      else if (*(sword *)(_a_flts + iVar4) == 4) {
        _printf(aMToSAsynchrono);
        _printf(aDueToUserWrite);
        _log_mtos_err(uVar1,uVar5);
        _psignal(*_active_u,10);
        _exception(1,0x309,uVar5);
loc_F00A5E74:
        bVar7 = !bVar8;
      }
      else {
        bVar7 = true;
      }
      if (bVar7) {
        puVar3 = aAfsr0xXAfar00x;
loc_F00A5E9C:
        _printf(puVar3,uVar1,uVar5,uVar6);
      }
      else if (_log_ce_error != 0) {
        puVar3 = aAfsr0xXAfar00x_0;
        goto loc_F00A5E9C;
      }
      _log_ce_error = 0;
    } while (*(int *)((int)&_a_head + _cpuid * 4) != *(int *)((int)&_a_tail + _cpuid * 4));
  }
  return CONCAT44(param_2,1);
}

