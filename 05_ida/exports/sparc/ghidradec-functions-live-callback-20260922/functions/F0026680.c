
/* WARNING: Removing unreachable block (ram,0xf002678c) */
/* WARNING: Removing unreachable block (ram,0xf0026758) */
/* WARNING: Removing unreachable block (ram,0xf0026824) */
/* WARNING: Removing unreachable block (ram,0xf00267d8) */
/* WARNING: Removing unreachable block (ram,0xf00266f0) */

undefined8 _vno_bsd_lock(int param_1,uint param_2)

{
  uint uVar1;
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
  undefined4 uVar4;
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
  *(int *)((int)register0x00000038 + -0x14) = param_1;
  uVar1 = *(uint *)(param_1 + 8);
  *(uint *)((int)register0x00000038 + 0x48) = param_2;
  if ((((uVar1 & 0x100) == 0) || (uVar4 = 0, (param_2 & 2) == 0)) &&
     (((uVar1 & 0x80) == 0 || (uVar4 = 0, (param_2 & 1) == 0)))) {
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x23;
    *(undefined4 *)((int)register0x00000038 + -0x1c) =
         *(undefined4 *)(*(int *)((int)register0x00000038 + -0x14) + 0x18);
    if ((*(uint *)((int)register0x00000038 + 0x48) & 2) == 0) {
      *(int *)((int)register0x00000038 + -0xc) = *(int *)((int)register0x00000038 + -0xc) + 1;
    }
    iVar2 = dword_F0133DDC + 0x28;
    _setjmp();
    iVar3 = *(int *)((int)register0x00000038 + -0x1c);
    if (iVar2 == 0) {
      while( true ) {
        while ((*(word *)(iVar3 + 4) & 4) != 0) {
          if ((*(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) & 0x100) == 0) {
            iVar2 = *(int *)((int)register0x00000038 + -0x1c);
            if ((*(uint *)((int)register0x00000038 + 0x48) & 4) != 0) goto loc_F00267F4;
            uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
            iVar3 = iVar2 + 10;
            *(word *)(iVar2 + 4) = *(word *)(iVar2 + 4) | 0x10;
            goto loc_F002678C;
          }
          _vno_bsd_unlock(*(undefined4 *)((int)register0x00000038 + -0x14),0x100);
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
        }
        if ((*(uint *)((int)register0x00000038 + 0x48) & 2) == 0) break;
        if ((*(word *)(*(int *)((int)register0x00000038 + -0x1c) + 4) & 8) == 0) break;
        if ((*(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) & 0x80) == 0) {
          if ((*(uint *)((int)register0x00000038 + 0x48) & 4) != 0) {
loc_F00267F4:
            uVar4 = 0x23;
            goto locret_F00268B8;
          }
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
          uVar4 = 0x23;
          *(word *)(iVar3 + 4) = *(word *)(*(int *)((int)register0x00000038 + -0x1c) + 4) | 0x10;
          iVar3 = iVar3 + 8;
loc_F002678C:
          _sleep(iVar3,uVar4);
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
        }
        else {
          _vno_bsd_unlock(*(undefined4 *)((int)register0x00000038 + -0x14),0x80);
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
        }
      }
      if ((*(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) & 0x100) != 0) {
        _panic(aVnoBsdLock);
      }
      uVar1 = *(uint *)((int)register0x00000038 + 0x48);
      if ((uVar1 & 2) != 0) {
        iVar2 = *(int *)((int)register0x00000038 + -0x1c);
        *(sword *)(iVar2 + 10) = *(sword *)(iVar2 + 10) + 1;
        *(word *)(iVar2 + 4) = *(word *)(iVar2 + 4) | 4;
        *(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) =
             *(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) | 0x100;
        uVar1 = *(uint *)((int)register0x00000038 + 0x48);
      }
      uVar4 = 0;
      if (((uVar1 & 1) != 0) &&
         (iVar2 = *(int *)((int)register0x00000038 + -0x1c),
         (*(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) & 0x80) == 0)) {
        *(sword *)(iVar2 + 8) = *(sword *)(iVar2 + 8) + 1;
        *(word *)(iVar2 + 4) = *(word *)(iVar2 + 4) | 8;
        *(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) =
             *(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) | 0x80;
        uVar4 = 0;
      }
    }
    else if ((_active_u[0x4f] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) == 0) {
      uVar4 = 0;
      *(undefined *)(dword_F0133DDC + 0x39) = 2;
    }
    else {
      uVar4 = 4;
    }
  }
locret_F00268B8:
  return CONCAT44(param_2,uVar4);
}

