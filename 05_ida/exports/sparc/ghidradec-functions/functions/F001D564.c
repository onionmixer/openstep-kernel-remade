
/* WARNING: Removing unreachable block (ram,0xf001d5e8) */

undefined8 _pfslowtimo(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
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
  if (_domains != 0) {
    uVar3 = *(uint *)(_domains + 0x14);
    iVar4 = _domains;
    while( true ) {
      if (uVar3 < *(uint *)(iVar4 + 0x18)) {
        pcVar1 = *(code **)(uVar3 + 0x28);
        while( true ) {
          if (pcVar1 == (code *)0x0) {
            uVar2 = *(uint *)(iVar4 + 0x18);
          }
          else {
            (*pcVar1)();
            uVar2 = *(uint *)(iVar4 + 0x18);
          }
          if (uVar2 <= uVar3 + 0x30) break;
          pcVar1 = *(code **)(uVar3 + 0x58);
          uVar3 = uVar3 + 0x30;
        }
        iVar4 = *(int *)(iVar4 + 0x1c);
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x1c);
      }
      if (iVar4 == 0) break;
      uVar3 = *(uint *)(iVar4 + 0x14);
    }
  }
  _timeout(_pfslowtimo,0,_hz / 2);
  return CONCAT44(param_2,param_1);
}
