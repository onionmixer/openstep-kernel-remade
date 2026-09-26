
/* WARNING: Removing unreachable block (ram,0xf002e1f4) */
/* WARNING: Removing unreachable block (ram,0xf002e1d4) */
/* WARNING: Removing unreachable block (ram,0xf002e1b8) */
/* WARNING: Removing unreachable block (ram,0xf002e224) */
/* WARNING: Removing unreachable block (ram,0xf002e12c) */
/* WARNING: Removing unreachable block (ram,0xf002e108) */
/* WARNING: Removing unreachable block (ram,0xf002e090) */
/* WARNING: Removing unreachable block (ram,0xf002e118) */
/* WARNING: Removing unreachable block (ram,0xf002e214) */
/* WARNING: Removing unreachable block (ram,0xf002e190) */
/* WARNING: Removing unreachable block (ram,0xf002e1cc) */
/* WARNING: Removing unreachable block (ram,0xf002e1e4) */
/* WARNING: Removing unreachable block (ram,0xf002e234) */
/* WARNING: Removing unreachable block (ram,0xf002e07c) */

undefined8 _arpioctl(int param_1,sword *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int *piVar4;
  sword *psVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  psVar5 = (sword *)0x0;
  if ((*param_2 != 2) || (uVar1 = (uint)(word)param_2[8], uVar1 != 0)) {
    uVar6 = 0x2f;
    goto locret_F002E240;
  }
  _spltty();
  iVar3 = *(int *)(param_2 + 2);
  iVar2 = iVar3;
  .urem(iVar3,0x13);
  piVar4 = (int *)(_arptab + iVar2 * 0xb4);
  iVar2 = 0;
  do {
    if (*piVar4 == iVar3) break;
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 5;
  } while (iVar2 < 9);
  if (8 < iVar2) {
    piVar4 = (int *)0x0;
  }
  if (piVar4 == (int *)0x0) {
    if (param_1 != -0x7fdb96e2) {
      _splx(uVar1);
      uVar6 = 6;
      goto locret_F002E240;
    }
    psVar5 = param_2;
    _ifa_ifwithnet();
    if (psVar5 == (sword *)0x0) {
      _splx(uVar1);
      uVar6 = 0x33;
      goto locret_F002E240;
    }
  }
  if (param_1 == -0x7fdb96e0) {
    _arptfree(piVar4);
  }
  else if (param_1 < -0x7fdb96df) {
    if (param_1 == -0x7fdb96e2) {
      if (piVar4 == (int *)0x0) {
        piVar4 = *(int **)(psVar5 + 0x10);
        _arptnew(piVar4,param_2 + 2);
        if (piVar4 == (int *)0x0) {
loc_F002E1D4:
          _splx(uVar1);
          uVar6 = 0x31;
          goto locret_F002E240;
        }
        if ((*(uint *)(param_2 + 0x10) & 4) != 0) {
          iVar2 = piVar4[4];
          _arptnew(iVar2,param_2 + 2);
          if (iVar2 == 0) {
            _arptfree(piVar4);
            goto loc_F002E1D4;
          }
          _arptfree();
        }
      }
      _bcopy(param_2 + 9,piVar4 + 1,6);
      *(byte *)((int)piVar4 + 0xb) = (byte)*(undefined4 *)(param_2 + 0x10) & 0x1c | 3;
      *(undefined *)((int)piVar4 + 10) = 0;
    }
  }
  else if (param_1 == -0x3fdb96e1) {
    _bcopy(piVar4 + 1,param_2 + 9,6);
    *(uint *)(param_2 + 0x10) = (uint)*(byte *)((int)piVar4 + 0xb);
  }
  _splx(uVar1);
  uVar6 = 0;
locret_F002E240:
  return CONCAT44(param_2,uVar6);
}
