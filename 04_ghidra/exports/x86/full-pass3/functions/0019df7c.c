/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019df7c */

void FUN_0019df7c(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  undefined4 uVar7;
  
  puVar1 = *(uint **)(param_1 + 0x1c);
  uVar2 = puVar1[7];
  if (uVar2 == 2) {
    puVar1[0x2b] = 0x55ff;
    puVar1[0x2c] = 0xffff;
    puVar1[0x2d] = 0xf;
    puVar1[0x2e] = 0x555f;
    puVar1[0x2f] = 0xaaaf;
  }
  else if (uVar2 < 3) {
    if (uVar2 == 1) {
      if (puVar1[8] == 1) {
        puVar1[0x2b] = 0x55;
        puVar1[0x2c] = 0xff;
        puVar1[0x2d] = 0;
        puVar1[0x2e] = 0x55;
        puVar1[0x2f] = 0xaa;
      }
      else {
        puVar1[0x2b] = 99;
        puVar1[0x2c] = 0xef;
        puVar1[0x2d] = 0;
        puVar1[0x2e] = 0xf5;
        puVar1[0x2f] = 0xfa;
      }
    }
  }
  else if (uVar2 == 3) {
    puVar1[0x2b] = 0x295f;
    puVar1[0x2c] = 0x7bde;
    puVar1[0x2d] = 0;
    puVar1[0x2e] = 0x294a;
    puVar1[0x2f] = 0x5294;
  }
  else if (uVar2 == 4) {
    puVar1[0x2b] = 0xff5555ff;
    puVar1[0x2c] = 0xffffffff;
    puVar1[0x2d] = 0xff000000;
    puVar1[0x2e] = 0xff555555;
    puVar1[0x2f] = 0xffaaaaaa;
  }
  puVar1[0x36] = 0;
  iVar4 = 2;
  do {
    *(undefined1 *)(iVar4 + 0xdc + (int)puVar1) = 0;
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  puVar1[0x38] = (int)puVar1 + 0xdd;
  if ((param_3 != 0) && (*puVar1 != 3)) {
    uVar2 = puVar1[0x2b];
    iVar4 = puVar1[3] * puVar1[2];
    uVar3 = puVar1[7];
    if (uVar3 < 4) {
      if ((uVar3 < 2) && (uVar3 != 1)) {
LAB_0019e13c:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
    }
    else if (uVar3 != 4) goto LAB_0019e13c;
    puVar6 = (uint *)puVar1[6];
    uVar3 = puVar1[7];
    if (uVar3 < 4) {
      if (uVar3 < 2) {
        if (uVar3 != 1) goto LAB_0019e1b4;
        while (iVar4 = iVar4 + -1, iVar4 != -1) {
          *(char *)puVar6 = (char)uVar2;
          puVar6 = (uint *)((int)puVar6 + 1);
        }
      }
      else {
        while (iVar4 = iVar4 + -1, iVar4 != -1) {
          *(short *)puVar6 = (short)uVar2;
          puVar6 = (uint *)((int)puVar6 + 2);
        }
      }
    }
    else {
      if (uVar3 != 4) {
LAB_0019e1b4:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      while (iVar4 = iVar4 + -1, iVar4 != -1) {
        *puVar6 = uVar2;
        puVar6 = puVar6 + 1;
      }
    }
  }
  *puVar1 = param_2;
  if (param_2 != 2) {
    if (param_2 < 3) {
      if (param_2 != 1) {
LAB_0019e228:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_FBInitConsole__can_t_i_001e47ec);
      }
      uVar7 = 0;
      iVar4 = puVar1[2] * 3;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 3;
      }
      iVar4 = iVar4 >> 2;
      iVar5 = puVar1[1] * 3;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 3;
      }
      iVar5 = iVar5 >> 2;
    }
    else {
      if (param_2 != 3) goto LAB_0019e228;
      uVar7 = 1;
      iVar4 = 200;
      iVar5 = 0x140;
    }
    FUN_0019d254(puVar1,iVar5,iVar4,param_5,param_4,uVar7);
  }
  return;
}

