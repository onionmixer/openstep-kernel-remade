
/* WARNING: Removing unreachable block (ram,0xf00b363c) */
/* WARNING: Removing unreachable block (ram,0xf00b3600) */
/* WARNING: Removing unreachable block (ram,0xf00b35c0) */
/* WARNING: Removing unreachable block (ram,0xf00b35ac) */
/* WARNING: Removing unreachable block (ram,0xf00b35e8) */
/* WARNING: Removing unreachable block (ram,0xf00b3618) */
/* WARNING: Removing unreachable block (ram,0xf00b3594) */
/* WARNING: Removing unreachable block (ram,0xf00b3540) */

undefined8 _obio_encode_reg(int *param_1,undefined *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  if (dword_F011DFB8 != 0) {
    _printf(aObioEncodeRegE,param_1[3]);
  }
  if ((param_2 != (undefined *)0x0) && (*param_2 = 0, param_1 != (int *)0x0)) {
    if (*param_1 == 0) {
      uVar3 = 0xffffffff;
      goto locret_F00B3648;
    }
    iVar2 = param_1[10];
    if (1 < iVar2 + 1U) {
      _getproplen(iVar2,&aReg_2);
      puVar1 = (undefined4 *)param_1[10];
      _getlongprop(puVar1,&aReg_3);
      if (puVar1 == (undefined4 *)0x0) {
        if (dword_F011DFB8 != 0) {
          _printf(aNoAddrQualifie,param_1[10]);
          uVar3 = 1;
          goto locret_F00B3648;
        }
      }
      else {
        uVar3 = *puVar1;
        uVar4 = puVar1[1];
        _kfree(puVar1,iVar2);
        _sprintf(param_2,&aXX,uVar3,uVar4);
        if (dword_F011DFB8 != 0) {
          _printf(aAddrXRegAddrXR,uVar4,puVar1[1],param_2);
        }
      }
      uVar3 = 1;
      goto locret_F00B3648;
    }
    if (dword_F011DFB8 != 0) {
      _printf(aObioEncodeRegI,param_1[3]);
    }
  }
  uVar3 = 0;
locret_F00B3648:
  return CONCAT44(param_2,uVar3);
}
