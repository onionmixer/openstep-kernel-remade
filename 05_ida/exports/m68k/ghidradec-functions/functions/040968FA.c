
void _pcb_module_init(void)

{
  _pcb_zone = _zinit(0x1a0,0x34000,0x6800,0,&aPcb);
  return;
}

