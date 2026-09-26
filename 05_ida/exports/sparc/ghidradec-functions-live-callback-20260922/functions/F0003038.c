
void _bootops(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}

