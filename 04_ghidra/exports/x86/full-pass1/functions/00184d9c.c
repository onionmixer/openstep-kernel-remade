/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00184d9c */

undefined4
FUN_00184d9c(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
            ,char *param_6,char *param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (DAT_001e7589 == '\0') {
    _lock_init(&DAT_001e758c,1);
    DAT_001e7589 = '\x01';
  }
  if (DAT_001e13ec == 0) {
    puVar1 = (undefined4 *)_kalloc(100);
    puVar1[2] = param_1;
    *(undefined2 *)(puVar1 + 3) = param_2;
    *(undefined2 *)((int)puVar1 + 0xe) = param_3;
    puVar1[4] = param_4;
    puVar1[5] = param_5;
    puVar1[0x18] = param_8;
    _strcpy((char *)(puVar1 + 6),param_6);
    _strcpy((char *)(puVar1 + 0x16),param_7);
    _lock_write(&DAT_001e758c);
    puVar5 = puVar1;
    if ((undefined **)PTR_LOOP_001e1400 != &PTR_LOOP_001e13fc) {
      *(undefined4 **)PTR_LOOP_001e1400 = puVar1;
      puVar5 = (undefined4 *)PTR_LOOP_001e13fc;
    }
    PTR_LOOP_001e13fc = (undefined *)puVar5;
    puVar1[1] = PTR_LOOP_001e1400;
    *puVar1 = &PTR_LOOP_001e13fc;
    PTR_LOOP_001e1400 = (undefined *)puVar1;
    _lock_done(&DAT_001e758c);
    uVar2 = 0;
  }
  else if (param_1 == 0) {
    puVar3 = (undefined4 *)_kalloc(0x84);
    puVar5 = &DAT_001e1410;
    puVar1 = puVar3;
    for (iVar4 = 0x1c; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar1 + 1;
    }
    *(undefined1 *)((int)puVar3 + 3) = 1;
    puVar3[1] = 0x84;
    puVar3[4] = DAT_001e13ec;
    puVar3[7] = param_5;
    puVar3[8] = 0;
    puVar3[10] = param_8;
    _strcpy((char *)(puVar3 + 0xc),param_6);
    *(undefined1 *)(puVar3 + 0x1c) = 2;
    *(undefined1 *)((int)puVar3 + 0x71) = 0x20;
    *(short *)((int)puVar3 + 0x72) =
         (short)CONCAT31((uint3)((byte)((ushort)*(undefined2 *)((int)puVar3 + 0x72) >> 8) & 0xf0),2)
    ;
    *(byte *)((int)puVar3 + 0x73) = *(byte *)((int)puVar3 + 0x73) & 0x9f | 0x10;
    *(undefined2 *)(puVar3 + 0x1d) = param_2;
    *(undefined2 *)((int)puVar3 + 0x76) = param_3;
    *(undefined1 *)(puVar3 + 0x1e) = 8;
    *(undefined1 *)((int)puVar3 + 0x79) = 8;
    *(short *)((int)puVar3 + 0x7a) =
         (short)CONCAT31((uint3)((byte)((ushort)*(undefined2 *)((int)puVar3 + 0x7a) >> 8) & 0xf0),6)
    ;
    *(byte *)((int)puVar3 + 0x7b) = *(byte *)((int)puVar3 + 0x7b) & 0x9f | 0x10;
    _strcpy((char *)(puVar3 + 0x1f),param_7);
    uVar2 = _msg_send_from_kernel(puVar3,1,0);
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

