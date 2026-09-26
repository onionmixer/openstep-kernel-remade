
undefined8 __regparm3 _machdep_call_(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uStack00000008;
  undefined1 auStack_38 [16];
  
  uStack00000008 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  puVar1 = auStack_38;
  if (_empty_stacks != 0) {
    _empty_stacks = 0;
    puVar1 = _stack_pointers;
  }
  *(undefined1 **)(puVar1 + -4) = auStack_38;
  *(undefined4 *)(puVar1 + -8) = 0x186e2f;
  _machdep_call();
  return CONCAT44(param_2,param_1);
}

