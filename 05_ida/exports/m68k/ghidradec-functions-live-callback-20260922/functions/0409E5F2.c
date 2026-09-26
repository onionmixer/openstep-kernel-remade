
/* WARNING: Control flow encountered bad instruction data */

void p_move(void)

{
  int unaff_A6;
  
  if ((*(word *)(unaff_A6 + -0xe4) & 0x1000) != 0) {
    switch(*(word *)(unaff_A6 + -0xe4) & 0x7f) {
    :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  bindec();
  mem_write();
  *(undefined *)(unaff_A6 + -0x11c) = 0;
  *(uint *)(unaff_A6 + -0xe0) = *(uint *)(unaff_A6 + -0xe0) >> 0x1d;
  return;
}

