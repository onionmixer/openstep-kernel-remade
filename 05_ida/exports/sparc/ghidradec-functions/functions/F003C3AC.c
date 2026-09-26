
/* WARNING: Removing unreachable block (ram,0xf003c5a8) */
/* WARNING: Removing unreachable block (ram,0xf003c570) */
/* WARNING: Removing unreachable block (ram,0xf003c4d4) */
/* WARNING: Removing unreachable block (ram,0xf003c46c) */
/* WARNING: Removing unreachable block (ram,0xf003c454) */
/* WARNING: Removing unreachable block (ram,0xf003c4ac) */
/* WARNING: Removing unreachable block (ram,0xf003c500) */
/* WARNING: Removing unreachable block (ram,0xf003c590) */
/* WARNING: Removing unreachable block (ram,0xf003c5c8) */
/* WARNING: Removing unreachable block (ram,0xf003c558) */
/* WARNING: Removing unreachable block (ram,0xf003c4a0) */

undefined8 sub_F003C3AC(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  if ((param_1[5] & 0x90000000U) == 0x10000000) {
    iVar2 = 1;
  }
  else {
    iVar2 = param_1[0xc];
  }
  puVar3 = _chtable;
  DAT_f013a9b4._0_4_ = DAT_f013a9b4._0_4_ + 1;
  if (_chtable < _chtable + _MAXCLIENTS * 0xc) {
    piVar4 = (int *)(_chtable + 8);
    do {
      if (piVar4[-1] == 0) {
        piVar4[-1] = 1;
        if (*piVar4 == 0) {
          piVar1 = param_1;
          _clntkudp_create(param_1,0x186a3,2,iVar2,param_2);
          *piVar4 = (int)piVar1;
          if (piVar1 == (int *)0x0) {
            _panic(aClgetNullClien);
          }
          (**(code **)(*(int *)(*(int *)*piVar4 + 0x20) + 0x10))();
        }
        else {
          _clntkudp_init(*piVar4,param_1,iVar2,param_2);
        }
        piVar1 = param_1;
        sub_F003C258(param_1,param_2);
        *(int **)*piVar4 = piVar1;
        if (*(int *)*piVar4 == 0) {
          _panic(aClgetNullAuth);
          iVar2 = *(int *)puVar3;
        }
        else {
          iVar2 = *(int *)puVar3;
        }
        *(int *)puVar3 = iVar2 + 1;
        if ((param_1[5] & 0xa0000000U) == 0xa0000000) {
          _clntkudp_interruptable(*piVar4,1);
          piVar4 = (int *)*piVar4;
        }
        else {
          piVar4 = (int *)*piVar4;
        }
        goto locret_F003C5D0;
      }
      puVar3 = (undefined *)((int)puVar3 + 0xc);
      piVar4 = piVar4 + 3;
    } while (puVar3 < _chtable + _MAXCLIENTS * 0xc);
  }
  _cltoomany = _cltoomany + 1;
  piVar4 = param_1;
  _clntkudp_create(param_1,0x186a3,2,iVar2,param_2);
  if (piVar4 == (int *)0x0) {
    _panic(aClgetNullClien_0);
    iVar2 = iRam00000000;
  }
  else {
    iVar2 = *piVar4;
  }
  (**(code **)(*(int *)(iVar2 + 0x20) + 0x10))();
  piVar1 = param_1;
  sub_F003C258(param_1,param_2);
  *piVar4 = (int)piVar1;
  if (piVar1 == (int *)0x0) {
    _panic(aClgetNullAuth_0);
  }
  if ((param_1[5] & 0xa0000000U) == 0xa0000000) {
    _clntkudp_interruptable(piVar4,1);
  }
locret_F003C5D0:
  return CONCAT44(param_2,piVar4);
}
