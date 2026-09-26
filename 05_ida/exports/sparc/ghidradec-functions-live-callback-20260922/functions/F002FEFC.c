
/* WARNING: Removing unreachable block (ram,0xf003008c) */
/* WARNING: Removing unreachable block (ram,0xf003021c) */
/* WARNING: Removing unreachable block (ram,0xf0030138) */
/* WARNING: Removing unreachable block (ram,0xf003004c) */
/* WARNING: Removing unreachable block (ram,0xf0030014) */
/* WARNING: Removing unreachable block (ram,0xf002ffa0) */
/* WARNING: Removing unreachable block (ram,0xf002ff8c) */
/* WARNING: Removing unreachable block (ram,0xf002ffc8) */
/* WARNING: Removing unreachable block (ram,0xf0030024) */
/* WARNING: Removing unreachable block (ram,0xf0030124) */
/* WARNING: Removing unreachable block (ram,0xf0030178) */
/* WARNING: Removing unreachable block (ram,0xf0030234) */
/* WARNING: Removing unreachable block (ram,0xf0030248) */
/* WARNING: Removing unreachable block (ram,0xf002ff30) */

undefined8
sub_F002FEFC(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  undefined *puVar7;
  char *pcVar8;
  int iVar9;
  undefined4 unaff_l0;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(int *)((int)register0x00000038 + 0x4c) = param_3;
  *(int *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  *(int *)((int)register0x00000038 + -0x48) = param_3 + 0x108;
  *(int *)((int)register0x00000038 + -0x4c) = param_4 + 0xec;
  *(undefined4 *)((int)register0x00000038 + -0x50) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x54) = 0;
  _microtime((undefined *)((int)register0x00000038 + -0x10));
  bVar1 = *(byte *)(*(int *)((int)register0x00000038 + 0x54) + 5);
  *(uint *)((int)register0x00000038 + -0x38) =
       (uint)bVar1 ^ *(uint *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0;
  *(uint *)(*(int *)((int)register0x00000038 + 0x4c) + 0x20) =
       (uint)bVar1 ^ *(uint *)((int)register0x00000038 + -0x10);
  *(undefined2 *)((int)register0x00000038 + -0x28) = 2;
  *(undefined2 *)((int)register0x00000038 + -0x26) = 0x43;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0xffffffff;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 1;
loc_F002FF7C:
  iVar2 = *(int *)((int)register0x00000038 + -0x40);
loc_F002FF80:
  if (iVar2 == 0) {
    uVar3 = *(undefined4 *)((int)register0x00000038 + 0x4c);
    _in_bootp_bptombuf();
    *(undefined4 *)((int)register0x00000038 + -0x34) = uVar3;
    piVar4 = *(int **)((int)register0x00000038 + 0x44);
    _if_output_mbuf(piVar4,uVar3,(undefined *)((int)register0x00000038 + -0x28));
    if (piVar4 != (int *)0x0) goto loc_F0030244;
  }
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(dword_F0133DDC + 0x28);
  iVar5 = dword_F0133DDC + 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(dword_F0133DDC + 0x2c);
  _setjmp();
  iVar2 = dword_F0133DDC;
  if (iVar5 == 0) {
    pcVar6 = sub_F002FE88;
    puVar7 = (undefined *)((int)register0x00000038 + -0x2c);
    *(undefined4 *)((int)register0x00000038 + -0x2c) =
         *(undefined4 *)((int)register0x00000038 + 0x48);
    iVar2 = _hz;
loc_F0030014:
    _timeout(pcVar6,puVar7,iVar2);
    piVar4 = *(int **)((int)register0x00000038 + 0x48);
loc_F0030020:
    do {
      do {
        while( true ) {
          sub_F002FEB4(piVar4,*(undefined4 *)((int)register0x00000038 + 0x50),300);
          iVar2 = dword_F0133DDC;
          if ((piVar4 != (int *)0x23) ||
             (*(int *)((int)register0x00000038 + -0x2c) != *(int *)((int)register0x00000038 + 0x48))
             ) break;
          _sbwait(*(int *)((int)register0x00000038 + -0x2c) + 0x24);
          piVar4 = *(int **)((int)register0x00000038 + 0x48);
        }
        if ((piVar4 != (int *)0x0) && (piVar4 != (int *)0x23)) {
          *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x18);
          goto loc_F0030084;
        }
        pcVar8 = *(char **)((int)register0x00000038 + 0x50);
        if (*(int *)((int)register0x00000038 + -0x2c) == 0) {
          iVar9 = *(int *)((int)register0x00000038 + -0x40) + 1;
          *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x18);
          *(int *)((int)register0x00000038 + -0x40) = iVar9;
          iVar5 = *(int *)((int)register0x00000038 + -0x3c);
          *(int *)((int)register0x00000038 + -0x44) = *(int *)((int)register0x00000038 + -0x44) + 1;
          *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0x14);
          if (iVar9 == iVar5) {
            if (iVar9 < 0x40) {
              *(int *)((int)register0x00000038 + -0x3c) = iVar9 * 2;
              *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
            }
            else {
              *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
            }
          }
          iVar2 = *(int *)((int)register0x00000038 + -0x40);
          if (*(int *)((int)register0x00000038 + -0x44) != 0x14) goto loc_F002FF80;
          piVar4 = *(int **)((int)register0x00000038 + 0x58);
          if ((*piVar4 == 0) && (sub_F0030258(), piVar4 != (int *)0x0)) goto loc_F0030244;
          _printf(aNoResponseFrom);
          *(undefined4 *)((int)register0x00000038 + -0x50) = 1;
          goto loc_F002FF7C;
        }
        piVar4 = *(int **)((int)register0x00000038 + 0x48);
      } while ((*(int *)(pcVar8 + 4) != *(int *)((int)register0x00000038 + -0x38)) ||
              (piVar4 = *(int **)((int)register0x00000038 + 0x48), *pcVar8 != '\x02'));
      pcVar8 = pcVar8 + 0x1c;
      _bcmp(pcVar8,*(undefined4 *)((int)register0x00000038 + 0x54),6);
      iVar2 = dword_F0133DDC;
      piVar4 = *(int **)((int)register0x00000038 + 0x48);
    } while (pcVar8 != (char *)0x0);
    if ((*(char *)(*(int *)((int)register0x00000038 + -0x48) + 6) == '\0') &&
       (*(char *)(*(int *)((int)register0x00000038 + -0x4c) + 6) != '\0')) {
      if (*(int *)((int)register0x00000038 + -0x54) == 0) goto loc_f00301c0;
      piVar4 = *(int **)((int)register0x00000038 + 0x48);
      if (*(int *)((int)register0x00000038 + -0x30) == 1) goto loc_F0030020;
    }
    *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0x14);
    _untimeout(sub_F002FE88,(undefined *)((int)register0x00000038 + -0x2c));
    if (*(int *)((int)register0x00000038 + -0x50) != 0) {
      _printf(aNetworkRespond);
    }
    piVar4 = (int *)0x0;
    goto loc_F0030244;
  }
  piVar4 = (int *)0x4;
  *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x18);
loc_F0030084:
  *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0x14);
  _untimeout(sub_F002FE88,(undefined *)((int)register0x00000038 + -0x2c));
loc_F0030244:
  _untimeout(sub_F002FEA4,(undefined *)((int)register0x00000038 + -0x30));
  return CONCAT44(param_2,piVar4);
loc_f00301c0:
  *(undefined4 *)((int)register0x00000038 + -0x54) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 1;
  pcVar6 = sub_F002FEA4;
  puVar7 = (undefined *)((int)register0x00000038 + -0x30);
  iVar2 = _hz * 10;
  goto loc_F0030014;
}

