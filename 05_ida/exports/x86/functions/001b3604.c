/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3604. */
int __cdecl EvSetParameterChar(id a1, int a2, char *__s1, int a4, int a5)
{
  id v5; // ebx

  v5 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b361f*/
  if ( !v5 ) /*0x1b3626*/
    return -729; /*0x1b3628*/
  if ( strncmp(__s1, "Ev_", 3u) || a1 == objc_msgSend(v5, sel_ev_port) ) /*0x1b3657*/
    return (int)objc_msgSend(v5, sel_setCharValues_forParameter_count_, a4, __s1, a5); /*0x1b3671*/
  return -705; /*0x1b3679*/
}
