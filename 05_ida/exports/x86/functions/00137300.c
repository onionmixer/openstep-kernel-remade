/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137300. */
void __noreturn svc_run(void)
{
  int v0; // ebx
  int v1; // [esp+10h] [ebp+8h]

  while ( 1 ) /*0x13730d*/
  {
    v0 = splnet(); /*0x13730d*/
    while ( !*(_WORD *)(*(_DWORD *)v1 + 36) ) /*0x137327*/
      sbwait(*(_DWORD *)v1 + 36); /*0x137318*/
    splx(v0); /*0x13732a*/
    svc_getreq(v1); /*0x137330*/
    ++Rpccnt; /*0x137335*/
  }
}
