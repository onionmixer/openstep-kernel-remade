
/* WARNING: Removing unreachable block (ram,0xf00eae3c) */
/* WARNING: Removing unreachable block (ram,0xf00eae5c) */
/* WARNING: Removing unreachable block (ram,0xf00eae14) */

undefined8 sub_F00EADC8(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined5 *puVar4;
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
  cVar1 = *param_2;
  uVar2 = param_3;
  if (cVar1 == '@') {
    _objc_msgSend(param_3,paName);
    puVar3 = aS0xX;
loc_F00EAE3C:
    _NXPrintf(param_1,puVar3,uVar2,param_3);
    goto locret_F00EAE64;
  }
  if (cVar1 < 'A') {
    if ((cVar1 != '%') && (cVar1 != '*')) goto loc_F00EAE58;
    puVar4 = &aS;
  }
  else {
    if (cVar1 == 'i') {
      puVar3 = aD0xX;
      goto loc_F00EAE3C;
    }
loc_F00EAE58:
    puVar4 = &a0xX;
  }
  _NXPrintf(param_1,puVar4,param_3);
locret_F00EAE64:
  return CONCAT44(param_2,param_1);
}
