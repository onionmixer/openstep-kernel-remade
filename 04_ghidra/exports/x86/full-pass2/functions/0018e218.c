/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e218 */

undefined4 _set_thread_state(int param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if (param_3 < 0x10) goto LAB_0018e3ce;
  if ((*(byte *)((int)param_2 + 0x26) & 2) == 0) {
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x4c) == 0) {
      uVar3 = param_2[0xb];
      if (uVar3 != 0) {
        if ((uVar3 & 4) == 0) {
          uVar2 = uVar3 >> 3 & 0x1fff;
          if (((uVar2 < 0x20) && (((byte)uVar3 & 3) == 3)) && ((_gdt[uVar2 * 8 + 5] & 0x60) == 0x60)
             ) goto LAB_0018e2a1;
        }
        else if (((byte)uVar3 & 3) == 3) {
LAB_0018e2a1:
          uVar3 = param_2[0xc];
          if ((uVar3 != 0) && ((uVar3 & 4) == 0)) {
            uVar3 = uVar3 >> 3 & 0x1fff;
            bVar1 = false;
            if ((uVar3 < 0x20) && ((_gdt[uVar3 * 8 + 5] & 0x60) == 0x60)) {
              bVar1 = true;
            }
            if (!bVar1) goto LAB_0018e3ce;
          }
          uVar3 = param_2[0xd];
          if ((uVar3 != 0) && ((uVar3 & 4) == 0)) {
            uVar3 = uVar3 >> 3 & 0x1fff;
            bVar1 = false;
            if ((uVar3 < 0x20) && ((_gdt[uVar3 * 8 + 5] & 0x60) == 0x60)) {
              bVar1 = true;
            }
            if (!bVar1) goto LAB_0018e3ce;
          }
          uVar3 = param_2[0xe];
          if ((uVar3 != 0) && ((uVar3 & 4) == 0)) {
            uVar3 = uVar3 >> 3 & 0x1fff;
            bVar1 = false;
            if ((uVar3 < 0x20) && ((_gdt[uVar3 * 8 + 5] & 0x60) == 0x60)) {
              bVar1 = true;
            }
            if (!bVar1) goto LAB_0018e3ce;
          }
          uVar3 = param_2[0xf];
          if ((uVar3 != 0) && ((uVar3 & 4) == 0)) {
            uVar3 = uVar3 >> 3 & 0x1fff;
            bVar1 = false;
            if ((uVar3 < 0x20) && ((_gdt[uVar3 * 8 + 5] & 0x60) == 0x60)) {
              bVar1 = true;
            }
            if (!bVar1) goto LAB_0018e3ce;
          }
          uVar3 = param_2[8];
          if (uVar3 != 0) {
            if ((uVar3 & 4) == 0) {
              uVar2 = uVar3 >> 3 & 0x1fff;
              if (((uVar2 < 0x20) && (((byte)uVar3 & 3) == 3)) &&
                 ((_gdt[uVar2 * 8 + 5] & 0x60) == 0x60)) goto LAB_0018e40c;
            }
            else if (((byte)uVar3 & 3) == 3) {
LAB_0018e40c:
              iVar4 = *(int *)(*(int *)(param_1 + 0x28) + 0x70);
              if (iVar4 == 0) {
                iVar4 = _kalloc(0xe0);
                *(int *)(*(int *)(param_1 + 0x28) + 0x70) = iVar4;
                puVar7 = (undefined4 *)(iVar4 + 0x84);
                puVar8 = &DAT_001d15e0;
                puVar9 = puVar7;
                for (iVar6 = 0x17; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *puVar9 = *puVar8;
                  puVar8 = puVar8 + 1;
                  puVar9 = puVar9 + 1;
                }
                *(undefined4 *)(iVar4 + 0xc4) = 0x200;
                *(undefined2 *)(iVar4 + 0xc0) = 99;
                *(undefined2 *)(iVar4 + 0xcc) = 0x6b;
                *(undefined2 *)(iVar4 + 0x90) = 0x6b;
                *(undefined2 *)(iVar4 + 0x8c) = 0x6b;
                *(undefined2 *)(iVar4 + 0x88) = 0;
                *(undefined2 *)(iVar4 + 0x84) = 0;
              }
              else {
                puVar7 = (undefined4 *)(iVar4 + 0x84);
              }
              puVar7[0xb] = *param_2;
              puVar7[8] = param_2[1];
              puVar7[10] = param_2[2];
              puVar7[9] = param_2[3];
              puVar7[4] = param_2[4];
              puVar7[5] = param_2[5];
              puVar7[6] = param_2[6];
              puVar7[0x11] = param_2[7];
              *(undefined2 *)(puVar7 + 0x12) = *(undefined2 *)(param_2 + 8);
              uVar3 = param_2[9];
              puVar7[0x10] = uVar3;
              puVar7[0x10] = uVar3 & 0x50fd7 | 0x202;
              puVar7[0xe] = param_2[10];
              *(undefined2 *)(puVar7 + 0xf) = *(undefined2 *)(param_2 + 0xb);
              *(undefined2 *)(puVar7 + 3) = *(undefined2 *)(param_2 + 0xc);
              *(undefined2 *)(puVar7 + 2) = *(undefined2 *)(param_2 + 0xd);
              *(undefined2 *)(puVar7 + 1) = *(undefined2 *)(param_2 + 0xe);
              *(undefined2 *)puVar7 = *(undefined2 *)(param_2 + 0xf);
              goto LAB_0018e502;
            }
          }
        }
      }
    }
    else {
      iVar4 = **(int **)(param_1 + 0x28);
      if (*(code **)(param_1 + 0x34) == _thread_bootstrap_return) {
        *(undefined4 *)(iVar4 + 0x28) = *param_2;
        *(undefined4 *)(iVar4 + 0x34) = param_2[1];
        *(undefined4 *)(iVar4 + 0x2c) = param_2[2];
        *(undefined4 *)(iVar4 + 0x30) = param_2[3];
        *(undefined4 *)(iVar4 + 0x44) = param_2[4];
        *(undefined4 *)(iVar4 + 0x40) = param_2[5];
        _thread_start(param_1,param_2[10]);
        goto LAB_0018e502;
      }
    }
LAB_0018e3ce:
    uVar5 = 4;
  }
  else {
    FUN_0018e510(param_1,param_2);
LAB_0018e502:
    uVar5 = 0;
  }
  return uVar5;
}

