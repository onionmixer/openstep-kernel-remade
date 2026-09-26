/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1060ec. */
pid_t __cdecl wait4(pid_t a1, int *a2, int a3, rusage *a4)
{
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  _BYTE v10[4]; // [esp+10h] [ebp-4Ch] BYREF
  _BYTE v11[72]; // [esp+14h] [ebp-48h] BYREF

  v4 = *(_DWORD **)(dword_1E875C + 36); /*0x1060fa*/
  v5 = wait1(v4[2], v11, v10, *v4, wait4); /*0x106114*/
  v6 = v5; /*0x106119*/
  if ( v5 ) /*0x106120*/
    unix_syscall_return(v5); /*0x106123*/
  v7 = v4[3]; /*0x10612b*/
  if ( v7 ) /*0x106130*/
    v6 = copyout(v11, v7, 72); /*0x10613b*/
  v8 = v4[1]; /*0x106140*/
  if ( v8 ) /*0x106145*/
    v6 = copyout(v10, v8, 4); /*0x106153*/
  return unix_syscall_return(v6); /*0x106161*/
}
