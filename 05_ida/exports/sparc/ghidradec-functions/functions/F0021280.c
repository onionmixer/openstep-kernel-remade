
/* WARNING: Removing unreachable block (ram,0xf00213c8) */
/* WARNING: Removing unreachable block (ram,0xf0021354) */
/* WARNING: Removing unreachable block (ram,0xf00212fc) */
/* WARNING: Removing unreachable block (ram,0xf00212d8) */
/* WARNING: Removing unreachable block (ram,0xf0021344) */
/* WARNING: Removing unreachable block (ram,0xf0021384) */
/* WARNING: Removing unreachable block (ram,0xf00213e4) */
/* WARNING: Removing unreachable block (ram,0xf0021290) */

undefined8 _connect(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
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
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar5;
  _getsock();
  if (iVar1 == 0) goto locret_F00213EC;
  iVar1 = *(int *)(iVar1 + 0x18);
  *(int *)((int)register0x00000038 + -0x14) = iVar1;
  if ((*(uint *)(iVar1 + 4) & 0x104) == 0x104) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x25;
    goto locret_F00213EC;
  }
  puVar2 = (undefined *)((int)register0x00000038 + -0xc);
  _sockargs(puVar2,piVar5[1],piVar5[2],8);
  *(char *)(dword_F0133DDC + 0x38) = (char)puVar2;
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F00213EC;
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x14);
  _soconnect(uVar3,*(undefined4 *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
  iVar1 = *(int *)((int)register0x00000038 + -0x14);
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    uVar4 = *(uint *)(iVar1 + 4) & 0x104;
    if (uVar4 != 0x104) {
      _splnet();
      *(uint *)((int)register0x00000038 + -0x10) = uVar4;
      iVar1 = dword_F0133DDC + 0x28;
      _setjmp();
      if (iVar1 == 0) {
        while (iVar1 = *(int *)((int)register0x00000038 + -0x14), (*(word *)(iVar1 + 6) & 4) != 0) {
          if (*(sword *)(iVar1 + 0x56) != 0) {
            iVar1 = *(int *)((int)register0x00000038 + -0x14);
            break;
          }
          _sleep(iVar1 + 0x54,0x1a);
        }
        *(char *)(dword_F0133DDC + 0x38) = (char)*(undefined2 *)(iVar1 + 0x56);
        *(undefined2 *)(iVar1 + 0x56) = 0;
      }
      else if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        *(undefined *)(dword_F0133DDC + 0x38) = 4;
      }
      _splx(*(undefined4 *)((int)register0x00000038 + -0x10));
      iVar1 = *(int *)((int)register0x00000038 + -0x14);
      goto loc_F00213D4;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = 0x24;
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
loc_F00213D4:
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
    *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) & 0xfffb;
  }
  _m_freem(uVar3);
locret_F00213EC:
  return CONCAT44(param_2,param_1);
}
