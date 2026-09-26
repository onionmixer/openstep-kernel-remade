/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bd474 */

void _get_disktab(void *param_1,void *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  int local_c;
  int local_8;
  
  _bcopy(param_1,param_2,0x18);
  _bcopy((void *)((int)param_1 + 0x18),(void *)((int)param_2 + 0x18),0x18);
  uVar1 = *(uint *)((int)param_1 + 0x30);
  *(uint *)((int)param_2 + 0x30) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = *(uint *)((int)param_1 + 0x34);
  *(uint *)((int)param_2 + 0x34) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = *(uint *)((int)param_1 + 0x38);
  *(uint *)((int)param_2 + 0x38) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = *(uint *)((int)param_1 + 0x3c);
  *(uint *)((int)param_2 + 0x3c) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = *(uint *)((int)param_1 + 0x40);
  *(uint *)((int)param_2 + 0x40) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  *(ushort *)((int)param_2 + 0x44) =
       *(ushort *)((int)param_1 + 0x44) >> 8 | *(ushort *)((int)param_1 + 0x44) << 8;
  *(ushort *)((int)param_2 + 0x46) =
       *(ushort *)((int)param_1 + 0x46) >> 8 | *(ushort *)((int)param_1 + 0x46) << 8;
  *(ushort *)((int)param_2 + 0x48) =
       *(ushort *)((int)param_1 + 0x48) >> 8 | *(ushort *)((int)param_1 + 0x48) << 8;
  *(ushort *)((int)param_2 + 0x4a) =
       *(ushort *)((int)param_1 + 0x4a) >> 8 | *(ushort *)((int)param_1 + 0x4a) << 8;
  *(ushort *)((int)param_2 + 0x4c) =
       *(ushort *)((int)param_1 + 0x4c) >> 8 | *(ushort *)((int)param_1 + 0x4c) << 8;
  *(ushort *)((int)param_2 + 0x4e) =
       *(ushort *)((int)param_1 + 0x4e) >> 8 | *(ushort *)((int)param_1 + 0x4e) << 8;
  puVar2 = (uint *)((int)param_1 + 0x50);
  puVar4 = (uint *)((int)param_2 + 0x50);
  iVar3 = 0;
  do {
    uVar1 = *puVar2;
    *puVar4 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  _bcopy((void *)((int)param_1 + 0x58),(void *)((int)param_2 + 0x58),0x18);
  _bcopy((void *)((int)param_1 + 0x70),(void *)((int)param_2 + 0x70),0x20);
  *(undefined1 *)((int)param_2 + 0x90) = *(undefined1 *)((int)param_1 + 0x90);
  *(undefined1 *)((int)param_2 + 0x91) = *(undefined1 *)((int)param_1 + 0x91);
  iVar3 = 0;
  local_8 = 0;
  local_c = 0;
  do {
    puVar2 = (uint *)((int)param_1 + local_c + iVar3 + 0x92);
    puVar4 = (uint *)((int)param_2 + local_8 + 0x94);
    uVar1 = *puVar2;
    *puVar4 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = puVar2[1];
    puVar4[1] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    *(ushort *)(puVar4 + 2) = (ushort)puVar2[2] >> 8 | (ushort)puVar2[2] << 8;
    *(ushort *)((int)puVar4 + 10) =
         *(ushort *)((int)puVar2 + 10) >> 8 | *(ushort *)((int)puVar2 + 10) << 8;
    *(char *)(puVar4 + 3) = (char)puVar2[3];
    *(ushort *)((int)puVar4 + 0xe) =
         *(ushort *)((int)puVar2 + 0xe) >> 8 | *(ushort *)((int)puVar2 + 0xe) << 8;
    *(ushort *)(puVar4 + 4) = (ushort)puVar2[4] >> 8 | (ushort)puVar2[4] << 8;
    *(undefined1 *)((int)puVar4 + 0x12) = *(undefined1 *)((int)puVar2 + 0x12);
    *(undefined1 *)((int)puVar4 + 0x13) = *(undefined1 *)((int)puVar2 + 0x13);
    _bcopy(puVar2 + 5,puVar4 + 5,0x10);
    *(char *)(puVar4 + 9) = (char)puVar2[9];
    _bcopy((void *)((int)puVar2 + 0x25),(void *)((int)puVar4 + 0x25),8);
    local_8 = local_8 + 0x30;
    local_c = local_c + 0x2d;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return;
}

