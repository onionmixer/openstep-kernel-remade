
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
