/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10619c. */
pid_t __cdecl wait3(int *a1, int a2, rusage *a3)
{
  int v3; // edx
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  _BYTE v8[72]; // [esp+Ch] [ebp-48h] BYREF

  v3 = *(_DWORD *)(dword_1E875C + 36); /*0x1061aa*/
  v4 = *(_DWORD *)(v3 + 8); /*0x1061ad*/
  v5 = wait1(*(_DWORD *)(v3 + 4), v8, dword_1E875C + 100, 0, wait3); /*0x1061c3*/
  v6 = v5; /*0x1061c8*/
  if ( v5 ) /*0x1061cf*/
    unix_syscall_return(v5); /*0x1061d2*/
  if ( v4 ) /*0x1061dc*/
    v6 = copyout(v8, v4, 72); /*0x1061e7*/
  return unix_syscall_return(v6); /*0x1061f5*/
}
