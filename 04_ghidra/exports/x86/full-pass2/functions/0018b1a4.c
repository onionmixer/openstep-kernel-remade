/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018b1a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _idt_init(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined *puVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  byte bVar6;
  byte bVar7;
  undefined2 uVar8;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  do {
    puVar3 = _idt;
    uVar1 = *(undefined4 *)(&_idt_pseudo + local_c);
    uVar2 = *(uint *)(&DAT_001e1a08 + local_c);
    bVar6 = (byte)(uVar2 >> 0x10) & 0x1f;
    uVar5 = (undefined2)uVar2;
    uVar8 = (undefined2)((uint)uVar1 >> 0x10);
    if (bVar6 == 0xf) {
      puVar4 = (undefined2 *)(_idt + local_c);
      *puVar4 = (short)uVar1;
      puVar4[3] = uVar8;
      puVar4[1] = uVar5;
      bVar6 = ((byte)(uVar2 >> 0x15) & 3) << 5;
      bVar7 = *(byte *)((int)puVar4 + 5) & 0x8f | 0xf;
LAB_0018b269:
      puVar3[local_c + 5] = bVar7 | bVar6 | 0x80;
    }
    else {
      if (bVar6 == 0xe) {
        puVar4 = (undefined2 *)(_idt + local_c);
        *puVar4 = (short)uVar1;
        puVar4[3] = uVar8;
        puVar4[1] = uVar5;
        bVar6 = ((byte)(uVar2 >> 0x15) & 3) << 5;
        bVar7 = *(byte *)((int)puVar4 + 5) & 0x8e | 0xe;
        goto LAB_0018b269;
      }
      if (bVar6 == 5) {
        *(undefined2 *)(_idt + local_c + 2) = uVar5;
        bVar6 = ((byte)uVar1 & 3) << 5;
        bVar7 = puVar3[local_c + 5] & 0x85 | 5;
        goto LAB_0018b269;
      }
    }
    local_c = local_c + 8;
    local_8 = local_8 + 1;
    if (0xff < local_8) {
      __idt_base = SUB42(_idt,0);
      uRam001e17bc = (undefined2)((uint)_idt >> 0x10);
      __idt_limit = 0x7ff;
      InterruptDescriptorTableRegister(CONCAT22(__idt_base,0x7ff));
      return;
    }
  } while( true );
}

