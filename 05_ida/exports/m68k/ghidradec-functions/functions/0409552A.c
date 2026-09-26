
void _dbg_panic(undefined4 param_1)

{
  _nmi_prf(aDbgPanicS,param_1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
