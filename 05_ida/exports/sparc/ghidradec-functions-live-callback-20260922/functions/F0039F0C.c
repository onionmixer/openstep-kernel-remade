
/* WARNING: Removing unreachable block (ram,0xf0039f60) */
/* WARNING: Removing unreachable block (ram,0xf0039f78) */
/* WARNING: Removing unreachable block (ram,0xf0039f30) */

undefined8 _unexport(undefined4 param_1,sword *param_2)

{
  int iVar1;
  int iVar2;
  sword *psVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  piVar4 = &_exported;
  iVar1 = _exported;
  do {
    if (iVar1 == 0) {
      uVar5 = 0x16;
locret_F0039F9C:
      return CONCAT44(param_2,uVar5);
    }
    iVar1 = *piVar4 + 0x20;
    _bcmp(iVar1,param_1,8);
    iVar2 = *piVar4;
    if (iVar1 == 0) {
      if (**(sword **)(iVar2 + 0x28) == *param_2) {
        psVar3 = *(sword **)(iVar2 + 0x28) + 1;
        _bcmp(psVar3,param_2 + 1);
        iVar2 = *piVar4;
        if (psVar3 == (sword *)0x0) {
          *piVar4 = *(int *)(iVar2 + 0x2c);
          _exportfree();
          uVar5 = 0;
          goto locret_F0039F9C;
        }
      }
      else {
        iVar2 = *piVar4;
      }
    }
    iVar1 = *(int *)(iVar2 + 0x2c);
    piVar4 = (int *)(iVar2 + 0x2c);
  } while( true );
}

