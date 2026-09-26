/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x166a5c. */
void __cdecl stack_privilege(int a1)
{
  if ( active_threads != a1 ) /*0x166a69*/
    panic(aStackPrivilege); /*0x166a70*/
  if ( !*(_DWORD *)(a1 + 48) ) /*0x166a75*/
    *(_DWORD *)(a1 + 48) = active_stacks; /*0x166a81*/
}
