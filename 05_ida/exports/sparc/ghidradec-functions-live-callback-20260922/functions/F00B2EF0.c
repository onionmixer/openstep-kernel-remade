
/* WARNING: Removing unreachable block (ram,0xf00b2fc8) */
/* WARNING: Removing unreachable block (ram,0xf00b2f88) */
/* WARNING: Removing unreachable block (ram,0xf00b2f64) */
/* WARNING: Removing unreachable block (ram,0xf00b2fa4) */
/* WARNING: Removing unreachable block (ram,0xf00b2fd8) */
/* WARNING: Removing unreachable block (ram,0xf00b2f44) */

undefined8 _path_to_devi(char *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
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
  
  puVar4 = _top_devinfo;
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
  if (param_1 == (char *)0x0) {
    puVar4 = (undefined *)0x0;
  }
  else {
    for (; (*param_1 != '\0' && (*param_1 == '/')); param_1 = param_1 + 1) {
    }
    if (dword_F011DDA0 != 0) {
      _printf(aPathS,param_1);
    }
    if (*param_1 != '\0') {
      puVar3 = puVar4;
      do {
        sub_F00B2D58(param_1,(undefined *)((int)register0x00000038 + -0x88));
        if (dword_F011DDA0 != 0) {
          _printf(aNameSRemainder,(undefined *)((int)register0x00000038 + -0x88),param_1);
        }
        if (*param_1 == '@') {
          param_1 = param_1 + 1;
          sub_F00B2D58(param_1,(undefined *)((int)register0x00000038 + -0x108));
        }
        else {
          *(undefined *)((int)register0x00000038 + -0x108) = 0;
        }
        if (dword_F011DDA0 != 0) {
          _printf(aAddrspecSRemai,(undefined *)((int)register0x00000038 + -0x108),param_1);
        }
        puVar4 = (undefined *)((int)register0x00000038 + -0x88);
        sub_F00B2E94(puVar4,(undefined *)((int)register0x00000038 + -0x108),puVar3);
        if (puVar4 == (undefined *)0x0) break;
        cVar1 = *param_1;
        while ((cVar2 = *param_1, cVar1 != '\0' && (param_1 = param_1 + 1, cVar2 != '/'))) {
          cVar1 = *param_1;
        }
        puVar3 = puVar4;
      } while (*param_1 != '\0');
    }
  }
  return CONCAT44(param_2,puVar4);
}

