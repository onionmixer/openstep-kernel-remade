
/* WARNING: Removing unreachable block (ram,0xf009a5ac) */

undefined8 sub_F009A4D4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  puVar6 = (undefined4 *)0x0;
  if (dword_F0131558 != (undefined4 *)0x0) {
    iVar2 = 0;
    iVar1 = dword_F0131558[3];
    puVar4 = dword_F0131558;
    while( true ) {
      if (iVar1 < param_1) {
        puVar5 = (undefined4 *)*puVar4;
        puVar6 = puVar4;
      }
      else {
        pcVar3 = (code *)puVar4[1];
        iVar2 = puVar4[2];
        if (puVar6 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*puVar4;
          dword_F0131558 = puVar5;
          *puVar4 = dword_F0131554;
        }
        else {
          *puVar6 = *puVar4;
          *puVar4 = dword_F0131554;
          puVar5 = (undefined4 *)*puVar6;
        }
        dword_F0131550 = dword_F0131550 + -1;
        dword_F0131554 = puVar4;
        (*pcVar3)();
        if (iVar2 == -1) goto locret_F009A5B4;
      }
      if (puVar5 == (undefined4 *)0x0) break;
      iVar1 = puVar5[3];
      puVar4 = puVar5;
    }
    if ((iVar2 != -1) && (dword_F0131558 != (undefined4 *)0x0)) {
      _softcall(sub_F009A5BC,0);
    }
  }
locret_F009A5B4:
  return CONCAT44(param_2,param_1);
}

