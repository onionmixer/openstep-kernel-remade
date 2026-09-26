
/* WARNING: Removing unreachable block (ram,0xf001d8b0) */

undefined8 _m_expand(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
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
  bVar1 = false;
  do {
    iVar2 = 1;
    _m_clalloc(1,0,param_1);
    if (iVar2 != 0) {
      uVar6 = 1;
locret_F001D954:
      return CONCAT44(param_2,uVar6);
    }
    if ((param_1 == 0) || (bVar1)) {
      uVar6 = 0;
      goto locret_F001D954;
    }
    if (_domains != 0) {
      uVar5 = *(uint *)(_domains + 0x14);
      iVar2 = _domains;
      while( true ) {
        if (uVar5 < *(uint *)(iVar2 + 0x18)) {
          pcVar3 = *(code **)(uVar5 + 0x2c);
          while( true ) {
            if (pcVar3 == (code *)0x0) {
              uVar4 = *(uint *)(iVar2 + 0x18);
            }
            else {
              (*pcVar3)();
              uVar4 = *(uint *)(iVar2 + 0x18);
            }
            if (uVar4 <= uVar5 + 0x30) break;
            pcVar3 = *(code **)(uVar5 + 0x5c);
            uVar5 = uVar5 + 0x30;
          }
          iVar2 = *(int *)(iVar2 + 0x1c);
        }
        else {
          iVar2 = *(int *)(iVar2 + 0x1c);
        }
        if (iVar2 == 0) break;
        uVar5 = *(uint *)(iVar2 + 0x14);
      }
    }
    DAT_f0134b08 = DAT_f0134b08 + 1;
    bVar1 = true;
  } while( true );
}

