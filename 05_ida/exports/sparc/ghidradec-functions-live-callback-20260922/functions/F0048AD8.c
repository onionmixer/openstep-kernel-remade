
/* WARNING: Removing unreachable block (ram,0xf0048b6c) */

undefined8 _fspause(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  iVar2 = *(int *)(dword_F0133DDC + 0x3c);
  cVar1 = *(char *)(dword_F0133DDC + 0x40);
  *(undefined4 *)(dword_F0133DDC + 0x3c) = 0;
  *(undefined *)(dword_F0133DDC + 0x40) = 0;
  if ((iVar2 != 0) && (cVar1 != '\0')) {
    if (*(char *)(dword_F0133DDC + 0x38) != '\x1c') {
      uVar4 = 0;
      goto locret_F0048B94;
    }
    if (((*(byte *)(_active_u + 0x25c) & 8) != 0) && (param_1 == 0)) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      pcVar3 = _fssleep;
      _rpsleep();
      uVar4 = 1;
      if (pcVar3 == (code *)0x0) {
        uVar4 = 0;
        *(undefined *)(dword_F0133DDC + 0x38) = 0x1c;
      }
      goto locret_F0048B94;
    }
  }
  uVar4 = 0;
locret_F0048B94:
  return CONCAT44(param_2,uVar4);
}

