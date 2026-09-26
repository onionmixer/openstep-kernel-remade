
/* WARNING: Removing unreachable block (ram,0xf00b4d04) */
/* WARNING: Removing unreachable block (ram,0xf00b4d1c) */
/* WARNING: Removing unreachable block (ram,0xf00b4cb4) */

undefined8 _esp_poll(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  uint uVar6;
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
  uVar5 = 0;
  uVar6 = uVar5;
  if (_esp_softc != (int *)0x0) {
    do {
      bVar1 = false;
      if (_esp_softc != (int *)0x0) {
        iVar2 = _esp_softc[1];
        piVar4 = _esp_softc;
        do {
          if (iVar2 == 0) {
            piVar4 = (int *)piVar4[10];
          }
          else {
            iVar2 = *piVar4;
            _splr();
            if (*piVar4 < iVar2) {
              puVar3 = (uint *)piVar4[0x28];
loc_F00B4CF4:
              if ((*puVar3 & 3) != 0) {
                _espsvc(piVar4);
                bVar1 = true;
                uVar6 = uVar6 | 1 << (*(byte *)(piVar4 + 0xc) & 0x1f);
              }
            }
            else {
              if (piVar4[0x20] != 0) {
                puVar3 = (uint *)piVar4[0x28];
                goto loc_F00B4CF4;
              }
              if (iVar2 == piVar4[0x2d]) {
                puVar3 = (uint *)piVar4[0x28];
                goto loc_F00B4CF4;
              }
            }
            _splx(iVar2);
            piVar4 = (int *)piVar4[10];
          }
          if (piVar4 == (int *)0x0) break;
          iVar2 = piVar4[1];
        } while( true );
      }
    } while (bVar1);
    uVar5 = 0;
    if (uVar6 != 0) {
      if ((uVar6 & uVar6 - 1) != 0) {
        _esp_nmultsvc = _esp_nmultsvc + 1;
      }
      uVar5 = 1;
      _esp_nhardints = _esp_nhardints + 1;
    }
  }
  return CONCAT44(param_2,uVar5);
}
